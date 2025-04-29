.PHONY: all distclean

BINEXT =

ifeq ($(shell uname),Darwin) # Forces GCC (gcc-14, homebrew) instead of Clang.
CC = gcc-14
BINEXT = .out
endif

CFLAGS += -Wall -pedantic -std=c23 -march=native -Ofast -I./include

# Executables.
EXECUTABLES = $(subst src/,executables/,$(subst .c,$(BINEXT),$(shell find src -name "Test_*.c")))

# Objects.
OBJECTS = $(subst src/,objects/,$(subst .c,.o,$(shell find src -name "*.c" -not -name "Test_*.c")))

# Directories.
DIRECTORIES = ./objects ./executables

# All.
all: $(DIRECTORIES) $(EXECUTABLES)
	@echo "Compiled everything!"

# Tests.
$(EXECUTABLES): executables/Test_%$(BINEXT): objects/Test_%.o $(OBJECTS) 
	@echo "Linking to $@"
	@$(CC) $^ -o $@

# Objects.
$(OBJECTS): objects/%.o: src/%.c $(HEADERS)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(subst src/,objects/,$(subst .c,.o,$(shell find src -name "Test_*.c"))): objects/%.o: src/%.c $(HEADERS)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Directories.
$(DIRECTORIES):
	@mkdir -p $(DIRECTORIES)

# Clean.
distclean:
	@echo "Cleaning the repo."
	@$(RM) -r $(DIRECTORIES)

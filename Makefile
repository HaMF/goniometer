TARGET   = goinometer
CC       = gcc
CFLAGS   = -pthread -lncurses -std=c99 -Wall -Wno-parentheses -I.

LINKER   = gcc -o
LFLAGS   = -pthread -lncurses -Wall -I. -lm 

# change these to set the proper directories where each files shoould be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(OBJECTS) $(LFLAGS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
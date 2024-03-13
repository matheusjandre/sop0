# Matheus Henrique Jandre Ferraz - Bacharelado Ciência da Computação
# GRR: 20215397

COMP = gcc
CFLAGS = -Wall -std=c99

PROGRAM = queue
MAIN = testafila.c

DEP = queue.o

all: $(DEP)
	@$(COMP) $(CFLAGS) *.o $(MAIN) -o $(PROGRAM)
	@echo "Successfully build. To run: ./$(PROGRAM)"

# OBJECTS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

queue.o: queue.h
	@$(COMP) $(CFLAGS) -c queue.c -o queue.o

# CLEANING -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

clean:
	@rm -rf *.o $(PROGRAM)
	@echo "Successfully purged files."

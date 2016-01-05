CC	= gcc
DEBUG	= -g
OPT	= -O3
CFLAGS	= $(DEBUG) $(OPT)
OBJECTS = main.o
LIBS	=-lm

project1: $(OBJECTS)
	cc -o $@ $(OBJECTS) $(LIBS) 

main.o: main.c

clean:
	/bin/rm -f *.o core 

realclean: clean
	/bin/rm -f project1

# DO NOT DELETE

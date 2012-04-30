CFLAGS=--std=c99 -O3 -g -Ilib
LDFLAGS=-lm
OBJ=$(subst .c,.o,$(shell ls *.c))
OBJX=$(subst .c,.x,$(shell ls *.c))
OBJLIB=$(subst .c,.o,$(shell ls lib/*.c))
#PROGRAMS=$(subst .c,.x,$(shell ls problem*.c))
PROGRAM=euler

.PHONY: clean all

all: euler.x

$(PROGRAM): $(OBJ) $(OBJLIB)
	gcc -o $(OBJ) $(OBJLIB) $(LDFLAGS)
	
eulib.o: ./lib/eulib.h 
euprobs.o: ./lib/euprobs.h 

%.x: %.c ./lib/eulib.o ./lib/euprobs.o
	gcc $(CFLAGS) $< ./lib/eulib.o ./lib/euprobs.o -o $@ $(LDFLAGS)
	cp $@ $(*F)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJ) $(OBJX) $(OBJLIB)

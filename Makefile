CC = g++
CCFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-parameter -fmax-errors=1 -fsanitize=undefined -fsanitize=address

a.out: main.cc
	@echo Give me a sec...
	$(CC) $(CCFLAGS) main.cc

clean:
	rm -f a.out core *.o

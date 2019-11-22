a.out: main.cc
	g++ -Wall -Wextra main.cc

clean:
	rm -f a.out core

a.out: main.o
	g++ main.o -lncurses -lgtest -pthread -DFOO -Wall -Wextra -Werror -std=c++17 -Wno-unused-variable -Wno-unused-parameter -o a.out

main.o: main.cc
	g++ -c main.cc

clean:
	rm a.out

	

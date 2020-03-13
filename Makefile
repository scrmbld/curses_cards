a.out: main.o player.o deck.o cards.o
	g++ main.o player.o deck.o cards.o -lncurses -lgtest -pthread -DFOO -Wall -Wextra -Werror -std=c++17 -Wno-unused-variable -Wno-unused-parameter -o a.out

main.o: main.cc
	g++ -c main.cc

player.o: player.cc player.h deck.o
	g++ -c player.cc

deck.o: deck.h deck.cc cards.o
	g++ -c deck.cc

cards.o: cards.cc cards.h
	g++ -c cards.cc

clean:
	rm a.out

	

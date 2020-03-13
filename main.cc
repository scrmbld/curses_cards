//all card sprites are 11 high by 14 wide
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <curses.h>
#include <gtest/gtest.h>
#include "cards.h"
#include "deck.h"
#include "player.h"
using namespace std;

void load_sprite(vector<vector<char>> &tgt, string path) {
	tgt.clear();
	tgt.resize(0);
	ifstream ins(path);
	while (ins) {
		string s;
		getline(ins, s);
		vector<char> vec;
		if (!ins) break;

		for (char c : s) {
			vec.push_back(c);
		}

		tgt.push_back(vec);
	}
}

void print_sprite (int x, int y, vector<vector<char>> sprite) {
	for (int i = 0; i < sprite.size(); i++) {
		for (int j = 0; j < sprite.at(i).size(); j++) {
			mvaddch(y + i, x + j, sprite.at(i).at(j));
		}
	}
}

void load_suit(vector<vector<vector<char>>> &tgt, string path) {
	tgt.clear();
	tgt.resize(13);
	vector<vector<char>> card;
	load_sprite(card, path);

	for (int i = 0; i < 13; i++) {
		string s;
		if (i + 1 == 1) s = 'a';
		else if (i + 1 == 11) s = 'j';
		else if (i + 1 == 12) s = 'q';
		else if (i + 1 == 13) s = 'k';
		else s = to_string(i + 1);
		vector<vector<char>> col;
		int numx = 0, numy = 0;
		for (int j = 0; j < card.size(); j++) {
			vector<char> row;
			for (int k = 0; k < card.at(j).size(); k++) {
				if (card.at(j).at(k) == '1') {
					for (int l = 0; l < s.size(); l++) {
						row.push_back(s.at(l));
						k++;
					}
				}
				row.push_back(card.at(j).at(k));
			}
			col.push_back(row);
		}

		tgt.at(i) = col;
	}
}


int main(int argc, char** argv) {
	
	//creating players
	vector<Player> players;
	Player dealer(5000, "Dealer");
	int player_count;
	while (true) {
		cout << "How many players are there? (1-6)\n";
		cin >> player_count;
		if (player_count < 1 || player_count > 6) {
			cout << "Please enter a number between 1 and 6\n";
			continue;
		}
		
		//input player names
		for (int i = 0; i < player_count; i++) {
			cout << "Enter a name for player " << i << endl;
			cin >> ws;//eat whitespace
			string s;
			getline(cin, s);
			players.push_back(Player(1000, s));
		}
		break;
	}

	//start ncurses
	initscr();
	noecho();

	//loading sprites
	vector<vector<vector<char>>> hearts, clubs, spades, diamonds;
	load_suit(hearts, "sprites/hearts.txt");
	load_suit(clubs, "sprites/clubs.txt");
	load_suit(spades, "sprites/spades.txt");
	load_suit(diamonds, "sprites/diamonds.txt");
	mvprintw(1, 1, "%d", hearts.at(0).size());


	refresh();
	getch();
	clear;
	endwin();
	system("clear");
	for (Player p : players) {
		cout << p << endl;
	}
	cout << dealer << endl;
}


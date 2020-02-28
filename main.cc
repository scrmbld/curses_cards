#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <curses.h>
#include <gtest/gtest.h>
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

int main(int argc, char** argv) {
        int key;
        initscr();
        printw("Hackerman");
        refresh();
        noecho();
		
		vector<vector<char>> blank;
		load_sprite(blank, "sprites/blank.txt");
		print_sprite(1, 1, blank);
		refresh();
		getch();
		clear;
		endwin();
		system("clear");

}


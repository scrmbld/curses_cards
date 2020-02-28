#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Card{
	private: 
		int face = 0;
		int suit = 0;
		string suit_string(int i) {
			if (i == 0) return "spades";
			if (i == 1) return "clubs";
			if (i == 2) return "diamonds";
			if (i == 3) return "hearts";
			else {
				cout << "invalid suit (" << i << ')' << endl;
				return "invalid suit (" + to_string(i) + ")";
			}
		}

	public:
		//constructors
		Card();
		Card(int, int);
		//accessors
		int get_face();  
		
		//will be used when displaying card to end user
		string face_string();
		
		string get_suit();
		//this is currently unused
		int get_suit_int();
};

//function definitions
std::ostream& operator<<(std::ostream &outs, Card c);
bool operator==(Card c, Card d);
bool operator!=(Card c, Card d);
bool operator==(Card c, int i);
bool operator<(Card c, int i);
bool operator>(Card c, int i);
bool operator<(Card c, Card d);
bool operator>(Card c, Card d);
bool card_greater(Card c, Card d);
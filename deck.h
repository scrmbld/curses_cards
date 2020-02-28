#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


class Deck{
	private:
		vector<Card> vec;
	public:
		friend class Hand;
		//accessors
		Card get_card(int i);
		//mutators
		Card deal();
		int size();
		void shuffle();
};

class Hand{
	private:
		vector<Card> vec;
	public: 
		//constructors
		Hand();
		//accessors
		Card get_card(int);
		int size();
		//mutators
		void add_card(Card);
		void clear();
};

std::ostream& operator<<(std::ostream &outs, Hand h);

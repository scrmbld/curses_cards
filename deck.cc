#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "cards.h"
#include "deck.h"
using namespace std;
//functions for Deck:

//accessors
Card Deck::get_card(int i) { return this->vec.at(i); }
int Deck::size() { return vec.size(); };
//mutators
Card Deck::deal() {
	Card c = this->vec.back();//deal from the back for speed
	vec.pop_back();
	return c;
}
void Deck::shuffle() {
	random_shuffle(vec.begin(), vec.end());
}


//functions for Hand:

//mutators
void Hand::add_card(Card c) {
	vec.push_back(c);
}
void Hand::clear() { vec.clear(); }
//constructors
Hand::Hand() {
	vec.clear();
}
//accessors
Card Hand::get_card(int i) { return vec.at(i); }
int Hand::size() { return vec.size(); }

//overloaded operators
std::ostream& operator<<(std::ostream &outs, Hand h) {
	for (int i = 0; i < h.size(); i++) {
    outs << h.get_card(i);
    outs << endl;
  }
  return outs;
}

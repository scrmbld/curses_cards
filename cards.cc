#include <iostream>
#include "cards.h"
//constructors
Card::Card() {
	this->face = 0;
	this->suit = 0;
}
Card::Card(int face, int suit) {
	this->face = face;
	this->suit = suit;
}
//accessors
int Card::get_face() { 
	if (face <= 0 || face > 13) {
		cout << "invalid face (" << face << ')' << endl;
		return -1;
	}
	return face; 
}

//will be used when displaying card to end user
string Card::face_string() {
	if (face <= 0 || face > 13) {
		cout << "invalid face (" << face << ')' << endl;
		return "invalid face (" + to_string(face) + ")";
	}
	if (face == 1) return "ace";
	else if (face == 11) return "jack";
	else if (face == 12) return "queen";
	else if (face == 13) return "king";
	else return to_string(face);
}

string Card::get_suit() {
	return suit_string(suit);
}

//enables cout << Card
std::ostream& operator<<(std::ostream &outs, Card c) {
	string s = c.face_string() + " of " + c.get_suit();
	outs << s;
	return outs;
}
//the Card == and != operators are mostly for the tests
bool operator==(Card c, Card d) {
	if (c.get_suit() == d.get_suit() && c.get_face() == d.get_face()) return true;
	return false;
}
bool operator!=(Card c, Card d) {
	if (c.get_suit() == d.get_suit() && c.get_face() == d.get_face()) return false;
	return true;
}

//Card int compares
bool operator==(Card c, int i) {
  if (c.get_face() == i) return true;
  return false;
}
bool operator<(Card c, int i) {
  if (c.get_face() < i) return true;
  return false;
}
bool operator>(Card c, int i) {
  if (c.get_face() > i) return true;
  return false;
}
bool operator<(Card c, Card d) {
  if (c.get_face() < d.get_face()) return true;
  return false;
}
bool operator>(Card c, Card d) {
  if (c.get_face() > d.get_face()) return true;
  return false;
}
bool card_greater(Card c, Card d) {
  if (c.get_face() > d.get_face()) return true;
  return false;
}

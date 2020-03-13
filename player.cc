#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "cards.h"
#include "deck.h"
#include "player.h"
using namespace std;

//functions for player:

//Constructors
Player::Player(int i, string s) {
  bank = i;
  name = s;
}

//accessors
int Player::get_money() { return bank; }
bool Player::is_dead() {
  if (bank <= 0 && wager <= 0)
    return true;
  return false;
}
int Player::get_wager() { return wager; }
string Player::get_name() { return name; }
//mutators
void Player::give_money(int i) { bank+= i; }
int Player::take_money(int i) {
  bank-= i;
  return i;
}
void Player::set_wager(int i) {
  wager = i;
}

//overloaded operators
std::ostream& operator<<(std::ostream &outs, Player p) {
  if (!p.is_dead()) outs << p.get_name() << ": $" << p.get_money();
  else outs << p.get_name() + ": eliminated";
  return outs;
}
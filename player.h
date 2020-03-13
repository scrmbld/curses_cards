#pragma once
#include <iostream>
#include <vector>
#include "cards.h"
#include "deck.h"
using namespace std;

class Player{
  private:
    //amount of money available
    int bank = 0;
    int wager = 0;
    //total value of hand
    string name;
  public:
    //public attributes
    Hand hand;
    //constructors
    Player(int, string);
    //accessors
    string get_name();
    int get_money();
    int get_wager();
    bool is_dead();
    //mutators
    void give_money(int);
    int take_money(int);
    void set_wager(int);
};

std::ostream& operator<<(std::ostream &outs, Player p);
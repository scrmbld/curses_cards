#include <iostream>
#include <curses.h>
#include <gtest/gtest.h>
using namespace std;

int main(int argc, char** argv) {
        int key;
        initscr();
        printw("Hackerman");
        refresh();
        noecho();
        while (true) {
                key = getch();
                printw("%d", key);
        }
        endwin();
}


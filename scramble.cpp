#include <ncurses\curses.h>

int main() {

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    mvprintw(0,0 "SCRAMBLE FOR YOU");
    refresh();

    getch();

    endwin();
    return 0;
}
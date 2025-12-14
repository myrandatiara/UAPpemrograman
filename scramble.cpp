#include <ncurses/curses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void animasi(const char teks[]){
    clear();
    for(int i=0;i<strlen(teks);i++){
        printw("%c", teks[i]);
        refresh();
        napms(40);
    }
}

void acak(char kata[]){
    int n = strlen(kata);
    for(int i=0;i<n;i++){
        int j = rand()%n;
        char t = kata[i];
        kata[i] = kata[j];
        kata[j] = t;
    }
}


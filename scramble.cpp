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

int main(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    if(has_colors() == FALSE){
        endwin();
        printf("Terminal tidak mendukung warna\n");
        return 0;
    }

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); 
    init_pair(2, COLOR_CYAN, COLOR_BLACK);   
    init_pair(3, COLOR_GREEN, COLOR_BLACK); 
    init_pair(4, COLOR_RED, COLOR_BLACK);   
    init_pair(5, COLOR_WHITE, COLOR_BLACK);  

    srand(time(0));

    char kata[20][20] = {
        "Logika","Pemrograman","Algoritma","Flowchart","Perulangan",
        "Array","Variabel","Function","Ncurses","Iostream",
        "Animasi","Integer","Boolean","Compiler","Python",
        "Error","Sequence","Bubble","Character","Nestedloop"
    };

    char jawaban[20];
    int skor = 0;
    int mainlagi = 1;
    int jumlahKata = 20;

    while(mainlagi){
        skor = 0;

        for(int i=0;i<5;i++){
            char soal[20];
            int idx = rand() % jumlahKata;

            strcpy(soal, kata[idx]);
            acak(soal);

            clear();

            attron(COLOR_PAIR(1));
            animasi("=== UnScramble Me! ===\n");
            attroff(COLOR_PAIR(1));

            attron(COLOR_PAIR(2));
            printw("\nSoal ke-%d\n", i+1);
            printw("Kata Acak : %s\n", soal);
            attroff(COLOR_PAIR(2));

            printw("Jawaban   : ");
            echo();
            getstr(jawaban);
            noecho();

            if(strcmp(jawaban, kata[idx])==0){
                attron(COLOR_PAIR(3));
                printw("\nBENAR!\n");
                attroff(COLOR_PAIR(3));
                skor += 10;
            }else{
                attron(COLOR_PAIR(4));
                printw("\nSALAH!\n");
                printw("Jawaban yang benar: %s\n", kata[idx]);
                attroff(COLOR_PAIR(4));
            }

            attron(COLOR_PAIR(5));
            printw("\nSkor sekarang : %d\n", skor);
            attroff(COLOR_PAIR(5));

            printw("Tekan tombol apa saja untuk lanjut...\n");
            refresh();
            getch();
        }

        clear();
        attron(COLOR_PAIR(1));
        printw("=== YATTAAAA ===\n");
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(3));
        printw("Kamu Menamatkan nya!\n");
        attroff(COLOR_PAIR(3));

        attron(COLOR_PAIR(5));
        printw("Skor Akhir: %d\n", skor);
        attroff(COLOR_PAIR(5));

        printw("Main lagi? (y/n)\n");
        char p = getch();
        if(p!='y') mainlagi = 0;
    }

    endwin();
    return 0;
}

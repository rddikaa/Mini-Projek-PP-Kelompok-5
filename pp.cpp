#include <ncurses/ncurses.h>
#include <windows.h>
using namespace std;

int main() {
    initscr();  

    for (int i = 0; i < 3; i++) {
        mvprintw(2, 10, "Loading...");
        mvprintw(3, 10, "--------------------"); 
        mvprintw(4, 10, "|                  |");
        mvprintw(5, 10, "--------------------");

        for (int f = 1; f < 18; f++) {
            mvprintw(4, 10 + f, ">");
            refresh();     
            Sleep(200);    
        }
    }

    endwin();  
    return 0;
}

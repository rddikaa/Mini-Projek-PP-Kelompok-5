#include <ncurses/curses.h>
#include <string>
int main(){
int x = 10, y = 10; // posisi awal teks
int ch;
// Inisialisasi ncurses
initscr(); // Memulai mode ncurses
// Mengaktifkan mode input mentah (menerima input apa adanya)
raw();
// Mengaktifkan penangkapan tombol khusus seperti panah
keypad(stdscr, TRUE);
// Mencegah karakter yang ditekan tampil di layar
noecho();
// Instruksi awal
mvprintw(0, 0, "Gunakan tombol panah untuk bergerak. Tekan 'q'untuk keluar.");
// Loop untuk menangani input dan pergerakan
while ((ch = getch()) != 'q'){
// Membersihkan layar setiap kali pergerakan terjadi
clear();
refresh();
mvprintw(0, 0, "Gunakan tombol panah untuk bergerak. Tekan'q' untuk keluar.");
mvprintw(1,0, "pp");
switch (ch){
case KEY_UP:
y = (y > 0) ? y - 1 : y;
break; // Bergerak ke atas
case KEY_DOWN:
y = (y < LINES ) ? y + 1 : y;
break; // Bergerak ke bawah
case KEY_LEFT:
x = (x > 0) ? x - 1 : x;
break; // Bergerak ke kiri
case KEY_RIGHT:
x = (x < COLS ) ? x + 1 : x;
break; // Bergerak ke kanan
}
// Debugging
std::string xTemp = std::to_string(x);
std::string yTemp = std::to_string(y);
std::string chTemp = std::to_string(ch);
mvprintw(1,0, "x :");
mvprintw(1,4,xTemp.c_str());
mvprintw(2,0,"y :");
mvprintw(2,4,yTemp.c_str());
mvprintw(3,0,"in:");
mvprintw(3,4,chTemp.c_str());
// Menampilkan 'X' pada posisi (y, x)
mvprintw(y, x, "y");
// Meng-update tampilan
refresh();
}
// Mengakhiri mode ncurses
endwin();
return 0;
}
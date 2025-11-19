#include <ncurses/curses.h>

void print_menu(WINDOW *menu_win, int pilihanTerpilih, const char *opsi[], int jumlahOpsi);

int main() {
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    int awalX = 0, awalY = 0;
    int lebar = 20, tinggi = 6;

    WINDOW *menu_win = newwin(tinggi, lebar, awalY, awalX);
    keypad(menu_win, TRUE);

    const char *opsi[] = {
        "Pilihan 1",
        "Pilihan 2",
        "Pilihan 3",
        "Keluar"
    };

    int jumlahOpsi = sizeof(opsi) / sizeof(opsi[0]);
    int pilihanTerpilih = 0;
    int pilihan = -1;

    while (1) {
        print_menu(menu_win, pilihanTerpilih, opsi, jumlahOpsi);
        int tombol = wgetch(menu_win);

        switch (tombol) {
            case KEY_UP:
                if (pilihanTerpilih <= 0)
                    pilihanTerpilih = jumlahOpsi - 1;
                else
                    --pilihanTerpilih;
                break;
            case KEY_DOWN:
                if (pilihanTerpilih >= jumlahOpsi - 1)
                    pilihanTerpilih = 0;
                else
                    ++pilihanTerpilih;
                break;
            case 10: // Enter key
                pilihan = pilihanTerpilih;
                break;
            default:
                break;
        }

        if (pilihan == 3)
            break;
    }

    clrtoeol();
    refresh();
    endwin();
    return 0;
}

void print_menu(WINDOW *menu_win, int pilihanTerpilih, const char *opsi[], int jumlahOpsi) {
    box(menu_win, 0, 0);
    for (int i = 0; i < jumlahOpsi; ++i) {
        if (i == pilihanTerpilih) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i + 1, 1, "%s", opsi[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, i + 1, 1, "%s", opsi[i]);
        }
    }
    wrefresh(menu_win);
}

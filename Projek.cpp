#include <iostream>
#include <string>
using namespace std;




// Bagian 1: Fungsi tambah tugas
void tambahTugas(string namaTugas[], string deadline[], string prioritas[], bool statusTugas[], int &jumlahTugas, int MAX_TUGAS) {
    
}

// Bagian 2: Tampilkan Tugas
void tampilkanTugas(string namaTugas[], string deadline[], string prioritas[], bool statusTugas[], int jumlahTugas) {
    
}

// Bagian 3: Ubah status tugas
void ubahStatus(bool statusTugas[], int jumlahTugas) {
}

// Bagian 4: Hapus tugas
void hapusTugas(string namaTugas[], string deadline[], string prioritas[], bool statusTugas[], int &jumlahTugas) {
}

// Bagian 5: Fungsi Statistik & menu
void tampilkanStatistik(bool statusTugas[], int jumlahTugas) {
}

void tampilkanMenu() {
    cout << "\n===== PROGRAM TO-DO LIST MAHASISWA =====\n";
    cout << "1. Tambah Tugas\n";
    cout << "2. Lihat Daftar Tugas\n";
    cout << "3. Ubah Status Tugas\n";
    cout << "4. Hapus Tugas\n";
    cout << "5. Statistik\n";
    cout << "6. Keluar\n";
}

// Fungsi utama
int main(){
    int MAX_TUGAS = 50;

    string namaTugas[MAX_TUGAS];
    string deadline[MAX_TUGAS];
    string prioritas[MAX_TUGAS];
    bool statusTugas[MAX_TUGAS];
    int jumlahTugas = 0;

    int pilihan;

    do {
        tampilkanMenu();
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahTugas(namaTugas, deadline, prioritas, statusTugas, jumlahTugas, MAX_TUGAS);
                break;
            case 2:
                tampilkanTugas(namaTugas, deadline, prioritas, statusTugas, jumlahTugas);
                break;
            case 3:
                ubahStatus(statusTugas, jumlahTugas);
                break;
            case 4:
                hapusTugas(namaTugas, deadline, prioritas, statusTugas, jumlahTugas);
                break;
            case 5:
                tampilkanStatistik(statusTugas, jumlahTugas);
                break;
            case 6:
                cout << "Keluar dari program. Sampai jumpa!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}
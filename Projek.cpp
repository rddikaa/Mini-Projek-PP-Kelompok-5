#include <iostream>
#include <string>

using namespace std;

const int MAX_TUGAS = 50;
string namaTugas[MAX_TUGAS];
string deadline[MAX_TUGAS];
string prioritas[MAX_TUGAS];
bool statusTugas[MAX_TUGAS];
int jumlahTugas = 0;


// Bagian 1: Fungsi tambah tugas
void tambahTugas() {
}

// BAgian 2: Tampilkan Tugas
void tampilkanTugas() {
}

// Bagian 3: Ubah status tugas
void ubahStatus() {
}

// Bagian 4: Hapus tugas
void hapusTugas() {
}

// Bagian 5: Fungsi Statistik & menu
void tampilkanStatistik() {
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
    tampilkanMenu();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;




// Bagian 1: Fungsi tambah tugas
void tambahTugas(string namaTugas[], string deadline[], string prioritas[], bool statusTugas[], int &jumlahTugas, int MAX_TUGAS) {
    if (jumlahTugas >= MAX_TUGAS) {
        cout << "Daftar tugas sudah penuh!\n";
        return;
    }

   cin.ignore();
    cout << "\nMasukkan nama tugas: ";
    getline(cin, namaTugas[jumlahTugas]);
    cout << "Masukkan deadline (contoh: 28 Des): ";
    getline(cin, deadline[jumlahTugas]);
    cout << "Masukkan prioritas (Tinggi/Sedang/Rendah): ";
    getline(cin, prioritas[jumlahTugas]);

    statusTugas[jumlahTugas] = false;
    jumlahTugas++;

    cout << "Tugas berhasil ditambahkan!\n";
}

// Bagian 2: Tampilkan Tugas
void tampilkanTugas(string namaTugas[], string deadline[], string prioritas[], bool statusTugas[], int jumlahTugas) {
    cout << "\n===== DAFTAR TUGAS =====\n";
    if (jumlahTugas == 0) {
        cout << "Belum ada tugas.\n";
        return;
    }

    for (int i = 0; i < jumlahTugas; i++) {
        cout << i + 1 << ". " << namaTugas[i]
             << " | Deadline: " << deadline[i]
             << " | Prioritas: " << prioritas[i]
             << " | Status: " << (statusTugas[i] ? "Selesai" : "Belum") << endl;
    }
}

// Bagian 3: Ubah status tugas
void ubahStatus(bool statusTugas[], int jumlahTugas) {
    int id;
    cout << "\nMasukkan nomor tugas yang ingin diubah statusnya: ";
    cin >> id;

    if (id < 1 || id > jumlahTugas) {
        cout << "Nomor tugas tidak valid!\n";
        return;
    }

    statusTugas[id - 1] = !statusTugas[id - 1];
    cout << "Status tugas diperbarui menjadi: "
         << (statusTugas[id - 1] ? "Selesai" : "Belum") << endl;
}

// Bagian 4: Hapus tugas
void hapusTugas(string namaTugas[], string deadline[], string prioritas[], bool statusTugas[], int &jumlahTugas) {
    int id;
    cout << "\nMasukkan nomor tugas yang ingin dihapus: ";
    cin >> id;

    if (id < 1 || id > jumlahTugas) {
        cout << "Nomor tugas tidak valid!\n";
        return;
    }

    for (int i = id - 1; i < jumlahTugas - 1; i++) {
        namaTugas[i] = namaTugas[i + 1];
        deadline[i] = deadline[i + 1];
        prioritas[i] = prioritas[i + 1];
        statusTugas[i] = statusTugas[i + 1];
    }

    jumlahTugas--;
    cout << "Tugas berhasil dihapus!\n";
}

// Bagian 5: Fungsi Statistik & menu
void tampilkanStatistik(bool statusTugas[], int jumlahTugas) {

    int selesai = 0;

    for (int i = 0; i < jumlahTugas; i++) {
        if (statusTugas[i]){
            selesai++;
        }
    }

    cout << "\n===== STATISTIK TUGAS =====\n";
    cout << "Total tugas: " << jumlahTugas << endl;
    cout << "Tugas selesai: " << selesai << endl;
    cout << "Tugas belum selesai: " << jumlahTugas - selesai<< endl;
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
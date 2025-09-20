#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
};

Penerbangan* head = nullptr;
int counterKode = 0;

void cls() {
    system("cls");
}

// header
void printHeader() {
    cout << "=============================================================\n";
    cout << "                  SISTEM JADWAL PENERBANGAN                  \n";
    cout << "-------------------------------------------------------------\n";
    cout << "       Nama : Razib Ramadhan        NIM : 2409106076\n";
    cout << "=============================================================\n";
}

// pilihan status penerbangan
string pilihStatus() {
    int pilihan;
    cout << "\nPilih status penerbangan:\n";
    cout << "1. Tepat Waktu\n";
    cout << "2. Terlambat\n";
    cout << "3. Naik Pesawat\n";
    cout << "4. Mendarat\n";
    cout << "5. Dibatalkan\n";
    cout << "Pilih (1-5): ";
    while (!(cin >> pilihan) || pilihan < 1 || pilihan > 5) {
        cout << "Input salah. Masukkan angka 1-5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    switch (pilihan) {
        case 1: return "Tepat Waktu";
        case 2: return "Terlambat";
        case 3: return "Naik Pesawat";
        case 4: return "Mendarat";
        case 5: return "Dibatalkan";
    }
    return "Tepat Waktu";
}

// membuat kode penerbangan
string buatKodePenerbangan() {
    string base = "JT-076";
    if (counterKode == 0) {
        counterKode++;
        return base;
    } else {
        counterKode++;
        return base + "-" + to_string(counterKode - 1);
    }
}

// tambah jadwal di akhir
void tambahJadwal() {
    cls();
    printHeader();
    Penerbangan* baru = new Penerbangan;
    baru->kodePenerbangan = buatKodePenerbangan();
    cout << "Masukkan tujuan penerbangan : ";
    cin.ignore();
    getline(cin, baru->tujuan);
    baru->status = pilihStatus();
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Penerbangan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "\nJadwal penerbangan berhasil ditambahkan.\n";
}

// sisipkan jadwal
void sisipkanJadwal() {
    cls();
    printHeader();
    int posisi = 6 + 1; // posisi 7
    Penerbangan* baru = new Penerbangan;
    baru->kodePenerbangan = buatKodePenerbangan();
    cout << "Masukkan tujuan penerbangan : ";
    cin.ignore();
    getline(cin, baru->tujuan);
    baru->status = pilihStatus();

    if (posisi <= 1 || head == nullptr) {
        baru->next = head;
        head = baru;
    } else {
        Penerbangan* temp = head;
        int i = 1;
        while (i < posisi - 1 && temp->next != nullptr) {
            temp = temp->next;
            i++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "\nJadwal penerbangan berhasil disisipkan pada posisi " << posisi << ".\n";
}

// hapus jadwal paling awal
void hapusAwal() {
    cls();
    printHeader();
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Penerbangan* hapus = head;
    head = head->next;
    cout << "Jadwal dengan kode " << hapus->kodePenerbangan << " berhasil dihapus.\n";
    delete hapus;
}

// update status penerbangan
void updateStatus() {
    cls();
    printHeader();
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }
    string kode;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    cin.ignore();
    getline(cin, kode);

    Penerbangan* temp = head;
    while (temp != nullptr && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Jadwal dengan kode " << kode << " tidak ditemukan.\n";
    } else {
        cout << "Status lama: " << temp->status << endl;
        temp->status = pilihStatus();
        cout << "\nStatus penerbangan berhasil diperbarui.\n";
    }
}

// tampilkan semua jadwal
void tampilkanJadwal() {
    cls();
    printHeader();
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }
    Penerbangan* temp = head;
    cout << "\n------------------- DAFTAR JADWAL PENERBANGAN -------------------\n";
    cout << left << setw(15) << "Kode"
         << setw(25) << "Tujuan"
         << setw(20) << "Status" << endl;
    cout << "-----------------------------------------------------------------\n";
    while (temp != nullptr) {
        cout << left << setw(15) << temp->kodePenerbangan
             << setw(25) << temp->tujuan
             << setw(20) << temp->status << endl;
        temp = temp->next;
    }
    cout << "-----------------------------------------------------------------\n";
}

int main() {
    int pilihan;
    do {
        cls();
        printHeader();
        cout << "Menu Utama:\n";
        cout << "1. Tambah Jadwal Penerbangan\n";
        cout << "2. Sisipkan Jadwal Penerbangan (Posisi 7)\n";
        cout << "3. Hapus Jadwal Paling Awal\n";
        cout << "4. Update Status Penerbangan\n";
        cout << "5. Tampilkan Semua Jadwal\n";
        cout << "0. Keluar\n";
        cout << "-------------------------------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipkanJadwal(); break;
            case 3: hapusAwal(); break;
            case 4: updateStatus(); break;
            case 5: tampilkanJadwal(); break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
        if (pilihan != 0) {
            cout << "\nTekan ENTER untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }
    } while (pilihan != 0);

    return 0;
}

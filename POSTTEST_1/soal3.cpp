#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Input data 4 mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }

    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK (ascending):\n";
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " | NIM: " << mhs[i].nim
             << " | IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}

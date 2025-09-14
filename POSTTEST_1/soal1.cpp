#include <iostream>
using namespace std;

void ayoKitaMemutar(int *arr, int i) {
    int *start = arr;
    int *end = arr + i - 1;
    int temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    const int array = 7;

    int data[array] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < array; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    ayoKitaMemutar(data, array);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < array; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

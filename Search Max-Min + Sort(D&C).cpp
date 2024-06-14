#include <iostream>
using namespace std;

void search(int Arr[], int kiri, int kanan, int &nilMin, int &nilMax) {
    if (kiri == kanan) {
        nilMin = nilMax = Arr[kiri];
        return;
    } else {
        int tengah = (kiri + kanan) / 2;
        int minkiri, minkanan, maxkiri, maxkanan;

        search(Arr, kiri, tengah, minkiri, maxkiri);
        search(Arr, tengah + 1, kanan, minkanan, maxkanan);

        nilMin = min(minkiri, minkanan);
        nilMax = max(maxkiri, maxkanan);
    }
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Masukkan Banyak Elemen Array: ";
    cin >> n;
    int Arr[n];

    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> Arr[i];
    }
    
    cout << "Bentuk Array (Belum Terurut) : " << endl;
    cout << "[";
    for (int i = 0; i < n; i++){
    	cout << " " << Arr[i] <<" ";
	}
    cout << "]" << endl;
    
    quicksort(Arr, 0, n - 1);

    cout << "Array yang diurutkan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << Arr[i] << " ";
    }
    cout << endl;

    int nilMin, nilMax;
    search(Arr, 0, n - 1, nilMin, nilMax);

    cout << "Nilai Min dari Array: " << nilMin << endl;
    cout << "Nilai Max dari Array: " << nilMax << endl;

    return 0;
}


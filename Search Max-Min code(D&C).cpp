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

int main() {
	int pilih;
	int n = -1;
	int Arr[1000];
	
	while(true){
		cout << "Max-Min Search Operation" << endl;
	    cout << "[1] Buat Array" << endl;
	    cout << "[2] Cetak Array" << endl;
	    cout << "[3] Cari nilai Max-Min" << endl;
	    cout << "[4] Keluar Program" << endl;
	    cout << "Masukkan Pilihan : ";
	    cin >> pilih;
	    switch (pilih){
	    	case 1:{
				cout << "Masukkan Banyak Elemen Array: ";
				cin >> n;
				if(n > 0){
					cout << "Masukkan elemen-elemen array:" << endl;
					for (int i = 0; i < n; i++) {
						cout << "Elemen ke-" << i + 1 << ": ";
						cin >> Arr[i];
					}
    			}else{
					cout << "Banyak elemen harus lebih dari 0" << endl;
				}
				cout << endl;
				break;
			}
			case 2:{
				if(n == -1){
					cout << "Array Belum dibuat" << endl;
				}else{
					cout << "Bentuk Array : " << endl;
    				cout << "[";
    				for (int i = 0; i < n; i++){
    					cout << " " << Arr[i] << " ";
					}
    				cout << "]" << endl;
				}
				cout << endl;
				break;
			}
			case 3:{
				if(n == -1){
					cout << "Array Belum dibuat" << endl;
				}else{
					int nilMin, nilMax;
					search(Arr, 0, n - 1, nilMin, nilMax);
					
					cout << "Nilai Min dari Array: " << nilMin << endl;
					cout << "Nilai Max dari Array: " << nilMax << endl;
				}
				cout << endl;
				break;
			}
			case 4:{
				return 0;
			}
			default:{
				cout << "Anda Salah Pilih" << endl;
				cout << endl;
				break;
			}
		}
	}
} // Thank You For Attention, Terima Kasih...

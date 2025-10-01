#include <iostream>
#include <vector>
using namespace std;

// fungsi merge 
// simplenya = gabung 2 array yang uda terurut jadi array penuh
void merge(vector<int>& arr, int left, int mid, int right) {
   
    /*
    1. ini cari panjang array kiri
    2. baru cari panjang array kanan
    */
    int n1 = mid - left + 1;  
    int n2 = right - mid;    

    // ini kayak deklarasi vector kiri ma kanan
    vector<int> L(n1), R(n2);

    // looping buat mengisi array kiri
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    // looping buat mengisi array kanan
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // inisiasi index buat i, j, sama k
    // kenapa k? karena kita lagi nulis ulang arr dari kiri - kanan
    // jdi ga selalu dari 0, intinya dari left
    int i = 0;    
    int j = 0;      
    int k = left;

    // bandingin elemen dari L dan R
    /*
    1. cek dulu klo elemen kiri lebih kecil atau sama kayak kanan
    2. klo iya, taruh elemen kiri ke arr
    3. terus geser posisi index kiri

    4. klo engga, taruh elemen kanan ke arr
    5. terus geser posisi index kanan
    */
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /*
    1. klo masih ada sisa di array kiri, copy dulu
    2. terus put ke arr
    */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /*
    1. ini sama kayak atas, bedanya versi kanan
    */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Fungsi utama merge sort
// = pecah" array jadi kiri dan kanan, terus urutin
void mergeSort(vector<int>& arr, int left, int right) {
   
    // klo sisa 1 element bakal berhenti
    if (left >= right)
        return;

    /*
    ini buat nyari mid nya
    */
    int mid = left + (right - left) / 2;

    /*
    1. urutin bagian kiri dulu
    2. baru urutin bagian kanan
    3. terakhir, gabungin kiri + kanan yg uda berurut
    */
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
   
    merge(arr, left, mid, right);
}

// buat display intinya
/*
1. caranya pake looping tiap elementnya
2. cari tau size array itu berapa, nah bakal looping terus
3. di cout deh
*/
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    /*
    ini dh tau la ya
    1. intinya minta input mau berapa elemen dulu
    2. misal 5, yauda masukin 5, karena disitu ada looping kan
    3. terus display deh sesuai fungsinya
    4. jreng", intinya outputkan hasilnya yg uda berurut
    */
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1);
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}
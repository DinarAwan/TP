#include<iostream>
using namespace std;

class KonversiArray {
    private:
    static const int MAX = 100;
    int data2D[MAX][MAX];
    int data1D[MAX * MAX];
    int n;
    int total;

    public:
    void konfersi1Dke2D();
    void konfersi2Dke1D();
    void tampilkanArray1D();
    void tampilkanArray2D(); 
    void inputArray2D();
    void inputUkuranArray();
    void bubbleShort1D();
    

};


void KonversiArray::inputUkuranArray(){
    cout<<"Masukan ordo array 2D : ";
    cin>>n;
    total = n * n;
}

void KonversiArray::konfersi2Dke1D() {
    int index = 0;
    for (int i = 0; i < n; i++) {         
        for (int j = 0; j < n; j++) {     
            data1D[index] = data2D[i][j];
            index++;
        }
    }
}

void KonversiArray::konfersi1Dke2D() {
    int index = 0;
    for (int i = 0; i < n; i++) {         
        for (int j = 0; j < n; j++) {     
            data2D[i][j] = data1D[index];
            index++;
        }
    }
}

void KonversiArray::tampilkanArray1D(){
    for (int i = 0; i< total; i++){
        cout<< data1D[i] << " ";
    }
}

void KonversiArray::tampilkanArray2D() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << data2D[i][j] << " ";
        }
        cout << endl;
    }
}

void KonversiArray::inputArray2D() {
    cout << "Masukkan elemen array 1D: " << endl;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << "Elemen ke-" << i + 1 << ": ";
            cin>>data2D[i][j];
        }
    }
}

void KonversiArray::bubbleShort1D(){
    for(int i = 0; i < total - 1; i++){
        for(int j = 0; j< total -i - 1; j++){
            if(data1D[j] > data1D[j + 1]){
                int temp = data1D[j];
                data1D[j] = data1D[j + 1];
                data1D[j + 1] = temp;
            }
        }
    }
}



int main(){
    KonversiArray x;
    x.inputUkuranArray();
    x.inputArray2D();
    x.tampilkanArray2D();
    
    x.konfersi2Dke1D();

    cout << "Array 1D: " << endl;
    x.tampilkanArray1D();
    x.bubbleShort1D();
    cout << "\nArray 1D setelah sorting: " << endl;
    x.tampilkanArray1D();
    x.konfersi1Dke2D();

    cout << "Array 2D: " << endl;
    x.tampilkanArray2D();
    return 0;
}

#include <iostream>	//operasi input output
#include <fstream>  //akses file
#include <string>	//mengoprasikan string
#include <iomanip>	//memanipulasi input output
using namespace std;

struct daftarMenu {			//mendeklarasikan struct
    string judul, pengarang, terbit;	//member struct
	int tahun;
};

void inf(int n) {							//fungsi untuk memasukan inputan ke file
	cout<<"Ingin Menambahkan Berapa Buku ?";cin>>n;
    daftarMenu *menu = new daftarMenu[n];  // mengalokasikan memori untuk daftarMenu
    cin.ignore(); 							// untuk membersihkan buffer setelah input
    for(int i = 0; i < n; i++){				// loop untuk memasukan data berulang ulang jika diperlukan memasukan data lebih dari satu
    	cout<<"Masukan Buku Ke-"<<i+1<<endl;;
    	cout << "Masukkan Judul: ";
    	getline(cin, menu[i].judul);		//Memasukan inputan dengan memanggil struct dan member struct
    	cout << "Masukkan Pengarang: ";
    	getline(cin, menu[i].pengarang);
    	cout << "Masukkan Penerbit: ";
    	getline(cin, menu[i].terbit);
    	cout << "Masukkan Tahun Terbit: ";
    	cin>>menu[i].tahun;	
    	cin.ignore();
    cout<<"\n|- - - - - - - - - - - - - - - - - - - -|\n";
	}
    										// ios :: app agar file tidak tertimpa
    ofstream fileku("text.txt", ios::app);	//untuk mengakses atau membuat file bernama text.txt
    if (fileku.is_open()) {					//percabangan jika file ada dan terbuka maka akan dilakukan
    	for(int i = 0; i < n; i++){			//loop untuk memasukan input ke file yang diakses
        	fileku << menu[i].judul << "|" 	//memanggil variabel menu yang menuju ke struct dan member struct
                   << menu[i].pengarang << "|" 
                   << menu[i].terbit << "|" 
                   << menu[i].tahun << "\n";
   		}
        fileku.close();						// menutup file yang telah diakses
        cout << "Data buku berhasil disimpan!\n";
    } else {
        cout << "Gagal membuka file untuk menyimpan data.\n";
    }

}

void outf() {							//fungsi untuk menampilkan isi file
    ifstream adahku("text.txt");
    string baris;					
    if (adahku.is_open()) {				//percabangan jika file ada dan terbuka maka akan dilakukan perintah dibawah
        while (getline(adahku, baris)) {	//mengulang pemanggilan perbaris pada file yang diakses
            // Mencetak header tabel
        cout << "\n+" << string(20, '-') << "+" << string(20, '-') << "+"  // baris 53 sampai 60 untuk mencetak keader tabel
             << string(20, '-') << "+" << string(15, '-') << "+\n";
        cout << "|" << setw(20) << left << "Judul" << "|" 
             << setw(20) << left << "Pengarang" << "|" 
             << setw(20) << left << "Penerbit" << "|" 
             << setw(15) << left << "Tahun Terbit" << "|\n";
        cout << "+" << string(20, '-') << "+" << string(20, '-') << "+" 
             << string(20, '-') << "+" << string(15, '-') << "+\n";

        // Mencetak data buku
        while (getline(adahku, baris)) {	//mengulang pemanggilan perbaris pada file yang diakses
            size_t pos = 0;
            int col = 0;
            string tokens[4];
            while ((pos = baris.find("|")) != string::npos) { //untuk pencarian dalam string
                tokens[col] = baris.substr(0, pos);
                baris.erase(0, pos + 1);
                col++;
            }
            tokens[3] = baris; // sisa string adalah tahun
            
            cout << "|" << setw(20) << left << tokens[0].substr(0, 19) << "|"
                 << setw(20) << left << tokens[1].substr(0, 19) << "|"
                 << setw(20) << left << tokens[2].substr(0, 19) << "|"
                 << setw(15) << left << tokens[3] << "|\n";
        }
        cout << "+" << string(20, '-') << "+" << string(20, '-') << "+" 
             << string(20, '-') << "+" << string(15, '-') << "+\n";
        }
        adahku.close();					//untuk menutup file
    } else {
        cout << "File tidak ditemukan atau tidak dapat dibuka.\n";
    }
        system("START /MIN NOTEPAD text.txt"); // untuk membuka file pada text.txt notepade++
}


int jumlah(){					//fungsi rekrusif untuk menghirung jumlah
	ifstream adahku("text.txt");		//untuk mengakases file texk.txt
    string baris;
    int hitung = 0;
    if (adahku.is_open()) {			//percabangan jika file ada dan terbuka
        while (getline(adahku, baris)) {	//untuk looping perbaris 
            hitung++;						//setiap looping di ++
        }
        adahku.close();
        return hitung-1;	//di - 1 karena ada baris header yang terhitung jadi di kurang 1 agar tepat untuk buku saja
    } else {
        cout << "File tidak ditemukan atau tidak dapat dibuka.\n";
    }
}
int main() {
    int pilihan;
    int n;
    daftarMenu* menu = new daftarMenu[n]; //mendeklarasikan array
    do {
        cout << "+===========================================+" << endl;
        cout << "|											" << endl;
        cout << "|    SISTEM CRUD INVENTORY BUKU		   	 " << endl;
        cout << "|                                           " << endl;
        cout << "|    1. TAMBAH BUKU                         " << endl;
        cout << "|                                           " << endl;
        cout << "|    2. DAFTAR BUKU               	         " << endl;
        cout << "|                                           " << endl;
        cout << "|    3. JUMLAH BUKU                         " << endl;
        cout << "|                                           " << endl;
        cout << "|    4. KELUAR		                         " << endl;
        cout << "|                                           " << endl;
        cout << "+===========================================+" << endl;
        cout<<"Pilih Salah Satu : ";
        cin >> pilihan;
        switch (pilihan) {		//percabangan jika memilih salah satu
        case 1:
        	int n;
            inf(n);			//memanggil fungsi untuk input data
            break;
        case 2:
            outf();			//memanggil fungsi untuk menampilkan data
            break;
        case 3:
            cout<<"Jumlah Buku = "<<jumlah()<<endl;	// memanggil fungsi rekursif untuk mengetahui jumlah
        	break;
        case 4:
            cout << "\nTerima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);		// kondisi jika memilih 4 akan keluar program

    return 0;
}


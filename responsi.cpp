#include<iostream>
#include<iomanip>
using namespace std;

class mahasiswa{
	public:
		void input();
		void sorting();
		void searching();
		
		private:
			int n;
			int nilai[10], nim[10];
			int sortnim, sortnilai,sortkelas;
			string sortnama, sortmk, cari, kelas, nama[30], matkul[30];
}; 

void mahasiswa::input(){
			cout<<"Masukkan Jumlah data Mahasiswa : ";
			cin>>n;
			for(int i=0; i<n; i++){
				cout<<"---------------------------------------"<<endl;
				cout<<"Masukkan Kelas Mahasiswa "<<i+1<< " : ";
				cin>>kelas[i];
				cout<<"Masukkan Matakuliah Mahasiswa "<<i+1<< " : ";
				cin>>matkul[i];
				cout<<"Masukkan Nama Mahasiswa "<<i+1<< " : ";
				cin>>nama[i];
				cout<<"Masukkan NIM Mahasiswa "<<i+1<<" : ";
				cin>>nim[i];
				cout<<"Masukkan Nilai Mahasiswa "<<i+1<<" : ";
				cin>>nilai[i];
			}
			cout<<"=============================================="<<endl;
		}

void mahasiswa::sorting(){ //sorting menggunakan metode insertion sort
			for(int i=0; i<n; i++){
				for(int j = i; j<n; j++){
					if(nim[i] > nim[j]){
						sortnilai = nilai[j];
						nilai[j] = nilai[i];
						nilai[i] = sortnilai;
						
							sortnama = nama[j];
							nama[j] = nama[i];
							nama[i] = sortnama;
							
							sortnim = nim [j];
							nim[j] = nim[i];
							nim[i] = sortnim;

              sortkelas = kelas [j];
              kelas[j] = kelas[i];
              kelas[i] = sortkelas;
              
              sortmk = matkul [j];
              matkul [j] = matkul[i];
              matkul [i] = sortmk;
					}
				}
			}
		}

void mahasiswa::searching(){
			//fungsi setiosflag adalah untuk memanipulasi format tulisan dan saya menggunakan ios left agar tulisan  rata kiri.
			//setw untuk mengatur lebar tulisan
			
			for(int i=0; i<n; i++){	
       			cout<<setiosflags (ios::left)<<setw(5)<<"Kelas : "<<kelas[i]<<endl;
       			cout<<setiosflags (ios::left)<<setw(5)<<"Mata Kuliah : "<<matkul[i]<<endl;
       		cout<<"===================================="<<endl;
			cout<<"| NIM        |  NAMA  |  NILAI     | "<<endl;
			cout<<"===================================="<<endl;
				cout<<"|  ";
				cout<<setiosflags(ios::left)<<setw(5)<<nim[i]<<"|   ";
				cout<<setiosflags(ios::left)<<setw(5)<<nama[i]<<"|   ";
				cout<<setiosflags(ios::left)<<setw(5)<<nilai[i]<<" |"<<endl;
			}
			
			cout<<"======================================="<<endl;
			cout<<"Masukkan Nama Mahasiswa yang ingin dicari  : ";
			cin>>cari;
			
			int k=0;
			for (int i=0; i<n; i++){
				if(nama[i] == cari){
					
				cout<<setiosflags(ios::left)<<setw(5)<<"Nama	: "<<nama[i]<<endl;
				cout<<setiosflags (ios::left)<<setw(5)<<"Kelas	: "<<kelas[i]<<endl;
				cout<<setiosflags(ios::left)<<setw(5)<<"NIM	: "<<nim[i]<<endl;
       			cout<<setiosflags (ios::left)<<setw(5)<<matkul[i]<<"	: "<<nilai[i]<<endl;
//				cout<<setiosflags(ios::left)<<setw(5)<<nilai[i]<<" |"<<endl;
			
			cout<<"======================================="<<endl;
					k++;
					break;
				}
			}
			if(k == 0){
				cout<<" MOHON MASUKKAN NAMA YANG VALID ";
			}
		}
int main(){
  mahasiswa x;
	x.input();
	x.sorting();
	x.searching();
}

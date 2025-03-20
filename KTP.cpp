#include<iostream>
#include<string>
using namespace std;

class Username{
	private:
		string nama;
		string alamat;
		
	public:
		friend ostream &operator<<(ostream &output, const Username &username);
		friend istream &operator >>(istream &input, Username &username);
		
		void setNama(string nama){
			this->nama = nama;
			this->alamat = alamat;
		}
		
		void tampilkan(){
			cout<<"Nama : "<<this->nama <<endl;
			cout<<"Alamat : "<<this->alamat<<endl;
		}
};

ostream &operator <<(ostream &output, const Username &username){
	output <<"nama : "<<username.nama<<endl; 
	return output;
}

istream &operator >>(istream &input, Username &username){
	cout<<"Nama : "<<username.nama;
	input >> username.nama;
	cout<<"Alamat : "<<username.alamat;
	input >> username.alamat;
	return input;
}

int main(){

cout<<"====KTP Jawir====\n";	
	Username x;
	cin >>x;


	x.tampilkan();	

}

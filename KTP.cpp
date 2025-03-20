#include<iostream>
#include<string>
using namespace std;

class Ktp{
	private:
		char goldar;
		int nik, Rt, Rw; 
		string nama, alamat, TTL, Provinsi, kabupaten, jeniskelamin, agama, kelurahan;
		string kecamatan, status, pekerjaan, negara;
		
		
	public:
		friend ostream &operator<<(ostream &output, const Ktp &ktp);
		friend istream &operator >>(istream &input, Ktp &ktp;

		void tampilkan(){
			//Tampilan 
		}
};

ostream &operator <<(ostream &output, const Ktp &ktp){
	output<<"Nama: " << ktp.nama<<endl;
	output<<"Alamat: "<< ktp.alamat<<endl;
	
	return output;
}

istream &operator >>(istream &input, Ktp &ktp){
	cout<<"Masukkan Nik Anda: ";
	input >>ktp.nik;
	input.ignore();
	
	cout<<"Provinsi: ";
	getline(input, ktp.provinsi);
	cout<<"Kabupaten/Kecamatan: ";
	input >> ktp.kabupaten;
	
	cout<<"Masukkan Nama anda: ";
	getline(input, ktp.nama);
	
	cout<<"Masukkan Tempat/Tgl Lahir anda: ";
	getline(input, ktp.TTL);
	
	cout<<"Jenis Kelamin: ";
	input >> ktp.jeniskelamin;
	
	cout<<"Masukkan Golongan darah anda: ";
	input >> ktp.goldar;
	input.ignore();
	
	cout<<"Masukkan alamat anda: ";
	getline(input,ktp.alamat);
	cout<<"Masukkan RT anda: ";
	input >> ktp.Rt;
	input.ignore();
	
	cout<<"Masukkan RW anda: ";
	input >> ktp.Rw;
	input.ignore();
	
	cout<<"Masukkan kelurahan/Desa anda: ";
	getline(input, ktp.kelurahan);
	cout<<"Masukkan kecamatan anda: ";
	input >> ktp.kecamatan;
	cout<<"Agama: ";
	input >> ktp.agama;
	cout<<"Status Perkawinan: ";
	input >> ktp.status;
	cout<<"Masukkan pekerjaan anda: ";
	input >> ktp.pekerjaan;
	cout<<"Kewarganegaraan: ";
	input >> ktp.negara;
	
	
	return input;
}

int main(){

cout<<"====KTP Sederhana ====\n";	
	Ktp data ;
	cin >>data;


	data.tampilkan();
	
	return 0;	

}

#include <iostream>
#include <string>
using namespace std;

class Ktp {
private:
    char goldar;
    int nik, Rt, Rw;
    string nama, alamat, TTL, provinsi, kabupaten, jeniskelamin, agama, kelurahan;
    string kecamatan, status, pekerjaan, negara;

public:
    friend ostream &operator<<(ostream &output, const Ktp &ktp);
    friend istream &operator>>(istream &input, Ktp &ktp);

    void tampilkan();
};

ostream &operator<<(ostream &output, const Ktp &ktp) {
    output << "Nama: " << ktp.nama << endl;
    output << "Alamat: " << ktp.alamat << endl;
    return output;
}

istream &operator>>(istream &input, Ktp &ktp) {
    cout << "Masukkan Nik Anda: ";
    input >> ktp.nik;
    input.ignore();

    cout << "Provinsi: ";
    getline(input, ktp.provinsi);
    
    cout << "Kabupaten/Kecamatan: ";
    getline(input, ktp.kabupaten);
    
    cout << "Masukkan Nama Anda: ";
    getline(input, ktp.nama);
    
    cout << "Masukkan Tempat/Tgl Lahir Anda: ";
    getline(input, ktp.TTL);
    
    cout << "Jenis Kelamin: ";
    getline(input, ktp.jeniskelamin);
    
    cout << "Masukkan Golongan darah Anda: ";
    input >> ktp.goldar;
    input.ignore();
    
    cout << "Masukkan alamat Anda: ";
    getline(input, ktp.alamat);
    
    cout << "Masukkan RT Anda: ";
    input >> ktp.Rt;
    input.ignore();
    
    cout << "Masukkan RW Anda: ";
    input >> ktp.Rw;
    input.ignore();
    
    cout << "Masukkan kelurahan/Desa Anda: ";
    getline(input, ktp.kelurahan);
    
    cout << "Masukkan kecamatan Anda: ";
    getline(input, ktp.kecamatan);
    
    cout << "Agama: ";
    getline(input, ktp.agama);
    
    cout << "Status Perkawinan: ";
    getline(input, ktp.status);
    
    cout << "Masukkan pekerjaan Anda: ";
    getline(input, ktp.pekerjaan);
    
    cout << "Kewarganegaraan: ";
    getline(input, ktp.negara);

    return input;
}

void Ktp::tampilkan() {
    cout << "\n\t\t\t   PROVINSI " << provinsi << endl;
    cout << "\t\t\t KABUPATEN " << kabupaten << endl;

    cout << "\nNIK\t\t\t: " << nik << endl;
    cout << "Nama\t\t\t: " << nama << endl;
    cout << "Tempat/Tgl Lahir\t: " << TTL << endl;
    cout << "Jenis Kelamin\t\t: " << jeniskelamin << "\t\tGol. Darah : " << goldar << endl;
    cout << "Alamat\t\t\t: " << alamat << endl;
    cout << "\tRT/RW\t\t: " << Rt << "/" << Rw << endl;
    cout << "\tKL/Desa\t\t: " << kelurahan << endl;
    cout << "\tKecamatan\t: " << kecamatan << endl;

    cout << "\nAgama\t\t\t: " << agama << endl;
    cout << "Status Perkawinan\t: " << status << endl;
    cout << "Pekerjaan\t\t: " << pekerjaan << endl;
    cout << "Kewarganegaraan\t\t: " << negara << endl;
    cout << "Berlaku Hingga\t\t: SEUMUR HIDUP" << endl;
}

int main() {
    cout << "==== KTP Sederhana ====\n";
    Ktp data;
    cin >> data;
    data.tampilkan();

    return 0;
}

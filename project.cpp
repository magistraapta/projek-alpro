#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void menuUtama();
void admin();
void user();

int kuota = 0;
string lokasi;

struct paket{
    string nama;
    string asal;
    string penerima;
    string tujuan;
    string berat;
    string cetakResi;
    string lokasi;
}pkt[50];



void inputPaket(){
    kuota++;
    for (int i = 0; i < kuota; i++)
    {
        cout << "Paket ke-" << kuota << endl;
        cout << "Nama pengirim: "; getline(cin >> ws, pkt[kuota].nama);
        cout << "Nama penerima: "; getline(cin >> ws, pkt[kuota].penerima);
        cout << "Asal barang (bandung, surabaya, jakarta): "; getline(cin, pkt[kuota].asal);
        cout << "Tujuan pengiriman (bandung, surabaya, jakarta): "; getline(cin, pkt[kuota].tujuan);
        cout << "Berat barang: ";cin>> pkt[kuota].berat;

        string noresi;
        srand(time(0));

        long int j = 0;
        j = 10000000 + (rand() % 90000000);

        noresi = to_string(j);

        pkt[kuota].cetakResi = noresi;

        cout<< "Nomor resi kamu: "<< pkt[kuota].cetakResi << endl;
        cout <<"\n" << endl;
        admin();
    }
    
    

    
}

void cariPaket(){
    kuota++;
    int counter = 0;
    string enteredNumber;
    awal:
    cout << "Masukkan nomor resi: "; cin >> enteredNumber;
    if (pkt[kuota].cetakResi == enteredNumber)
    {
        counter = 1;
        cout << "\n\n------------------INFO PAKET------------------";
        cout << "\n-----------------------------------------------";
        cout << "\n\t\t---JASA KURIR JNA---";
        cout << "\n    Nama Pengirim : " << pkt[kuota].nama << " " << endl;
        cout << "\n    Nama penerima: " << pkt[kuota].penerima << " " << endl;
        cout << "\n    From : " << pkt[kuota].asal << endl;
        cout << "\n    To : " << pkt[kuota].tujuan << endl;
        cout << "\n    Berat Paket: " << pkt[kuota].berat << "kg" << endl;
        cout << "\n    Nomor resi : " << pkt[kuota].cetakResi << endl;

            cout << "\n-----------------------------------------------\n";
        menuUtama();
    } else if (pkt[kuota].cetakResi != enteredNumber)
    {
        cout << "Nomor resi tidak ditemukan atau salah!" << endl;
        goto awal;
    }
    
}

void updateLokasi(){
   
}

void admin(){
    int pilih;
    cout <<"1. input data paket" << endl;
    cout <<"2. Update lokasi paket" << endl;
    cout <<"3. Kembali" << endl;
    cout << ">> "; cin >> pilih;
    switch (pilih)
    {
    case 1:
        inputPaket();
        break;
    case 2:
        updateLokasi();
        break;
    case 3:
        menuUtama();
        break;
    
    default:
        break;
    }
}

void lacakPaket(){

}


void user(){
    int pilih;
    cout << "1. Cek informasi paket" << endl;
    cout << "2. Lacak paket" << endl;
    cout << "3. Kembali" << endl;
    cout <<">> ";cin >>pilih;
    switch (pilih)
    {
    case 1:
        cariPaket();
        break;
    case 2:
        lacakPaket();
        break;
    case 3:
        menuUtama();
        break;
    
    default:
        break;
    }
}

void menuUtama(){
    
    cout << "\n" << endl;
    int pilih;
    cout << "1. Menu admin" << endl;
    cout << "2. Menu User" << endl;
    cout << ">> "; cin >> pilih;
    switch (pilih)
    {
    case 1:
        admin();
        
        break;
    case 2:
        user();
        
        break;
    
    default:
        break;
    }
}

int main()
{
    menuUtama();
    return 0;
}

#include <iostream>
using namespace std;

void menu();

struct paket {
    string nama;
    string asal;
    string tujuan;
    string kelas;
    string tanggal;
    string noKursi;
    string noTiket;
    string biaya;
}tkt[100];


string tipeKelas;



void pesanTiket(int i){
    int asal, tujuan,kelas;
    do
    {
        cout << "\nKota asal" << endl;
        cout << "1. Jakarta" << endl;
        cout << "2. Surabaya" << endl;
        cout << "3. Lombok" << endl;
        cout << "Pilih kota asal: "; cin >> asal;
        switch (asal)
        {
        case 1:
            tkt[i].asal = "Jakarta";
            break;
        case 2:
            tkt[i].asal = "Surabaya";
            break;
        case 3:
            tkt[i].asal = "Lombok";
            break;
        
        default:
        cout << "Input invalid";
            break;
        }

    } while (asal > 3);

    do
    {
        cout << "\nKota tujuan" << endl;
        cout << "1. New York" << endl;
        cout << "2. Los Angeles" << endl;
        cout << "3. Tokyo" << endl;
        cout << "4. seoul" << endl;
        cout << "Pilih kota tujuan: "; cin >> tujuan;
        switch (tujuan)
        {
        case 1:
            tkt[i].tujuan = "New York";
            break;
        case 2:
            tkt[i].tujuan = "Los Angeles";
            break;
        case 3:
            tkt[i].tujuan = "Tokyo";
            break;
        case 4:
            tkt[i].tujuan = "Seoul";
            break;
        
        default:
        cout << "Input Invalid" << endl;
            break;
        }
    } while (tujuan > 4);

    cout << "\nMasukkan nama anda: "; getline(cin >> ws, tkt[i].nama);
    cout << "Tanggal Keberangkatan (dd-mm-yy): "; getline(cin >> ws, tkt[i].tanggal);

    do
    {
        cout << "\nPilih kelas tiket" << endl;
        cout << "1. Economy" << endl;
        cout << "2. Business" << endl;
        cout << ">> "; cin >> kelas;
        switch (kelas)
        {
        case 1:
            tkt[i].kelas = "Economy";
            tipeKelas = "Economy";
            break;
        case 2:
            tkt[i].kelas = "Business";
            tipeKelas = "Business";
            break;
        
        default:
        cout << "Invalid Input";
            break;
        }
    } while (kelas > 2);
    
    srand(time(0));

    long int k = 0;
    k = 10 + (rand() % 90);

    tkt[i].noKursi = to_string(k);

    srand(time(0));

    long int j = 0;
    j = 10000000 + (rand() % 90000000);

    tkt[i].noTiket= to_string(j);

    

    cout << "\nTiked berhasil di booking " << endl;
    cout << "Nomor tiket anda: " << tkt[i].noTiket << endl;

    if (tipeKelas == "Economy" )
    {
        tkt[i].biaya = "Rp. 680.000";
    } else {
        tkt[i].biaya = "Rp. 1.200.000";
    }
}

void cekTiket(int i){
    int counter = 0;
    string enteredNumber;
   cout << "Masukkan nomor tiket anda: "; cin>> enteredNumber;
   for (int j = 0; j <= i; j++)
   {
        if (tkt[j].noTiket == enteredNumber) {
            counter = 1;
            cout << "\n\n------------------Your Ticket------------------";
            cout << "\n-----------------------------------------------";
            cout << "\n\t\t---Lombok Airlines---";
            cout << "\n   Your Name : " << tkt[j].nama;
            cout << "\n   From : " << tkt[j].asal;
            cout << "\t\tTo : " << tkt[j].tujuan;
            cout << "\n   Date : " << tkt[j].tanggal << "\t" << "Seat number : B" << tkt[j].noKursi; 
            cout << "\n   Ticket Class : " << tkt[j].kelas;
            cout << "\n   Ticket number : " << tkt[j].noTiket << "\tFare : " << tkt[j].biaya;

            cout << "\n-----------------------------------------------\n";
            cout << "-----------------------------------------------\n";
            menu();
            break;
        } else if (tkt[j].noTiket == " ")
        {
            cout << "Tiket anda tidak ditemukan" << endl;
            menu();
        }
        
   }
   if (counter == 0)
        {
            cout << "Tiket anda tidak ditemukan" << endl;
            menu();
        } else {
            counter = 0;
        } 
}

void cancelTiket(int i){
    int counter = 0;
    string enteredNumber;

   cout << "Masukkan nomor tiket anda: "; cin>> enteredNumber;
   for (int j = 0; j <= i; j++)
   {
        if (tkt[j].noTiket == enteredNumber) {
            counter = 1;
            tkt[j].nama= " ";
            tkt[j].noTiket= " ";
            tkt[j].tujuan= " ";
            tkt[j].asal= " ";
            tkt[j].biaya= " ";
            tkt[j].noKursi= " ";
            tkt[j].tanggal= " ";
            tkt[j].kelas= " ";
          
            break;
        }
   }

     if (counter == 0)
        {
            cout << "Tiket anda tidak ditemukan" << endl;
            menu();
        } else {
            cout << "tiket berhasil di cancel" << endl;
            counter = 0;
        }
}

void menu(){
    int pilih;
    int i;
    do
    {
        i++;
        cout << "\n--------------MENU UTAMA--------------" << endl;
        cout << "1. Pesan tiket " << endl;
        cout << "2. Cek tiket " << endl;
        cout << "3. Cancel tiket " << endl;
        cout << ">> ";cin >> pilih;
        switch (pilih)
        {
        case 1:
            pesanTiket(i);
            break;
        case 2:
            cekTiket(i);
            break;
        case 3:
            cancelTiket(i);
            break;
        
        
        default:
            break;
        }
    } while (pilih != 2);
}

int main()
{
    menu();
    return 0;
}
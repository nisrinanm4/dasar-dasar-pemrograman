#include <iostream>
using namespace std;

int main(){
    cout << "Selamat Datang di Permainan Game Tebak Angka"<<endl;
    cout << "============================================"<<endl;
    cout << endl;
    cout << "Silahkan Login Terlebih Dahulu"<<endl;
    cout << "Masukkan Nama dan NIM Anda"<<endl;

    string nama,nim;
    int check = 0;

do
{
        cout << "Nama : ";
        cin >> nama;
        cout << "NIM : ";
        cin >> nim;
        if (nama == "nisrina" && nim == "124240149")
    {
        check = 3;
    } 
        check++;
} while (check < 3);

    int tebak_angka;
    int angka_benar = 4;

    cout <<endl;
    cout << "MENU PERMAINAN"<<endl;
    cout << "Tebak Angka (1-10)"<<endl;
    cout <<endl;
    cout << "Masukan Angka Dari (1-10) : ";
    cin >> tebak_angka;

do
{ 
    if (tebak_angka > angka_benar)
    {
        cout << "Angka terlalu besar";
        break;
    } 
        else if (tebak_angka < angka_benar)
    {
        cout << "Angka Terlalu Kecil";
        break;
    }
        else 
    {
        cout << "Selamat Kamu Benar, Angkanya adalah " << angka_benar <<endl;
        break;
    }
} while (tebak_angka != angka_benar);

    return 0;
}

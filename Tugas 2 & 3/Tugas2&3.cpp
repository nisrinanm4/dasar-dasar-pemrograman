#include <iostream>
using namespace std;

struct barang {
    string nama_barang;
    int jumlah_barang_beli;
    int harga_satuan;
    int total_harga;
};
    void inputBarang(barang daftar_barang[], int& jumlah_brng)
        { 
            cout << "Jumlah Barang Belanja : ";
            cin >> jumlah_brng;
            system("pause");

            for (int i = 0; i < jumlah_brng; i++)
            {
                cout << "Nama Barang Belanjaan ke " << i + 1 << " : ";
                cin >> daftar_barang[i].nama_barang;

                cout << "Jumlah Barang Yang di Beli : ";
                cin >> daftar_barang[i].jumlah_barang_beli;

                cout << "Harga Barang Satuan: Rp.";
                cin >> daftar_barang[i].harga_satuan;

                daftar_barang[i].total_harga = daftar_barang[i].jumlah_barang_beli * daftar_barang[i].harga_satuan;

                cout << "Total Harga: Rp." << daftar_barang[i].total_harga << endl;
                cout << endl;
            }
            system("cls");
        }
 
void tampilkanDaftarBelanja(barang daftar_barang[], int jumlah_brng)
        {
            int total_harga_brng = 0;

            cout << "============================"<< endl;
            cout << "      DAFTAR BELANJA        "<< endl;
            cout << "============================"<< endl;
            cout << endl;
            
            for (int i = 0; i < jumlah_brng; i++) 
            {
                cout << daftar_barang[i].nama_barang << endl;
                cout << "Harga Barang Satuan : " << daftar_barang[i].harga_satuan << endl;
                cout << "Total Harga Barang : " << daftar_barang[i].total_harga << endl;
                cout <<endl;

                total_harga_brng += daftar_barang[i].total_harga;
            }
            cout << "============================"<< endl;
            cout << "Total Harga Belanja: " << total_harga_brng << endl;
            cout << endl;
            cout << "Terimakasih Sudah Berbelanja! "<<endl;
            cout << "Silahkan Datang Kembali!";
        }

int main()
{
    int menu;
    int jumlah_brng = 0;
    const int MAX_BARANG = 100;

    barang Daftar_barang[MAX_BARANG];

do {
        cout << "Selamat Datang Di Toko Alat Tulis\n";
        cout << "==================================\n";
        cout << "Silahkan Pilih Menu :\n";
        cout << "1. Data Barang Belanjaan\n";  
        cout << "2. Daftar Barang Belanjaan\n"; 
        cout << endl;

        cout << "Pilih Menu : ";
        cin >> menu;

        system("cls");

switch (menu) {
        case 1: 
            inputBarang(Daftar_barang, jumlah_brng);
            break;

        case 2: 
            tampilkanDaftarBelanja(Daftar_barang, jumlah_brng);
            break;

            default:
            cout << "Pilihan menu tidak valid!" << endl;
            break;
    }

} while (menu != 2);
return 0;
}

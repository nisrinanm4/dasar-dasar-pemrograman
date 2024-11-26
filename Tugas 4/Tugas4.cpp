#include <iostream>
using namespace std;

struct buku {
    string judul_buku, pengarang;
    int daftar_buku, harga, id_buku;
    string judul_baru, pengarang_baru;
    int harga_baru;
};

//Menu Tambah Buku
void inputbuku(buku daftar_buku[], int& jumlah_buku)
{
    cout << "Masukan Jumlah Buku : ";
    cin >> jumlah_buku;

    for (int i = 0; i < jumlah_buku; i++)
    {
        cout << "Buku Ke-" << i + 1 << endl;
        cout << "Masukkan ID buku : ";
        cin >> daftar_buku[i].id_buku;
        cin.ignore();

        cout << "Judul Buku : ";
        getline(cin, daftar_buku[i].judul_buku);

        cout << "Nama Pengarang : ";
        getline(cin, daftar_buku[i].pengarang);

        cout << "Harga :";
        cin >> daftar_buku[i].harga;
        system("cls");
    }
}

// Menu Tampilkan Daftar Buku
void tampilkandaftarbuku(buku daftar_buku[], int& jumlah_buku)
{
    cout << "Daftar Buku :" << endl;
    for (int i = 0; i < jumlah_buku; i ++)
    {
        cout << "Buku Ke-" << i + 1 << endl;
        cout << "ID Buku: " << daftar_buku[i].id_buku << endl;
        cout << "Judul: " << daftar_buku[i].judul_buku << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Harga: " << daftar_buku[i].harga << endl;
        cout << endl;
    }
    system ("pause");
}

//Menu Ubah Data Buku
void ubahbuku(buku daftar_buku[], int& jumlah_buku)
{
    int id;
    bool found = false;
    cout << "Masukkan ID buku yang ingin diubah: ";
    cin >> id;

    for (int i = 0; i < jumlah_buku; i++)
    {
        if (daftar_buku[i].id_buku == id)
        {
            found = true;
            cout << "Judul Baru: ";
            cin >> daftar_buku[i].judul_baru;

            cout << "Nama Pengarang Baru: ";
            cin >> daftar_buku[i].pengarang_baru;
            cout << "Harga Baru: ";

            cin >> daftar_buku[i].harga_baru;
            cout << "Data Berhasil Diperbarui" <<endl;
            break;
            system("cls");
        }
    }
    if (!found){
        cout << "Id Buku tidak ditemukan!"<< endl;
        system("cls");
    }
}

//Menu Hapus Buku
void hapusbuku(buku daftar_buku[], int& jumlah_buku)
{
    int id;
    bool found = false;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlah_buku; i++)
    if (daftar_buku[i].id_buku == id)
    {
        found = true;
        for (int x = i; x < jumlah_buku - 1; x++)
        {
            daftar_buku[x] = daftar_buku[x + 1];
        }
        jumlah_buku--;
        cout << "Buku Berhasil Dihapus!" << endl;
        break;
    }
}

//Hitung Total Harga Pembelian Dengan Diskon
void totalharga(buku daftar_buku[], int& jumlah_buku)
{
    int jumlahbuku_dibeli;
    cout << "Masukkan Jumlah Buku Yang Ingin Dibeli: ";
    cin >> jumlahbuku_dibeli;

    int id_buku_dibeli[100];
    int totalharga = 0;
    bool diskon_penulis = false;

    cout << "Masukkan Id Buku Yang Ingin Dibeli:";
    for (int i = 0; i < jumlahbuku_dibeli; i++){
        cin >> id_buku_dibeli[i];
    }
    
    string penulis_dipilih = "";
    int jumlah_buku_dari_penulis = 0;

    for (int i = 0; i < jumlahbuku_dibeli; i++) 
    {
        bool found = false;
        for (int j = 0; j < jumlah_buku; j++) 
        {
            if (daftar_buku[j].id_buku == id_buku_dibeli[i]) 
            {
                totalharga += daftar_buku[j].harga;

                if (penulis_dipilih.empty()) 
                {
                    penulis_dipilih = daftar_buku[j].pengarang;
                }

                if (daftar_buku[j].pengarang == penulis_dipilih) 
                {
                    jumlah_buku_dari_penulis++;
                }
                found = true;
                break;
            }
        }

        if (!found) 
        {
            cout << "Buku dengan ID " << id_buku_dibeli[i] << " tidak ditemukan!" << endl;
        }
    }

    if (jumlah_buku_dari_penulis >= 2) 
        {
            totalharga -= totalharga * 5 / 100; 
        }

    string kode_voucher;
    cout << "Masukkan kode voucher (opsional): ";
    cin >> kode_voucher;

    if (kode_voucher == "JPYUM") 
        {
            totalharga -= totalharga * 10 / 100;
        }

    cout << "Total Harga Pembelian Setelah Diskon: Rp " << totalharga << endl;

    if (totalharga < 0) 
        {
            totalharga = 0; 
        }
    system("pause");
}

int main(){

    int menu;
    int jumlah_buku = 0;
    const int MAX_buku = 100;

    buku daftar_buku[MAX_buku];

do 
{
    cout << "Menu:" << endl;
    cout << "1. Tambah Buku"<< endl;
    cout << "2. Tampilkan Daftar Buku" << endl;
    cout << "3. Ubah Data Buku" << endl;
    cout << "4. Hapus Buku" << endl;
    cout << "5. Hitung Total Harga Pembelian Dengan Diskon" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih Opsi : ";
    cin >> menu;
    system("cls");

switch (menu)
    {
    case 1 :
    inputbuku(daftar_buku, jumlah_buku);
    break;

    case 2 :
    tampilkandaftarbuku(daftar_buku, jumlah_buku);
    break;

    case 3 :
    ubahbuku(daftar_buku, jumlah_buku);
    break;

    case 4 :
    hapusbuku(daftar_buku, jumlah_buku);
    break;

    case 5:
    totalharga(daftar_buku, jumlah_buku);
    break;
    case 6:
    cout << "Program Keluar." << endl;
    break;
    
    default:
    cout << "Pilihan tidak valid! Silakan pilih lagi." << endl;
    break;
    }

}   while (menu != 6);
    return 0;
}

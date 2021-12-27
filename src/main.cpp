//TODO: mengganti file ini sebagai main
//TODO: merapikan tab

//!DALAM FILE INI JUGA NANTI TERDAPAT PEMILIHAN MOBIL

#include <iostream>
#include <conio.h>
#include <sstream>
#include "RandomData.h"

using namespace std;

#define SEBELUMNYA 75  // 75 adalah kode ASCII tombol panah ke kiri
#define SELANJUTNYA 77 // 77 adalah kode ASCII tombol panah ke kanan
#define KELUAR 27      // 27 adalah kode ASCII tombol esc
#define MASUK 13       // 13 adalah kode ASCII tombol enter
//#define KEMBALI 8      // 8 adalah kode ASCII tombol backspace

/*variabel global*/
int pilihan = 0, jmlh_hari = 0, awal, akhir;
char y_n[] = "y/n";
string pil;
/*pointer untuk menangkap inputan sebelum dicasting ke integer*/
char *pilihan_str = NULL, *jmlHari_str = NULL;

void selesai()
{
    system("cls");
    cout << "\t~ Terima kasih ~" << endl;
    cout << "   Tekan ENTER untuk keluar...";
    cin.get();
}

void Spesification()
{
    cout << "=== Spesifikasi ===" << endl;
    cout << "Mobil: " << modelRandom[pilihan] << endl;
    cout << "Plat nomor: " << platNomor[pilihan] << endl;
    cout << "CC : " << cc[pilihan] << endl;
    cout << "Tipe Mesin : " << tipeMesin[pilihan] << endl;
    cout << "Bahan Bakar : " << bahanbakar[pilihan] << endl;
    cout << "Bensin : " << bensin[pilihan] << endl;
    cout << "Kursi : " << kursi[pilihan] << endl;
    cout << "Kilometer : " << kilometer[pilihan] << endl;
    cout << "Ber AC : " << adaAC[pilihan] << endl;
    cout << "Warna : " << warna[pilihan] << endl;
    cout << "Harga : " << harga[pilihan] << endl;
    cout << endl;
}

//menambahkan tab(\t) sesuai dengan panjang teks pada model mobil
string FormatModel(string model)
{
    string ret = model + " ";
    int pj = model.size() + 1;
    if (pj < 10)
        ret += "\t\t\t";
    else if (pj < 16)
        ret += "\t\t";
    else if (pj < 25)
        ret += "\t";
    return ret;
}
string FormatLicensePlate(string plate)
{
    //jika panjang teks dari plate adalah 7 maka tambahkan spasi pada elemen 1
    //jika tidak maka akan mengembalikan instansi yang sama dengan parameter plate
    return plate.size() == 7 ? plate.insert(1, 1, ' ') : plate;
}

// mengeluarkan output model mobil beserta plat nomor mobilnya
void DisplayGarageContent(int start, int stop)
{
    int no = 1; //nomer urut mobil pada daftar mobil yang ditampilkan
    cout << " || No.|| \t    Model Mobil \t\t || \tPlat Nomor \t||" << endl;
    cout << " =========================================================================" << endl;
    for (int i = start; i < stop; i++)
    {
        string model = FormatModel(modelRandom[i]);
        string plate = FormatLicensePlate(platNomor[i]);
        cout << " || " << no << ". ||\t" << model << "\t || "
             << "\t" << plate << "\t"
             << "||" << endl;
        no++;
    }
}

int main()
{
    generateRandomData();
pertama:
    // garasi satu menampilkan indeks array ke 0 sampai 4
    awal = 0;
    akhir = 5;
    system("cls");
    cout << "\t\t\t ====================\t\t\t\t\t" << endl;
    cout << "\t\t\t || Garasi Pertama ||\t\t\t\t\t" << endl;
    cout << "\t\t\t ====================\t\t\t\t\t" << endl;
    cout << endl;
    cout << " =========================================================================" << endl;
    DisplayGarageContent(awal, akhir);
    cout << " =========================================================================" << endl;
    cout << endl
         << "\t\t\t\t\t\t\t-----------" << endl;
    cout << "\t\t\t\t\t\t\t| next >> |" << endl;
    cout << "\t\t\t\t\t\t\t-----------" << endl;
    cout << endl;
    cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar" << endl;
    while (1)
    {
        switch (getch())
        {
        case SELANJUTNYA:
        kedua:
            // garasi satu menampilkan indeks array ke 5 sampai 10
            awal = 5;
            akhir = 11;
            system("cls");
            cout << "\t\t\t ==================\t\t\t\t\t" << endl;
            cout << "\t\t\t || Garasi Kedua ||\t\t\t\t\t" << endl;
            cout << "\t\t\t ==================\t\t\t\t\t" << endl;
            cout << endl;
            cout << " =========================================================================" << endl;
            DisplayGarageContent(awal, akhir);
            cout << " =========================================================================" << endl;
            cout << endl
                 << "\t-----------"
                 << "\t\t\t\t\t"
                 << "-----------" << endl;
            cout << "\t| << prev |"
                 << "\t\t\t\t\t"
                 << "| next >> |" << endl;
            cout << "\t-----------"
                 << "\t\t\t\t\t"
                 << "-----------" << endl;
            cout << endl;
            cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar" << endl;
            while (1)
            {
                switch (getch())
                {
                case SEBELUMNYA:
                    goto pertama;
                    break;
                case SELANJUTNYA:
                    // garasi satu menampilkan indeks array ke 11 sampai 14
                    awal = 11;
                    akhir = 15;
                    system("cls");
                    cout << "\t\t\t ===================\t\t\t\t\t" << endl;
                    cout << "\t\t\t || Garasi Ketiga ||\t\t\t\t\t" << endl;
                    cout << "\t\t\t ===================\t\t\t\t\t" << endl;
                    cout << endl;
                    cout << " =========================================================================" << endl;
                    DisplayGarageContent(awal, akhir);
                    cout << " =========================================================================" << endl;
                    cout << endl
                         << "\t-----------" << endl;
                    cout << "\t| << prev |" << endl;
                    cout << "\t-----------" << endl;
                    cout << endl;
                    cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar" << endl;
                    while (1)
                    {
                        switch (getch())
                        {
                        case SEBELUMNYA:
                            goto kedua;
                            break;
                        case MASUK:
                            goto pilih;
                            break;
                        case KELUAR:
                            selesai();
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case MASUK:
                    goto pilih;
                    break;
                case KELUAR:
                    selesai();
                    break;
                default:
                    break;
                }
            }
            break;
        case MASUK:
            goto pilih;
            break;
        case KELUAR:
            selesai();
            break;
        default:
            break;
        }
    }

pilih:
    cout << "\nMasukan Pilihan : ";
    cin >> pil;
    stringstream strtoint(pil);
    strtoint >> pilihan;

    // menentukan inputan sesuai dengan yang diminta atau tidak
    if ((pilihan > 0) && (pilihan <= (akhir - awal)))
    {
        pilihan = pilihan + awal - 1;

        // mencari mobil tersedia atau tidak, dan menampilkan data mobil jika tersedia
        if (!tersedia[pilihan])
        {
            cout << "Mohon Maaf Mobil Tidak Tersedia" << endl;
            cout << "Tekan ENTER untuk kembali ke menu memilih mobil...";
            cin.ignore();
            goto pertama;
        }
        else
        {
        spesifikasi:
            system("cls");
            Spesification();
            cout << "Apakah anda yakin, ketik y/n: ";
            cin >> y_n;
            if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
            {
                cout << "jumlah hari, data pelanggan, biaya, bayar" << endl;
                //TODO: MEMASUKKAN JUMLAH HARI
                //TODO: INPUT DATA DIRI PELANGGAN
                //TODO: MENGELUARKAN BIAYA DAN RESUME PELANGGAN
                //TODO: PEMBAYARAN
            }
            else
            {
                if ((y_n[0] == 'n') || (y_n[0] == 'N'))
                {
                    cout << "Tekan ENTER untuk kembali ke menu memilih mobil...";
                    cin.ignore();
                    goto pertama;
                }
                else
                {
                    cout << "ERROR: silahkan masukkan y/n, dilain itu salah." << endl;
                    cout << "Tekan ENTER untuk kembali memilih y/n...";
                    cin.ignore();
                    goto spesifikasi;
                }
            }
        }
    }
    else
    {
        cout << "ERROR: silahkan masukkan angka yang sesuai dengan kolom nomor." << endl;
        cout << "Tekan ENTER untuk kembali ke menu memilih mobil...";
        cin.ignore();
        goto pertama;
    }
    // setelah penampilan spesifikasi
    // cout << "\nTekan ENTER apabila anda sudah yakin dan tekan BACKSPACE apabila ingin kembali ke daftar menu mobil...";
    // while (1)
    // {
    //     switch (getch())
    //     {
    //     case MASUK:
    //         disini meminta input data pelanggan
    //         disini juga mengeluarkan data pelanggan dan pembayarannya
    //         goto selesai;
    //         break;
    //     case KEMBALI:
    //         goto pertama;
    //         break;
    //     default:
    //         break;
    //     }
    // }

    // selesai:
    //     system("cls");
    //     cout << "\t~ Terima kasih ~" << endl;
    //     cout << "   Tekan ENTER untuk keluar...";
    //     cin.get();

    return 0;
}

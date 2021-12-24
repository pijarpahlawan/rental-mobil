//TODO: mengganti file ini sebagai main
//TODO: merapikan tab

//!DALAM FILE INI JUGA NANTI TERDAPAT PEMILIHAN MOBIL

#include <iostream>
#include <conio.h>
#include "RandomData.h"

using namespace std;

#define SEBELUMNYA 75  // 75 adalah kode ASCII tombol panah ke kiri
#define SELANJUTNYA 77 // 77 adalah kode ASCII tombol panah ke kanan
#define KELUAR 27      // 27 adalah kode ASCII tombol esc
#define KEMBALI 8      // 8 adalah kode ASCII tombol backspace
#define MASUK 13       // 13 adalah kode ASCII tombol enter
int pilihan;           // variabel yang menampung pilihan mobil

// mengeluarkan output model mobil beserta plat nomor mobilnya
void DisplayGarageContent(int start, int stop)
{
    int no = 1; //nomer urut mobil pada daftar mobil yang ditampilkan
    cout << "No.\tModel Mobil\t\t\tPlat Nomor " << endl;
    for (int i = start; i < stop; i++)
    {
        cout << no << ".\t" << modelRandom[i] << "\t\t\t" << platNomor[i] << endl;
        no++;
    }
}

int main()
{
    generateRandomData();
pertama:
    system("cls");
    cout << "=== Garasi Satu ===" << endl;
    DisplayGarageContent(0, 5); // garasi satu menampilkan indeks array ke 0 sampai 4
    cout << endl
         << "\t\t\t\t\t\tnext >>" << endl;
    cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar" << endl;
    while (1)
    {
        switch (getch())
        {
        case SELANJUTNYA:
        kedua:
            system("cls");
            cout << "=== Garasi Kedua ===" << endl;
            DisplayGarageContent(5, 11); // garasi satu menampilkan indeks array ke 5 sampai 10
            cout << endl
                 << "<< prev\t\t\t\t\t\tnext >>" << endl;
            cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar" << endl;
            while (1)
            {
                switch (getch())
                {
                case SEBELUMNYA:
                    goto pertama;
                    break;
                case SELANJUTNYA:
                    system("cls");
                    cout << "=== Garasi Ketiga ===" << endl;
                    DisplayGarageContent(11, 15); // garasi satu menampilkan indeks array ke 11 sampai 14
                    cout << endl
                         << "<< prev" << endl;
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
                            goto selesai;
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
                    goto selesai;
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
            goto selesai;
            break;
        default:
            break;
        }
    }

pilih:
    cout << "Pilih mobil: ";
    cin >> pilihan;
    //TODO: Fungsi output spesifikasi

    //?setelah penampilan spesifikasi
    cout << "Tekan ENTER apabila anda sudah yakin dan tekan BACKSPACE apabila ingin kembali ke daftar menu mobil...";
    while (1)
    {
        switch (getch())
        {
        case MASUK:
            //*disini meminta input data pelanggan
            //*disini juga mengeluarkan data pelanggan dan pembayarannya
            goto selesai;
            break;
        case KEMBALI:
            goto pertama;
            break;
        default:
            break;
        }
    }

selesai:
    system("cls");
    cout << "Terimakasih" << endl;
    cout << "Tekan ENTER untuk keluar...";
    cin.ignore();

    return 0;
}

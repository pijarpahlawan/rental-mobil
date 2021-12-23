//!DALAM FILE INI JUGA NANTI TERDAPAT PEMILIHAN MOBIL

#include <iostream>
#include <conio.h>
#include "RandomData.h"

#define SEBELUMNYA 75  // 75 adalah kode ASCII tombol panah ke kiri
#define SELANJUTNYA 77 // 77 adalah kode ASCII tombol panah ke kanan
#define KELUAR 27      // 27 adalah kode ASCII tombol esc

using namespace std;

// mengeluarkan output model mobil beserta plat nomor mobilnya
void DisplayGarageContent(int start, int stop)
{
    int no = 1; //nomer urut mobil pada daftar mobil yang ditampilkan
    for (int i = start; i < stop; i++)
    {
        cout << no << ".\t" << modelRandom[i] << "\t\t\t" << platNomor[i] << endl;
        no++;
    }
}

void displayList()
{
pertama:
    system("cls");
    cout << "=== Garasi Satu ===" << endl;
    cout << "No.\tModel Mobil\t\t\tPlat Nomor" << endl;
    DisplayGarageContent(0, 5); // garasi satu menampilkan indeks array ke 0 sampai 4
    cout << endl
         << "\t\t\t\t\t\tnext >>" << endl;
    cout << "Tekan ESC untuk keluar";
    while (1)
    {
        switch (getch())
        {
        case SELANJUTNYA:
        kedua:
            system("cls");
            cout << "=== Garasi Kedua ===" << endl;
            cout << "No.\tModel Mobil\t\t\tPlat Nomor" << endl;
            DisplayGarageContent(5, 11); // garasi satu menampilkan indeks array ke 5 sampai 10
            cout << endl
                 << "<< prev\t\t\t\t\t\tnext >>" << endl;
            cout << "Tekan ESC untuk keluar";
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
                    cout << "No.\tModel Mobil\t\t\tPlat Nomor" << endl;
                    DisplayGarageContent(11, 15); // garasi satu menampilkan indeks array ke 11 sampai 14
                    cout << endl
                         << "<< prev" << endl;
                    cout << "Tekan ESC untuk keluar";
                    while (1)
                    {
                        switch (getch())
                        {
                        case SEBELUMNYA:
                            goto kedua;
                            break;
                        case KELUAR:
                            goto selesai;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case KELUAR:
                    goto selesai;
                    break;
                default:
                    break;
                }
            }
            break;
        case KELUAR:
            goto selesai;
            break;
        default:
            break;
        }
    }
selesai:
    system("cls");
    cout << "Terimakasih" << endl;
    cin.ignore();
}

//!DALAM FILE INI JUGA NANTI TERDAPAT PEMILIHAN MOBIL

#include <iostream>
#include <conio.h>
#include "RandomData.h"

#define SEBELUMNYA 75
#define SELANJUTNYA 77
#define KELUAR 27

using namespace std;

void displayList()
{
    int no; //nomor daftar mobil dalam garasi
pertama:
    system("cls");
    cout << "=== Garasi Satu ===" << endl;
    cout << "No.\tModel Mobil\t\t\tPlat Nomor" << endl;
    no = 1;
    for (int i = 0; i < 5; i++)
    {
        cout << no << ".\t" << modelRandom[i] << "\t\t\t" << platNomor[i] << endl;
        no++;
    }
    cout << "\t\t\t\t\t\t\tnext >>" << endl;
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
            no = 1;
            for (int i = 5; i < 11; i++)
            {
                cout << no << ".\t" << modelRandom[i] << "\t\t\t" << platNomor[i] << endl;
                no++;
            }
            cout << "<< prev\t\t\t\t\t\t\tnext >>" << endl;
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
                    no = 1;
                    for (int i = 11; i < 15; i++)
                    {
                        cout << no << ".\t" << modelRandom[i] << "\t\t\t" << platNomor[i] << endl;
                        no++;
                    }
                    cout << "<< prev" << endl;
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
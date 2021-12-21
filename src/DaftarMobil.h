//!DALAM FILE INI JUGA NANTI TERDAPAT PEMILIHAN MOBIL

#include <iostream>
#include <conio.h>
#include "RandomData.h"

#define SEBELUMNYA 75
#define SELANJUTNYA 77
#define KELUAR 27

using namespace std;

void DisplayGarageContent(int garageNumber)
{
    int start, stop, no = 1;
    if (garageNumber == 1)
    {
        start = 0;
        stop = 5;
    }
    else if (garageNumber == 2)
    {
        start = 5;
        stop = 11;
    }
    else if (garageNumber == 3)
    {
        start = 11;
        stop = 15;
    }
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
    DisplayGarageContent(1);
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
            DisplayGarageContent(2);
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
                    DisplayGarageContent(3);
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
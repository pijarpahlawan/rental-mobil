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

string FormatModel(string model)
{
    string ret = model + " ";
    int pj = model.size() + 1;
    //cout << pj << endl;
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
    system("cls");
    cout << "\t\t\t ====================\t\t\t\t\t" << endl;
    cout << "\t\t\t || Garasi Pertama ||\t\t\t\t\t" << endl;
    cout << "\t\t\t ====================\t\t\t\t\t" << endl;
    cout << endl;
    cout << " =========================================================================" << endl;
    DisplayGarageContent(0, 5); // garasi satu menampilkan indeks array ke 0 sampai 4
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
            system("cls");
            cout << "\t\t\t ==================\t\t\t\t\t" << endl;
            cout << "\t\t\t || Garasi Kedua ||\t\t\t\t\t" << endl;
            cout << "\t\t\t ==================\t\t\t\t\t" << endl;
            cout << endl;
            cout << " =========================================================================" << endl;
            DisplayGarageContent(5, 11); // garasi satu menampilkan indeks array ke 5 sampai 10
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
                    system("cls");
                    cout << "\t\t\t ===================\t\t\t\t\t" << endl;
                    cout << "\t\t\t || Garasi Ketiga ||\t\t\t\t\t" << endl;
                    cout << "\t\t\t ===================\t\t\t\t\t" << endl;
                    cout << endl;
                    cout << " =========================================================================" << endl;
                    DisplayGarageContent(11, 15); // garasi satu menampilkan indeks array ke 11 sampai 14
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
    cout << "\nPilih mobil : ";
    cin >> pilihan;
    //TODO: Fungsi output spesifikasi

    //?setelah penampilan spesifikasi
    cout << "\nTekan ENTER apabila anda sudah yakin dan tekan BACKSPACE apabila ingin kembali ke daftar menu mobil...";
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
    cout << "\t~ Terima kasih ~" << endl;
    cout << "   Tekan ENTER untuk keluar...";
    cin.get();

    return 0;
}

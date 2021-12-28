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

int pilihan = 0;         // variabel untuk menampung pilihan mobil
int start = 0, stop = 0; // variabel untuk awalan dan akhiran pengindeksan array ada setiap garasi
int currentGarage;       // variabel untuk menampung nomor garasi
char y_n[] = "";         // variabel untuk menampung jawaban y/n
string pil = "";         // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer

/* control flow condition variables */
bool doneInteraction = false;
bool exitProgram = false;
bool isRun = true;

/* meminta lama pinjam mobil */
int CarLoanPeriod()
{
    int jmlh_hari = 0;   // variabel untuk menampung lama sewa mobil
    string jumHari = ""; // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer

    while (isRun)
    {
        system("cls");
        cout << "Anda mau meminjam untuk berapa hari: ";
        cin >> jumHari;
        stringstream strtoint(jumHari);
        strtoint >> jmlh_hari;

        if (jmlh_hari > 0)
        {
            cout << endl;
            cout << "Apakah anda yakin, ketik y/n ";
            cin >> y_n;
            if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
            {
                cout << "Menampilkan biaya untuk " << jmlh_hari << " hari: ";
                isRun = false;
            }
            else
            {
                if (!((y_n[0] == 'n') || (y_n[0] == 'N')))
                {
                    cout << "ERROR:silahkan masukkan y/n, dilain itu salah." << endl;
                }
                cin.clear();
                cout << "Tekan ENTER untuk mengulangi...";
                cin.ignore();
                cin.get();
            }
        }
        else
        {
            cout << "ERROR:silahkan masukkan bilangan bulat positif, dilain itu akan gagal." << endl;
            cin.clear();
            cout << "Tekan ENTER untuk mengulangi...";
            cin.ignore();
            cin.get();
        }
    }

    return jmlh_hari;
}

/* tampilan program selesai */
void selesai()
{
    system("cls");
    cout << "\t~ Terima kasih ~" << endl;
    cout << "   Tekan ENTER untuk keluar...";
    cin.get();
}

/* menampilkan spesifikasi mobil */
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

/* menambahkan tab(\t) sesuai dengan panjang teks pada model mobil */
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

/* mengeluarkan output model mobil beserta plat nomor mobilnya */
void DisplayGarageContent(int nomorGarasi)
{
    int no = 1; //nomer urut mobil pada daftar mobil yang ditampilkan
    string nomer = "";
    switch (nomorGarasi)
    {
    case 1:
        start = 0;
        stop = 5;
        nomer = "Pertama";
        break;
    case 2:
        start = 5;
        stop = 11;
        nomer = "Kedua";
        break;
    case 3:
        start = 11;
        stop = 15;
        nomer = "Ketiga";
        break;
    default:
        break;
    }
    system("cls");
    cout << "\t\t\t============================" << endl;
    cout << "\t\t\t||\tGarasi " << nomer << "\t  ||" << endl;
    cout << "\t\t\t============================" << endl;
    cout << endl;
    cout << "===========================================================================" << endl;
    cout << "||| No.|| \t    Model Mobil \t\t || \tPlat Nomor \t|||" << endl;
    cout << "===========================================================================" << endl;
    for (int i = start; i < stop; i++)
    {
        string model = FormatModel(modelRandom[i]);
        string plate = FormatLicensePlate(platNomor[i]);
        cout << "||| " << no << ". ||\t" << model << "\t || "
             << "\t" << plate << "\t"
             << "|||" << endl;
        no++;
    }
    cout << "===========================================================================" << endl;
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
    cout << "***************************************************************************" << endl;
    cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar" << endl;
}

int main()
{
    generateRandomData();

    /* control flow display models */
pertama:
    currentGarage = 1;
    doneInteraction = false;
    while (true)
    {
        DisplayGarageContent(currentGarage);
        switch (getch())
        {
        case SEBELUMNYA:
            currentGarage--;
            break;
        case SELANJUTNYA:
            currentGarage++;
            break;
        case MASUK:
            doneInteraction = true;
            break;
        case KELUAR:
            doneInteraction = true;
            exitProgram = true;
            selesai();
        default:
            break;
        }
        if (doneInteraction)
            break;
        currentGarage = currentGarage > 3 ? 1 : currentGarage < 1 ? 3
                                                                  : currentGarage;
        DisplayGarageContent(currentGarage);
    }
    if (exitProgram)
        return 0;

    /* get chosen models */
pilih:
    cout << "\nMasukan Pilihan : ";
    cin >> pil;
    stringstream strtoint(pil);
    strtoint >> pilihan;

    /* menentukan inputan sesuai dengan yang diminta atau tidak */
    if ((pilihan > 0) && (pilihan <= (stop - start)))
    {
        pilihan = pilihan + start - 1;

        /* mencari mobil tersedia atau tidak, dan menampilkan data spesifikasi mobil jika tersedia */
        if (!tersedia[pilihan])
        {
            cout << "\n###########################################################################" << endl;
            cout << "(!)                   Mohon Maaf Mobil Tidak Tersedia                   (!)" << endl;
            cout << "###########################################################################" << endl;
            cout << "\nTekan ENTER untuk kembali ke menu memilih mobil...";
            cin.ignore();
            cin.get();
            goto pertama;
        }
        else
        {
            /* bertanya kepada user apakah yakin atau tidak, jika yakin lanjut ke sesi berikutnya */
        spesifikasi:
            system("cls");
            Spesification();
            cout << "Apakah anda yakin? (y/n): ";
            cin >> y_n;

            if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
            {
                //TODO: INPUT DATA DIRI PELANGGAN
                //TODO: MEMASUKKAN JUMLAH HARI
                //TODO: MENGELUARKAN BIAYA DAN RESUME PELANGGAN
                //TODO: PEMBAYARAN
            }
            else
            {
                if ((y_n[0] == 'n') || (y_n[0] == 'N'))
                {
                    cout << "\nTekan ENTER untuk kembali ke menu memilih mobil...";
                    cin.ignore();
                    cin.get();
                    goto pertama;
                }
                else
                {
                    cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "ERROR: silahkan masukkan y/n, dilain itu salah." << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "\nTekan ENTER untuk kembali memilih y/n...";
                    cin.ignore();
                    cin.get();
                    goto spesifikasi;
                }
            }
        }
    }
    else
    {
        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "ERROR: silahkan masukkan angka yang sesuai dengan kolom nomor." << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "\nTekan ENTER untuk kembali ke menu memilih mobil...";
        cin.ignore();
        cin.get();
        goto pertama;
    }

    return 0;
}

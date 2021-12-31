#pragma once
#include <iostream>
#include <conio.h>
#include "RandomData.h"
#include "Helpers.h"

using namespace std;

int start = 0, stop = 0;                              // variabel untuk awalan dan akhiran pengindeksan array pada setiap garasi
char y_n[] = "";                                      // variabel untuk menampung jawaban y/n
int tarif = 0;                                        // variabel yang menampung tarif penyewaan
bool exitProgram = false;                             // variabel sebagai kondisi program telah selesai
string nama = "", nik = "", alamat = "", noTelp = ""; // variabel yang menampung input data diri pelanggan

/* tampilan selamat datang */
void Welcome()
{
    system("cls");
    cout << "\t====================================================" << endl;
    cout << "\t|  SELAMAT DATANG DI PENYEWAAN MOBIL LEPAS KUNCI   |" << endl;
    cout << "\t|	     *********SEMBADA********   	   |" << endl;
    cout << "\t====================================================\n\n"
         << endl;
    system("pause");
}

/* mengeluarkan output model mobil beserta plat nomor mobilnya */
void DisplayGarageContent(int nomorGarasi)
{
    int no = 1;                    // nomer urut mobil pada daftar mobil yang ditampilkan
    string nomer = "";             // garasi keberapa
    string model = "", plate = ""; // model dan plat nomor yang telah diformat agar mudah terbaca

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
        model = FormatModel(modelRandom[i]);
        plate = FormatLicensePlate(platNomor[i]);
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

//menampilkan spesifikasi mobil
void Specification(int index)
{
    // cout << "================================================================" << endl;
    // cout << "|" << endl;
    // cout << "|" "--- Spesifikasi ---" << endl;
    // cout << "|" "Mobil\t\t: " << modelRandom[index] << endl;
    // cout << "|" "Pabrikan\t: " << pabrikan[index] << endl;
    // cout << "|" "Jenis Mobil\t: " << jenisMobil[index] << endl;
    // cout << "|" "Plat nomor\t: " << platNomor[index] << endl;
    // cout << "|" "Kapasitas Mesin\t: " << cc[index] << endl;
    // cout << "|" "Transmisi\t: " << tipeMesin[index] << endl;
    // cout << "|" "Bahan Bakar\t: " << bahanbakar[index] << endl;
    // cout << "|" "Kapasitas Tanki\t: " << bensin[index] << endl;
    // cout << "|" "Jumlah Kursi\t: " << kursi[index] << endl;
    // cout << "|" "Kilometer\t: " << kilometer[index] << endl;
    // cout << "|" "Ber AC\t\t: " << adaAC[index] << endl;
    // cout << "|" "Warna\t\t: " << warna[index] << endl;
    // cout << "|" "Harga Per Hari\t: " << harga[index] << endl;
    // cout << "================================================================" << endl;
    // cout << endl;
    cout << "=== Spesifikasi ===" << endl;
    cout << "Mobil\t\t: " << modelRandom[index] << endl;
    cout << "Pabrikan\t: " << pabrikan[index] << endl;
    cout << "Jenis Mobil\t: " << jenisMobil[index] << endl;
    cout << "Plat nomor\t: " << platNomor[index] << endl;
    cout << "Kapasitas Mesin\t: " << cc[index] << endl;
    cout << "Transmisi\t: " << tipeMesin[index] << endl;
    cout << "Bahan Bakar\t: " << bahanbakar[index] << endl;
    cout << "Kapasitas Tanki\t: " << bensin[index] << endl;
    cout << "Jumlah Kursi\t: " << kursi[index] << endl;
    cout << "Kilometer\t: " << kilometer[index] << endl;
    cout << "Ber AC\t\t: " << adaAC[index] << endl;
    cout << "Warna\t\t: " << warna[index] << endl;
    cout << "Harga Per Hari\t: " << FormatPrice(harga[index]) << endl;
    cout << endl;
}

/* meminta lama pinjam mobil */
int GetCarLoanPeriod()
{
    int jmlh_hari = 0;   // variabel untuk menampung lama sewa mobil
    string jumHari = ""; // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer

    while (true)
    {
        system("cls");
        JudulSesi(1);
        cout << "Masukkan jumlah hari meminjam: ";
        cin >> jumHari;
        jmlh_hari = StrToInt(jumHari);

        if (jmlh_hari > 0)
        {
            cout << endl;
            cout << "Apakah anda yakin? (y/n): ";
            cin >> y_n;
            if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
                break;
            else
            {
                if (!((y_n[0] == 'n') || (y_n[0] == 'N')))
                {
                    ErrorNotif(1);
                }
                cout << "\nTekan ENTER untuk mengulangi...";
                cin.ignore();
                cin.get();
            }
        }
        else
        {
            ErrorNotif(3);
            cout << "\nTekan ENTER untuk mengulangi...";
            cin.ignore();
            cin.get();
        }
    }

    return jmlh_hari;
}

/* meminta data diri pelanggan */
void CustomerDatas()
{
    while (true)
    {
        system("cls");
        JudulSesi(2);
        cout << "Masukkan data diri anda" << endl;
        cout << "Nama\t\t: ";
        cin.ignore();
        getline(cin, nama);
        cout << "NIK\t\t: ";
        getline(cin, nik);
        cout << "Alamat\t\t: ";
        getline(cin, alamat);
        cout << "No. Telepon\t: ";
        getline(cin, noTelp);

        if (!IsStringAllDigit(nik) || !IsStringAllDigit(noTelp))
        {
            ErrorNotif(4);
            cin.clear();
            cout << "\nTekan ENTER untuk kembali memasukkan data diri...";
            cin.ignore();
        }
        else
            break;
    }
}

/* meminta pilihan metode pembayaran */
int GetPaymentMethod(int bayar)
{
    int billChoice = 0;
    string pilihanBayar = ""; // variabel yang menampung pilihan metode pembayaran

    while (true)
    {
        system("cls");
        JudulSesi(3);
        cout << "Pemesanan atas nama:" << endl;
        cout << "Nama\t\t: " << nama << endl;
        cout << "NIK\t\t: " << nik << endl;
        cout << "Alamat\t\t: " << alamat << endl;
        cout << "No. Telepon\t: " << noTelp << endl;
        cout << "--------------------------------------" << endl;
        cout << "Total tarif: " << FormatPrice(bayar) << endl;
        cout << "--------------------------------------" << endl;
        cout << "Metode Pembayaran:" << endl;
        cout << "[1] Uang Tunai\n[2] Transfer" << endl;
        cout << "\nMasukkan pilihan: " << endl;
        cin >> pilihanBayar;
        billChoice = StrToInt(pilihanBayar);

        if (!(0 < billChoice <= 2))
        {
            ErrorNotif(2);
            cin.clear();
            cout << "\nTekan ENTER untuk kembali memasukkan pilihan metode bayar...";
            cin.ignore();
        }
        else
            break;
    }

    return billChoice;
}

/* meminta pembayaran */
void GetPaid(int pilihan)
{
    int uang = 0;    // variabel yang menampung uang pembayaran
    string pay = ""; // variabel untuk menampung uang pembayaran sementara sebelum dicasting ke tipe integer

    if (pilihan == 1)
    {
        while (1)
        {
            system("cls");
            JudulSesi(4);
            cout << "Masukkan uang anda: ";
            cin >> pay;
            uang = StrToInt(pay);
            if (uang < 0)
            {
                ErrorNotif(3);
                cout << "\nTekan ENTER untuk mengulangi...";
                cin.ignore();
                cin.get();
            }
            else
            {
                if (uang > tarif)
                {
                    cout << "Uang anda kembali: " << uang - tarif << endl;
                    system("pause");
                    break;
                }
                else if (uang < tarif)
                {
                    cout << "Uang anda kurang: " << tarif - uang << endl;
                    cout << "\nTekan ENTER untuk mengulangi...";
                    cin.ignore();
                    cin.get();
                }
            }
        }
    }
    else
    {
        cout << "\nTransfer pembayaran anda ke nomor rekening berikut:\n"
             << nomorRekening << endl;
        system("pause");
    }
}

/* tampilan program selesai */
void Selesai()
{
    exitProgram = true;
    system("cls");
    cout << "********** TERIMA KASIH ATAS KEPERCAYAAN ANDA KEPADA KAMI **********" << endl;
    cout << "		=================================" << endl;
    cout << "		|	KRITIK DAN SARAN	|" << endl;
    cout << "		| 	  0812345678910		|" << endl;
    cout << " 		=================================\n\n"
         << endl;
    system("pause");
}
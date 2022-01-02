#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include "RandomData.h"
#include "Helpers.h"

using namespace std;

int start = 0;                                        // variabel untuk awalan pengindeksan array pada setiap garasi
int stop = 0;                                         // variabel untuk akhiran pengindeksan array pada setiap garasi
int pilihanMobil = 0;                                 // variabel untuk menampung pilihan mobil
int jmlh_hari = 0;                                    // variabel untuk menampung lama sewa mobil
int uang = 0;                                         // variabel yang menampung uang pembayaran
char y_n[] = "";                                      // variabel untuk menampung jawaban y/n
int tarif = 0;                                        // variabel yang menampung tarif penyewaan
bool exitProgram = false;                             // variabel sebagai kondisi program telah selesai
string nama = "", nik = "", alamat = "", noTelp = ""; // variabel yang menampung input data diri pelanggan

/* tampilan selamat datang */
void Welcome()
{
    system("cls");
    cout << "\t====================================================\n";
    cout << "\t|  SELAMAT DATANG DI PENYEWAAN MOBIL LEPAS KUNCI   |\n";
    cout << "\t|	     *********SEMBADA********   	   |\n";
    cout << "\t====================================================\n\n\n";
    cout << "\t\t Pencet ENTER untuk melanjutkan....";
    cin.ignore();
}

/* mengeluarkan output model mobil beserta plat nomor mobilnya */
void DisplayGarageContent(int nomorGarasi)
{
    int no = 1;        // nomer urut mobil pada daftar mobil yang ditampilkan
    string nomer = ""; // garasi keberapa
    string model = ""; // model mobil yang telah diformat agat mudah terbaca
    string plate = ""; // model dan plat nomor yang telah diformat agar mudah terbaca

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
    cout << "\t\t\t============================\n";
    cout << "\t\t\t||\tGarasi " << nomer << "\t  ||\n";
    cout << "\t\t\t============================\n\n\n";
    cout << "===========================================================================\n";
    cout << "||| No.|| \t    Model Mobil \t\t || \tPlat Nomor \t|||\n";
    cout << "===========================================================================\n";
    for (int i = start; i < stop; i++)
    {
        model = FormatModel(modelRandom[i]);
        plate = FormatLicensePlate(platNomor[i]);
        cout << "||| " << no << ". ||\t" << model << "\t || \t" << plate << "\t|||\n";
        no++;
    }
    cout << "===========================================================================\n";
    cout << "\n\t-----------\t\t\t\t\t-----------\n";
    cout << "\t| << prev |\t\t\t\t\t| next >> |\n";
    cout << "\t-----------\t\t\t\t\t-----------\n\n";
    cout << "***************************************************************************\n";
    cout << "Tekan ENTER untuk memilih mobil dan tekan ESC untuk keluar\n";
}

//menampilkan spesifikasi mobil
void Specification(int index)
{
    JudulSesi(0);
    cout << "Mobil\t\t\t: " << modelRandom[index] << endl;
    cout << "Pabrikan\t\t: " << pabrikan[index] << endl;
    cout << "Jenis Mobil\t\t: " << jenisMobil[index] << endl;
    cout << "Plat nomor\t\t: " << platNomor[index] << endl;
    cout << "Kapasitas Mesin\t\t: " << cc[index] << endl;
    cout << "Transmisi\t\t: " << tipeMesin[index] << endl;
    cout << "Bahan Bakar\t\t: " << bahanbakar[index] << endl;
    cout << "Kapasitas Tanki\t\t: " << bensin[index] << endl;
    cout << "Jumlah Kursi\t\t: " << kursi[index] << endl;
    cout << "Kilometer\t\t: " << kilometer[index] << endl;
    cout << "Ber AC\t\t\t: " << adaAC[index] << endl;
    cout << "Warna\t\t\t: " << warna[index] << endl;
    cout << "Harga Per Hari\t\t: " << FormatPrice(harga[index]) << endl;
    cout << endl;
}

/* meminta lama pinjam mobil */
void GetCarLoanPeriod()
{
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
            if (MakeLowercase(y_n)[0] == 'y')
                break;
            else
            {
                if (MakeLowercase(y_n)[0] != 'y')
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
}

/* meminta data diri pelanggan */
void CustomerDatas()
{
    bool cond = true;
    while (true)
    {
        system("cls");
        JudulSesi(2);
        cout << "Masukkan data diri anda\n";
        cout << "Nama\t\t: ";
        if (cond)
            cin.ignore();
        getline(cin, nama);
        cout << "NIK\t\t: ";
        getline(cin, nik);
        cout << "Alamat\t\t: ";
        getline(cin, alamat);
        cout << "No. Telepon\t: ";
        getline(cin, noTelp);

        cond = true;
        if (IsStringContainsAnyDigit(nama))
        {
            ErrorNotif(5);
            cond = false;
        }
        if (IsStringAllDigit(alamat))
        {
            ErrorNotif(6);
            cond = false;
        }
        if (!IsStringAllDigit(nik) || !IsStringAllDigit(noTelp))
        {
            ErrorNotif(4);
            cond = false;
        }
        if (cond)
            break;
        cout << "\nNote :\n";
        cout << "- nama tidak boleh memiliki angka\n- alamat tidak boleh angka seluruhnya\n- NIK dan nomor telepon harus berisi angka\n";
        cout << "\nTekan ENTER untuk kembali memasukkan data diri...";
        cin.get();
        cond = false;
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
        cout << "Nama\t\t: " << Capitalize(nama) << endl;
        cout << "NIK\t\t: " << nik << endl;
        cout << "Alamat\t\t: " << alamat << endl;
        cout << "No. Telepon\t: " << noTelp << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "Total tarif: " << FormatPrice(bayar) << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "Metode Pembayaran:" << endl;
        cout << "[1] Uang Tunai\n[2] Transfer" << endl;
        cout << "\nMasukkan pilihan: ";
        cin >> pilihanBayar;
        billChoice = StrToInt(pilihanBayar);

        if (billChoice != 1 && billChoice != 2)
        {
            ErrorNotif(2);
            cout << "\nTekan ENTER untuk kembali memasukkan pilihan metode bayar...";
            cin.ignore();
            cin.get();
        }
        else
            break;
    }

    return billChoice;
}

/* meminta pembayaran */
void GetPaid(int pilihan)
{
    void Struck();
    string pay = ""; // variabel untuk menampung uang pembayaran sementara sebelum dicasting ke tipe integer
    if (pilihan == 1)
    {
        while (1)
        {
            system("cls");
            JudulSesi(4);
            cout << "Total tarif\t\t: " << FormatPrice(tarif) << endl;
            cout << "Masukkan uang anda\t: ";
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
                    cout << "Uang anda kembali\t: " << FormatPrice(uang - tarif) << endl;
                    Struck();
                    ReadFile("kwitansi.txt");
                    cout << "NOTE: pembayaran telah tersimpan di kwitansi.txt\n\n";
                    system("pause");
                    break;
                }
                else if (uang < tarif)
                {
                    cout << "Uang anda kurang\t: " << FormatPrice(tarif - uang) << endl;
                    cout << "\nTekan ENTER untuk mengulangi...";
                    getch();
                }
                else
                {
                    Struck();
                    ReadFile("kwitansi.txt");
                    cout << "NOTE: pembayaran telah tersimpan di kwitansi.txt\n\n";
                    system("pause");
                    break;
                }
            }
        }
    }
    else
    {
        cout << "...........................................................................\n";
        cout << "Total tarif: " << FormatPrice(tarif) << endl;
        cout << "\nTransfer pembayaran anda ke nomor rekening berikut:\n";
        cout << nomorRekening << endl;
        cout << "Anda akan mendapatkan kwitansi melalui SMS setelah pembayaran terkonfirmasi\n\n";
        system("pause");
    }
}

/* menulis kwitansi peminjaman ke kwitansi.ext */
void Struck()
{
    ofstream kwitansi;
    kwitansi.open("kwitansi.txt");
    kwitansi << "=================================================\n";
    kwitansi << "|\t       KWITANSI PEMBAYARAN       \t|\n";
    kwitansi << "|\t        **** SEMBADA ****        \t|\n";
    kwitansi << "-------------------------------------------------\n";
    kwitansi << " No. Transaksi\t:" << nomorTransaksi << endl;
    kwitansi << " Nama Penyewa\t:" << Capitalize(nama) << endl;
    kwitansi << " Jenis Mobil\t:" << modelRandom[pilihanMobil] << endl;
    kwitansi << " Plat \t\t:" << platNomor[pilihanMobil] << endl;
    kwitansi << " Jumlah hari\t:" << jmlh_hari << endl;
    kwitansi << "-------------------------------------------------\n";
    kwitansi << " Jumlah sewa\t:" << FormatPrice(tarif) << endl;
    kwitansi << " Jumlah uang\t:" << FormatPrice(uang) << endl;
    kwitansi << " Kembalian\t:" << FormatPrice(uang - tarif) << endl;
    kwitansi << "-------------------------------------------------\n";
    kwitansi << "\t\t      LUNAS       \t\t\n";
    kwitansi << "-------------------------------------------------\n";
    kwitansi << " \t    SIMPAN BUKTI PEMBAYARAN !    \t\n";
    kwitansi << " ~Terimakasih Atas Kepercayaan Anda Kepada Kami~ \n";
    kwitansi << "=================================================\n\n\n";
    kwitansi.close();
    cout << "\nTekan ENTER untuk menampilkan kwitansi...";
    cin.ignore();
    cin.get();
    system("cls");
}

/* tampilan program selesai */
void Selesai()
{
    exitProgram = true;
    system("cls");
    cout << "********** TERIMA KASIH ATAS KEPERCAYAAN ANDA KEPADA KAMI **********\n";
    cout << "		=================================\n";
    cout << "		|	KRITIK DAN SARAN	|\n";
    cout << "		| 	  0812345678910		|\n";
    cout << " 		=================================\n\n\n";
    system("pause");
}

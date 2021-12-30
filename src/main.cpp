#include <iostream>
#include <conio.h>
#include "RandomData.h"
#include "Extension.h"

using namespace std;

#define SEBELUMNYA 75  // 75 adalah kode ASCII tombol panah ke kiri
#define SELANJUTNYA 77 // 77 adalah kode ASCII tombol panah ke kanan
#define KELUAR 27      // 27 adalah kode ASCII tombol esc
#define MASUK 13       // 13 adalah kode ASCII tombol enter

/* global variables */
int start = 0, stop = 0;                              // variabel untuk awalan dan akhiran pengindeksan array pada setiap garasi
int tarif = 0;                                        // variabel yang menampung tarif penyewaan
char y_n[] = "";                                      // variabel untuk menampung jawaban y/n
bool exitProgram = false;                             // variabel sebagai kondisi program telah selesai
string nama = "", nik = "", alamat = "", noTelp = ""; // variabel yang menampung input data diri pelanggan

void Welcome();
void DisplayGarageContent(int nomorGarasi);
void Specification(int index);
int CarLoanPeriod();
void CustomerDatas();
int CustomerPaying(int bayar);
void Selesai();

int main()
{
    bool doneInteraction = false; // variabel sebagai kondisi looping menampilkan daftar mobil
    bool reprint = true;          // variabel sebagai kondisi untuk mencetak daftar mobil
    int currentGarage = 0;        // variabel untuk menampung nomor garasi
    int garageCap = 0;            // variabel untuk menampung jumlah kapasitas mobil per garasi
    int pilihanMobil = 0;         // variabel untuk menampung pilihan mobil
    string pilMob = "";           // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer

    Welcome();
    GenerateRandomData();

    /* control flow display models */
menu:
    currentGarage = 1;
    doneInteraction = false;
    reprint = true;
    while (true)
    {
        if (reprint)
            DisplayGarageContent(currentGarage);
        switch (getch())
        {
        case SEBELUMNYA:
            reprint = true;
            currentGarage--;
            break;
        case SELANJUTNYA:
            reprint = true;
            currentGarage++;
            break;
        case MASUK:
            reprint = true;
            doneInteraction = true;
            break;
        case KELUAR:
            reprint = true;
            doneInteraction = true;
            Selesai();
        default:
            reprint = false;
            break;
        }
        if (doneInteraction)
            break;
        currentGarage = currentGarage > 3 ? 1 : currentGarage < 1 ? 3
                                                                  : currentGarage;
    }
    if (exitProgram)
        return 0;

    /* get chosen models */
    cout << "\nMasukan Pilihan: ";
    cin >> pilMob;
    pilihanMobil = StrToInt(pilMob);

    if (currentGarage == 1)
        garageCap = 5;
    else if (currentGarage == 2)
        garageCap = 6;
    else if (currentGarage == 3)
        garageCap = 4;
    /* menentukan inputan sesuai dengan yang diminta atau tidak */
    if ((pilihanMobil > 0) && (pilihanMobil <= garageCap))
    {
        pilihanMobil = pilihanMobil + start - 1;

        /* mencari mobil tersedia atau tidak, dan menampilkan data spesifikasi mobil jika tersedia */
        if (!tersedia[pilihanMobil])
        {
            cout << "\n###########################################################################" << endl;
            cout << "(!)                   Mohon Maaf Mobil Tidak Tersedia                   (!)" << endl;
            cout << "###########################################################################" << endl;
            cout << "\nTekan ENTER untuk kembali ke menu memilih mobil...";
            cin.ignore();
            cin.get();
            goto menu;
        }

    /* menampilkan spesifikasi dan bertanya kepada user apakah yakin atau tidak
    jika yakin lanjut ke sesi berikutnya. jika tidak yakin kembali ke menu pilihan mobil*/
    spesifikasi:
        system("cls");
        Specification(pilihanMobil);
        cout << "Apakah anda yakin? (y/n): ";
        cin >> y_n;
        if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
        {
            //TODO: MEMASUKKAN JUMLAH HARI
            tarif = CarLoanPeriod() * harga[pilihanMobil];
            //TODO: INPUT DATA DIRI PELANGGAN
            CustomerDatas();
            //TODO: MENGELUARKAN BIAYA DAN RESUME PELANGGAN
            //! ini if else
            CustomerPaying(tarif);
            //TODO: PEMBAYARAN
            Selesai();
        }
        else
        {
            if ((y_n[0] == 'n') || (y_n[0] == 'N'))
            {
                cout << "\nTekan ENTER untuk kembali ke menu memilih mobil...";
                cin.ignore();
                cin.get();

                goto menu;
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
    else
    {
        cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "ERROR: silahkan masukkan angka yang sesuai dengan kolom nomor." << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "\nTekan ENTER untuk kembali ke menu memilih mobil...";
        cin.ignore();
        cin.get();
        goto menu;
    }
    Selesai();
    return 0;
}

/* tampilan selamat datang */
void Welcome()
{
    system("cls");
    cout << "\n\n************************************************************************\n\n";
    cout << "\t====================================================" << endl;
    cout << "\t|  SELAMAT DATANG DI PENYEWAAN MOBIL LEPAS KUNCI   |" << endl;
    cout << "\t|	     *********SEMBADA********   	   |" << endl;
    cout << "\t====================================================" << endl;
    cout << "\n\n************************************************************************";
    getch();
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
int CarLoanPeriod()
{
    int jmlh_hari = 0;   // variabel untuk menampung lama sewa mobil
    string jumHari = ""; // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer

    while (true)
    {
        system("cls");
        cout << "Masukkan jumlah hari meminjam: ";
        cin >> jumHari;
        jmlh_hari = StrToInt(jumHari);

        if (jmlh_hari > 0)
        {
            cout << endl;
            cout << "Apakah anda yakin? (y/n): ";
            cin >> y_n;
            if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
            {
                cout << "Menampilkan biaya untuk " << jmlh_hari << " hari: ";
                break;
            }
            else
            {
                if (!((y_n[0] == 'n') || (y_n[0] == 'N')))
                {
                    cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "ERROR: silahkan masukkan y/n, dilain itu salah." << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                }
                cout << "\nTekan ENTER untuk mengulangi...";
                cin.ignore();
                cin.get();
            }
        }
        else
        {
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "ERROR: silahkan masukkan bilangan bulat positif, dilain itu akan gagal." << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
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
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "ERROR: NIK atau nomor telepon yang anda masukkan tidak valid." << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cin.clear();
            cout << "\nTekan ENTER untuk kembali memasukkan data diri...";
            cin.ignore();
        }
        else
            break;
    }
}

//! ini bagiannya putra, jangan ikut commit
int CustomerPaying(int bayar)
{
    int billChoice = 0;
    string pilihanBayar = ""; // variabel yang menampung pilihan metode pembayaran

    while (true)
    {
        system("cls");
        cout << "Pemesanan atas nama:" << endl;
        cout << "Nama\t\t: " << nama << endl;
        cout << "NIK\t\t: " << nik << endl;
        cout << "Alamat\t\t: " << alamat << endl;
        cout << "No. Telepon\t: " << noTelp << endl;
        cout << "--------------------------------------" << endl;
        cout << "Total tarif: " << FormatPrice(bayar) << endl;
        cout << "--------------------------------------" << endl;
        cout << "Metode Pembayaran:" << endl;
        cout << "[1] Transfer\n[2] Uang Tunai" << endl;
        cout << "\nMasukkan pilihan: " << endl;
        cin >> pilihanBayar;
        billChoice = StrToInt(pilihanBayar);

        if (!(0 < billChoice <= 2))
        {
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "ERROR: silahkan masukkan angka sesuai yang ada dalam pilihan." << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cin.clear();
            cout << "\nTekan ENTER untuk kembali memasukkan pilihan metode bayar...";
            cin.ignore();
        }
        else
            break;
    }

    return billChoice;
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
    cout << " 		=================================" << endl;
    system("pause");
}
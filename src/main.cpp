#include <iostream>
#include <conio.h>
#include <sstream>
#include "RandomData.h"

using namespace std;

#define SEBELUMNYA 75  // 75 adalah kode ASCII tombol panah ke kiri
#define SELANJUTNYA 77 // 77 adalah kode ASCII tombol panah ke kanan
#define KELUAR 27      // 27 adalah kode ASCII tombol esc
#define MASUK 13       // 13 adalah kode ASCII tombol enter

int pilihan = 0;                                              // variabel untuk menampung pilihan mobil
int start = 0, stop = 0;                                      // variabel untuk awalan dan akhiran pengindeksan array pada setiap garasi
int currentGarage = 0;                                        // variabel untuk menampung nomor garasi
char y_n[] = "";                                              // variabel untuk menampung jawaban y/n
string pil = "";                                              // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer
string nama = "", nik_str = "", alamat = "", noTelp_str = ""; // variabel yang menampung input data diri pelanggan
long long int nik = 0, no_telp = 0;                           // variabel yang menampung NIK dan nomor telepon setelan diubah menjadi integer

/* control flow condition variables */
bool doneInteraction = false;
bool exitProgram = false;
bool reprint = false;
bool changed = false;
bool isRun = false;

/* meminta data diri pelanggan */
void CustomerDatas()
{
    isRun = true;
    while (isRun)
    {
        system("cls");
        cout << "Masukkan data diri anda" << endl;
        cout << "Nama\t\t: ";
        cin.ignore();
        getline(cin, nama);
        cout << "NIK\t\t: ";
        getline(cin, nik_str);
        cout << "Alamat\t\t: ";
        getline(cin, alamat);
        cout << "No. Telepon\t: ";
        getline(cin, noTelp_str);

        // str to int
        //! diconvert menjadi integer untuk memastikan bahwa yang dimasukkan adalah bentuk angka
        stringstream id(nik_str);
        id >> nik;
        stringstream phoneNum(noTelp_str);
        phoneNum >> no_telp;

        //? NIK dan nomor telepon harus bilangan positif
        if (nik < 1 || no_telp < 1)
        {
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "ERROR: NIK atau nomor telepon yang anda masukkan tidak valid." << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cin.clear();
            cout << "\nTekan ENTER untuk kembali memasukkan data diri...";
            cin.ignore();
        }
        else
        {
            isRun = false;
        }
    }
}

/* meminta lama pinjam mobil */
int CarLoanPeriod()
{
    int jmlh_hari = 0;   // variabel untuk menampung lama sewa mobil
    string jumHari = ""; // variabel untuk menampung pilihan mobil sementara sebelum dicasting ke tipe integer

    isRun = true;
    while (isRun)
    {
        system("cls");
        cout << "Anda mau meminjam untuk berapa hari: ";
        cin >> jumHari;
        stringstream pilInt(jumHari);
        pilInt >> jmlh_hari;

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
void Selesai()
{
    exitProgram = true;
    system("cls");
    cout << "\t~ Terima kasih ~" << endl;
    cout << "   Tekan ENTER untuk keluar...";
    cin.get();
}

/* menampilkan spesifikasi mobil */
void Spesification()
{
    cout << "=== Spesifikasi ===" << endl;
    cout << "Mobil\t\t: " << modelRandom[pilihan] << endl;
    cout << "Pabrikan\t: " << pabrikan[pilihan] << endl;
    cout << "Jenis Mobil\t: " << jenisMobil[pilihan] << endl;
    cout << "Plat nomor\t: " << platNomor[pilihan] << endl;
    cout << "Kapasitas Mesin\t: " << cc[pilihan] << endl;
    cout << "Transmisi\t: " << tipeMesin[pilihan] << endl;
    cout << "Bahan Bakar\t: " << bahanbakar[pilihan] << endl;
    cout << "Kapasitas Tanki\t: " << bensin[pilihan] << endl;
    cout << "Jumlah Kursi\t: " << kursi[pilihan] << endl;
    cout << "Kilometer\t: " << kilometer[pilihan] << endl;
    cout << "Ber AC\t\t: " << adaAC[pilihan] << endl;
    cout << "Warna\t\t: " << warna[pilihan] << endl;
    cout << "Harga Per Hari\t: " << harga[pilihan] << endl;
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
    reprint = true;

    /* control flow display models */
pertama:
    currentGarage = 1;
    doneInteraction = false;
    changed = false;
    while (true)
    {
        if (reprint && !changed)
            DisplayGarageContent(currentGarage);
        switch (getch())
        {
        case SEBELUMNYA:
            reprint = true;
            currentGarage--;
            changed = true;
            break;
        case SELANJUTNYA:
            reprint = true;
            currentGarage++;
            changed = true;
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
        if (reprint && changed)
            DisplayGarageContent(currentGarage);
    }

    /* get chosen models */
    cout << "\nMasukan Pilihan : ";
    cin >> pil;
    stringstream pilInt(pil);
    pilInt >> pilihan;

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
            /* menampilkan spesifikasi dan bertanya kepada user apakah yakin atau tidak 
            jika yakin lanjut ke sesi berikutnya. jika tidak yakin kembali ke menu pilihan mobil*/
        spesifikasi:
            system("cls");
            Spesification();
            cout << "Apakah anda yakin? (y/n): ";
            cin >> y_n;
            if ((y_n[0] == 'y') || (y_n[0] == 'Y'))
            {
                //TODO: INPUT DATA DIRI PELANGGAN
                CustomerDatas();
                cout << nama << "\n"
                     << nik_str << "\n"
                     << alamat << "\n"
                     << noTelp_str << endl;
                cin.ignore();
                Selesai();
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

    if (exitProgram)
        return 0;
}

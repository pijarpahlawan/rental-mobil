#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

/* fungsi untuk memeriksa apakah dalam angka terdapat huruf 
    - akan true jika inputan tidak ada string (all int)
    - akan false jika inputan terdapat string (sekali dapat) */
bool IsStringAllDigit(const string &str)
{
    //inisialisasi instansi dari iterator string
    string::const_iterator it = str.begin();
    //jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    //mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

/* fungsi untuk menentukan apakah ada angka di inputan 
    - akan false jika tidak ditemukan angka pada string (all string)
    - akan true jika saat itu juga ditemukan angka (sekali dapat) */
bool IsStringContainsAnyDigit(const string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            return true;
    }
    return false;
}

bool IsNameValid(const string &name)
{
    /*
        Allowed characters:
        - A-Z
        - a-z
        - [space] = 32; tanda kutip (') = 39; tanda hubung (-) = 45; titik (.) = 46
    */
    for (int i = 0; i < name.size(); i++)
    {
        int asciiCode = int(name[i]);
        if (!(asciiCode == 32 || asciiCode == 39 || asciiCode == 45 || asciiCode == 46 || (asciiCode > 64 && asciiCode < 91) || (asciiCode > 96 && asciiCode < 123)))
            return false;
    }
    //cek ulang apakah semua karakter terdiri atas [spasi] ' - atau .
    string::const_iterator first = name.begin();
    string::const_iterator last = name.end();
    string::const_iterator it = name.begin();
    while (it != last)
    {
        int asciiCode = int(*it);
        if (asciiCode == 32 || asciiCode == 39 || asciiCode == 45 || asciiCode == 46)
            first++;
        it++;
    }
    return !name.empty() && first != last;
}

/* fungsi untuk mengubah string ke lowercase */
string MakeLowercase(const string &str)
{
    string result = str;
    for (int i = 0; i < str.size(); i++)
    {
        if (result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

/* fungsi untuk mengubah string ke titlecase */
string Capitalize(const string &str)
{
    string result = str;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        // 32 = karakter spasi; 45 = karakter tanda hubung; 46 = karakter titik; 97 s/d 122 = lower case
        if ((i == 0 || result[i - 1] == 32 || result[i - 1] == 45 || result[i - 1] == 46) && result[i] > 96 && result[i] < 123)
        {
            result[i] = result[i] - 32;
        }
    }
    return result;
}

/* fungsi untuk menampilkan judul setiap sesi */
void JudulSesi(int sesiKe)
{
    int mid;
    string judul = "";
    if (sesiKe == 0)
        judul = "Spesifikasi Mobil";
    else if (sesiKe == 1)
        judul = "Kurun Waktu Peminjaman";
    else if (sesiKe == 2)
        judul = "Input Data Pelanggan";
    else if (sesiKe == 3)
        judul = "Resume Pemesanan";
    else if (sesiKe == 4)
        judul = "Pembayaran Tunai";

    mid = 75 - judul.size();
    for (int i = 0; i < 150; i++)
    {
        cout << "=";
        if (i == 74)
        {
            cout << endl;
            for (int j = 0; j < mid; j++)
            {
                cout << ":";
                if (j == (mid / 2))
                {
                    cout << judul;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

/* fungsi untuk menampilkan error */
void ErrorNotif(int errorKind)
{
    string error = "ERROR: ";

    if (errorKind == 1)
        error = error + "silahkan masukkan y/n, dilain itu salah.";
    else if (errorKind == 2)
        error = error + "silahkan masukkan angka yang sesuai yang ada dalam pilihan.";
    else if (errorKind == 3)
        error = error + "silahkan masukkan bilangan bulat positif, dilain itu akan gagal.";
    else if (errorKind == 4)
        error = error + "NIK atau nomor telepon yang anda masukkan tidak valid.";
    else if (errorKind == 5)
        error = error + "Nama yang anda masukkan tidak valid.";
    else if (errorKind == 6)
        error = error + "Alamat yang anda masukkan tidak valid.";

    cout << endl;
    for (int i = 0; i < 150; i++)
    {
        cout << "!";
        if (i == 74)
        {
            cout << "\n" << error << "\n";
        }
    }
    cout << endl;
}

/* fungsi untuk mengkonversi string ke integer */
int StrToInt(string str)
{
    int isInt;
    stringstream ToInt(str);
    ToInt >> isInt;
    return isInt;
}

/* fungsi untuk mengkonversi integer ke string */
string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
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

/* fungsi untuk me-format plat nomor */
string FormatLicensePlate(string plate)
{
    //jika panjang teks dari plate adalah 7 maka tambahkan spasi pada elemen 1
    //jika tidak maka akan mengembalikan instansi yang sama dengan parameter plate
    return plate.size() == 7 ? plate.insert(1, 1, ' ') : plate;
}

/* fungsi untuk me-format harga supaya mudah dibaca */
string FormatPrice(int price)
{
    string priceStr = IntToString(price);
    int count = 0;
    for (int i = priceStr.size(); i > 0; i -= 3)
    {
        //tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0)
            priceStr.insert(i, ".");
        count++;
    }
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return "Rp" + priceStr;
}

/* fungsi untuk membaca file */
void ReadFile(const char *filename)
{
    ifstream stream;
    string baris = "";

    stream.open(filename);
    while (getline(stream, baris))
    {
        cout << baris << "\n";
    }
    stream.close();
}

/* Meng-enkripsi string mengguakan jenkins one at a time algorithm */
unsigned int EncryptJoaat(const string &str)
{
    unsigned int result = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int ascii = int(str[i]);
        result += ascii;
        result += result << 10;
        result ^= result >> 6;
    }
    result += result << 3;
    result ^= result >> 11;
    result += result << 15;
    return result;
}

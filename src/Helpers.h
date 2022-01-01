#pragma once
#include <iostream>
#include <sstream>

using namespace std;

/* fungsi untuk menentukan apakah ada angka di inputan */
bool IsThereACharacter(string str)
{
    string digit = "0123456789";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < digit.length(); j++)
        {
            if (str[i] == digit[j])
            {
                return false;
            }
        }
    }
    return true;
}

/* fungsi untuk menentukan apakah inputan terdiri dari integer */
bool AreAllInteger(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
            return false;
    }
    return true;
}

/* fungsi untuk menampilkan judul setiap seksi */
void JudulSesi(int sesiKe)
{
    int mid;
    string judul = "";
    if (sesiKe == 0)
        judul = "Spesifikasi Mobil";
    if (sesiKe == 1)
        judul = "Kurun Waktu Peminjaman";
    if (sesiKe == 2)
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
        error = error + "Nama atau alamat yang anda masukkan tidak valid.";

    cout << endl;
    for (int i = 0; i < 150; i++)
    {
        cout << "!";
        if (i == 74)
        {
            cout << "\n"
                 << error << "\n";
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

/* fungsi untuk memeriksa apakah dalam angka terdapat huruf */
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

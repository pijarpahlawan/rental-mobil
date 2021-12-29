#pragma once
#include "iostream"

using namespace std;

string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

bool IsStringAllDigit(const string& str)
{
    //inisialisasi instansi dari iterator string
    string::const_iterator it = str.begin();
    //jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it)) ++it;
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
string FormatLicensePlate(string plate)
{
    //jika panjang teks dari plate adalah 7 maka tambahkan spasi pada elemen 1
    //jika tidak maka akan mengembalikan instansi yang sama dengan parameter plate
    return plate.size() == 7 ? plate.insert(1, 1, ' ') : plate;
}
// fungsi untuk me-format harga supaya mudah dibaca
string FormatPrice(int price)
{
    string priceStr = IntToString(price);
    int count = 0;
    for (int i = priceStr.size(); i > 0; i-=3)
    {
        //tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0) priceStr.insert(i, ".");
        count++;
    }
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return "Rp" + priceStr;
}

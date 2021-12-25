#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include "DataMobil.h"

using namespace std;

//array tempat menyimpan hasil randomisasi
string modelRandom[15]; //!tidak ikut spesifikasi
string platNomor[15];   //!tidak ikut spesifikasi
bool tersedia[15];      //!tidak ikut spesifikasi
string cc[15];
string tipeMesin[15];
string bahanbakar[15];
string bensin[15];
string kursi[15];
int kilometer[15];
string adaAC[15];
string warna[15];
int harga[15];
string nomorRekening; //!tidak ikut spesifikasi

//mengubah integer menjadi string
string IntToString(int a)
{
    ostringstream temp; //template character
    temp << a;          //formating a to char array (string)
    return temp.str();  //returning <a> to string value
}

//merandom data
void generateRandomData()
{
    srand((unsigned int)time(NULL)); //seed rand()

    //mengambil 15 data mobil, spesifikasi, dan harganya
    for (int i = 0; i < 15; i++)
    {
        /*mendapatkan indeks ke-r array sebelum terandom. berbasis array models[]*/
        int r = rand() % (sizeof(models) / sizeof(string));

        /*merandom model mobil*/
        modelRandom[i] = models[r];

        /*merandom ketersediaan mobil*/
        tersedia[i] = rand() % 10 != 1;

        /*merandom spesifikasi mobil*/
        cc[i] = engines[r];
        tipeMesin[i] = engineTypes[r];
        bahanbakar[i] = fuelTypes[r];
        bensin[i] = fuels[r];
        kursi[i] = seats[r];
        kilometer[i] = rand() % 98888 + 1111;
        adaAC[i] = haveAC[r];
        warna[i] = rand() % 2 == 1 ? colors[r] : allColors[rand() % 108];
        harga[i] = prices[r];

        /*merandom plat nomor mobil*/
        string platDaerah = awalanPlat[rand() % (sizeof(awalanPlat) / sizeof(string))];
        int nomorPlat = rand() % 8999 + 1000;
        char akhiran1 = rand() % 26 + 65;
        char akhiran2 = rand() % 26 + 65;
        platNomor[i] = platDaerah + IntToString(nomorPlat) + akhiran1 + akhiran2;
    }

    //merandom nomor rekening
    for (int i = 0; i < 5; i++)
    {
        int noRek = rand() % 999 + 11;
        if (i == 0)
        {
            nomorRekening = IntToString(noRek);
        }
        else
        {
            nomorRekening = nomorRekening + IntToString(noRek);
        }
    }
}

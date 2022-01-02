#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include "DataMobil.h"
#include "Helpers.h"

using namespace std;

//array tempat menyimpan hasil randomisasi
string modelRandom[15];
string platNomor[15];
bool tersedia[15];
string cc[15];
string tipeMesin[15];
string bahanbakar[15];
string bensin[15];
string kursi[15];
int kilometer[15];
string adaAC[15];
string warna[15];
int harga[15];
string pabrikan[15];
string jenisMobil[15];
string nomorRekening;
int indexes[15]; // *hanya dipakai di file ini
unsigned int nomorTransaksi;

//merandom plat nomor
string GenerateRandomLicensePlate()
{
    //mengambil satu elemen array dari awalanPlat[] secara acak
    string platDaerah = awalanPlat[rand() % (sizeof(awalanPlat) / sizeof(string))];
    int nomorPlat = rand() % 8999 + 1000;
    char akhiran1 = rand() % 26 + 65; // ?ascii value dari A - Z adalah 65 - 90
    char akhiran2 = rand() % 26 + 65;
    //mengembalikan string gabungan dari ke 4 variabel diatas
    return platDaerah + IntToString(nomorPlat) + akhiran1 + akhiran2;
}

//merandom data
void GenerateRandomData()
{
    srand((unsigned int)time(NULL));

    //mengambil 15 data mobil, spesifikasi, dan harganya
    for (int i = 0; i < 15; i++)
    {
        //mendapatkan indeks ke-r array sebelum terandom. berbasis array models[]
        int r;
        //loop untuk menghindari memasukkan model mobil yang sama
        while (true)
        {
            r = rand() % (sizeof(models) / sizeof(string));
            //untuk mengecek apakah variabel r sudah berada di array indexes
            bool found = false;
            for (int j = 0; j < 15; j++)
            {
                if (indexes[j] == r)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                indexes[i] = r;
                break;
            }
        }

        //merandom model mobil
        modelRandom[i] = models[r];

        //merandom ketersediaan mobil
        tersedia[i] = rand() % 10 != 1;

        //merandom spesifikasi mobil
        cc[i] = engines[r];
        tipeMesin[i] = engineTypes[r];
        bahanbakar[i] = fuelTypes[r];
        bensin[i] = fuels[r];
        kursi[i] = seats[r];
        kilometer[i] = rand() % 98888 + 1111;
        adaAC[i] = haveAC[r];
        warna[i] = rand() % 2 == 1 ? colors[r] : allColors[rand() % (sizeof(allColors) / sizeof(string))];
        harga[i] = prices[r];
        pabrikan[i] = manufacturers[r];
        jenisMobil[i] = bodyTypes[r];
        platNomor[i] = GenerateRandomLicensePlate();
    }

    //merandom nomor rekening
    for (int i = 0; i < 5; i++)
    {
        int noRek = rand() % 999 + 11;
        nomorRekening += IntToString(noRek);
    }

    //merandom nomor transaksi
    string randomString = "";
    for (int i = 0; i < rand() % 5 + 3; i++)
    {
        int affix = rand() % 2 == 1 ? 0 : 32;
        randomString += rand() % 26 + 35 + affix;
    }
    nomorTransaksi = EncryptJoaat(randomString);
}

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include "DataMobil.h"

using namespace std;

//array tempat menyimpan hasil randomisasi
string modelRandom[15];
string bensin[15];
string kursi[15];
string cc[15];
string warna[15];
string adaAC[15];
string tipeMesin[15];
string bahanbakar[15];
int harga[15];
string platNomor[15];
string nomorRekening;
int kilometer[15];
bool tersedia[15];

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

        //randomization
        modelRandom[i] = models[r];
        bensin[i] = fuels[r];
        kursi[i] = seats[r];
        cc[i] = engines[r];
        harga[i] = prices[r];
        warna[i] = rand() % 2 == 1 ? colors[r] : allColors[rand() % 108];
        adaAC[i] = haveAC[r];
        tipeMesin[i] = engineTypes[r];
        bahanbakar[i] = fuelTypes[r];
        kilometer[i] = rand() % 98888 + 1111;
        tersedia[i] = rand() % 10 != 1;
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

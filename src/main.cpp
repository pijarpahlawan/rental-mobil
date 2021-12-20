#include "iostream"
#include "ctime"
#include "stdlib.h"
#include "sstream"
#include "DataMobil.h"

using namespace std;

string IntToString(int a);
int main()
{
    string modelRandom[15];
    string bensin[15];
    string kursi[15];
    string cc[15];
    int harga[15];
    string warna[15];
    string adaAC[15];
    string tipeMesin[15];
    string bahanbakar[15];
    int kilometer[15];
    string platNomor[15];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 15; i++)
    {
        int r = rand() % (sizeof(models) / sizeof(string));
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
        string platDaerah = awalanPlat[rand() % (sizeof(awalanPlat) / sizeof(string))];
        int nomorPlat = rand() % 8999 + 1000;
        char akhiran1 = rand() % 26 + 65;
        char akhiran2 = rand() % 26 + 65;
        platNomor[i] = platDaerah + IntToString(nomorPlat) + akhiran1 + akhiran2;
        cout << modelRandom[i] << " Plat: " << platNomor[i] << endl;
    }
    //Ada 3 Garasi. Garasi 1 akan mengambil array index 0 - 4, Garasi 2 akan mengambil array index 5 - 10, Garasi 3 akan mengambil array index 11 - 14
}

string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}
#include <iostream>
using namespace std;

void InputHari()
{
    unsigned int jmlh_hari;
    char y_n;
    bool isRun = true;

    while (isRun)
    {
        cout << "Anda mau meminjam untuk berapa hari: ";
        cin >> jmlh_hari;
        cout << endl;
        cout << "Apakah anda yakin, ketik y/n ";
        if (!(cin >> y_n))
        {
            cout << "Input error\n";
            cin.clear();
            cin.ignore();
        }
        else if (y_n == 'y' || y_n == 'Y')
        {
            cout << "Menampilkan biaya untuk " << jmlh_hari << " hari: ";
            isRun = false;
        }
        else if (y_n == 'N' || y_n == 'n')
        {
            continue;
        }
        else if ((y_n != 'N' || y_n != 'n') || (y_n != 'y' || y_n != 'Y'))
            cout << "Input salah\n\n";
    }
}
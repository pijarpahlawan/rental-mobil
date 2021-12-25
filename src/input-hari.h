#include <iostream>
using namespace std;
bool asked = false;

void Ulang()
{
    asked = false;
    cout << "Tekan ENTER untuk mengulangi";
    cin.clear();
    cin.ignore();
    cin.ignore();
    cin.get();  
    system("cls");    
}

void InputHari()
{
    int jmlh_hari = 0;
    char y_n;
    bool isRun = true;
    while (isRun)
    {
        baleni:
        system("cls");
        cout << "Anda mau meminjam untuk berapa hari: ";
        if ((cin >> jmlh_hari) && jmlh_hari > 0)
        {
            cout << endl;
            cout << "Apakah anda yakin, ketik y/n ";
            asked = true;
        } 
        else
        {
            cout << "Silahkan masukkan bilangan bulat positif, dilain itu akan gagal" << endl;
            Ulang();
            goto baleni;
        }               
        if ((cin >> y_n) && (y_n == 'y' || y_n == 'Y'))
        {
            cout << "Menampilkan biaya untuk " << jmlh_hari << " hari: ";
            isRun = false;
        }
        else
        {
            if (!(y_n == 'n' || y_n == 'N'))
            {
                cout << "Silahkan masukkan y/n, dilain itu salah" << endl;
            }
            Ulang();
        }       
    }
}

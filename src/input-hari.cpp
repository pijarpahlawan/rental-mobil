#include <iostream>
using namespace std;

void Ulang()
{
    cin.clear();
    cout << "Tekan ENTER untuk mengulangi...";
    cin.ignore();
    cin.get();
}

int main()
{
    int jmlh_hari = 0;
    char *jmlHari_str;
    char y_n[] = "y/n";
    bool isRun = true;

    while (isRun)
    {
        system("cls");
        cout << "Anda mau meminjam untuk berapa hari: ";
        cin >> jmlHari_str;
        /*sscanf() berfungsi untuk mengcasting tipe data string ke integer*/
        if (sscanf(jmlHari_str, "%d", &jmlh_hari) && jmlh_hari > 0)
        {
            cout << endl;
            cout << "Apakah anda yakin, ketik y/n ";
            cin >> y_n;
            if ((sizeof(y_n) / sizeof(char) == 4) && (y_n[0] == 'y' || y_n[0] == 'Y'))
            {
                cout << "Menampilkan biaya untuk " << jmlh_hari << " hari: ";
                isRun = false;
            }
            else
            {
                if ((sizeof(y_n) / sizeof(char) == 4) && !(y_n[0] == 'n' || y_n[0] == 'N'))
                {
                    cout << "ERROR:silahkan masukkan y/n, dilain itu salah." << endl;
                }
                Ulang();
            }
        }
        else
        {
            cout << "ERROR:silahkan masukkan bilangan bulat positif, dilain itu akan gagal." << endl;
            Ulang();
        }
    }

    return jmlh_hari;
}
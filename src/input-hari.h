#include <iostream>
using namespace std;
bool asked = false;

void Ulang()
{
    asked = false;
    cin.clear();
    cin.ignore();
    cout << "Tekan ENTER untuk mengulangi";
    cin.get();
    system("cls");
}

int main()
{
    int jmlh_hari = 0;
    char *jmlHari_str;
    char y_n[] = "y/n";
    bool isRun = true;
    while (isRun)
    {
    baleni:
        system("cls");
        cout << "Anda mau meminjam untuk berapa hari: ";
        cin >> jmlHari_str;
        /*sscanf() berfungsi untuk mengcasting tipe data string ke integer*/
        if (sscanf(jmlHari_str, "%d", &jmlh_hari) && jmlh_hari > 0)
        {
            cout << endl;
            cout << "Apakah anda yakin, ketik y/n ";
            cin >> y_n;
            asked = true;
        }
        else
        {
            cout << "Silahkan masukkan bilangan bulat positif, dilain itu akan gagal" << endl;
            Ulang();
            goto baleni;
        }
        if ((sizeof(y_n) / sizeof(char) == 4) && (y_n[0] == 'y' || y_n[0] == 'Y'))
        {
            cout << "Menampilkan biaya untuk " << jmlh_hari << " hari: ";
            isRun = false;
        }
        else
        {
            if ((sizeof(y_n) / sizeof(char) == 4) && !(y_n[0] == 'n' || y_n[0] == 'N'))
            {
                cout << "Silahkan masukkan y/n, dilain itu salah" << endl;
            }
            Ulang();
        }
    }
    return jmlh_hari;
}
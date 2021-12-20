#include "iostream"
#include "RandomData.h"

using namespace std;

int main()
{
	generateRandomData();

	//tampilan selamat datang
	//pengumpulan data
	//randomisasi
	//tampilkan mobil per garasi
	//memilih mobil
	//menanyakan identitas
	//menanyakan kurun waktu peminjaman
	//pembayaran
	//tampilan terimakasih

	for (int i = 0; i < 15; i++)
	{
		cout << modelRandom[i] << " Kapasitas tangki: " << bensin[i] << " Plat: " << platNomor[i] << " Tersedia: " << tersedia[i] << endl;
	}

	cin.ignore();
	return 0;
}

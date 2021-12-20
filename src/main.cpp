#include "iostream"
#include "RandomData.h"

using namespace std;

int main()
{
	generateRandomData();
	for (int i = 0; i < 15; i++)
	{
		cout << modelRandom[i] << " Plat: " << platNomor[i] << " Tersedia: " << tersedia[i] << endl;
	}
	return 1;
}

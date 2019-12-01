#include <iostream>
using namespace std;

const int Dias = 7;
typedef double tTemp[Dias];

double media(const tTemp temp);

int main()
{
	tTemp temp;
	for (int i = 0; i < Dias; i++)
	{
		cout << "Temperatura del dia " << i + 1 << " : ";
		cin >> temp[i];
	}
	cout << "Temperatura dia lunes: " << temp[0] << endl;
	cout << "Temperatura media: " << media(temp) << endl;
	return 0;
}

double media(const tTemp temp)
{
	double total=0, media;
	for (int i = 0; i < Dias; i++)
	{
		total = total + temp[i];
	}
	media = total / Dias;
	return media;
}
#include <iostream>
using namespace std;

int main()
{
	double d, num;
	bool encontrado = false;
	cout << "Encontrar primero mayor que: ";
	cin >> num;
	cout << "Siguiente (-1 para terminar): ";
	cin >> d;
	while ((d != -1) && !encontrado) {
		if (d > num)
		{
			encontrado = true;
		}
		else
		{
			cout << "Siguiente (-1 para terminar): ";
			cin >> d;
		}
	}
	return 0;
}

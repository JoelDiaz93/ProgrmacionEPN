#include <iostream>
using namespace std;

int EsPrimo(int Valor);

int main()
{
	int primo=0, a=0;
	while (primo<=0)
	{
		cout << "Ingrese hasta que numero desea la secuencia de N primos: ";
		cin >> primo;
	}
	cout << "La secuencia es: " << endl;
	for (int i = 1; i <= primo; i++)
	{
		if (EsPrimo(i) == 0)
		{
			cout << i << " ,";
		}
	}
	return 0;
}

int EsPrimo(int Valor)
{
	int primo = 0;
	for (int i = 2; i < Valor - 1 && primo == 0; i++)
	{
		if (Valor % i == 0)
		{
			primo = 1;
		}
	}
	return primo;
}
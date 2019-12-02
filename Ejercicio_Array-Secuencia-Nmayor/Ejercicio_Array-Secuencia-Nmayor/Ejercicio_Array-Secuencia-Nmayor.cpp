/*
Desarrolla un programa que determine si una secuencia de enteros introducidos por el teclado y terminada en 0 
(centinela) es creciente o no (cada elemento es mayor o igual que el anterior).
*/

#include <iostream>
using namespace std;

const int Max = 100;
typedef int nArray[Max];

int main()
{
	nArray num;
	int cont = 0, mayor=0;
	cout << "Ingrese Secuencia de numeros (0 para terminar)" << endl;
	do
	{
		cin >> num[cont];
		if (num[cont]!=0)
		{
			cont++;
		}
	} while (num[cont] != 0);
	for (int i = 0; i <= cont; i++)
	{
		cout << num[i] << " ";
		if (num[i] <= num[i + 1])
		{
			mayor = num[i + 1];	
		}
	}
	cout << "Es creciente hasta: " << mayor;
	return 0;
}
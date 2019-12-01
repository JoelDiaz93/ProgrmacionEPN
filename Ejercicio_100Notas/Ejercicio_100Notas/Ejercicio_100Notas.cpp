#include <iostream>
using namespace std;

const int Max = 100;
typedef double tArray[Max];

double promedio(const tArray Nota, int cont);
int calif(const tArray Nota);
double mayor(const tArray Nota, int cont);

int main()
{
	tArray Nota;
	Nota[0] = 0;
	int cont = 0, i=0;
	while (cont <= Max) {
		cout << "Ingrese la nota del estudiante N: " << cont + 1 << endl;
		cin >> Nota[cont];
		if (Nota[cont]>=0)
		{
			cont++;
		}
		else
		{
			break;
		}
	}
	/*while (i < cont)
	{
		if (Nota[i] >= 7 && Nota[i] <= 10)
		{
			cout << Nota[i] << " Aprobado" << endl;
		}
		else if (Nota[i] >= 0 && Nota[i] < 7)
		{
			cout << Nota[i] << " Suspenso" << endl;
		}
		else
		{
			cout << Nota[i] << " Nota no valida" << endl;
		}
		i++;
	}
	*/
	cout << "La mayor nota es: " << mayor(Nota, cont);
}

double promedio(const tArray Nota, int cont) {
	double resultado, suma = 0;
	for (int i = 0; i < cont; i++)
	{
		suma = suma + Nota[i];
	}
	resultado = suma / cont;
	return resultado;
}

int calif(const tArray Nota) {
	int resultado = 0;
	for (int i = 0; i < Max; i++)
	{
		if (Nota[i] >= 0 && Nota[i] < 7) {
			resultado++;
		}
	}
	return resultado;
}

double mayor(const tArray Nota, int cont) {
	double mayor=0;
	for (int i = 0; i < cont; i++)
	{
		if (mayor<Nota[i]) {
			mayor = Nota[i];
		}
	}
	return mayor;
}
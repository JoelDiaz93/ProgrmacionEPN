#include <iostream>
using namespace std;

const int Max = 10;
typedef double tArray[Max];

double promedio(const tArray Nota);
int calif(const tArray Nota);

int main()
{
	tArray Nota;
	int cont=0;
	while (cont<Max) {
		cout << "Ingrese la nota del estudiante N: " << cont + 1 << endl;
		cin >> Nota[cont];
		cont++;
	}
	cont = 0;
	while (cont<Max)
	{
		if (Nota[cont]>=7 && Nota[cont]<=10)
		{
			cout << Nota[cont] << " Aprobado" << endl;
		}
		else if (Nota[cont] >= 0 && Nota[cont] < 7)
		{
			cout << Nota[cont] << " Suspenso" << endl;
		}
		else
		{
			cout << Nota[cont] << " Nota no valida" << endl;
		}
		cont++;
	}
	cout << "El Promedio del curso es: " << promedio(Nota) << endl;
	cout << "Cantidad de estudiantes aprobados: " << Max - calif(Nota) << endl;
	cout << "Cantidad de estudiantes en suspenso: " << calif(Nota) << endl;
}

double promedio(const tArray Nota) {
	double resultado, suma=0;
	for (int i = 0; i < Max; i++)
	{
		suma = suma + Nota[i];
	}
	resultado = suma / 10;
	return resultado;
}

int calif(const tArray Nota) {
	int resultado=0;
	for (int i = 0; i < Max; i++)
	{
		if (Nota[i] >= 0 && Nota[i] < 7) {
			resultado++;
		}
	}
	return resultado;
}

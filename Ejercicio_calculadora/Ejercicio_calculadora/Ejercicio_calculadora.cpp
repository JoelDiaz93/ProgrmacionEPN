#include <iostream>
using namespace std;

double suma(double num1, double num2);
double resta(double num1, double num2);
double multiplicacion(double num1, double num2);
double division(double num1, double num2);

int main()
{
	int i = 1;
	double n1, n2;
	while (i != 0)
	{
		cout << "CALCULADORA" << endl;
		cout << "1. Suma" << endl;
		cout << "2. Resta" << endl;
		cout << "3. Multiplicacion" << endl;
		cout << "4. Division" << endl;
		cout << "0. Salir" << endl;
		cin >> i;
			switch (i)
			{
			case 1:
			{
				cout << "Ingrese 2 numeros para la suma: " << endl;
				cin >> n1 >> n2;
				cout << "La suma de " << n1 << " + " << n2 << " = " << suma(n1, n2) << endl;
				break;
			}
			case 2:
			{
				cout << "Ingrese 2 numeros para la resta: " << endl;
				cin >> n1 >> n2;
				cout << "La resta de " << n1 << " - " << n2 << " = " << resta(n1, n2) << endl;
				break;
			}
			case 3:
			{
				cout << "Ingrese 2 numeros para la multiplicacion: " << endl;
				cin >> n1 >> n2;
				cout << "La multiplicacion de " << n1 << " * " << n2 << " = " << multiplicacion(n1, n2) << endl;
				break;
			}
			case 4:
			{
				cout << "Ingrese 2 numeros para la division: " << endl;
				cin >> n1 >> n2;
				cout << "La division de " << n1 << " / " << n2 << " = " << division(n1, n2) << endl;
				break;
			}
			default:
				break;
			}

	}
	return 0;
}

	double suma(double num1, double num2) {
		double res;
		res = num1 + num2;
		return res;
	}
	double resta(double num1, double num2) {
		double res;
		res = num1 - num2;
		return res;
	}
	double multiplicacion(double num1, double num2) {
		double res;
		res = num1 * num2;
		return res;
	}
	double division(double num1, double num2) {
		double res;
		res = num1 / num2;
		return res;
	}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

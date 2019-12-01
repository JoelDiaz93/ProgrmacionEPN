#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i, fib1 = 0, fib2 = 1, fibr = 0;
	cout << "Hasta que numero desea imprimir la serie de fibonacci: " << endl;
	cin >> i;

	while (fibr<=i)
	{
		cout << fibr << " ";
		fibr = fib1 + fib2;
		fib2 = fib1;
		fib1 = fibr;
	}

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

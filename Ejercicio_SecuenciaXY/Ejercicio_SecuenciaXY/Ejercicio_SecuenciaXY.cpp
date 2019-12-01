#include <iostream>
using namespace std;
#include <fstream>

const int Max = 100;
typedef char tArray[Max];

int main()
{
	tArray lista;
	char c;
	int cont = 0;
	ifstream archivo;
	archivo.open("lista.txt");
	if (archivo.is_open())
	{
		archivo >> c;
		while (c != '*' && cont<Max)
		{
			if (c=='x')
			{
				lista[cont+1] = c;
				archivo >> c;
				if (c=='y') {
					cont++;
				}
			}
			lista[cont] = c;
			archivo >> c;
		}
		archivo.close();
		cout << "xy aparece " << cont << " veces.";
	}
	else
	{
		cout << "El archivo no se pudo abrir!" << endl;
	}
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

#include <iostream>
using namespace std;
#include <fstream>

const int Max = 100;
typedef double tArray[Max];

double media(const tArray lista, int cont);

int main()
{
	tArray lista;
	int contador = 0;
	double valor, med;
	ifstream archivo;
	archivo.open("lista.txt");
	if (archivo.is_open()) {
		archivo >> valor;
		while ((valor != -1) && (contador < Max)) {
			lista[contador] = valor;
			contador++;
			archivo >> valor;
		}
		archivo.close();
		med = media(lista, contador);
		cout << "Media de los elementos de la lista: " << med << endl;
	}
	else
	{
		cout << "No se pudo abrir el achivo!" << endl;
	}
	return 0;
}

double media(const tArray lista, int cont) {
	double med, total = 0;
	for (int ind = 0; ind < cont; ind++)
	{
		total = total + lista[ind];
	}
	med = total / cont;
	return med;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

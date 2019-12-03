#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
using namespace std;

const int Max = 50;
typedef string tArray[Max];

int main()
{
	int opcion=1,totalpos=0, longitud=0, cont=0, inv=0;
	string buscar, apariciones, aux1, aux2;
	tArray palabras, invertir;
	ifstream archivo;
	archivo.open("texto.txt");
	if (archivo.is_open())
	{
		while (opcion != 0)
		{
			for (int i = 0; i < Max; i++)
			{
				archivo >> palabras[i];
			}
			cout << "MENU" << endl;
			cout << "1.- Listar Palabras" << endl;
			cout << "2.- Buscar Palabras" << endl;
			cout << "3.- Contar Palabras" << endl;
			cout << "4.- Mayor palabra de longitud" << endl;
			cout << "5.- Desplazar Palabra" << endl;
			cout << "0.- Salir" << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 1:
			{
				for (int i = 0; i < Max; i++)
				{
					if (palabras[i]!="" && palabras[i]!="xxx")
					{
						cout << "Palabra [" << i + 1 << "] :" << palabras[i] << endl;
					}
				}
				break;
			}
			case 2:
			{
				cout << "Que palabra desea buscar? ";
				cin >> buscar;
				for (int i = 0; i < Max; i++)
				{
					if (palabras[i] == buscar)
					{
						cout << "Palabra " << buscar << " se encuentra en la posicion: " << i+1 << endl;
					}
				}
				break;
			}
			case 3:
			{
				cout << "Que palabra desea contar apariciones? ";
				cin >> apariciones;
				for (int i = 0; i < Max; i++)
				{
					if (palabras[i] == apariciones)
					{
						totalpos++;
					}
				}
				cout << apariciones << " Se repite: " << totalpos << endl;
				break;
			}
			case 4:
			{
				cout << "longitud de las palabras: ";
				cin >> longitud;
				for (int i = 0; i < Max; i++)
				{
					if (longitud < palabras[i].length())
					{
						cout << "La palabra de mayor longitud a " << longitud << " en la posicion: " << i + 1 << endl;
					}
				}
				break;
			}
			case 5:
			{
				invertir[0] = palabras[Max - 1];
				for (int i = 0; i < Max-1; i++)
				{
					for (int j = i+1; j < Max; j++)
					{
						invertir[j] = palabras[i];
					}
				}
				for (int i = 0; i < Max; i++)
				{
					cout << palabras[i] << endl;
				}

				break;
			}
			default:
				break;
			}
		}
		archivo.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo..." << endl;
	}
	return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

const int Max = 100;
typedef char cArray[Max];

int main()
{
	cArray cadena;
	char c;
	int cont = 0, par=0, pos1=0, pos2=0;
	ifstream archivo;
	archivo.open("texto.txt");
	if (archivo.is_open())
	{
		archivo >> c;
		while (c!='#' && cont < Max)
		{
			cadena[cont] = c;
			if (c=='(')
			{
				par++;
				pos1 = cont;
				if (par==1 && pos2!=0)
				{
					pos1 = cont+1;
					pos2 = 0;
				}
			}
			else if (c==')')
			{
				par--;
				pos2 = cont;
				if (par==-1 && pos1!=0)
				{
					pos2 = cont + 1; 
					pos1 = 0;
				}
			}
			archivo >> c;
			cont++;
		}
		for (int i = 0; i < cont; i++)
		{
			cout << cadena[i]; 
		}
		cout << endl;
		if (par == 0)
		{
			cout << "Los parentesis se han abierto y cerrado correctamente."<< endl;
		}
		else
		{
			if (par>0)
			{
				cout << "Existen " << par << " (, demas en la cadena" << endl;
				cout << "El error esta en la posicion " << pos1;
			}
			else
			{
				cout << "Existen " << par*-1 << " ), demas en la cadena" << endl;
				cout << "El error esta en la posicion " << pos2;
			}
		}
	}
	else
	{
		cout << "No se puede leer archivo texto.txt";
	}
}

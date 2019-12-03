/*
Implementa un programa que lea del teclado secuencias de caracteres terminadas en punto y que, para cada secuencia,
cuente y muestre en la pantalla el número de blancos, letras y dígitos que hay entre la primera pareja de paréntesis.
Si sólo hay un paréntesis de apertura, el recuento seguirá hasta el final de la secuencia. Puede no haber ninguna
pareja de paréntesis. El programa solicitará secuencias hasta que se introduzca una línea con sólo el punto. Un
ejemplo de ejecución del programa sería el siguiente:
Entrada: Esto es (una prueba) de secuencia de entrada.↲ Salida: Blancos: 1 Letras: 9 Dígitos: 0 Entrada: Esto es la
prueba de secuencia (de entrada 2.↲ Salida: Blancos: 2 Letras: 9 Dígitos: 1 Entrada: Esto es la prueba de secuencia
de entrada 3.↲ Salida: Blancos: 0 Letras: 0 Dígitos: 0 Entrada: .↲ Fin del programa
Recuerda que con cin.sync(); puedes descartar el salto de línea (y lo que pueda haber después del punto), una vez
leído el punto final de cada texto.
*/
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
	string cadena = " ";
	char c = ' ';
	int let = 0, num = 0, esp = 0, aux=0;
	while (cadena.length() > 1 || c != '.')
	{
		cout << "Escriba una cadena de texto y numeros con punto final: ";
		getline(cin, cadena);
		for (int i = 0; i < cadena.length(); i++)
		{
			c = cadena[i];
			if (c == '(')
			{
				for (int j=i; j< cadena.length();j++)
				{
					c = cadena[j];
					if (c != ')')
					{
						if (isalpha(c))
						{
							let++;

						}
						else if (isdigit(c))
						{
							num++;
						}
						else if (isspace(c))
						{
							esp++;
						}
					}
					else
					{
						j = cadena.length();
					}
				}
				if (let > 0 || num > 0 || esp > 0)
				{
					cout << "Hay " << let << " Letras, " << num << " numeros, " << esp << " espacios." << endl;
				}
				c = ' ';
			}
		}
		
		let = 0;
		num = 0;
		esp = 0;
	}
	return 0;
}
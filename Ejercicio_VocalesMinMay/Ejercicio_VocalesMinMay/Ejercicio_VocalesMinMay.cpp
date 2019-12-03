#include <iostream>
#include <string>
using namespace std;


int main()
{
	char vocal='a';
	while (vocal!='.')
	{
		cout << "Ingrese vocal en minuscula (punto para finalizar): ";
		cin >> vocal;
		switch (vocal)
		{
		case 'a':
		{
			cout << "A" << endl;
			break;
		}
		case 'e':
		{
			cout << "E" << endl;
			break;
		}
		case 'i':
		{
			cout << "I" << endl;
			break;
		}
		case 'o':
		{
			cout << "O" << endl;
			break;
		}
		case 'u':
		{
			cout << "U" << endl;
			break;
		}
		default:
		{
			cout << "Solo vocales minusculas..." << endl;
			break;
		}
		}
	}
	return 0;
}

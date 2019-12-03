#include <iostream>
using namespace std;

int main()
{
	int n1, n2;
	cout << "ingrese 2 numeros para encontrar los multiplos de 6 entre ellos: ";
	cin >> n1 >> n2;
	if (n1>n2)
	{
		cout << "Los numeros divisibles entre " << n2 << " y " << n1 << " para 6 son: "<< endl;
		for (int i = n2; i <= n1; i++)
		{
			if (i%6==0)
			{
				cout << i << " ";
			}
		}
	}
	else if(n2>n1)
	{
		cout << "Los numeros divisibles entre " << n1 << " y " << n2 << " para 6 son: " << endl;
		for (int i = n1; i <= n2; i++)
		{
			if (i % 6 == 0)
			{
				cout << i << " ";
			}
		}
	}

}
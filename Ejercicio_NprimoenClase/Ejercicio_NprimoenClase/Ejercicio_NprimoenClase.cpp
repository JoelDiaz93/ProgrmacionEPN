#include <iostream>
using namespace std;

bool primo(int n);

int main()
{
	int p = 0;
	cout << "Ingrese hasta que numero se va a realizar: ";
	cin >> p;
	if (p > 0)
	{
		primo(p);

	}
}
bool primo(int n)
{
	bool esPrimo = true;
	for (int i = 2; i <= n - 1; i++)
	{
		if (n % 1 == 0)
		{
			esPrimo = false;
		}
	}
	return esPrimo;
}
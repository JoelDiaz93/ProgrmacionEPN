#include <iostream>
using namespace std;

int main()
{
    int m=0, n=0, r=0;
    while (m<=0 || n<=0|| m==n)
    {
        cout << "Ingrese 2 numeros enteros positivos, diferentes de 0" << endl;
        cin >> m >> n;
    }
    if (m>n)
    {
        for (int i=n; i<=m; i++)
        {
            r=r+i;
        }
    }
    else if (n>m)
    {
        for (int i=m; i<=n; i++)
        {
            r=r+i;
        }
    }
    cout << "La sumatoria es: " << r << endl;
    return 0;
}

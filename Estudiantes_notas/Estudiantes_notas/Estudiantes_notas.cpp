#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 100;

typedef struct
{
	string nombre;
	string apellidos;
	int edad;
	string nif;
	double nota;
} tEstudiante;
typedef tEstudiante tArray[MAX];
typedef struct
{
	tArray elementos;
	int contador;
} tLista;

//Prototipos
int menu(); //menu del programa
void cargar(tLista& lista, bool& ok); //carga del archivo
void guardar(const tLista& lista); // guardar el archivo
void leerEstudiante(tEstudiante& estudiante); // Lee los datos
void insertarEstudiante(tLista& lista, tEstudiante estudiante, bool& ok); //inserta un nuevo estudiante
void eliminarEstudiante(tLista& lista, int pos, bool& ok); // Elimina un estudiante de la lista
string nombreCompleto(tEstudiante estudiante);
void calificar(tLista& lista);	//Notas de los estudiantes
double mediaClase(const tLista& lista); //nota media
int mayorNota(const tLista& lista); //indice del estudiante con mayor nota
void mostrarEstudiante(tEstudiante estudiante);
void listado(const tLista& lista, double media, int mayor); //listado de la clase

int main()
{
	tLista lista;
	tEstudiante estudiante;
	bool exito;
	int op=1, pos;
	cargar(lista, exito);
	if (!exito)
	{
		cout << "No se ha podido cargar la lista!" << endl;
	}
	else
	{
		do
		{
			op = menu();
			switch (op)
			{
			case 1:
			{
				leerEstudiante(estudiante);
				insertarEstudiante(lista, estudiante, exito);
				if (!exito)
				{
					cout << "Lista llena: imposible insertar..." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Posicion: ";
				cin >> pos;
				eliminarEstudiante(lista, pos - 1, exito);
				if (!exito)
				{
					cout << "Elemento inexistente!" << endl;
				}
				break;
			}
			case 3:
			{
				calificar(lista);
				break;
			}
			case 4:
			{
				listado(lista, mediaClase(lista), mayorNota(lista));
			}
			default:
				break;
			}
		} while (op!=0);
		guardar(lista);
	}
	return 0;
}

int menu()
{
	int op;
	do
	{
		cout << "1 - Anadir un nuevo estudiante" << endl;
		cout << "2 - Eliminar un estudiante" << endl;
		cout << "3 - Calificar a los estudiantes" << endl;
		cout << "4 - Listado de estudiantes" << endl;
		cout << "0 - Salir" << endl;
		cout << "Opcion:" << endl;
		cin >> op;
	} while ((op < 0) || (op > 4));
	return op;
}

void cargar(tLista& lista, bool& ok)
{
	tEstudiante estudiante; //Variable auxiliar para leer
	ifstream archivo;
	char aux;
	lista.contador = 0; //inicializa lista
	archivo.open("clase.txt");
	if (!archivo.is_open())
	{
		ok = false;
	}
	else
	{
		ok = true;
		getline(archivo, estudiante.nombre); //Leemos el primer nombre
		while ((estudiante.nombre != "XXX") && (lista.contador < MAX))
		{
			getline(archivo, estudiante.apellidos);
			archivo >> estudiante.edad;
			archivo >> estudiante.nif;
			archivo >> estudiante.nota;
			archivo.get(aux); //Saltamos el intro
			lista.elementos[lista.contador] = estudiante; //Al final
			lista.contador++;
			getline(archivo, estudiante.nombre); //Siguiente nombre
		} // Si hay mas de MAX estudiantes, ignoramos el resto
	}
	archivo.close();
}

void guardar(const tLista& lista)
{
	ofstream archivo;
	archivo.open("clase.txt");
	for (int i = 0; i < lista.contador; i++)
	{
		archivo << lista.elementos[i].nombre << endl;
		archivo << lista.elementos[i].apellidos << endl;
		archivo << lista.elementos[i].edad << endl;
		archivo << lista.elementos[i].nif << endl;
		archivo << lista.elementos[i].nota << endl;
	}
	archivo << "XXX" << endl; //centinela final
	archivo.close();
}

void leerEstudiante(tEstudiante& estudiante)
{
	cin.ignore(); //Descartar cualquier entrada pendiente
	cout << "Nombre: ";
	getline(cin, estudiante.nombre);
	cout << "Apellidos: ";
	getline(cin, estudiante.apellidos);
	cout << "Edad: ";
	cin >> estudiante.edad;
	cout << "NIF: ";
	cin >> estudiante.nif;
	estudiante.nota = -1; //Sin calificar de momento
	cin.sync(); //Descartar cualquier entrada pendiente
}

void insertarEstudiante(tLista& lista, tEstudiante estudiante, bool& ok)
{
	ok = true;
		if (lista.contador == MAX) {
			ok = false;
		}
		else
		{
			lista.elementos[lista.contador] = estudiante; //insertamos el final
			lista.contador++;
		}
}

void eliminarEstudiante(tLista& lista, int pos, bool& ok)
{
	//espera el indice del elemento en pos
	if ((pos < 0) || (pos > lista.contador - 1))
	{
		ok = false; // Elemento inexistente
	}
	else
	{
		ok = true;
		for (int i = pos; i < lista.contador-1; i++)
		{
			lista.elementos[i] = lista.elementos[i + 1];
		}
		lista.contador--;
	}
}

string nombreCompleto(tEstudiante estudiante)
{
	return estudiante.nombre + " " + estudiante.apellidos;
}

void calificar(tLista& lista)
{
	for (int i = 0; i < lista.contador; i++)
	{
		cout << "Nota del estudiante " << nombreCompleto(lista.elementos[i]) << ": ";
		cin >> lista.elementos[i].nota;
	}
}

double mediaClase(const tLista& lista)
{
	double aux, suma = 0;
	for (int i = 0; i < lista.contador; i++)
	{
		suma += lista.elementos[i].nota;
	}
	aux = suma / lista.contador;
	return aux;
}

int mayorNota(const tLista& lista)
{
	double max = 0;
	int pos = 0;
	for (int  i = 0; i < lista.contador; i++)
	{
		if (lista.elementos[i].nota > max)
		{
			max = lista.elementos[i].nota;
			pos = i;
		}
	}
	return pos;
}

void mostrarEstudiante(tEstudiante estudiante)
{
	cout << setw(35) << left << nombreCompleto(estudiante);
	cout << estudiante.nif << " ";
	cout << setw(2) << estudiante.edad << " anios ";
	cout << fixed << setprecision(1) << estudiante.nota;
}

void listado(const tLista& lista, double media, int mayor)
{
	for (int i = 0; i < lista.contador; i++)
	{
		cout << setw(3) << left << i + 1 << ": ";
		mostrarEstudiante(lista.elementos[i]);
		if (i == mayor)
		{
			cout << " Mayor nota! ";
		}
		cout << endl;
	}
	cout << "Media de la clase: " << fixed << setprecision(1) << media << endl << endl;
}
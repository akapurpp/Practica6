#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "colors.h"
#include "Lanchas.h"

using namespace std;

int velocidad;
int nitro;
int distancia;
bool nitro_usado;
string nombre;

void Encabezado() {
	cout << "\t" << MAGENTA << "===========================================================================" << endl;
	cout << "\t" << "=                                BIENVENIDO                               =" << endl;
	cout << "\t" << "=                            CARRERAS DE LANCHAS                          =" << endl;
	cout << "\t" << "=                                GAS A FONDO                              =" << endl;
	cout << "\t" << "===========================================================================" << endl << "\n" << RESET;
}



int main() {


	// Inicializar la semilla para generar números aleatorios
	srand(time(NULL));

	// Crear las dos lanchas que participarán en la carrera

	Encabezado();
	string nombreLancha1;
	string nombreLancha2;
	cout << "Ingrese el nombre del corredor 1: ";
	cin >> nombreLancha1;
	Lanchas lancha1(0, nombreLancha1, 0, 1);

	cout << "Ingrese el nombre del corredor 2: ";
	cin >> nombreLancha2;
	Lanchas lancha2(0, nombreLancha2, 0, 1);
	cout << endl;

	system("pause");
	system("cls");



	// Simular los cinco turnos de la carrera
	for (int i = 1; i <= 5; i++) {

		Encabezado();
		cout << "\t" << "Turno " << i << ": Jugador " << lancha1.getNombre() << endl;
		cout << endl;


		//Jugar el turno de la lancha 1


		cout << "Para lanzar el dado pulsa 0" << endl;
		int lanzar;
		cin >> lanzar;
		int resultado_dado = lancha1.lanzar_dado();
		if (lanzar == 0) {
			cout << "\n" << lancha1.getNombre() << " lanza el dado y obtiene " << resultado_dado << endl;
		}
		else {
			while (lanzar != 0) {
				cout << "No has pulsado 0, vuelve a intentarlo." << endl;
				cin >> lanzar;
				if (lanzar == 0) {
					cout << "\n" << lancha1.getNombre() << " lanza el dado y obtiene " << resultado_dado << endl;
				}
			}
		}

		lancha1.mover_lancha(resultado_dado);
		lancha1.printStatus();
		lancha1.usar_nitro();
		lancha1.calcular_distancia_recorrida();
		cout << endl;
		system("pause");
		system("cls");



		Encabezado();
		cout << "\t" << "Turno " << i << ": Jugador " << lancha2.getNombre() << endl;
		cout << endl;

		// Jugar el turno de la lancha 2
		resultado_dado = lancha2.lanzar_dado();

		cout << "Para lanzar el dado pulsa 0" << endl;
		int lanzar2;
		cin >> lanzar2;

		if (lanzar2 == 0) {
			cout << "\n" << lancha2.getNombre() << " lanza el dado y obtiene " << resultado_dado << endl;
		}
		else {
			while (lanzar2 != 0) {
				cout << "No has pulsado 0, vuelve a intentarlo." << endl;
				cin >> lanzar2;
				if (lanzar2 == 0) {
					cout << "\n" << lancha2.getNombre() << " lanza el dado y obtiene " << resultado_dado << endl;
				}
			}
		}

		lancha2.mover_lancha(resultado_dado);
		lancha2.printStatus();
		lancha2.usar_nitro();
		lancha2.calcular_distancia_recorrida();

		system("pause");
		system("cls");
	
		if (i != 5) {
			Encabezado();
			cout << "\t" << "Turno " << i << endl;
			cout << "" << endl;
			cout << "Barco de => " << lancha1.getNombre() << endl;
			lancha1.imprimir_lancha(lancha1);
			cout << "Barco de => " << lancha2.getNombre() << endl;
			lancha2.imprimir_lancha(lancha2);


			system("pause");
			system("cls");
		}
		

	}







	// Determinar la lancha ganadora

	Encabezado();
	cout << "La carrera ha terminado:" << endl;
	system("pause");
	system("cls");
	Encabezado();
	cout << RED<< "=> RESULTADOS DE LA CARRERA <=" << endl << RESET;
	cout << "" << endl;
	cout << "Barco de => " << lancha1.getNombre() << " " << lancha1.getDistancia() << " metros" << endl;
	lancha1.imprimir_lancha(lancha1);
	cout << "Barco de => " << lancha2.getNombre() << " " << lancha2.getDistancia() << " metros" << endl;
	lancha2.imprimir_lancha(lancha2);
	cout << "\t" << endl;

	if (lancha1.es_ganadora(lancha2)) { // lancha1 es ganadora
		cout << GREEN << lancha1.getNombre() << " ha ganado la carrera!!!" << endl << RESET;
	}
	else if (lancha2.es_ganadora(lancha1)) { // lancha2 es ganadora
		cout << GREEN << lancha2.getNombre() << " ha ganado la carrera!!!" << endl << RESET;
	}
	else { // Empate
		cout << ORANGE << "Ha habido un empate!!!" << endl << RESET;
	}



	return 0;
}

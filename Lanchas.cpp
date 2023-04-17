#pragma once
#include "Lanchas.h"
#include  <iostream>
#include <stdio.h>
#include "colors.h"
#include <windows.h>

//constructor
Lanchas::Lanchas(int pVelocidad, std::string pNombre, int pDistancia, int pNitro) {
	velocidad = pVelocidad;
	nombre = pNombre;
	distancia = pDistancia;
	nitro = pNitro;



}

//getters
int Lanchas::getVelocidad() {
	return velocidad;
}

std::string Lanchas::getNombre() {
	return nombre;
}

int Lanchas::getDistancia() {
	return distancia;
}

int Lanchas::getNitro() {
	return nitro;
}





//setters

void Lanchas::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}

void Lanchas::setNombre(std::string pNombre) {
	nombre = pNombre;
}

void Lanchas::setDistancia(int pDistancia) {
	distancia = pDistancia;
}

void Lanchas::setNitro(int pNitro) {
	nitro = pNitro;
}




//Metodos propios


void Lanchas::printStatus() {
	cout << getNombre() << " tiene una velocidad de " << getVelocidad() << " KM/h" << std::endl;
}

bool Lanchas::es_ganadora(Lanchas otra_lancha)
{
	return distancia > otra_lancha.getDistancia();
}

int Lanchas::lanzar_dado() {
	return rand() % 6 + 1; // genera un número aleatorio entre 1 y 6
	cout << "El dado ha salido " << lanzar_dado() << std::endl;

}

void Lanchas::mover_lancha(int resultado_dado) {
	velocidad += resultado_dado;
	// se calcula la velocidad sumando el resultado del dado
}

void Lanchas::usar_nitro() {

	if(nitro_usado == true) { // Comprueba si ya se ha usado la nitro
		cout << "Ya has usado la nitro en esta carrera." << std::endl;
		return;
	}

	// Pregunta al usuario si quiere usar la nitro
	cout << "Quieres usar la nitro? " << std::endl;
	cout << "1. Si" << std::endl;
	cout << "2. No" << std::endl;
	int opcion;
	cin >> opcion;

	if (opcion == 1) {
		// Usa la nitro
		if (rand() % 2 == 0) { // Determina aleatoriamente si la nitro funciona o falla
			velocidad *= 2;
			cout << GREEN << "La nitro ha tenido éxito y te ha duplicado tu velocidad, ahora tienes una velocidad de " << velocidad << " KM/h" << std::endl << RESET;
		}
		else {
			cout << RED << "La nitro ha fallado y te ha dividido tu velocidad" << std::endl << RESET;
			velocidad /= 2;
		}
		nitro_usado = true; // Establece nitro_usado a true para que no se pueda usar de nuevo
	}
	else if (opcion == 2) {
		cout << "No has usado la nitro." << std::endl;
	}
}

void Lanchas::calcular_distancia_recorrida() {
	distancia += velocidad * 100;
	// se calcula la distancia recorrida multiplicando la velocidad por 100
	cout << "La distancia recorrida es de " << distancia << " metros" << std::endl;

}

void Lanchas::imprimir_lancha(Lanchas& lancha) {

	cout << "\n\n";
	for (size_t i = 0; i < lancha.getDistancia()/200; i++)
	{
		cout << BLUE<< "~~" << RESET;
		Sleep(50);
	}
	cout << ORANGE << "        |\\ " << endl << RESET;
	for (size_t i = 0; i < lancha.getDistancia() / 200; i++)
	{
		cout << BLUE << "~~" << RESET;
		Sleep(50);
	}
	cout << ORANGE << "        | \\" << endl << RESET;
	for (size_t i = 0; i < lancha.getDistancia() / 200; i++)
	{
		cout << BLUE << "~~" << RESET;
		Sleep(50);
	}
	cout << ORANGE << "        |  \\" << endl << RESET;
	for (size_t i = 0; i < lancha.getDistancia() / 200; i++)
	{
		cout << BLUE << "~~" << RESET;
		Sleep(50);
	}
	cout << ORANGE << "        |___\\" << endl << RESET;
	for (size_t i = 0; i < lancha.getDistancia() / 200; i++)
	{
		cout << BLUE << "~~" << RESET;
		Sleep(50);
	}
	cout << ORANGE << "_____\\--|----/______" << endl << RESET;

	for (size_t i = 0; i < lancha.getDistancia() / 200; i++)
	{
		cout << BLUE << "~~" << RESET;
		Sleep(50);
	}
	cout << ORANGE<< "      \\_____/" << endl << RESET;
	cout << "\n";
}








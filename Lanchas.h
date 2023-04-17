#pragma once
#include  <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Lanchas
{

private:
	int velocidad;
	std::string nombre;
	int distancia;
	int nitro;
	bool nitro_usado;


public:
	//constructor
	Lanchas(int pVelocidad, std::string pNombre, int pDistancia, int pNitro);

	//getters
	int getVelocidad();

	std::string getNombre();

	int getDistancia();

	int getNitro();




	//setters

	void setVelocidad(int pVelocidad);

	void setNombre(std::string pNombre);

	void setDistancia(int pDistancia);

	void setNitro(int pNitro);





	//metodos propios

	int lanzar_dado();

	void mover_lancha(int resultado_dado);

	void calcular_distancia_recorrida();

	void printStatus();

	void usar_nitro();

	bool es_ganadora(Lanchas otra_lancha);

	void imprimir_lancha(Lanchas& lancha);
};


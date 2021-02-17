#pragma once
#include <iostream>
#include <vector>
#include "Monigote.h"
#include "Mapa.h"
#include"Poblador.h"
using namespace std;
using namespace System::Drawing;
class Movimiento
{
private:
	Mapa** mapa;
	int* ce;
	Monigote* obj_monigote;


	vector<Poblador*>*pobladores;
 
 
public:
	Movimiento();
	Movimiento(Bitmap^ bmp);
	~Movimiento();
	//NUEVO
	void Init(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa, Bitmap^ bmp_azul);
	void Run(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa, Bitmap^ bmp_azul);
	void Mover_Monigote(Graphics^ g);
	void Cambiar_Direccion_Monigote(direccion dir);
	void Dibujar_Monigote(Graphics^ g, Bitmap^ bmp_monigote);
	void Dibujar_Mapa(Graphics^ g, Bitmap^ bmp_mapa);
	bool Colision_Mapa(Entidad* obj1, Entidad* obj2);
	void Insertar_Aldeano(Graphics^ g, Bitmap^ bmp_poblador, int j, int color);
};

#pragma once
#include "Entidad.h"
class Mapa :
    public Entidad
{
private:
	double w, h;
	float f, c;
	bool limite;
public:
	Mapa();
	Mapa(int px, int py, Bitmap^ bmp);
	void Dibujar_Imagen(Graphics^ g, Bitmap^ bmp, int pf, int pc, bool plimite);
	float retornar_Ancho();
	float retornar_Alto();
	bool retornar_limite();
	~Mapa();
};


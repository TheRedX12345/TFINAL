#include "Entidad.h"
Entidad::Entidad() {}
Entidad::Entidad(int px, int py)
{
	x = px;
	y = py;
	dx = 1 + rand() % 10;
	dy = 1 + rand() % 5;
	
}
void Entidad::Entidad::Dibujar(Graphics^ g)
{

}
void Entidad::Dibujar_R(Graphics^ g)
{

}
void Entidad::Mover(Graphics^ g)
{

}
Entidad::~Entidad()
{}
int Entidad::retornar_X() { return x; }
int Entidad::retornar_Y() { return y; }
void Entidad::cambiar_X(int nuevo) { x = nuevo; }
void Entidad::cambiar_Y(int nuevo) { y = nuevo; }
float Entidad::retornar_Ancho() { return 0; }
float Entidad::retornar_Alto() { return 0; }
int Entidad::retornar_DX() { return dx; }
int Entidad::retornar_DY() { return dy; }
void Entidad::cambiar_DX(int nuevo) { dx = nuevo; }
void Entidad::cambiar_DY(int nuevo) { dy = nuevo; }

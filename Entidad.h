#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

public enum direccion { arriba, abajo, izquierda, derecha, ninguno };

class Entidad
{
protected:
	int x, y, dx, dy;
public:
	Entidad();
	Entidad(int px, int py);
	virtual void Dibujar(Graphics^ g);
	virtual void Dibujar_R(Graphics^ g);
	virtual void Mover(Graphics^ g);
	// Metodos Getter y Setter en Español
	int retornar_X();
	int retornar_Y();
	void cambiar_X(int nuevo);
	void cambiar_Y(int nuevo);
	virtual float retornar_Ancho();
	virtual float retornar_Alto();
	int retornar_DX();
	int retornar_DY();
	void cambiar_DX(int nuevo);
	void cambiar_DY(int nuevo);
	~Entidad();
};

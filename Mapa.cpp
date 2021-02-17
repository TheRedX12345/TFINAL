#include "Mapa.h"
Mapa::Mapa() {}
Mapa::Mapa(int px, int py, Bitmap^ bmp) : Entidad(px, py) {
	w = 38.8;
	h = 39;
	dx = dy = 0;
	f = 0;
	c = 0;
	limite = false;
}
void Mapa::Dibujar_Imagen(Graphics^ g, Bitmap^ bmp, int pf, int pc, bool plimite)
{
	f = pf;
	c = pc;
	limite = plimite;
	Rectangle porcion = Rectangle(c * w, f * h, w, h);
	Rectangle zoom = Rectangle(x, y, w, h);
	g->DrawImage(bmp,zoom, porcion, GraphicsUnit::Pixel);
}
float Mapa::retornar_Ancho() { return w/1.27; }
float Mapa::retornar_Alto() { return h/1.25; }
bool Mapa::retornar_limite() { return limite; }
Mapa::~Mapa() {}

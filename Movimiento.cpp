#include "Movimiento.h"
Movimiento::Movimiento() {}
Movimiento::Movimiento(Bitmap^ bmp) {
	ce = new int;
	*ce = 0;
}

void Movimiento::Insertar_Aldeano(Graphics^ g, Bitmap^ bmp_poblador, int j, int color)
{

	int x = mapa[j]->retornar_X();
	int y = mapa[j]->retornar_Y();
	Poblador* aux = new Poblador(x,y,bmp_poblador);
	pobladores->push_back(aux);
 

}
void Movimiento::Init(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa, Bitmap^ bmp_azul)
{
	int aux_x = 0;
	int aux_y = 0;

 
	
	mapa = new Mapa * [2500];
	for (int i = 0; i < 2500; i++) {
		int x = aux_x;
		int y = aux_y;
		mapa[i] = new Mapa(x, y, bmp_mapa);
		if ((i + 1) % 50 == 0) {
			aux_x = 0;
			aux_y =  aux_y + mapa[i]->retornar_Alto();
		}
		else
			aux_x = aux_x + mapa[i]->retornar_Ancho();
	}

	obj_monigote = new Monigote(mapa[1222]->retornar_X(), mapa[1222]->retornar_Y(), bmp_monigote);
	obj_monigote->cambiar_ult_movimiento(direccion::arriba);

	 
 
}
void Movimiento::Run(Bitmap^ bmp_monigote, Graphics^ g, Bitmap^ bmp_mapa, Bitmap^ bmp_azul)
{
	Dibujar_Mapa(g, bmp_mapa);
	Mover_Monigote(g);
	for (int i = 0; i < 50; i++)
	{

		if (Colision_Mapa(obj_monigote, mapa[i]) && (mapa[i]->retornar_limite()))
		{
			obj_monigote->cambiar_X(obj_monigote->retornar_X() - obj_monigote->retornar_DX());
			obj_monigote->cambiar_Y(obj_monigote->retornar_Y() - obj_monigote->retornar_DY());
			obj_monigote->cambiar_ult_movimiento(ninguno);
		}

	}
	Dibujar_Monigote(g, bmp_monigote);

	//Si hay colision aqui modificar

}
void Movimiento::Mover_Monigote(Graphics^ g)
{
	obj_monigote->Movimiento(g);
}
void Movimiento::Cambiar_Direccion_Monigote(direccion dir) {
	obj_monigote->cambiar_ult_movimiento(dir);
}
void Movimiento::Dibujar_Monigote(Graphics^ g, Bitmap^ bmp_monigote)
{
	obj_monigote->Dibujar(g, bmp_monigote);
}
Movimiento::~Movimiento() {

}
void Movimiento::Dibujar_Mapa(Graphics^ g, Bitmap^ bmp_mapa) {
	//PRIMERA LINEA
	mapa[0]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[2]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[3]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[4]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[5]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[6]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[7]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[8]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[9]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[10]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[11]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[12]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[13]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[14]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[15]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[16]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[17]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[18]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[19]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[20]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[21]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[22]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[23]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[24]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[25]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[26]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[27]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[28]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[29]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[30]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[31]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[32]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[33]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[34]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[35]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[36]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[37]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[38]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[39]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[40]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[41]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[42]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[43]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[44]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[45]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[46]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[47]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[48]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[49]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//SEGUNDA LINEA
	mapa[50]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[51]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[52]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[53]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[54]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[55]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[56]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[57]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[58]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[59]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[60]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[61]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[62]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[63]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[64]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[65]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[66]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[67]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[68]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[69]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[70]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[71]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[72]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[73]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[74]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[75]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[76]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[77]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[78]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[79]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[80]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[81]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[82]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[83]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[84]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[85]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[86]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[87]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[88]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[89]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[90]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[91]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[92]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[93]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[94]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[95]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[96]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[97]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[98]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[99]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//TERCERA LINEA
	mapa[100]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[101]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[102]->Dibujar_Imagen(g, bmp_mapa, 9, 5, true);
	mapa[103]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[104]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[105]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[106]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[107]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[108]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[109]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[110]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[111]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[112]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[113]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[114]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[115]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[116]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[117]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[118]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[119]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[120]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[121]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[122]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[123]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[124]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[125]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[126]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[127]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[128]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[129]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[130]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[131]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[132]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[133]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[134]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[135]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[136]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[137]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[138]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[139]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[140]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[141]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[142]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[143]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[144]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[145]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[146]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[147]->Dibujar_Imagen(g, bmp_mapa, 9, 5, true); //TRONCO
	mapa[148]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[149]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 4
	mapa[150]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[151]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[152]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[153]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[154]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[155]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[156]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[157]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[158]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[159]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[160]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[161]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[162]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[163]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[164]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[165]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[166]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[167]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[168]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[169]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[170]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[171]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[172]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[173]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[174]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[175]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[176]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[177]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[178]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[179]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[180]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[181]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[182]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[183]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[184]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[185]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[186]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[187]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[188]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[189]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[190]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[191]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[192]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[193]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[194]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[195]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[196]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[197]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[198]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[199]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 5
	mapa[200]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[201]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[202]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[203]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[204]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[205]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[206]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[207]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[208]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[209]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[210]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[211]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[212]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[213]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[214]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[215]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[216]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[217]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[218]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[219]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[220]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[221]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[222]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[223]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[224]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[225]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[226]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[227]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[228]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[229]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[230]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[231]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[232]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[233]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[234]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[235]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[236]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[237]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[238]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[239]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[240]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[241]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[242]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[243]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[244]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[245]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[246]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[247]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[248]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[249]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 6
	mapa[250]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[251]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[252]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[253]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[254]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[255]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[256]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[257]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[258]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[259]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[260]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[261]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[262]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[263]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[264]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[265]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[266]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[267]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[268]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[269]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[270]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[271]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[272]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[273]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[274]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[275]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[276]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[277]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[278]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[279]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[280]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[281]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[282]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[283]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[284]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[285]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[286]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[287]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[288]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[289]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[290]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[291]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[292]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[293]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[294]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[295]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[296]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[297]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[298]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[299]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LiNEA 7
	mapa[300]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[301]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[302]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[303]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[304]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[305]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[306]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[307]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[308]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[309]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[310]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[311]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[312]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[313]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[314]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[315]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[316]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[317]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[318]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[319]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[320]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[321]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[322]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[323]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[324]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[325]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[326]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[327]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[328]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[329]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[330]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[331]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[332]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[333]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[334]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[335]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[336]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[337]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[338]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[339]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[340]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[341]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[342]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[343]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[344]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[345]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[346]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[347]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true); //TRONCO
	mapa[348]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[349]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 8
	mapa[350]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[351]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[352]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[353]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[354]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[355]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[356]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[357]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[358]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[359]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[360]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[361]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[362]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[363]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[364]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[365]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[366]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[367]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[368]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[369]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[370]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[371]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[372]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[373]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[374]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[375]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[376]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[377]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[378]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[379]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[380]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[381]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[382]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[383]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[384]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[385]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[386]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[387]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[388]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[389]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[390]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[391]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[392]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[393]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[394]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[395]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[396]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[397]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[398]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[399]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 9
	mapa[400]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[401]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[402]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[403]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[404]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[405]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[406]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[407]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[408]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[409]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[410]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[411]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[412]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[413]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[414]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[415]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[416]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[417]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[418]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[419]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[420]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[421]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[422]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[423]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[424]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[425]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[426]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[427]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[428]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[429]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[430]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[431]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[432]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[433]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[434]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[435]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[436]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[437]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[438]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[439]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[440]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[441]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[442]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[443]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[444]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[445]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[446]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[447]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[448]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[449]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 10
	mapa[450]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[451]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[452]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[453]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[454]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[455]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[456]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[457]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[458]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[459]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[460]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[461]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[462]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[463]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[464]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[465]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[466]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[467]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[468]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[469]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[470]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[471]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[472]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[473]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[474]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[475]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[476]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[477]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[478]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[479]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[480]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[481]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[482]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[483]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[484]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[485]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[486]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[487]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[488]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[489]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[490]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[491]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[492]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[493]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[494]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[495]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[496]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[497]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[498]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[499]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 11
	mapa[500]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[501]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[502]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[503]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[504]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[505]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[506]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[507]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[508]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[509]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[510]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[511]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[512]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[513]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[514]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[515]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[516]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[517]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[518]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[519]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[520]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[521]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[522]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[523]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[524]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[525]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[526]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[527]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[528]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[529]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[530]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[531]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[532]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[533]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[534]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[535]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[536]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[537]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[538]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[539]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[540]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[541]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[542]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[543]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[544]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[545]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[546]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[547]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[548]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[549]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 12
	mapa[550]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[551]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[552]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[553]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[554]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[555]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[556]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[557]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[558]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[559]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[560]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[561]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[562]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[563]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[564]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[565]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[566]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[567]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[568]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[569]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[570]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[571]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[572]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[573]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[574]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[575]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[576]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[577]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[578]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[579]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[580]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[581]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[582]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[583]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[584]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[585]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[586]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[587]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[588]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[589]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[590]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[591]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[592]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[593]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[594]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[595]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[596]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[597]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[598]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[599]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 13
	mapa[600]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[601]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);
	mapa[602]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[603]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[604]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[605]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[606]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[607]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[608]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[609]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[610]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[611]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[612]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[613]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[614]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[615]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[616]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[617]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[618]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[619]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[620]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[621]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[622]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[623]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[624]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[625]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[626]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[627]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[628]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[629]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[630]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[631]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[632]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[633]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[634]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[635]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[636]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[637]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[638]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[639]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[640]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[641]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[642]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[643]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[644]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[645]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[646]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[647]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[648]->Dibujar_Imagen(g, bmp_mapa, 9, 3, false);//FLORES
	mapa[649]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 14
	mapa[650]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[651]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[652]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[653]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[654]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[655]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[656]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[657]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[658]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[659]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[660]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[661]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[662]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[663]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[664]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[665]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[666]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[667]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[668]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[669]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[670]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[671]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[672]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[673]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[674]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[675]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[676]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[677]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[678]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[679]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[680]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[681]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[682]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[683]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[684]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[685]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[686]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[687]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[688]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[689]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[690]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[691]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[692]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[693]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[694]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[695]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[696]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[697]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false); //TRONCO
	mapa[698]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);//FLORES
	mapa[699]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 15
	mapa[700]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[701]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[702]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[703]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[704]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[705]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[706]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[707]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[708]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[709]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[710]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[711]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[712]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[713]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[714]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[715]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[716]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[717]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[718]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[719]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[720]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[721]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[722]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[723]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[724]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[725]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[726]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[727]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[728]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[729]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[730]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[731]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[732]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[733]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[734]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[735]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[736]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[737]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[738]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[739]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[740]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[741]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[742]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[743]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[744]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[745]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[746]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[747]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[748]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[749]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 16
	mapa[750]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[751]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[752]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[753]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[754]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[755]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[756]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[757]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[758]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[759]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[760]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[761]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[762]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[763]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[764]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[765]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[766]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[767]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[768]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[769]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[770]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[771]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[772]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[773]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[774]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[775]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[776]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[777]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[778]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[779]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[780]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[781]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[782]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[783]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[784]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[785]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[786]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[787]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[788]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[789]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[790]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[791]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[792]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[793]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[794]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[795]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[796]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[797]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[798]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[799]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//Linea 17
	mapa[800]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[801]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[802]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[803]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[804]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[805]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[806]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[807]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[808]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[809]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[810]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[811]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[812]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[813]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[814]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[815]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[816]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[817]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[818]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[819]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[820]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[821]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[822]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[823]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[824]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[825]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[826]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[827]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[828]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[829]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[830]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[831]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[832]->Dibujar_Imagen(g, bmp_mapa, 12, 3, true);
	mapa[833]->Dibujar_Imagen(g, bmp_mapa, 12, 4, true);
	mapa[834]->Dibujar_Imagen(g, bmp_mapa, 12, 4, true);
	mapa[835]->Dibujar_Imagen(g, bmp_mapa, 12, 4, true);
	mapa[836]->Dibujar_Imagen(g, bmp_mapa, 12, 4, true);
	mapa[837]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[838]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[839]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[840]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[841]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[842]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[843]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[844]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[845]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[846]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[847]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[848]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[849]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 18
	mapa[850]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[851]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[852]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[853]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[854]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[855]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[856]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[857]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[858]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[859]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[860]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[861]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[862]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[863]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[864]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[865]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[866]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[867]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[868]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[869]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[870]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[871]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[872]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[873]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[874]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[875]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[876]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[877]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[878]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[879]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[880]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[881]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[882]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[883]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[884]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[885]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[886]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[887]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[888]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[889]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[890]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[891]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[892]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[893]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[894]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[895]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[896]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[897]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[898]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[899]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	//LINEA 19
	mapa[900]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[901]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[902]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[903]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[904]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[905]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[906]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[907]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[908]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[909]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[910]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[911]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[912]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[913]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[914]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[915]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[916]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[917]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[918]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[919]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[920]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[921]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[922]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[923]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[924]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[925]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[926]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[927]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[928]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[929]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[930]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[931]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[932]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[933]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[934]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[935]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[936]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[937]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[938]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[939]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[940]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[941]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[942]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[943]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[944]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[945]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[946]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[947]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[948]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[949]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 20

	mapa[950]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[951]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[952]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[953]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[954]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[955]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[956]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[957]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[958]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[959]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[960]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[961]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[962]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[963]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[964]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[965]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[966]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[967]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[968]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[969]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[970]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[971]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[972]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[973]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[974]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[975]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[976]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[977]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[978]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[979]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[980]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[981]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[982]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[983]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[984]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[985]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[986]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[987]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[988]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[989]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[990]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[991]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[992]->Dibujar_Imagen(g, bmp_mapa, 8, 0, false);
	mapa[993]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[994]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[995]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[996]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[997]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[998]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[999]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 21

	mapa[1000]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1001]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1002]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1003]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1004]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1005]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1006]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1007]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1008]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1009]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1010]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1011]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1012]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1013]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1014]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1015]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1016]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1017]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1018]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1019]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1020]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1021]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1022]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1023]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1024]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1025]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1026]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1027]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1028]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1029]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1030]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1031]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1032]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[1033]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[1034]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[1035]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[1036]->Dibujar_Imagen(g, bmp_mapa, 0, 0, true);
	mapa[1037]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1038]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1039]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1040]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1041]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1042]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1043]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1044]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1045]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1046]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1047]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[1048]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[1049]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 21

	mapa[1050]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1051]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1052]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1053]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1054]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1055]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1056]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1057]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1058]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1059]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1060]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1061]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1062]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1063]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1064]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1065]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1066]->Dibujar_Imagen(g, bmp_mapa, 12, 3, false);
	mapa[1067]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[1068]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[1069]->Dibujar_Imagen(g, bmp_mapa, 12, 4, false);
	mapa[1070]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1071]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1072]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1073]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1074]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1075]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1076]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1077]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1078]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1079]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1080]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1081]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1082]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1083]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1084]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1085]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1086]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1087]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1088]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1089]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1090]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1091]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1092]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1093]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1094]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1095]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1096]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1097]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[1098]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[1099]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 22
	mapa[1100]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1101]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1102]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1103]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1104]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1105]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1106]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1107]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1108]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1109]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1110]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1111]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1112]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1113]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1114]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1115]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1116]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1117]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1118]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1119]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1120]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1121]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1122]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1123]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1124]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1125]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1126]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1127]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1128]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1129]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1130]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1131]->Dibujar_Imagen(g, bmp_mapa, 9, 5, false);
	mapa[1132]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1133]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1134]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1135]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1136]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1137]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1138]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1139]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1140]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1141]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1142]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1143]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1144]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1145]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1146]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1147]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[1148]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[1149]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 23
	mapa[1150]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1151]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1152]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1153]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1154]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1155]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1156]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1157]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1158]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1159]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1160]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1161]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1162]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1163]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1164]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1165]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1166]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1167]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1168]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1169]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1170]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1171]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1172]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1173]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1174]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1175]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1176]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1177]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1178]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1179]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1180]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1181]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1182]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1183]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1184]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1185]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1186]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1187]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1188]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1189]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1190]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1191]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1192]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1193]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1194]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1195]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1196]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1197]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[1198]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[1199]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//LINEA 24
	mapa[1200]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1201]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1202]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1203]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1204]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1205]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1206]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1207]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1208]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1209]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1210]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1211]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1212]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1213]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1214]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1215]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1216]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1217]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1218]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1219]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1220]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1221]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1222]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1223]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1224]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1225]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1226]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1227]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1228]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1229]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1230]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1231]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1232]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1233]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1234]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1235]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1236]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1237]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1238]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1239]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1240]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1241]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1242]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1243]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1244]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1245]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1246]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);
	mapa[1247]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false); //TRONCO
	mapa[1248]->Dibujar_Imagen(g, bmp_mapa, 0, 0, false);//FLORES
	mapa[1249]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

	//FINAL LINEa

	mapa[1250]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);
	mapa[1251]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1252]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1253]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1254]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1255]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1256]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1257]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1258]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1259]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1260]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1261]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1262]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1263]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1264]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1265]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1266]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1267]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1268]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1269]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1270]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1271]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1272]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1273]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1274]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1275]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1276]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1277]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1278]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1279]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1280]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1281]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1282]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1283]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1284]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1285]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1286]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1287]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1288]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1289]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1290]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1291]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1292]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1293]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1294]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1295]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1296]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);
	mapa[1297]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false); //TRONCO
	mapa[1298]->Dibujar_Imagen(g, bmp_mapa, 0, 3, false);//FLORES
	mapa[1299]->Dibujar_Imagen(g, bmp_mapa, 0, 3, true);

}
bool Movimiento::Colision_Mapa(Entidad* obj1, Entidad* obj2) {
	Rectangle rect1 = Rectangle(obj1->retornar_X(),
		obj1->retornar_Y(),
		obj1->retornar_Ancho(),
		obj1->retornar_Alto());
	Rectangle rect2 = Rectangle(obj2->retornar_X(),
		obj2->retornar_Y(),
		obj2->retornar_Ancho() / 1.5,
		obj2->retornar_Alto() / 2);
	return rect1.IntersectsWith(rect2);
}
 

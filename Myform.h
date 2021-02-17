#pragma once
#include "Movimiento.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			bmp_monigote = gcnew Bitmap("protagonista.png");
			bmp_mapa = gcnew Bitmap("sprite_mapa.png");
			bmp_azul = gcnew Bitmap("azul.png");
			bmp_morado = gcnew Bitmap("morado.png");
			bmp_naranja = gcnew Bitmap("naranja.png");
			bmp_verde = gcnew Bitmap("verde.png");
			obj_movimiento = new Movimiento();
			srand(time_t(NULL));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete obj_movimiento;
			delete bmp_monigote;
			delete bmp_mapa; {
				delete bmp_azul;
				delete bmp_verde;
				delete bmp_naranja;
				delete bmp_morado;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


		Movimiento* obj_movimiento;
		Bitmap^ bmp_monigote;
		Bitmap^ bmp_mapa;
		Bitmap^ bmp_azul;
		Bitmap^ bmp_naranja;
		Bitmap^ bmp_verde;
		Bitmap^ bmp_morado;

	private: System::Windows::Forms::Timer^ timer1;
		  

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 402);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//CREAMOS UNA REGION ORIGINAL DE TRABAJO
		Graphics^ g = CreateGraphics();
		//DUPLICAMOS EL AREA GRAFICA EN MEMORIA RAM
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		//USAMOS EL BUFFER CREADO EN MEMORIA RAM

		obj_movimiento->Run(bmp_monigote, bf->Graphics, bmp_mapa, bmp_azul);

		//ACTUALIZAMOS EL GRAPHICS ORIGINAL CON LO TRABAJADO EN RAM
		bf->Render(g);

		//LIBERAMOS
		delete bf;
		delete espacio;
		delete g;

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Left)
			obj_movimiento->Cambiar_Direccion_Monigote(direccion::izquierda);
		if (e->KeyCode == Keys::Right)
			obj_movimiento->Cambiar_Direccion_Monigote(direccion::derecha);
		if (e->KeyCode == Keys::Up)
			obj_movimiento->Cambiar_Direccion_Monigote(direccion::arriba);
		if (e->KeyCode == Keys::Down)
			obj_movimiento->Cambiar_Direccion_Monigote(direccion::abajo);

		if (e->KeyCode == Keys::Escape)
			Close();
	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		Graphics^ g = CreateGraphics();
		if (toupper(e->KeyChar) == 'I') {
			obj_movimiento->Init(bmp_monigote, g, bmp_mapa,bmp_azul);
			timer1->Enabled = true;
		}
		if (toupper(e->KeyChar) == 'P')
			timer1->Enabled = false;
		if (toupper(e->KeyChar) == 'C')
			timer1->Enabled = true;
		delete g;
	}
	};
}

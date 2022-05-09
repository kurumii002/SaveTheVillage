#pragma once
#include "FrmSeguridad.h"
#include "FrmSalud.h"
#include "FrmConfig.h"
#include "FrmConfig2.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmNivel
	/// </summary>
	public ref class FrmNivel : public System::Windows::Forms::Form
	{
	public:
		FrmNivel(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmNivel()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnSeguridad;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmNivel::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnSeguridad = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(130, 219);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Salud";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FrmNivel::button1_Click);
			// 
			// btnSeguridad
			// 
			this->btnSeguridad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSeguridad->Location = System::Drawing::Point(304, 219);
			this->btnSeguridad->Name = L"btnSeguridad";
			this->btnSeguridad->Size = System::Drawing::Size(129, 47);
			this->btnSeguridad->TabIndex = 1;
			this->btnSeguridad->Text = L"Seguridad";
			this->btnSeguridad->UseVisualStyleBackColor = true;
			this->btnSeguridad->Click += gcnew System::EventHandler(this, &FrmNivel::btnSeguridad_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(144, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(279, 37);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Escoge el mundo";
			// 
			// FrmNivel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(567, 345);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnSeguridad);
			this->Controls->Add(this->button1);
			this->Name = L"FrmNivel";
			this->Text = L"Nivel";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmConfig^ formConfig = gcnew FrmConfig;
		this->Hide();
		formConfig->ShowDialog(); //abre el otro formulario (juego)
		this->Show();

		//FrmSalud^ formSalud = gcnew FrmSalud;
		//formSalud->Show(); //abre el otro formulario (juego)
	}
	private: System::Void btnSeguridad_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmConfig2^ formConfig2 = gcnew FrmConfig2;
		this->Hide();
		formConfig2->ShowDialog(); //abre el otro formulario (juego)
		this->Show();
		
		//FrmSeguridad^ formseguri = gcnew FrmSeguridad;
		//formseguri->Show();
	}
	};
}

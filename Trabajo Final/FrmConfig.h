#pragma once
#include "FrmSalud.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmConfig
	/// </summary>
	public ref class FrmConfig : public System::Windows::Forms::Form
	{
	public:
		FrmConfig(void)
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
		~FrmConfig()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnIniciar;


	private: System::Windows::Forms::NumericUpDown^ txtnumEnemigos;
	private: System::Windows::Forms::NumericUpDown^ txtnumAliados;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->txtnumEnemigos = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtnumAliados = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtnumEnemigos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtnumAliados))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enemigos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Aliados:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(66, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Configuración";
			// 
			// btnIniciar
			// 
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->Location = System::Drawing::Point(87, 142);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(75, 37);
			this->btnIniciar->TabIndex = 5;
			this->btnIniciar->Text = L"Iniciar";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &FrmConfig::btnIniciar_Click);
			// 
			// txtnumEnemigos
			// 
			this->txtnumEnemigos->Location = System::Drawing::Point(121, 65);
			this->txtnumEnemigos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->txtnumEnemigos->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->txtnumEnemigos->Name = L"txtnumEnemigos";
			this->txtnumEnemigos->Size = System::Drawing::Size(120, 20);
			this->txtnumEnemigos->TabIndex = 8;
			this->txtnumEnemigos->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// txtnumAliados
			// 
			this->txtnumAliados->Location = System::Drawing::Point(121, 101);
			this->txtnumAliados->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->txtnumAliados->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->txtnumAliados->Name = L"txtnumAliados";
			this->txtnumAliados->Size = System::Drawing::Size(120, 20);
			this->txtnumAliados->TabIndex = 9;
			this->txtnumAliados->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// FrmConfig
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(257, 193);
			this->Controls->Add(this->txtnumAliados);
			this->Controls->Add(this->txtnumEnemigos);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"FrmConfig";
			this->Text = L"Configuración";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtnumEnemigos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtnumAliados))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmSalud^ frm = gcnew FrmSalud(Convert::ToInt32(txtnumEnemigos->Value), Convert::ToInt32(txtnumAliados->Value));
		this->Hide();
		frm->ShowDialog();
		delete frm;
		this->Show();
	}
	};
}

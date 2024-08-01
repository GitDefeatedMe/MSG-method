#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <myMath.h>
#include<vector>



double uxx(double x, double y)
{
	return M_PI * M_PI * y * y * exp(pow(sin(M_PI * x * y), 2.)) * pow(sin(2. * M_PI * x * y), 2.) + 2 * M_PI * M_PI * y * y * exp(pow(sin(M_PI * x * y), 2.)) * cos(2. * M_PI * x * y);
}
double uyy(double x, double y)
{
	return M_PI * M_PI * x * x * exp(pow(sin(M_PI * x * y), 2.)) * pow(sin(2. * M_PI * x * y), 2.) + 2 * M_PI * M_PI * x * x * exp(pow(sin(M_PI * x * y), 2.)) * cos(2. * M_PI * x * y);
}
double f(double x, double y)
{
	return -uxx(x, y) - uyy(x, y);
}
double u(double x, double y)
{
	return exp(pow(sin(M_PI * x * y), 2.));
}

int N = 200, M = 200, iterations = 1000;
int iterations_end = 10;
double eps = 1e-10, eps_cur = 1;
double nev, R0;

bool end_sucsess = true;
Vector V;


double a = 0, b = 2, c = 0, d = 1;
double h;
double k;


namespace msgUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;




	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ out_n;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ out_Nmax;

	private: System::Windows::Forms::TextBox^ out_epsM;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ out_Nmet;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ out_R;

	private: System::Windows::Forms::TextBox^ out_m;
	private: System::Windows::Forms::TextBox^ out_epsMetRes;


	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ in_m;

	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ in_n;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ in_Nmax;

	private: System::Windows::Forms::TextBox^ in_eps;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::CheckBox^ useTh;

	private: System::Windows::Forms::DataGridView^ dataV;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataU;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::TextBox^ out_maxY;

	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::TextBox^ out_maxX;

	private: System::Windows::Forms::TextBox^ out_eps;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::TextBox^ out_R0;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::TextBox^ out_y;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::TextBox^ out_x;



	
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->out_y = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->out_x = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->out_R0 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->out_maxY = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->out_maxX = (gcnew System::Windows::Forms::TextBox());
			this->out_eps = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->out_Nmet = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->out_R = (gcnew System::Windows::Forms::TextBox());
			this->out_m = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->out_epsMetRes = (gcnew System::Windows::Forms::TextBox());
			this->out_n = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->out_Nmax = (gcnew System::Windows::Forms::TextBox());
			this->out_epsM = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->in_m = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->in_n = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->in_Nmax = (gcnew System::Windows::Forms::TextBox());
			this->in_eps = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->useTh = (gcnew System::Windows::Forms::CheckBox());
			this->dataV = (gcnew System::Windows::Forms::DataGridView());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->dataU = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataV))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataU))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label32);
			this->panel1->Controls->Add(this->out_y);
			this->panel1->Controls->Add(this->label33);
			this->panel1->Controls->Add(this->out_x);
			this->panel1->Controls->Add(this->label31);
			this->panel1->Controls->Add(this->label30);
			this->panel1->Controls->Add(this->out_R0);
			this->panel1->Controls->Add(this->label29);
			this->panel1->Controls->Add(this->label28);
			this->panel1->Controls->Add(this->label26);
			this->panel1->Controls->Add(this->out_maxY);
			this->panel1->Controls->Add(this->label27);
			this->panel1->Controls->Add(this->out_maxX);
			this->panel1->Controls->Add(this->out_eps);
			this->panel1->Controls->Add(this->label25);
			this->panel1->Controls->Add(this->label24);
			this->panel1->Controls->Add(this->label23);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->out_Nmet);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->out_R);
			this->panel1->Controls->Add(this->out_m);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->out_epsMetRes);
			this->panel1->Controls->Add(this->out_n);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->out_Nmax);
			this->panel1->Controls->Add(this->out_epsM);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(17, 252);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(470, 592);
			this->panel1->TabIndex = 0;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label32->Location = System::Drawing::Point(184, 458);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(27, 16);
			this->label32->TabIndex = 38;
			this->label32->Text = L"y = ";
			// 
			// out_y
			// 
			this->out_y->Enabled = false;
			this->out_y->Location = System::Drawing::Point(216, 458);
			this->out_y->Name = L"out_y";
			this->out_y->Size = System::Drawing::Size(97, 20);
			this->out_y->TabIndex = 37;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label33->Location = System::Drawing::Point(28, 457);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(26, 16);
			this->label33->TabIndex = 36;
			this->label33->Text = L"x = ";
			// 
			// out_x
			// 
			this->out_x->Enabled = false;
			this->out_x->Location = System::Drawing::Point(60, 457);
			this->out_x->Name = L"out_x";
			this->out_x->Size = System::Drawing::Size(97, 20);
			this->out_x->TabIndex = 35;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label31->Location = System::Drawing::Point(28, 557);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(342, 16);
			this->label31->TabIndex = 34;
			this->label31->Text = L"Для невязки СЛАУ использована евклидова норма";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label30->Location = System::Drawing::Point(28, 535);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(74, 16);
			this->label30->TabIndex = 33;
			this->label30->Text = L"||R_0(N)|| = ";
			// 
			// out_R0
			// 
			this->out_R0->Enabled = false;
			this->out_R0->Location = System::Drawing::Point(108, 534);
			this->out_R0->Name = L"out_R0";
			this->out_R0->Size = System::Drawing::Size(131, 20);
			this->out_R0->TabIndex = 32;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label29->Location = System::Drawing::Point(28, 519);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(348, 16);
			this->label29->TabIndex = 31;
			this->label29->Text = L"Невязка СЛАУ на начальном приближении ||R_0(N)|| ";
			// 
			// label28
			// 
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->Location = System::Drawing::Point(28, 484);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(340, 35);
			this->label28->TabIndex = 30;
			this->label28->Text = L"В качестве начального приближения использовано нулевое начальное приближение";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->Location = System::Drawing::Point(184, 433);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(23, 16);
			this->label26->TabIndex = 29;
			this->label26->Text = L"j = ";
			// 
			// out_maxY
			// 
			this->out_maxY->Enabled = false;
			this->out_maxY->Location = System::Drawing::Point(216, 433);
			this->out_maxY->Name = L"out_maxY";
			this->out_maxY->Size = System::Drawing::Size(97, 20);
			this->out_maxY->TabIndex = 28;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label27->Location = System::Drawing::Point(28, 432);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(23, 16);
			this->label27->TabIndex = 27;
			this->label27->Text = L"i = ";
			// 
			// out_maxX
			// 
			this->out_maxX->Enabled = false;
			this->out_maxX->Location = System::Drawing::Point(60, 432);
			this->out_maxX->Name = L"out_maxX";
			this->out_maxX->Size = System::Drawing::Size(97, 20);
			this->out_maxX->TabIndex = 26;
			// 
			// out_eps
			// 
			this->out_eps->Enabled = false;
			this->out_eps->Location = System::Drawing::Point(277, 374);
			this->out_eps->Name = L"out_eps";
			this->out_eps->Size = System::Drawing::Size(132, 20);
			this->out_eps->TabIndex = 25;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->Location = System::Drawing::Point(28, 374);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(244, 16);
			this->label25->TabIndex = 24;
			this->label25->Text = L"задача решена с погрешностью ε1 = ";
			// 
			// label24
			// 
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->Location = System::Drawing::Point(28, 397);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(340, 35);
			this->label24->TabIndex = 23;
			this->label24->Text = L"Максимальное отклонение точного и численного решений наблюдается в узле\r\n";
			// 
			// label23
			// 
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(28, 339);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(340, 35);
			this->label23->TabIndex = 22;
			this->label23->Text = L"Тестовая задача должна быть решена с погрешностью не более ε = 0.5⋅10 –6;";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(28, 300);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(60, 16);
			this->label15->TabIndex = 21;
			this->label15->Text = L"||R(N)|| = ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(28, 261);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 16);
			this->label14->TabIndex = 20;
			this->label14->Text = L"ε(N) =";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(28, 217);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 16);
			this->label4->TabIndex = 19;
			this->label4->Text = L"N = ";
			// 
			// out_Nmet
			// 
			this->out_Nmet->Enabled = false;
			this->out_Nmet->Location = System::Drawing::Point(64, 217);
			this->out_Nmet->Name = L"out_Nmet";
			this->out_Nmet->Size = System::Drawing::Size(102, 20);
			this->out_Nmet->TabIndex = 16;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(184, 98);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 16);
			this->label13->TabIndex = 7;
			this->label13->Text = L"y m = ";
			// 
			// out_R
			// 
			this->out_R->Enabled = false;
			this->out_R->Location = System::Drawing::Point(91, 300);
			this->out_R->Name = L"out_R";
			this->out_R->Size = System::Drawing::Size(131, 20);
			this->out_R->TabIndex = 18;
			// 
			// out_m
			// 
			this->out_m->Enabled = false;
			this->out_m->Location = System::Drawing::Point(226, 98);
			this->out_m->Name = L"out_m";
			this->out_m->Size = System::Drawing::Size(97, 20);
			this->out_m->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(28, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"x n = ";
			// 
			// out_epsMetRes
			// 
			this->out_epsMetRes->Enabled = false;
			this->out_epsMetRes->Location = System::Drawing::Point(76, 261);
			this->out_epsMetRes->Name = L"out_epsMetRes";
			this->out_epsMetRes->Size = System::Drawing::Size(149, 20);
			this->out_epsMetRes->TabIndex = 17;
			// 
			// out_n
			// 
			this->out_n->Enabled = false;
			this->out_n->Location = System::Drawing::Point(70, 98);
			this->out_n->Name = L"out_n";
			this->out_n->Size = System::Drawing::Size(97, 20);
			this->out_n->TabIndex = 0;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(28, 323);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(342, 16);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Для невязки СЛАУ использована евклидова норма";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(28, 284);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(264, 16);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Схема (СЛАУ) решена с невязкой ||R(N)||";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(28, 240);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(301, 16);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Достигнута точность итерационного метода";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(28, 200);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(314, 16);
			this->label9->TabIndex = 12;
			this->label9->Text = L"На решение схемы (СЛАУ) затрачено итераций";
			// 
			// out_Nmax
			// 
			this->out_Nmax->Enabled = false;
			this->out_Nmax->Location = System::Drawing::Point(213, 176);
			this->out_Nmax->Name = L"out_Nmax";
			this->out_Nmax->Size = System::Drawing::Size(111, 20);
			this->out_Nmax->TabIndex = 11;
			// 
			// out_epsM
			// 
			this->out_epsM->Enabled = false;
			this->out_epsM->Location = System::Drawing::Point(176, 153);
			this->out_epsM->Name = L"out_epsM";
			this->out_epsM->Size = System::Drawing::Size(147, 20);
			this->out_epsM->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(28, 176);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(179, 16);
			this->label8->TabIndex = 9;
			this->label8->Text = L"по числу итераций Nmax =";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(28, 153);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(138, 16);
			this->label7->TabIndex = 8;
			this->label7->Text = L"по точности ε_мет =";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(28, 137);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(147, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"критерии остановки :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(28, 121);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(218, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Метод сопряженных градиентов";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(149, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Справка";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(28, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(340, 35);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Для решения тестовой задачи использована сетка-основа с числом разбиений по";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(172, 28);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(41, 16);
			this->label16->TabIndex = 12;
			this->label16->Text = L"y m = ";
			// 
			// in_m
			// 
			this->in_m->Location = System::Drawing::Point(214, 28);
			this->in_m->Name = L"in_m";
			this->in_m->Size = System::Drawing::Size(97, 20);
			this->in_m->TabIndex = 11;
			this->in_m->Text = L"40";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(16, 28);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(36, 16);
			this->label17->TabIndex = 10;
			this->label17->Text = L"x n = ";
			// 
			// in_n
			// 
			this->in_n->Location = System::Drawing::Point(58, 28);
			this->in_n->Name = L"in_n";
			this->in_n->Size = System::Drawing::Size(97, 20);
			this->in_n->TabIndex = 8;
			this->in_n->Text = L"40";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(16, 5);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(140, 16);
			this->label18->TabIndex = 9;
			this->label18->Text = L"число разбиений по";
			// 
			// in_Nmax
			// 
			this->in_Nmax->Location = System::Drawing::Point(201, 90);
			this->in_Nmax->Name = L"in_Nmax";
			this->in_Nmax->Size = System::Drawing::Size(111, 20);
			this->in_Nmax->TabIndex = 17;
			this->in_Nmax->Text = L"1000";
			// 
			// in_eps
			// 
			this->in_eps->Location = System::Drawing::Point(160, 67);
			this->in_eps->Name = L"in_eps";
			this->in_eps->Size = System::Drawing::Size(152, 20);
			this->in_eps->TabIndex = 16;
			this->in_eps->Text = L"1e-7";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(16, 90);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(179, 16);
			this->label19->TabIndex = 15;
			this->label19->Text = L"по числу итераций Nmax =";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(16, 67);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(138, 16);
			this->label20->TabIndex = 14;
			this->label20->Text = L"по точности ε_мет =";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(16, 51);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(147, 16);
			this->label21->TabIndex = 13;
			this->label21->Text = L"критерии остановки :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(359, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 42);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(16, 110);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(150, 16);
			this->label22->TabIndex = 19;
			this->label22->Text = L"Использовать потоки";
			// 
			// useTh
			// 
			this->useTh->AutoSize = true;
			this->useTh->Location = System::Drawing::Point(180, 112);
			this->useTh->Name = L"useTh";
			this->useTh->Size = System::Drawing::Size(15, 14);
			this->useTh->TabIndex = 20;
			this->useTh->UseVisualStyleBackColor = true;
			// 
			// dataV
			// 
			this->dataV->AllowUserToAddRows = false;
			this->dataV->AllowUserToDeleteRows = false;
			this->dataV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataV->Location = System::Drawing::Point(538, 44);
			this->dataV->Name = L"dataV";
			this->dataV->ReadOnly = true;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->NullValue = L"0";
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataV->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataV->RowTemplate->ReadOnly = true;
			this->dataV->Size = System::Drawing::Size(827, 380);
			this->dataV->TabIndex = 21;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->useTh);
			this->panel2->Controls->Add(this->in_n);
			this->panel2->Controls->Add(this->label22);
			this->panel2->Controls->Add(this->label17);
			this->panel2->Controls->Add(this->in_m);
			this->panel2->Controls->Add(this->in_Nmax);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->in_eps);
			this->panel2->Controls->Add(this->label21);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Location = System::Drawing::Point(17, 44);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(495, 137);
			this->panel2->TabIndex = 22;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(359, 80);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 39);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(17, 213);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(495, 23);
			this->progressBar1->TabIndex = 23;
			// 
			// dataU
			// 
			this->dataU->AllowUserToAddRows = false;
			this->dataU->AllowUserToDeleteRows = false;
			this->dataU->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataU->Location = System::Drawing::Point(538, 436);
			this->dataU->Name = L"dataU";
			this->dataU->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->NullValue = L"0";
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataU->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataU->RowTemplate->ReadOnly = true;
			this->dataU->Size = System::Drawing::Size(827, 380);
			this->dataU->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1386, 856);
			this->Controls->Add(this->dataU);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->dataV);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"3821Б1ПМоп1 Василевский А.П. Ступень 3";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataV))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataU))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// ФОНОВАЯ РАБОТА МСГ

	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {


		N = Convert::ToInt32(in_n->Text);
		M = Convert::ToInt32(in_m->Text);
		iterations = Convert::ToInt32(in_Nmax->Text);

		eps = Convert::ToDouble(this->in_eps->Text->Replace(L".", L","));

		if (N % 2 != 0)
		{
			useTh->Enabled = true;
			end_sucsess = false;
			MessageBox::Show(this, "Число разбиений по x должно быть кратным 2", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (M % 2 != 0)
		{
			useTh->Enabled = true;
			end_sucsess = false;
			MessageBox::Show(this, "Число разбиений по x должно быть кратным 2", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// что-то очень медленное ...

		h = (b - a) / (double)N;
		k = (d - c) / (double)M;

		double h2 = 1. / (h * h), k2 = 1. / (k * k);

		Vector F((N - 1) * (M - 1));

		// инициализируем правую часть
		for (int j = 0; j < M / 2; j++)
		{
			for (int i = N / 2; i < (N - 1); i++)
			{

				double x = a + h * (i + 1), y = c + k * (j + 1);
				F[i + j * (N - 1)] = -f(x, y);

				if (i == N / 2)
				{
					F[i + j * (N - 1)] -= u(x - h, y) * h2;
				}
				if (j == 0)
				{
					F[i + j * (N - 1)] -= u(x, y - k) * k2;
				}
				if (i + 1 == N - 1)
				{
					F[i + j * (N - 1)] -= u(x + h, y) * h2;
				}

			}
		}
		for (int j = M / 2; j < (M - 1); j++)
		{
			for (int i = 0; i < (N - 1); i++)
			{
				double x = a + h * (i + 1), y = c + k * (j + 1);
				F[i + j * (N - 1)] = -f(x, y);

				if (i < N / 2 && j == M / 2)
				{
					F[i + j * (N - 1)] -= u(x, y - k) * k2;
				}
				if (i + 1 == N - 1)
				{
					F[i + j * (N - 1)] -= u(x + h, y) * h2;
				}
				if (j + 1 == M - 1)
				{
					F[i + j * (N - 1)] -= u(x, y + k) * k2;
				}
				if (i == 0)
				{
					F[i + j * (N - 1)] -= u(x - h, y) * h2;
				}
			}
		}


		AbstractMatrix A(N, M, a, b, c, d);

		Vector xs((N - 1) * (M - 1)), xs_1((N - 1) * (M - 1));
		Vector hs_1, hs;
		double alpha_s, betta_s;
		Vector rs = A * xs + -F;
		R0 = F.Norm();


		// Первыый шаг
		iterations_end = 1;
		hs = -(A * xs + -F);
		alpha_s = -Scalar(A * xs + -F, hs) / Scalar(A * hs, hs);

		xs = xs_1 + hs * alpha_s;

		eps_cur = (xs + -xs_1).Norm();
		nev = A.ResidualThreading(xs, F, 6).Norm();

		// n шаг
		iterations_end = 2;
		for (; iterations_end <= iterations && eps_cur > eps; iterations_end++)
		{
			backgroundWorker1->ReportProgress((int)((float)iterations_end / (float)iterations * 100));
			if (backgroundWorker1->CancellationPending)
			{
				return;
			}

			xs_1 = xs;
			hs_1 = hs;

			if (!useTh->Checked)
			{
				rs = A * xs_1 + -F;

				betta_s = Scalar(A * hs_1, rs) / Scalar(A * hs_1, hs_1);
				hs = -rs + (hs_1 * betta_s);

				alpha_s = -Scalar(A * xs_1 + -F, hs) / Scalar(A * hs, hs);

				xs = xs_1 + hs * alpha_s;

				eps_cur = (hs * alpha_s).Norm();
				
			}
			else
			{
				rs = A.ResidualThreading(xs_1, F, 6);
				Vector Ahs1 = A.MultyplyThreading(hs_1, 6);


				betta_s = Ahs1.MultiplyThread(rs, 6) / Ahs1.MultiplyThread(hs_1, 6);
				hs = -rs + (hs_1 * betta_s);

				alpha_s = -rs.MultiplyThread(hs, 6) / (A.MultyplyThreading(hs, 6)).MultiplyThread(hs, 6);

				xs = xs_1 + hs * alpha_s;

				eps_cur = (hs * alpha_s).Norm();
			}

			// std::cout << "EPS " << iterations_end << " = " << eps_cur << '\n';
			nev = A.ResidualThreading(xs, F, 6).Norm();
			V = xs;
		}
	}
	private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
		progressBar1->Value = e->ProgressPercentage;
	}
	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
		if (!e->Cancelled && end_sucsess)
		{
			this->dataV->Rows->Clear();
			this->dataV->Columns->Clear();

			this->dataU->Rows->Clear();
			this->dataU->Columns->Clear();


			Vector res((N - 1) * (M - 1));

			{
				for (int i = 0; i < N - 1; i++)
				{
					this->dataV->Columns->Add(Convert::ToString(i + 1), Convert::ToString(i + 1));
					this->dataU->Columns->Add(Convert::ToString(i + 1), Convert::ToString(i + 1));
				}

				for (int j = M - 2; j >= 0; j--)
				{
					this->dataV->Rows->Add();
					this->dataV->Rows[(M - 2) - j]->HeaderCell->Value = Convert::ToString(j + 1);

					this->dataU->Rows->Add();
					this->dataU->Rows[(M - 2) - j]->HeaderCell->Value = Convert::ToString(j + 1);
				}

			}



			for (int j = M - 2; j >= 0; j--)
			{
				for (int i = 0; i < N - 1; i++)
				{
					if ((i >= N / 2 && i < N - 1 && j >= 0 && j < M / 2) ||
						(i >= 0 && i < N - 1 && j >= M / 2 && j < M - 1))
					{
						double x = a + h * (i + 1), y = c + k * (j + 1);

						res[i + j * (N - 1)] = V[i + j * (N - 1)] - u(x, y);
						


						{
							this->dataU->Rows[(M - 2) - j]->Cells[i]->Value = Convert::ToString(u(x, y));
							this->dataV->Rows[(M - 2) - j]->Cells[i]->Value = Convert::ToString(V[i + j * (N - 1)]);
						}
					}

				}
			}

			int maxNevInd = res.indNormMax();
			int i = maxNevInd % (N - 1);
			int j = maxNevInd / (N - 1);


			out_n->Text = in_n->Text;
			out_m->Text = in_m->Text;
			out_epsM->Text = in_eps->Text;
			out_Nmax->Text = in_Nmax->Text;
			out_Nmet->Text = Convert::ToString(iterations_end - 1);
			out_epsMetRes->Text = Convert::ToString(eps_cur);
			out_R->Text = Convert::ToString(nev);
			out_eps->Text = Convert::ToString(res.NormMax());
			out_R0->Text = Convert::ToString(R0);

			out_maxX->Text = Convert::ToString(i + 1);
			out_maxY->Text = Convert::ToString(j + 1);

			out_x->Text = Convert::ToString(h * (double)(i + 1));
			out_y->Text = Convert::ToString(k * (double)(j + 1));
		}
		progressBar1->Value = 0;
	}




		   // КНОПОЧКИ
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		end_sucsess = true;
		backgroundWorker1->RunWorkerAsync();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		end_sucsess = false;
		backgroundWorker1->CancelAsync();
	}
};
}

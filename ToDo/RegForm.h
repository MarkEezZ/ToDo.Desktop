#pragma once

namespace ToDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RegForm
	/// </summary>
	public ref class RegForm : public System::Windows::Forms::Form
	{
	public:
		RegForm(void)
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
		~RegForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelRegistration;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPassword1;
	private: System::Windows::Forms::Button^ buttonReg;

	private: System::Windows::Forms::TextBox^ textBoxPassword2;
	private: System::Windows::Forms::Label^ labelMsg;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonLogIn;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegForm::typeid));
			this->labelRegistration = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonReg = (gcnew System::Windows::Forms::Button());
			this->textBoxPassword2 = (gcnew System::Windows::Forms::TextBox());
			this->labelMsg = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonLogIn = (gcnew System::Windows::Forms::Button());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelRegistration
			// 
			this->labelRegistration->AutoSize = true;
			this->labelRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelRegistration->ForeColor = System::Drawing::Color::White;
			this->labelRegistration->Location = System::Drawing::Point(111, 45);
			this->labelRegistration->Name = L"labelRegistration";
			this->labelRegistration->Size = System::Drawing::Size(117, 20);
			this->labelRegistration->TabIndex = 0;
			this->labelRegistration->Text = L"Регистрация";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->BackColor = System::Drawing::Color::White;
			this->textBoxLogin->Location = System::Drawing::Point(103, 167);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(132, 20);
			this->textBoxLogin->TabIndex = 1;
			// 
			// textBoxPassword1
			// 
			this->textBoxPassword1->BackColor = System::Drawing::Color::White;
			this->textBoxPassword1->Location = System::Drawing::Point(103, 213);
			this->textBoxPassword1->Name = L"textBoxPassword1";
			this->textBoxPassword1->PasswordChar = '*';
			this->textBoxPassword1->Size = System::Drawing::Size(132, 20);
			this->textBoxPassword1->TabIndex = 2;
			// 
			// buttonReg
			// 
			this->buttonReg->BackColor = System::Drawing::Color::Black;
			this->buttonReg->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonReg->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonReg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonReg->ForeColor = System::Drawing::Color::White;
			this->buttonReg->Location = System::Drawing::Point(95, 369);
			this->buttonReg->Name = L"buttonReg";
			this->buttonReg->Size = System::Drawing::Size(140, 40);
			this->buttonReg->TabIndex = 3;
			this->buttonReg->Text = L"Зарегистрироваться";
			this->buttonReg->UseVisualStyleBackColor = false;
			this->buttonReg->Click += gcnew System::EventHandler(this, &RegForm::buttonReg_Click);
			// 
			// textBoxPassword2
			// 
			this->textBoxPassword2->BackColor = System::Drawing::Color::White;
			this->textBoxPassword2->Location = System::Drawing::Point(103, 260);
			this->textBoxPassword2->Name = L"textBoxPassword2";
			this->textBoxPassword2->PasswordChar = '*';
			this->textBoxPassword2->Size = System::Drawing::Size(132, 20);
			this->textBoxPassword2->TabIndex = 4;
			// 
			// labelMsg
			// 
			this->labelMsg->ForeColor = System::Drawing::Color::White;
			this->labelMsg->Location = System::Drawing::Point(12, 294);
			this->labelMsg->Name = L"labelMsg";
			this->labelMsg->Size = System::Drawing::Size(310, 22);
			this->labelMsg->TabIndex = 5;
			this->labelMsg->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(77, 336);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Есть аккаунт\?";
			// 
			// buttonLogIn
			// 
			this->buttonLogIn->BackColor = System::Drawing::Color::SpringGreen;
			this->buttonLogIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLogIn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonLogIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLogIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->buttonLogIn->ForeColor = System::Drawing::Color::Black;
			this->buttonLogIn->Location = System::Drawing::Point(187, 325);
			this->buttonLogIn->Name = L"buttonLogIn";
			this->buttonLogIn->Size = System::Drawing::Size(62, 24);
			this->buttonLogIn->TabIndex = 7;
			this->buttonLogIn->Text = L"Войти";
			this->buttonLogIn->UseVisualStyleBackColor = false;
			this->buttonLogIn->Click += gcnew System::EventHandler(this, &RegForm::buttonLogIn_Click);
			// 
			// textBoxName
			// 
			this->textBoxName->BackColor = System::Drawing::Color::White;
			this->textBoxName->Location = System::Drawing::Point(103, 120);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(132, 20);
			this->textBoxName->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::SpringGreen;
			this->label2->Location = System::Drawing::Point(100, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Ваше имя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::SpringGreen;
			this->label3->Location = System::Drawing::Point(100, 151);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Логин";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::SpringGreen;
			this->label4->Location = System::Drawing::Point(100, 197);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Введите пароль";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::SpringGreen;
			this->label5->Location = System::Drawing::Point(100, 244);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Повторите пароль";
			// 
			// RegForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->ClientSize = System::Drawing::Size(334, 461);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->buttonLogIn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelMsg);
			this->Controls->Add(this->textBoxPassword2);
			this->Controls->Add(this->buttonReg);
			this->Controls->Add(this->textBoxPassword1);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->labelRegistration);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegForm";
			this->Text = L"Регистрация";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RegForm::RegForm_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void buttonReg_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void RegForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	};
}

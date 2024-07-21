#pragma once

namespace ToDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AuthForm
	/// </summary>
	public ref class AuthForm : public System::Windows::Forms::Form
	{
	public:
		AuthForm(void)
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
		~AuthForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Button^ buttonSignIn;
	private: System::Windows::Forms::Label^ labelLogin;
	private: System::Windows::Forms::Label^ labelMsg;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AuthForm::typeid));
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonSignIn = (gcnew System::Windows::Forms::Button());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->labelMsg = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->textBoxLogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxLogin->ForeColor = System::Drawing::Color::SpringGreen;
			this->textBoxLogin->Location = System::Drawing::Point(95, 210);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(140, 20);
			this->textBoxLogin->TabIndex = 0;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxPassword->ForeColor = System::Drawing::Color::White;
			this->textBoxPassword->Location = System::Drawing::Point(95, 256);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(140, 20);
			this->textBoxPassword->TabIndex = 1;
			// 
			// buttonSignIn
			// 
			this->buttonSignIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->buttonSignIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSignIn->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonSignIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSignIn->ForeColor = System::Drawing::Color::White;
			this->buttonSignIn->Location = System::Drawing::Point(95, 359);
			this->buttonSignIn->Name = L"buttonSignIn";
			this->buttonSignIn->Size = System::Drawing::Size(140, 50);
			this->buttonSignIn->TabIndex = 2;
			this->buttonSignIn->Text = L"Войти";
			this->buttonSignIn->UseVisualStyleBackColor = false;
			this->buttonSignIn->Click += gcnew System::EventHandler(this, &AuthForm::buttonSignIn_Click);
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->BackColor = System::Drawing::Color::Transparent;
			this->labelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLogin->ForeColor = System::Drawing::Color::White;
			this->labelLogin->Location = System::Drawing::Point(140, 83);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(51, 20);
			this->labelLogin->TabIndex = 3;
			this->labelLogin->Text = L"Вход";
			// 
			// labelMsg
			// 
			this->labelMsg->BackColor = System::Drawing::Color::Transparent;
			this->labelMsg->ForeColor = System::Drawing::Color::White;
			this->labelMsg->Location = System::Drawing::Point(12, 294);
			this->labelMsg->Name = L"labelMsg";
			this->labelMsg->Size = System::Drawing::Size(310, 23);
			this->labelMsg->TabIndex = 4;
			this->labelMsg->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(95, 192);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Логин:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(95, 240);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Пароль:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(27, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AuthForm::button1_Click);
			// 
			// AuthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(334, 461);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelMsg);
			this->Controls->Add(this->labelLogin);
			this->Controls->Add(this->buttonSignIn);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AuthForm";
			this->Text = L"Авторизация";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AuthForm::AuthForm_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void buttonSignIn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void AuthForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

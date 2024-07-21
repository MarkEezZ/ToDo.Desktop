#pragma once
#include "ToDoForm.h"

namespace ToDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddForm
	/// </summary>
	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonAddToDo;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::TextBox^ textBoxToDo;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelMessage;
	private: System::Windows::Forms::Label^ label3;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddForm::typeid));
			this->buttonAddToDo = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxToDo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonAddToDo
			// 
			this->buttonAddToDo->BackColor = System::Drawing::Color::Black;
			this->buttonAddToDo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonAddToDo->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonAddToDo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAddToDo->ForeColor = System::Drawing::Color::White;
			this->buttonAddToDo->Location = System::Drawing::Point(133, 355);
			this->buttonAddToDo->Name = L"buttonAddToDo";
			this->buttonAddToDo->Size = System::Drawing::Size(106, 40);
			this->buttonAddToDo->TabIndex = 0;
			this->buttonAddToDo->Text = L"Добавить";
			this->buttonAddToDo->UseVisualStyleBackColor = false;
			this->buttonAddToDo->Click += gcnew System::EventHandler(this, &AddForm::buttonAddToDo_Click);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CalendarTitleBackColor = System::Drawing::Color::SpringGreen;
			this->dateTimePicker->CalendarTrailingForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->dateTimePicker->CustomFormat = L"ddd dd.MM.yyyy hh:mm:ss";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(91, 150);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker->TabIndex = 2;
			// 
			// textBoxToDo
			// 
			this->textBoxToDo->BackColor = System::Drawing::Color::Black;
			this->textBoxToDo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxToDo->ForeColor = System::Drawing::Color::White;
			this->textBoxToDo->Location = System::Drawing::Point(91, 205);
			this->textBoxToDo->Multiline = true;
			this->textBoxToDo->Name = L"textBoxToDo";
			this->textBoxToDo->Size = System::Drawing::Size(200, 88);
			this->textBoxToDo->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(88, 131);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Выберите дату";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(88, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Введите задачи построчно:";
			// 
			// labelMessage
			// 
			this->labelMessage->ForeColor = System::Drawing::Color::White;
			this->labelMessage->Location = System::Drawing::Point(12, 309);
			this->labelMessage->Margin = System::Windows::Forms::Padding(3);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(360, 26);
			this->labelMessage->TabIndex = 6;
			this->labelMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(111, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Добавьте задачи";
			// 
			// AddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->ClientSize = System::Drawing::Size(384, 461);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelMessage);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxToDo);
			this->Controls->Add(this->dateTimePicker);
			this->Controls->Add(this->buttonAddToDo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddForm";
			this->Text = L"Добавить";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion
		private: System::Void buttonAddToDo_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

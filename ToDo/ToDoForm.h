#include <string>
#include <filesystem>

#pragma once

namespace ToDo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ToDoForm
	/// </summary>
	public ref class ToDoForm : public System::Windows::Forms::Form
	{
	public:
		ToDoForm(System::String^ userLogin)
		{
			InitializeComponent();
			loadTodos();

			this->labelHiMessage->Text = generateHiMessage() + getNameFromFile(userLogin);
			this->timer1->Start();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ToDoForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonInfo;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonPrint;
	private: System::Windows::Forms::Button^ buttonNextMonth;
	private: System::Windows::Forms::Button^ buttonPrevMonth;
	public: System::Windows::Forms::FlowLayoutPanel^ panelMain;
	private: System::Windows::Forms::FlowLayoutPanel^ columnMonday;
	private: System::Windows::Forms::FlowLayoutPanel^ columnTuesday;
	private: System::Windows::Forms::FlowLayoutPanel^ columnWednesday;
	private: System::Windows::Forms::FlowLayoutPanel^ columnThursday;
	private: System::Windows::Forms::FlowLayoutPanel^ columnFriday;
	private: System::Windows::Forms::FlowLayoutPanel^ columnSaturday;
	private: System::Windows::Forms::FlowLayoutPanel^ columnSunday;
	private: System::Windows::Forms::Label^ labelMonday;
	private: System::Windows::Forms::Label^ labelTuesday;
	private: System::Windows::Forms::Label^ labelWednesday;
	private: System::Windows::Forms::Label^ labelThursday;
	private: System::Windows::Forms::Label^ labelFriday;
	private: System::Windows::Forms::Label^ labelSaturday;
	private: System::Windows::Forms::Label^ labelSunday;
	public: System::Windows::Forms::Label^ debug;
	private: System::Windows::Forms::Button^ buttonFind;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerMain;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ buttonSelectColor;
	private: System::Windows::Forms::Label^ labelColor;
	private: System::Windows::Forms::Label^ labelCurrentColor;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ labelHiMessage;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ToDoForm::typeid));
			this->buttonInfo = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonPrint = (gcnew System::Windows::Forms::Button());
			this->buttonNextMonth = (gcnew System::Windows::Forms::Button());
			this->buttonPrevMonth = (gcnew System::Windows::Forms::Button());
			this->panelMain = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnMonday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnTuesday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnWednesday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnThursday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnFriday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnSaturday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->columnSunday = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelMonday = (gcnew System::Windows::Forms::Label());
			this->labelTuesday = (gcnew System::Windows::Forms::Label());
			this->labelWednesday = (gcnew System::Windows::Forms::Label());
			this->labelThursday = (gcnew System::Windows::Forms::Label());
			this->labelFriday = (gcnew System::Windows::Forms::Label());
			this->labelSaturday = (gcnew System::Windows::Forms::Label());
			this->labelSunday = (gcnew System::Windows::Forms::Label());
			this->debug = (gcnew System::Windows::Forms::Label());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerMain = (gcnew System::Windows::Forms::DateTimePicker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelHiMessage = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->buttonSelectColor = (gcnew System::Windows::Forms::Button());
			this->labelCurrentColor = (gcnew System::Windows::Forms::Label());
			this->labelColor = (gcnew System::Windows::Forms::Label());
			this->panelMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonInfo
			// 
			this->buttonInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonInfo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonInfo->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonInfo->ForeColor = System::Drawing::Color::White;
			this->buttonInfo->Location = System::Drawing::Point(35, 683);
			this->buttonInfo->Name = L"buttonInfo";
			this->buttonInfo->Size = System::Drawing::Size(75, 50);
			this->buttonInfo->TabIndex = 0;
			this->buttonInfo->Text = L"Подробнее";
			this->buttonInfo->UseVisualStyleBackColor = false;
			this->buttonInfo->Visible = false;
			this->buttonInfo->Click += gcnew System::EventHandler(this, &ToDoForm::buttonInfo_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonAdd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonAdd->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->buttonAdd->ForeColor = System::Drawing::Color::White;
			this->buttonAdd->Location = System::Drawing::Point(35, 135);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 50);
			this->buttonAdd->TabIndex = 1;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = false;
			this->buttonAdd->Visible = false;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &ToDoForm::buttonAdd_Click);
			// 
			// buttonPrint
			// 
			this->buttonPrint->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonPrint->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPrint->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonPrint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPrint->ForeColor = System::Drawing::Color::White;
			this->buttonPrint->Location = System::Drawing::Point(35, 615);
			this->buttonPrint->Name = L"buttonPrint";
			this->buttonPrint->Size = System::Drawing::Size(75, 50);
			this->buttonPrint->TabIndex = 2;
			this->buttonPrint->Text = L"Печать";
			this->buttonPrint->UseVisualStyleBackColor = false;
			this->buttonPrint->Visible = false;
			this->buttonPrint->Click += gcnew System::EventHandler(this, &ToDoForm::buttonPrint_Click);
			// 
			// buttonNextMonth
			// 
			this->buttonNextMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonNextMonth->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonNextMonth->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonNextMonth->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNextMonth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->buttonNextMonth->ForeColor = System::Drawing::Color::White;
			this->buttonNextMonth->Location = System::Drawing::Point(252, 50);
			this->buttonNextMonth->Name = L"buttonNextMonth";
			this->buttonNextMonth->Size = System::Drawing::Size(85, 45);
			this->buttonNextMonth->TabIndex = 3;
			this->buttonNextMonth->Text = L"Следующий месяц";
			this->buttonNextMonth->UseVisualStyleBackColor = false;
			this->buttonNextMonth->Visible = false;
			this->buttonNextMonth->Click += gcnew System::EventHandler(this, &ToDoForm::buttonNextMonth_Click);
			// 
			// buttonPrevMonth
			// 
			this->buttonPrevMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonPrevMonth->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPrevMonth->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonPrevMonth->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPrevMonth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->buttonPrevMonth->ForeColor = System::Drawing::Color::White;
			this->buttonPrevMonth->Location = System::Drawing::Point(144, 50);
			this->buttonPrevMonth->Name = L"buttonPrevMonth";
			this->buttonPrevMonth->Size = System::Drawing::Size(85, 45);
			this->buttonPrevMonth->TabIndex = 4;
			this->buttonPrevMonth->Text = L"Предыдущий месяц";
			this->buttonPrevMonth->UseVisualStyleBackColor = false;
			this->buttonPrevMonth->Visible = false;
			this->buttonPrevMonth->Click += gcnew System::EventHandler(this, &ToDoForm::buttonPrevMonth_Click);
			// 
			// panelMain
			// 
			this->panelMain->AutoSize = true;
			this->panelMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(4)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)));
			this->panelMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelMain->Controls->Add(this->columnMonday);
			this->panelMain->Controls->Add(this->columnTuesday);
			this->panelMain->Controls->Add(this->columnWednesday);
			this->panelMain->Controls->Add(this->columnThursday);
			this->panelMain->Controls->Add(this->columnFriday);
			this->panelMain->Controls->Add(this->columnSaturday);
			this->panelMain->Controls->Add(this->columnSunday);
			this->panelMain->ForeColor = System::Drawing::Color::Black;
			this->panelMain->Location = System::Drawing::Point(144, 135);
			this->panelMain->Margin = System::Windows::Forms::Padding(0);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Size = System::Drawing::Size(870, 600);
			this->panelMain->TabIndex = 5;
			this->panelMain->Visible = false;
			// 
			// columnMonday
			// 
			this->columnMonday->AutoScroll = true;
			this->columnMonday->AutoSize = true;
			this->columnMonday->Location = System::Drawing::Point(2, 2);
			this->columnMonday->Margin = System::Windows::Forms::Padding(2);
			this->columnMonday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnMonday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnMonday->Name = L"columnMonday";
			this->columnMonday->Size = System::Drawing::Size(120, 40);
			this->columnMonday->TabIndex = 1;
			// 
			// columnTuesday
			// 
			this->columnTuesday->AutoScroll = true;
			this->columnTuesday->AutoSize = true;
			this->columnTuesday->Location = System::Drawing::Point(126, 2);
			this->columnTuesday->Margin = System::Windows::Forms::Padding(2);
			this->columnTuesday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnTuesday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnTuesday->Name = L"columnTuesday";
			this->columnTuesday->Size = System::Drawing::Size(120, 40);
			this->columnTuesday->TabIndex = 2;
			// 
			// columnWednesday
			// 
			this->columnWednesday->AutoScroll = true;
			this->columnWednesday->AutoSize = true;
			this->columnWednesday->Location = System::Drawing::Point(250, 2);
			this->columnWednesday->Margin = System::Windows::Forms::Padding(2);
			this->columnWednesday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnWednesday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnWednesday->Name = L"columnWednesday";
			this->columnWednesday->Size = System::Drawing::Size(120, 40);
			this->columnWednesday->TabIndex = 3;
			// 
			// columnThursday
			// 
			this->columnThursday->AutoScroll = true;
			this->columnThursday->AutoSize = true;
			this->columnThursday->Location = System::Drawing::Point(374, 2);
			this->columnThursday->Margin = System::Windows::Forms::Padding(2);
			this->columnThursday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnThursday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnThursday->Name = L"columnThursday";
			this->columnThursday->Size = System::Drawing::Size(120, 40);
			this->columnThursday->TabIndex = 3;
			// 
			// columnFriday
			// 
			this->columnFriday->AutoScroll = true;
			this->columnFriday->AutoSize = true;
			this->columnFriday->Location = System::Drawing::Point(498, 2);
			this->columnFriday->Margin = System::Windows::Forms::Padding(2);
			this->columnFriday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnFriday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnFriday->Name = L"columnFriday";
			this->columnFriday->Size = System::Drawing::Size(120, 40);
			this->columnFriday->TabIndex = 3;
			// 
			// columnSaturday
			// 
			this->columnSaturday->AutoScroll = true;
			this->columnSaturday->AutoSize = true;
			this->columnSaturday->Location = System::Drawing::Point(622, 2);
			this->columnSaturday->Margin = System::Windows::Forms::Padding(2);
			this->columnSaturday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnSaturday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnSaturday->Name = L"columnSaturday";
			this->columnSaturday->Size = System::Drawing::Size(120, 40);
			this->columnSaturday->TabIndex = 3;
			// 
			// columnSunday
			// 
			this->columnSunday->AutoScroll = true;
			this->columnSunday->AutoSize = true;
			this->columnSunday->Location = System::Drawing::Point(746, 2);
			this->columnSunday->Margin = System::Windows::Forms::Padding(2);
			this->columnSunday->MaximumSize = System::Drawing::Size(120, 600);
			this->columnSunday->MinimumSize = System::Drawing::Size(120, 40);
			this->columnSunday->Name = L"columnSunday";
			this->columnSunday->Size = System::Drawing::Size(120, 40);
			this->columnSunday->TabIndex = 4;
			// 
			// labelMonday
			// 
			this->labelMonday->AutoSize = true;
			this->labelMonday->BackColor = System::Drawing::Color::Transparent;
			this->labelMonday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelMonday->ForeColor = System::Drawing::Color::White;
			this->labelMonday->Location = System::Drawing::Point(168, 115);
			this->labelMonday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelMonday->Name = L"labelMonday";
			this->labelMonday->Size = System::Drawing::Size(75, 13);
			this->labelMonday->TabIndex = 6;
			this->labelMonday->Text = L"Понедельник";
			this->labelMonday->Visible = false;
			// 
			// labelTuesday
			// 
			this->labelTuesday->AutoSize = true;
			this->labelTuesday->BackColor = System::Drawing::Color::Transparent;
			this->labelTuesday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelTuesday->ForeColor = System::Drawing::Color::White;
			this->labelTuesday->Location = System::Drawing::Point(305, 115);
			this->labelTuesday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelTuesday->Name = L"labelTuesday";
			this->labelTuesday->Size = System::Drawing::Size(49, 13);
			this->labelTuesday->TabIndex = 7;
			this->labelTuesday->Text = L"Вторник";
			this->labelTuesday->Visible = false;
			// 
			// labelWednesday
			// 
			this->labelWednesday->AutoSize = true;
			this->labelWednesday->BackColor = System::Drawing::Color::Transparent;
			this->labelWednesday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelWednesday->ForeColor = System::Drawing::Color::White;
			this->labelWednesday->Location = System::Drawing::Point(435, 115);
			this->labelWednesday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelWednesday->Name = L"labelWednesday";
			this->labelWednesday->Size = System::Drawing::Size(38, 13);
			this->labelWednesday->TabIndex = 8;
			this->labelWednesday->Text = L"Среда";
			this->labelWednesday->Visible = false;
			// 
			// labelThursday
			// 
			this->labelThursday->AutoSize = true;
			this->labelThursday->BackColor = System::Drawing::Color::Transparent;
			this->labelThursday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelThursday->ForeColor = System::Drawing::Color::White;
			this->labelThursday->Location = System::Drawing::Point(550, 115);
			this->labelThursday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelThursday->Name = L"labelThursday";
			this->labelThursday->Size = System::Drawing::Size(49, 13);
			this->labelThursday->TabIndex = 9;
			this->labelThursday->Text = L"Четверг";
			this->labelThursday->Visible = false;
			// 
			// labelFriday
			// 
			this->labelFriday->AutoSize = true;
			this->labelFriday->BackColor = System::Drawing::Color::Transparent;
			this->labelFriday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelFriday->ForeColor = System::Drawing::Color::White;
			this->labelFriday->Location = System::Drawing::Point(675, 115);
			this->labelFriday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelFriday->Name = L"labelFriday";
			this->labelFriday->Size = System::Drawing::Size(50, 13);
			this->labelFriday->TabIndex = 10;
			this->labelFriday->Text = L"Пятница";
			this->labelFriday->Visible = false;
			// 
			// labelSaturday
			// 
			this->labelSaturday->AutoSize = true;
			this->labelSaturday->BackColor = System::Drawing::Color::Transparent;
			this->labelSaturday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelSaturday->ForeColor = System::Drawing::Color::White;
			this->labelSaturday->Location = System::Drawing::Point(800, 115);
			this->labelSaturday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelSaturday->Name = L"labelSaturday";
			this->labelSaturday->Size = System::Drawing::Size(48, 13);
			this->labelSaturday->TabIndex = 7;
			this->labelSaturday->Text = L"Суббота";
			this->labelSaturday->Visible = false;
			// 
			// labelSunday
			// 
			this->labelSunday->AutoSize = true;
			this->labelSunday->BackColor = System::Drawing::Color::Transparent;
			this->labelSunday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelSunday->ForeColor = System::Drawing::Color::White;
			this->labelSunday->Location = System::Drawing::Point(913, 115);
			this->labelSunday->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->labelSunday->Name = L"labelSunday";
			this->labelSunday->Size = System::Drawing::Size(74, 13);
			this->labelSunday->TabIndex = 11;
			this->labelSunday->Text = L"Воскресенье";
			this->labelSunday->Visible = false;
			// 
			// debug
			// 
			this->debug->AutoSize = true;
			this->debug->Location = System::Drawing::Point(29, 50);
			this->debug->Name = L"debug";
			this->debug->Size = System::Drawing::Size(0, 13);
			this->debug->TabIndex = 12;
			this->debug->Visible = false;
			// 
			// buttonFind
			// 
			this->buttonFind->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonFind->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonFind->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonFind->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->buttonFind->ForeColor = System::Drawing::Color::White;
			this->buttonFind->Location = System::Drawing::Point(903, 50);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(109, 43);
			this->buttonFind->TabIndex = 13;
			this->buttonFind->Text = L"Найти";
			this->buttonFind->UseVisualStyleBackColor = false;
			this->buttonFind->Visible = false;
			this->buttonFind->Click += gcnew System::EventHandler(this, &ToDoForm::buttonFind_Click);
			// 
			// dateTimePickerMain
			// 
			this->dateTimePickerMain->CalendarForeColor = System::Drawing::Color::White;
			this->dateTimePickerMain->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->dateTimePickerMain->CalendarTitleBackColor = System::Drawing::Color::SpringGreen;
			this->dateTimePickerMain->CalendarTrailingForeColor = System::Drawing::Color::SpringGreen;
			this->dateTimePickerMain->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dateTimePickerMain->CustomFormat = L"MMM yyyy";
			this->dateTimePickerMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->dateTimePickerMain->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerMain->Location = System::Drawing::Point(766, 69);
			this->dateTimePickerMain->Name = L"dateTimePickerMain";
			this->dateTimePickerMain->Size = System::Drawing::Size(120, 20);
			this->dateTimePickerMain->TabIndex = 14;
			this->dateTimePickerMain->Visible = false;
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(4)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)));
			this->progressBar1->ForeColor = System::Drawing::Color::SpringGreen;
			this->progressBar1->Location = System::Drawing::Point(304, 369);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(430, 33);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 15;
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &ToDoForm::timer1_Tick);
			// 
			// labelHiMessage
			// 
			this->labelHiMessage->BackColor = System::Drawing::Color::Transparent;
			this->labelHiMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelHiMessage->ForeColor = System::Drawing::Color::White;
			this->labelHiMessage->Location = System::Drawing::Point(304, 338);
			this->labelHiMessage->Name = L"labelHiMessage";
			this->labelHiMessage->Size = System::Drawing::Size(430, 23);
			this->labelHiMessage->TabIndex = 16;
			// 
			// buttonSelectColor
			// 
			this->buttonSelectColor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->buttonSelectColor->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSelectColor->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
			this->buttonSelectColor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSelectColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->buttonSelectColor->ForeColor = System::Drawing::Color::White;
			this->buttonSelectColor->Location = System::Drawing::Point(35, 381);
			this->buttonSelectColor->Name = L"buttonSelectColor";
			this->buttonSelectColor->Size = System::Drawing::Size(75, 50);
			this->buttonSelectColor->TabIndex = 17;
			this->buttonSelectColor->Text = L"Выбрать цвет";
			this->buttonSelectColor->UseVisualStyleBackColor = false;
			this->buttonSelectColor->Visible = false;
			this->buttonSelectColor->Click += gcnew System::EventHandler(this, &ToDoForm::buttonSelectColor_Click);
			// 
			// labelCurrentColor
			// 
			this->labelCurrentColor->AutoSize = true;
			this->labelCurrentColor->BackColor = System::Drawing::Color::Transparent;
			this->labelCurrentColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->labelCurrentColor->ForeColor = System::Drawing::Color::White;
			this->labelCurrentColor->Location = System::Drawing::Point(32, 289);
			this->labelCurrentColor->Name = L"labelCurrentColor";
			this->labelCurrentColor->Size = System::Drawing::Size(81, 13);
			this->labelCurrentColor->TabIndex = 18;
			this->labelCurrentColor->Text = L"Текущий цвет:";
			this->labelCurrentColor->Visible = false;
			// 
			// labelColor
			// 
			this->labelColor->BackColor = System::Drawing::Color::SpringGreen;
			this->labelColor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelColor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelColor->Location = System::Drawing::Point(35, 313);
			this->labelColor->Margin = System::Windows::Forms::Padding(0);
			this->labelColor->Name = L"labelColor";
			this->labelColor->Size = System::Drawing::Size(75, 50);
			this->labelColor->TabIndex = 19;
			this->labelColor->Visible = false;
			// 
			// ToDoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1124, 781);
			this->Controls->Add(this->labelColor);
			this->Controls->Add(this->labelCurrentColor);
			this->Controls->Add(this->buttonSelectColor);
			this->Controls->Add(this->labelHiMessage);
			this->Controls->Add(this->dateTimePickerMain);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->debug);
			this->Controls->Add(this->labelSunday);
			this->Controls->Add(this->labelSaturday);
			this->Controls->Add(this->labelFriday);
			this->Controls->Add(this->labelThursday);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->labelWednesday);
			this->Controls->Add(this->labelTuesday);
			this->Controls->Add(this->labelMonday);
			this->Controls->Add(this->panelMain);
			this->Controls->Add(this->buttonPrevMonth);
			this->Controls->Add(this->buttonNextMonth);
			this->Controls->Add(this->buttonPrint);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->buttonInfo);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::Transparent;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ToDoForm";
			this->Text = L"Задачи";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ToDoForm::ToDoForm_FormClosed);
			this->panelMain->ResumeLayout(false);
			this->panelMain->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion
		private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
		private: System::String^ getNameFromFile(System::String^ login);
		private: System::String^ generateHiMessage();
		private: System::Void buttonInfo_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ToDoForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		private: System::Void buttonSelectColor_Click(System::Object^ sender, System::EventArgs^ e);
		public: System::Void checkBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		public: System::Void removeToDo_Click(System::Object^ sender, System::EventArgs^ e);
		public: System::Void buttonRemoveSelected_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		public: System::Void loadTodos();
		public:	System::Windows::Forms::CheckBox^ createItem(System::String^ itemData, bool isChecked);
		public: System::Windows::Forms::FlowLayoutPanel^ createToDo(System::String^ date, array<System::String^>^ todos, std::string filePath);
		private: System::Void buttonPrevMonth_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonNextMonth_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonPrint_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

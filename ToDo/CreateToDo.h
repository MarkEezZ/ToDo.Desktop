#pragma once


System::Windows::Forms::CheckBox^ createItem(System::String^ itemData, ToDo::ToDoForm^ toDoForm) {
	System::Windows::Forms::FlowLayoutPanel^ itemContainer = gcnew System::Windows::Forms::FlowLayoutPanel();
	itemContainer->Margin = System::Windows::Forms::Padding(2, 0, 2, 2);
	itemContainer->Size = System::Drawing::Size(110, 88);

	System::Windows::Forms::CheckBox^ checkBox = gcnew System::Windows::Forms::CheckBox();
	checkBox->Margin = System::Windows::Forms::Padding(2, 0, 0, 0);
	checkBox->AutoSize = true;
	checkBox->Text = itemData;
	checkBox->UseVisualStyleBackColor = true;
	checkBox->BackColor = System::Drawing::Color::Transparent;
	checkBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(toDoForm, &ToDo::ToDoForm::checkBox_MouseDown);
	checkBox->CheckAlign = System::Drawing::ContentAlignment::TopLeft;
	return checkBox;
}


System::Windows::Forms::FlowLayoutPanel^ createToDo(System::String^ date, array<System::String^>^ todos, std::string filePath, ToDo::ToDoForm^ toDoForm) {
	System::Windows::Forms::FlowLayoutPanel^ containerDate = gcnew System::Windows::Forms::FlowLayoutPanel();
	containerDate->Margin = System::Windows::Forms::Padding(2);
	containerDate->Size = System::Drawing::Size(110, 20);

	System::Windows::Forms::Label^ dateLabel = gcnew System::Windows::Forms::Label();
	dateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	dateLabel->Margin = System::Windows::Forms::Padding(1);
	dateLabel->Size = System::Drawing::Size(88, 18);
	dateLabel->Text = date;

	System::Windows::Forms::Button^ closeButton = gcnew System::Windows::Forms::Button();
	closeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	closeButton->Margin = System::Windows::Forms::Padding(1);
	closeButton->Size = System::Drawing::Size(18, 18);
	closeButton->Text = "X";
	closeButton->Click += gcnew System::EventHandler(toDoForm, &ToDo::ToDoForm::removeToDo_Click);

	containerDate->Controls->Add(dateLabel);
	containerDate->Controls->Add(closeButton);

	System::Windows::Forms::FlowLayoutPanel^ containerItems = gcnew System::Windows::Forms::FlowLayoutPanel();
	containerItems->AutoScroll = true;
	containerItems->Margin = System::Windows::Forms::Padding(2, 0, 2, 2);
	containerItems->Size = System::Drawing::Size(110, 62);

	for each (System::String^ todo in todos) {
		containerItems->Controls->Add(createItem(todo, toDoForm));
	}

	System::Windows::Forms::Button^ buttonRemoveSelected = gcnew System::Windows::Forms::Button();
	buttonRemoveSelected->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5, System::Drawing::FontStyle::Regular,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
	buttonRemoveSelected->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	buttonRemoveSelected->Margin = System::Windows::Forms::Padding(2, 0, 2, 2);
	buttonRemoveSelected->Size = System::Drawing::Size(110, 24);
	buttonRemoveSelected->Text = "Удалить отмеченные";
	buttonRemoveSelected->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(toDoForm, &ToDo::ToDoForm::buttonRemoveSelected_Click);

	System::Windows::Forms::FlowLayoutPanel^ container = gcnew System::Windows::Forms::FlowLayoutPanel();
	container->Name = L"toDo-" + date;
	container->Size = System::Drawing::Size(114, 114);
	container->BackColor = System::Drawing::Color::Aqua;
	container->Controls->Add(containerDate);
	container->Controls->Add(containerItems);
	container->Controls->Add(buttonRemoveSelected);
	container->Tag = gcnew System::String(filePath.c_str());

	return container;
}
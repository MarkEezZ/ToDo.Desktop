#include "AddForm.h"
#include <fstream>
#include "Split.h"
#include "InfoForm.h"
#include "ToStandardString.h"
#include "GetTodosFromFile.h"
#include <map>


System::Void ToDo::ToDoForm::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    AddForm^ addForm = gcnew AddForm();
    addForm->Owner = this;
    addForm->Show();
}


System::Void ToDo::ToDoForm::buttonFind_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->loadTodos();
}


System::Void ToDo::ToDoForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
    this->progressBar1->PerformStep();

    if (this->progressBar1->Value == this->progressBar1->Maximum - 1) {
        this->timer1->Interval = 500;
    }
    else if (this->progressBar1->Value == this->progressBar1->Maximum) {
        this->timer1->Stop();

        this->labelHiMessage->Visible = false;
        this->progressBar1->Visible = false;

        this->buttonSelectColor->Visible = true;
        this->labelCurrentColor->Visible = true;
        this->labelColor->Visible = true;
        this->buttonInfo->Visible = true;
        this->buttonAdd->Visible = true;
        this->buttonPrint->Visible = true;
        this->buttonNextMonth->Visible = true;
        this->buttonPrevMonth->Visible = true;
        this->panelMain->Visible = true;
        this->labelMonday->Visible = true;
        this->labelTuesday->Visible = true;
        this->labelWednesday->Visible = true;
        this->labelThursday->Visible = true;
        this->labelFriday->Visible = true;
        this->labelSaturday->Visible = true;
        this->labelSunday->Visible = true;
        this->debug->Visible = true;
        this->buttonFind->Visible = true;
        this->dateTimePickerMain->Visible = true;
    }
}


System::String^ ToDo::ToDoForm::getNameFromFile(System::String^ requiredLogin)
{
    std::ifstream fin;
    std::filesystem::path path = "data/users.txt";

    try {
        fin.open(path);
    }
    catch (const std::exception& ex) {
        throw ex;
    }

    while (!fin.eof()) {
        std::string str;
        std::getline(fin, str);

        if (str.length() > 0) {
            std::vector<std::string> userData = split(str, "/");
            std::string login = userData[0];

            if (gcnew String(login.c_str()) == requiredLogin) {
                fin.close();
                return gcnew String(userData[2].c_str());
            }
        }
    }
    fin.close();
}


System::String^ ToDo::ToDoForm::generateHiMessage()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    
    if (now->tm_hour >= 5 && now->tm_hour < 12) {
        return "Доброе утро, ";
    }
    else if (now->tm_hour >= 12 && now->tm_hour < 18) {
        return "Добрый день, ";
    }
    else if (now->tm_hour >= 18 && now->tm_hour <= 23) {
        return "Добрый вечер, ";
    }
    else if (now->tm_hour >= 0 && now->tm_hour < 5) {
        return "Хули не спим, ";
    }
}


System::Void ToDo::ToDoForm::buttonInfo_Click(System::Object^ sender, System::EventArgs^ e)
{
    InfoForm^ infoForm = gcnew InfoForm();
    infoForm->Show();
}


System::Void ToDo::ToDoForm::ToDoForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Application::Exit();
}


System::Void ToDo::ToDoForm::buttonSelectColor_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (this->colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        this->labelColor->BackColor = this->colorDialog1->Color;
    }
}


System::Void ToDo::ToDoForm::checkBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    System::Windows::Forms::CheckBox^ checkBox = dynamic_cast<System::Windows::Forms::CheckBox^>(sender);

    switch (e->Button)
    {
    case System::Windows::Forms::MouseButtons::Right:
        if (checkBox->BackColor == System::Drawing::Color::Transparent || checkBox->BackColor != this->labelColor->BackColor) {
            checkBox->BackColor = this->labelColor->BackColor;
        }
        else {
            checkBox->BackColor = System::Drawing::Color::Transparent;
        }
        break;

    default:
        break;
    }
}


System::Void ToDo::ToDoForm::buttonRemoveSelected_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    FlowLayoutPanel^ generalContainer = (FlowLayoutPanel^)((Button^)sender)->Parent;
    std::string path = toStandardString(dynamic_cast<String^>(generalContainer->Tag));

    if (std::filesystem::exists(path)) {
        std::fstream clear_file(path, std::ios::out);
        clear_file.close();

        System::IO::FileStream^ stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::Append);
        System::IO::StreamWriter^ swr = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));
    
        FlowLayoutPanel^ checkBoxContainer = (FlowLayoutPanel^)((FlowLayoutPanel^)((Button^)sender)->Parent)->Controls[1];
        size_t length = checkBoxContainer->Controls->Count;
        int removedCount = 0;

        for (size_t i = 0; i < length - removedCount;) {
            CheckBox^ checkBox = (CheckBox^)checkBoxContainer->Controls[i];
            if (checkBox->Checked) {
                checkBoxContainer->Controls->Remove(checkBox);
                removedCount++;
            }
            else {
                String^ checkedValue = "false";
                if (checkBox->Checked)
                    checkedValue = "true";

                swr->WriteLine(checkBox->Text + " / " + checkedValue);
                i++;
            }
        }

        swr->Close();
        stream->Close();
    }
}

System::Void ToDo::ToDoForm::loadTodos()
{
    std::map<int, std::string> WeekDaysForColumns = {
        { 1, "columnMonday" },
        { 2, "columnTuesday" },
        { 3, "columnWednesday" },
        { 4, "columnThursday" },
        { 5, "columnFriday" },
        { 6, "columnSaturday" },
        { 0, "columnSunday" },
    };

    std::filesystem::path path = "data/paths.txt";

    if (!std::filesystem::exists("data")) {
        std::filesystem::create_directory("data");
    }
    if (!std::filesystem::exists(path)) {
        std::ofstream pathsFile(path);
        pathsFile.close();
    }

    std::ifstream fin;

    for each (FlowLayoutPanel ^ column in this->panelMain->Controls)
    {
        column->Controls->Clear();
    }

    try {
        fin.open(path);
    }
    catch (const std::exception& ex) {
        throw ex;
    }

    DateTime^ date = this->dateTimePickerMain->Value;

    while (!fin.eof()) {
        std::string str;
        std::getline(fin, str);

        if (str.length() > 0) {
            std::vector<std::string> splittedPath = split(str, "/");
            int year = std::stoi(splittedPath[1]);
            int month = std::stoi(splittedPath[2]);
            int day = std::stoi(split(splittedPath[3], ".")[0]);

            System::DateTime^ dateFromFile = gcnew System::DateTime(year, month, day);

            if (date->Year == year && date->Month == month) {
                String^ fullDate = day + L"." + month + L"." + year;

                array<System::String^>^ allTodos = getTodosFromFile(str);
                FlowLayoutPanel^ toDo = this->createToDo(fullDate, allTodos, str);

                for each (FlowLayoutPanel ^ column in this->panelMain->Controls)
                {
                    if (column->Name == gcnew String(WeekDaysForColumns[int(dateFromFile->DayOfWeek)].c_str())) {
                        column->Controls->Add(toDo);
                        column->Height += 1;
                        break;
                    }
                }
            }
        }
    }
    fin.close();
}


System::Void ToDo::ToDoForm::removeToDo_Click(System::Object^ sender, System::EventArgs^ e)
{
    FlowLayoutPanel^ dateContainer = (FlowLayoutPanel^)((Button^)sender)->Parent;
    FlowLayoutPanel^ generalContainer = (FlowLayoutPanel^)dateContainer->Parent;

    std::string path = toStandardString(dynamic_cast<String^>(generalContainer->Tag));
    if (std::filesystem::exists(path)) {
        std::filesystem::remove(path);
    }


    std::ifstream ifs;
    ifs.open("data/paths.txt");
    std::vector<std::string> records;

    while (!ifs.eof()) {
        std::string str;
        std::getline(ifs, str);

        if (str.length() > 0 && str != path) {
            records.push_back(str);
        }
    }
    ifs.close();

    std::ofstream ofs;
    ofs.open("data/paths.txt", std::ofstream::out | std::ofstream::trunc);
    for each (std::string str in records)
    {
        ofs << str << std::endl;
    }
    ofs.close();

    ((FlowLayoutPanel^)((FlowLayoutPanel^)((FlowLayoutPanel^)((Button^)sender)->Parent)->Parent)->Parent)->Controls->Remove((FlowLayoutPanel^)((FlowLayoutPanel^)((Button^)sender)->Parent)->Parent);
}


System::Void ToDo::ToDoForm::buttonPrevMonth_Click(System::Object^ sender, System::EventArgs^ e)
{
    DateTime^ date = this->dateTimePickerMain->Value;
    date = date->AddMonths(-1);
    this->dateTimePickerMain->Value = DateTime(date->Year, date->Month, date->Day);

    loadTodos();
}


System::Void ToDo::ToDoForm::buttonNextMonth_Click(System::Object^ sender, System::EventArgs^ e)
{
    DateTime^ date = this->dateTimePickerMain->Value;
    date = date->AddMonths(1);
    this->dateTimePickerMain->Value = DateTime(date->Year, date->Month, date->Day);

    loadTodos();
}


System::Void ToDo::ToDoForm::checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    FlowLayoutPanel^ itemsContainer = (FlowLayoutPanel^)((CheckBox^)sender)->Parent;
    FlowLayoutPanel^ generalContainer = (FlowLayoutPanel^)itemsContainer->Parent;
    std::string path = toStandardString(dynamic_cast<String^>(generalContainer->Tag));
    int index = itemsContainer->Controls->IndexOf((CheckBox^)sender);

    if (!std::filesystem::exists(path)) {
        return;
    }

    std::ifstream fin;
    fin.open(path);

    std::vector<std::string> records;
    while (!fin.eof()) {
        std::string str;
        std::getline(fin, str);

        if (str.length() > 0) {
            records.push_back(str);
        }
    }

    fin.clear();
    fin.close();

    std::string checkedValue = "false";
    if (((CheckBox^)sender)->Checked)
        checkedValue = "true";

    records[index] = split(records[index], " / ")[0] + " / " + checkedValue;
    
    std::ofstream ofs;
    ofs.open(path, std::ofstream::out | std::ofstream::trunc);
    for each (std::string str in records)
    {
        ofs << str << std::endl;
    }
    ofs.close();
}

System::Void ToDo::ToDoForm::buttonPrint_Click(System::Object^ sender, System::EventArgs^ e)
{
    PrintDialog^ pd = gcnew PrintDialog();
    pd->ShowDialog();
}


System::Windows::Forms::CheckBox^ ToDo::ToDoForm::createItem(System::String^ itemData, bool isChecked)
{
    System::Windows::Forms::FlowLayoutPanel^ itemContainer = gcnew System::Windows::Forms::FlowLayoutPanel();
    itemContainer->Margin = System::Windows::Forms::Padding(2, 0, 2, 2);
    itemContainer->Size = System::Drawing::Size(110, 88);

    System::Windows::Forms::CheckBox^ checkBox = gcnew System::Windows::Forms::CheckBox();
    checkBox->Margin = System::Windows::Forms::Padding(2, 0, 0, 0);
    checkBox->MinimumSize = System::Drawing::Size(90, 0);
    checkBox->AutoSize = true;
    checkBox->Text = itemData;
    checkBox->Checked = isChecked;
    checkBox->UseVisualStyleBackColor = true;
    checkBox->BackColor = System::Drawing::Color::Transparent;
    checkBox->CheckAlign = System::Drawing::ContentAlignment::TopLeft;
    checkBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ToDo::ToDoForm::checkBox_MouseDown);
    checkBox->CheckedChanged += gcnew System::EventHandler(this, &ToDoForm::checkBox_CheckedChanged);
    return checkBox;
}


System::Windows::Forms::FlowLayoutPanel^ ToDo::ToDoForm::createToDo(System::String^ date, array<System::String^>^ todos, std::string filePath)
{
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
    closeButton->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
    closeButton->BackColor = System::Drawing::Color::FromArgb(12, 5, 48);
    closeButton->ForeColor = System::Drawing::Color::White;
    closeButton->Cursor = System::Windows::Forms::Cursors::Hand;
    closeButton->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
    closeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    closeButton->Click += gcnew System::EventHandler(this, &ToDo::ToDoForm::removeToDo_Click);

    containerDate->Controls->Add(dateLabel);
    containerDate->Controls->Add(closeButton);

    System::Windows::Forms::FlowLayoutPanel^ containerItems = gcnew System::Windows::Forms::FlowLayoutPanel();
    containerItems->AutoScroll = true;
    containerItems->Margin = System::Windows::Forms::Padding(2, 0, 2, 2);
    containerItems->Size = System::Drawing::Size(110, 62);

    for each (System::String ^ todo in todos) {
        std::vector<std::string> todoSplitted = split(toStandardString(todo), " / ");
        bool isChecked = false;
        if (todoSplitted[1] == "true") {
            isChecked = true;
        }
        containerItems->Controls->Add(this->createItem(gcnew String(todoSplitted[0].c_str()), isChecked));
    }

    System::Windows::Forms::Button^ buttonRemoveSelected = gcnew System::Windows::Forms::Button();
    buttonRemoveSelected->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
    buttonRemoveSelected->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    buttonRemoveSelected->Margin = System::Windows::Forms::Padding(2, 0, 2, 2);
    buttonRemoveSelected->Size = System::Drawing::Size(110, 24);
    buttonRemoveSelected->Text = "Удалить отмеченные";
    buttonRemoveSelected->BackColor = System::Drawing::Color::FromArgb(12, 5, 48);
    buttonRemoveSelected->ForeColor = System::Drawing::Color::White;
    buttonRemoveSelected->Cursor = System::Windows::Forms::Cursors::Hand;
    buttonRemoveSelected->FlatAppearance->BorderColor = System::Drawing::Color::SpringGreen;
    buttonRemoveSelected->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    buttonRemoveSelected->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ToDo::ToDoForm::buttonRemoveSelected_Click);

    System::Windows::Forms::FlowLayoutPanel^ container = gcnew System::Windows::Forms::FlowLayoutPanel();
    container->Name = L"toDo-" + date;
    container->Size = System::Drawing::Size(114, 114);
    container->BackColor = System::Drawing::Color::White;
    container->Controls->Add(containerDate);
    container->Controls->Add(containerItems);
    container->Controls->Add(buttonRemoveSelected);
    container->Tag = gcnew System::String(filePath.c_str());

    return container;
}

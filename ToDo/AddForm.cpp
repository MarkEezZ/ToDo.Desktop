#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "AddForm.h"
#include "WeekDays.h"
#include "WeekDaysForColumns.h"
#include "Months.h"
#include "Trim.h"
#include "GetTodosFromFile.h"
#include "AddTodosToFile.h"
#include "Split.h"
#include "ToStandardString.h"


System::Void ToDo::AddForm::buttonAddToDo_Click(System::Object^ sender, System::EventArgs^ e)
{
	ToDoForm^ toDoForm = (ToDoForm^)this->Owner;

	int nonEmptyCounter = 0;
	for each (String^ line in this->textBoxToDo->Lines) {
		if (line->Trim()->Length != 0)
			nonEmptyCounter++;
	}

	if (nonEmptyCounter == 0) {
		this->labelMessage->Text = L"¬ведите данные";
		return;
	}

	array<System::String^>^ formattedTodos = gcnew array<System::String^>(nonEmptyCounter);
	int recordsCount = 0;
	for each (String ^ line in this->textBoxToDo->Lines) {
		if (line->Trim()->Length != 0) {
			formattedTodos[recordsCount] = line->Trim() + " / " + "false";
			recordsCount++;
		}	
	}

	DateTime^ date = this->dateTimePicker->Value;
	String^ fullDate = date->Day + L"." + date->Month + L"." + date->Year;

	std::string year = std::to_string(date->Year);
	std::string month = std::to_string(date->Month);
	std::string day = std::to_string(date->Day);

	std::string folders = "data/" + year + "/" + month;
	std::filesystem::create_directories(folders);

	std::string filePath = folders + "/" + day + ".txt";

	AddToFile(filePath, formattedTodos);
	AddToPaths(filePath);

	array<System::String^>^ allTodos = getTodosFromFile(filePath);

	for each (FlowLayoutPanel^ column in toDoForm->panelMain->Controls)
	{
		for each (FlowLayoutPanel^ todoContainer in column->Controls)
		{
			if (todoContainer->Name == L"toDo-" + fullDate) {
				FlowLayoutPanel^ checkBoxContainer = dynamic_cast<FlowLayoutPanel^>(todoContainer->Controls[1]);

				for each (String^ todoString in formattedTodos)
				{
					std::vector<std::string> todoSplitted = split(toStandardString(todoString), " / ");
					bool isChecked = false;
					if (todoSplitted[1] == "true") {
						isChecked = true;
					}
					CheckBox^ checkBox = toDoForm->createItem(gcnew String(todoSplitted[0].c_str()), isChecked);
					checkBoxContainer->Controls->Add(checkBox);
				}
				return;
			}
		}
	}

	FlowLayoutPanel^ toDo = toDoForm->createToDo(fullDate, allTodos, filePath);

	for each (FlowLayoutPanel ^ column in toDoForm->panelMain->Controls)
	{
		if (column->Name == gcnew String(WeekDaysForColumns[int(date->DayOfWeek)].c_str())) {
			column->Controls->Add(toDo);
			column->Height += 1;
			break;
		}
	}
}
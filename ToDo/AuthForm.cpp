#include "AuthForm.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <map>
#include "Split.h"
#include "ToDoForm.h"


System::Void ToDo::AuthForm::buttonSignIn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxLogin->Text->Trim()->Length == 0) {
		this->labelMsg->Text = L"������� �����";
		return;
	}
	if (this->textBoxPassword->Text->Trim()->Length == 0) {
		this->labelMsg->Text = L"������� ������";
		return;
	}

	std::ifstream fin;
	std::filesystem::path path = "data/users.txt";

	if (std::filesystem::exists(path)) {
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
				std::string login = split(str, "/")[0];
				std::string password = split(str, "/")[1];

				if (gcnew String(login.c_str()) == this->textBoxLogin->Text->Trim()) {
					if (gcnew String(password.c_str()) == this->textBoxPassword->Text->Trim()) {
						fin.close();

						ToDoForm^ toDoForm = gcnew ToDoForm(gcnew String(login.c_str()));
						toDoForm->Show();
						this->Hide();
					}
					this->labelMsg->Text = L"�������� ������";
					fin.close();
					return;
				}
			}
		}
		this->labelMsg->Text = L"������������ �� ������";
		fin.close();
		return;
	}
	else {
		this->labelMsg->Text = L"��� ������ �������� �����������";
	}
}

System::Void ToDo::AuthForm::AuthForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
}

System::Void ToDo::AuthForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Owner->Show();
	this->Hide();
}

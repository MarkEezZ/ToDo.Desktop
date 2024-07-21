#include "RegForm.h"
#include "AuthForm.h"
#include <filesystem>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array < String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(0);
	ToDo::RegForm regForm;
	Application::Run(% regForm);
}


System::Void ToDo::RegForm::buttonReg_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxName->Text->Trim()->Length == 0) {
		this->labelMsg->Text = L"Имя не может быть пустым.";
		return;
	}
	else if (this->textBoxName->Text->IndexOf("/") != -1) {
		this->labelMsg->Text = L"Имя не может содержать /.";
		return;
	}

	else if (this->textBoxLogin->Text->IndexOf(" ") != -1) {
		this->labelMsg->Text = L"Логин не может содержать пробелы.";
		return;
	}
	else if (this->textBoxLogin->Text->Trim()->Length < 4) {
		this->labelMsg->Text = L"Логин не может быть меньше 4 символов.";
		return;
	}
	else if (this->textBoxName->Text->IndexOf("/") != -1) {
		this->labelMsg->Text = L"Логин не может содержать /.";
		return;
	}

	else if (this->textBoxPassword1->Text->Trim()->Length < 4) {
		this->labelMsg->Text = L"Пароль не может быть меньше 4 символов.";
		return;
	}
	else if (this->textBoxPassword1->Text->IndexOf(" ") != -1) {
		this->labelMsg->Text = L"Пароль не может содержать пробелы.";
		return;
	}
	else if (this->textBoxPassword1->Text->IndexOf("/") != -1) {
		this->labelMsg->Text = L"Пароль не может содержать /.";
		return;
	}
	else if (this->textBoxPassword2->Text->Trim() != this->textBoxPassword1->Text->Trim()) {
		this->labelMsg->Text = L"Пароли не совпадают.";
		return;
	}

	this->labelMsg->Text = L"";

	std::filesystem::path folder = "data/";
	std::filesystem::path path = "data/users.txt";

	if (!std::filesystem::exists(path)) {
		std::filesystem::create_directory(folder);
	}

	IO::FileStream^ stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::OpenOrCreate);
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(stream);

	while (sr->Peek() >= 0)
	{
		if (sr->ReadLine()->Split('/')[0] == this->textBoxLogin->Text) {
			this->labelMsg->Text = L"Данный логин занят.";

			stream->Close();
			sr->Close();

			return;
		}
	}

	stream->Close();
	sr->Close();

	if (std::filesystem::exists(path)) {
		stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::Append);
	}
	else {
		stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::OpenOrCreate);
	}

	IO::StreamWriter^ swr = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));;

	swr->WriteLine(
		this->textBoxLogin->Text->Trim() + "/" +
		this->textBoxPassword1->Text->Trim() + "/" +
		this->textBoxName->Text->Trim()
	);

	swr->Close();
	stream->Close();

	AuthForm^ authForm = gcnew AuthForm();
	authForm->Show();
	this->Hide();
}


System::Void ToDo::RegForm::buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e)
{
	AuthForm^ authForm = gcnew AuthForm();
	authForm->Owner = this;
	authForm->Show();
	this->Hide();
}

System::Void ToDo::RegForm::RegForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	Application::Exit();
}

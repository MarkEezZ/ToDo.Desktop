#pragma once
#include <filesystem>

static void AddToFile(std::filesystem::path path, array<System::String^>^ todos)
{
	System::IO::FileStream^ stream;
	System::IO::StreamWriter^ swr;

	if (std::filesystem::exists(path)) {
		stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::Append);
		swr = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));
	}
	else {
		stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::OpenOrCreate);
		swr = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));
	}

	for (int i = 0; i < todos->Length; i++) {
		swr->WriteLine(todos[i]);
	}

	swr->Close();
	stream->Close();
}


static void AddToPaths(std::string newTodoPath)
{
	std::filesystem::path path = "data/paths.txt";
	bool isExist = false;

	std::ifstream fin;
	try {
		fin.open(path);
	}
	catch (const std::exception& ex) {
		throw ex;
	}

	while (!fin.eof()) {
		std::string str;
		std::getline(fin, str);

		if (str == newTodoPath) {
			isExist = true;
			break;
		}
	}

	fin.close();

	if (!isExist) {
		System::IO::FileStream^ stream;
		System::IO::StreamWriter^ swr;

		if (std::filesystem::exists(path)) {
			stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::Append);
			swr = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));
		}
		else {
			stream = System::IO::File::Open(gcnew System::String(path.c_str()), System::IO::FileMode::OpenOrCreate);
			swr = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));
		}

		swr->WriteLine((gcnew System::String(newTodoPath.c_str()))->Trim());

		swr->Close();
		stream->Close();
	}
}
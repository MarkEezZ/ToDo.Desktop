#include <fstream>
#include <filesystem>
#pragma once

static array<System::String^>^ getTodosFromFile(std::filesystem::path path) {
	if (!std::filesystem::exists(path)) {
		return gcnew array<System::String^>(0);
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

	array<System::String^>^ allTodos = gcnew array<System::String^>(records.size());
	for (size_t i = 0; i < records.size(); i++) {
		allTodos[i] = gcnew System::String(records[i].c_str());
	}

	return allTodos;
}

#include "Settings.h"
#include "string"

Settings::Settings() {
	fin.open("Settings.txt");
}

Settings& Settings::get_instance() {
	static Settings settings;
	return settings;
}

float Settings::get_parametr(Parametr parametr) {
	mutex.lock();
	float result = 0;
	string current_string;
	bool param_is_founded = false;
	while (!fin.eof()) {
		getline(fin, current_string);

		int value_pos = current_string.find("=") + 1;
		string substr_contained_value;
		substr_contained_value = current_string.substr(value_pos);

		switch (parametr) {
		case Parametr::lecturer_salary:
			if (current_string.find("ЗП преподавателей") == 0) {
				param_is_founded = true;
				result = atof(substr_contained_value.c_str());
			}
			break;
		case Parametr::lab_assistant_salary:
			if (current_string.find("ЗП лаборантов") == 0) {
				param_is_founded = true;
				result = atof(substr_contained_value.c_str());
			}
			break;
		case Parametr::bonus:
			if (current_string.find("Премия") == 0) {
				param_is_founded = true;
				result = atof(substr_contained_value.c_str());
			}
			break;
		}

		if (param_is_founded)
			break;
	}
	fin.seekg(0);
	mutex.unlock();
	return result;
}
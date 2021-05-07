#pragma once
#include <fstream>
#include <mutex>

using namespace std;

enum class Parametr
{
	lecturer_salary,
	lab_assistant_salary,
	bonus
};

class Settings
{
private:
	Settings();
	ifstream fin;
	mutex mutex;
public:
	static Settings& get_instance();
	float get_parametr(Parametr);
};


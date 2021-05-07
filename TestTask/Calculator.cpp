#include "Calculator.h"
#include "Settings.h"

float Calculator::calculate_salary_summ(vector<Account*> accounts) {
	float result = 0;

	for (int i = 0; i < accounts.size(); i++) {
		float salary = 0;
		switch (accounts[i]->get_position()) {
		case Position::lab_assistant: 
			salary = Settings::get_instance().get_parametr(Parametr::lab_assistant_salary);
			break;
		case Position::lecturer:
			salary = Settings::get_instance().get_parametr(Parametr::lecturer_salary);
			break;
		}
		result += (1 + Settings::get_instance().get_parametr(Parametr::bonus) / 100) * salary;
	}
	return result;
}
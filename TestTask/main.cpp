#include <iostream>
#include "Calculator.h"
#include <thread>


int main() {
	setlocale(LC_ALL, "Rus");


	Account acc1(Position::lecturer);
	Account acc2(Position::lecturer);
	Account acc3(Position::lab_assistant);
	vector<Account*> accounts = { &acc1, &acc2, &acc3 };

	cout << "Суммарные расходы: " << Calculator::calculate_salary_summ(accounts) << endl;

	system("pause");
}
#pragma once
#include "Account.h"
#include "vector"

using namespace std;

class Calculator
{
private:
	Calculator();

public:
	static float calculate_salary_summ(vector<Account*>);
};


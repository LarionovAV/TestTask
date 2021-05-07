#include <string>

using namespace std;
#pragma once
enum class Position {
	lecturer,
	lab_assistant
};
class Account
{
private:
	Position pos;

public:
	Account(Position pos);
	Position get_position();
};


#include "Account.h"

Position Account::get_position() {
	return pos; 
}

Account::Account(Position pos) {
	this->pos = pos;
}

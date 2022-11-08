#pragma once
#include <iostream>
#include "enemy.h"

using std::string;

class troll : public enemy
{
private:
	int mRegen;
	static int mNumberOfTrolls;
public:
	troll();
	troll(int _regen);
	~troll();

	void attack();
	int getSpeed();
	void regenerate();
};


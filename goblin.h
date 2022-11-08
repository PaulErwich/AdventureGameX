#pragma once
#include <iostream>
#include "enemy.h"

class goblin : public enemy
{
private:
	bool mExtraSpeed;
	static int mNumberOfGoblins;
public:
	goblin();
	goblin(bool _extraSpeed);
	~goblin();
	
	int getSpeed();

	static int getNumberOfGoblins();
};


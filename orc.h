#pragma once
#include <iostream>
#include "enemy.h"

using std::string;

class orc : public enemy
{
private:
	bool mExtraStrength;
	static int mNumberOfOrcs;
public:
	orc();
	orc(bool _extraStrength);
	~orc();

	void attack();
	int getSpeed();
};


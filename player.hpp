#pragma once
#include <iostream>
#include "entity.hpp"
#include "enemy.h"

using std::cout;
using std::cin;
using std::string;

class player : public entity
{
private:
	string mName;
	int mExperience;

	weapon* mSword;
	weapon* mSpear;
	weapon* mDaggers;
	weapon* mBow;

public:
	player();
	player(string _name, int _maxHealth, int _speed, int _attack, typeArmor _armor, int _level);
	~player();

	void playerAttack(entity &_defender);

	void displayStats();

	void increaseExp(int _expAmount);
	void levelCheck();
	void levelUp();

	void weaponSwap();
};

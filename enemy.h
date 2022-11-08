#pragma once
#include <iostream>
#include "entity.hpp"

enum class typeSize {SMALL, MEDIUM, LARGE, GIANT};

class enemy : public entity
{
protected:
	std::string mSpecies;
	typeSize mSize;
	int mExpDropped;
public:
	enemy();
	enemy(string _species, typeSize _size, int _expGiven, int _maxHealth, int _speed, int _attack, typeArmor _armor, int _level);
	virtual ~enemy();

	void enemyAttack(entity& _defender);

	string getSpecies();
	int getExpDropped();

	virtual void regenerate();
};


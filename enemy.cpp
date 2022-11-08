#include "enemy.h"

enemy::enemy()
{
	mSpecies = "Goblin";
	mSize = typeSize::SMALL;
	mExpDropped = 10;
}

enemy::enemy(string _species, typeSize _size, int _expGiven, int _maxHealth, int _speed, int _attack, typeArmor _armor, int _level) : entity(_maxHealth, _speed, _attack, _level, _armor)
{
	mSpecies = _species;
	mSize = _size;
	mExpDropped = _expGiven;
}

enemy::~enemy()
{
}

void enemy::enemyAttack(entity& _defender)
{
	cout << "--------------------------\n";
	cout << "The " << mSpecies << " attacks you with their " << mEquipedWeapon->getWeaponName() << "\n";

	int damage = attack(_defender);

	cout << "They did " << damage << " damage.\n";
	cout << "You have " << _defender.getCurrentHealth() << "hp left.\n";
	cout << "--------------------------\n";

	if (mSpecies == "Troll")
		regenerate();
}

string enemy::getSpecies() { return mSpecies; }

int enemy::getExpDropped() { return mExpDropped; }

void enemy::regenerate()
{
	//Blank function so i can call the function created in the troll class using the virtual keyword.
}



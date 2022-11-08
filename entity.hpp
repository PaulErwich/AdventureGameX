#pragma once
#include <iostream>
#include "weapon.hpp"

//Using an enum class instead of declaring the enum inside the class
//This means it can be accessed and used in places other than the class
//Because it's its own class
enum class typeArmor { NONE, LIGHT, MEDIUM, HEAVY };

class entity
{
protected:
	int mMaxHealth;
	int mCurrentHealth;
	int mSpeed;
	int mAttack;
	typeArmor mArmor;
	std::string mArmorName;
	weapon* mEquipedWeapon;

	int mLevel;
public:
	entity();
	//entity(int _maxHealth, int _speed, int _attack, int _level, typeArmor _armor);
	entity(int, int, int, int, typeArmor);
	~entity();

	//Attack methods, as it's been made in the entity class it will be inherited
	//The method can also directly access protected attributes of the defender as they're in the same class.
	int attack(entity &_defender);

	int getCurrentHealth();
	int getSpeed();
	typeWield getWeaponTypeWield();
	int getHitChance();

};








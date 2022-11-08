#pragma once
#include <iostream>

using std::cout;
using std::string;

#define random(min, max) rand() % (max + 1 - min) + min

enum class attackType {MELEE, EXTENDED_MELEE, THROWABLE_MELEE, RANGED};

enum class typeWield {ONE_HANDED, TWO_HANDED, DUEL_WIELD};

class weapon
{
private:
	string mWeaponName;
	int mDamageMax;
	int mDamageMin;
	attackType mAttackType;
	string mAttackTypeName;
	typeWield mWield;
	string mWieldName;
	int mHitChance;

	bool mIgnoreArmor;

public:
	weapon();
	weapon(string _weaponName, int _maxDamage, int _minDamage, attackType _attackType, typeWield _wield, int _hitChance, bool _ignoreArmor);
	~weapon();

	int getRandomDamage();
	string getWeaponName();
	bool getIgnoreArmor();
	typeWield getTypeWield();
	int getHitChance();

	void displayWeaponStats();
	
};


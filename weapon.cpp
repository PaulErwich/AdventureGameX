#include "weapon.hpp"

weapon::weapon()
{
	mWeaponName = "Short Sword";
	mDamageMax = 8;
	mDamageMin = 5;
	mAttackType = attackType::MELEE;
	switch (mAttackType)
	{
	case attackType::MELEE:
		mAttackTypeName = "Melee";
		break;
	case attackType::EXTENDED_MELEE:
		mAttackTypeName = "Extended Melee";
		break;
	case attackType::THROWABLE_MELEE:
		mAttackTypeName = "Throwable Melee";
		break;
	case attackType::RANGED:
		mAttackTypeName = "Ranged";
		break;
	}

	mWield = typeWield::ONE_HANDED;
	switch (mWield)
	{
	case typeWield::ONE_HANDED:
		mWieldName = "One handed";
		break;
	case typeWield::TWO_HANDED:
		mWieldName = "Two handed";
		break;
	case typeWield::DUEL_WIELD:
		mWieldName = "Duel Wield";
		break;
	}

	mHitChance = 100;
	mIgnoreArmor = false;
}

weapon::weapon(string _weaponName, int _maxDamage, int _minDamage, attackType _attackType, typeWield _wield, int _hitChance, bool _ignoreArmor)
{
	mWeaponName = _weaponName;
	mDamageMax = _maxDamage;
	mDamageMin = _minDamage;
	mAttackType = _attackType;
	switch (mAttackType)
	{
	case attackType::MELEE:
		mAttackTypeName = "Melee";
		break;
	case attackType::EXTENDED_MELEE:
		mAttackTypeName = "Extended Melee";
		break;
	case attackType::THROWABLE_MELEE:
		mAttackTypeName = "Throwable Melee";
		break;
	case attackType::RANGED:
		mAttackTypeName = "Ranged";
		break;
	}

	mWield = _wield;
	switch (mWield)
	{
	case typeWield::ONE_HANDED:
		mWieldName = "One handed";
		break;
	case typeWield::TWO_HANDED:
		mWieldName = "Two handed";
		break;
	case typeWield::DUEL_WIELD:
		mWieldName = "Duel Wield";
		break;
	}
	mHitChance = _hitChance;

	mIgnoreArmor = _ignoreArmor;
}

weapon::~weapon()
{

}

bool weapon::getIgnoreArmor() { return mIgnoreArmor; }

typeWield weapon::getTypeWield()
{
	return mWield;
}

void weapon::displayWeaponStats()
{
	cout << "======WEAPON STATS======\n";
	cout << "Weapon name: " << mWeaponName << "\n";
	cout << "Maximum weapon damage: " << mDamageMax << "\n";
	cout << "Minimum weapon damage: " << mDamageMin << "\n";
	cout << "Weapon attack type: " << mAttackTypeName << "\n";
	cout << "Wield: " << mWieldName << "\n";
}

string weapon::getWeaponName() { return mWeaponName; }

int weapon::getHitChance() { return mHitChance; }

int weapon::getRandomDamage()
{ 
	int damage;
	damage = random(mDamageMin, mDamageMax);
	return damage; 
}

#include "troll.h"

troll::troll()
{
	mMaxHealth = 75;
	mCurrentHealth = mMaxHealth;
	mSpeed = 10;
	mAttack = 10;
	mArmor = typeArmor::MEDIUM;
	mArmorName = "Medium";
	mEquipedWeapon = new weapon("Battle Axe", 20, 10, attackType::MELEE, typeWield::TWO_HANDED, 100, false);

	mSpecies = "Troll";
	mSize = typeSize::LARGE;
	mExpDropped = 50;

	mRegen = 5;
	mNumberOfTrolls++;
}

troll::troll(int _regen)
{
	mMaxHealth = 75;
	mCurrentHealth = mMaxHealth;
	mSpeed = 10;
	mAttack = 10;
	mArmor = typeArmor::MEDIUM;
	mArmorName = "Medium";
	mEquipedWeapon = new weapon;

	mSpecies = "Troll";
	mSize = typeSize::LARGE;
	mExpDropped = 50;

	mRegen = _regen;
	mNumberOfTrolls++;
}

troll::~troll()
{
	mNumberOfTrolls--;
}

int troll::getSpeed() { return mSpeed; }

void troll::regenerate()
{
	mCurrentHealth += mRegen;
	if (mCurrentHealth > mMaxHealth) mCurrentHealth = mMaxHealth;
}

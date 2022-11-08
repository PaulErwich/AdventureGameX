#include "orc.h"

orc::orc()
{
	mMaxHealth = 50;
	mCurrentHealth = mMaxHealth;
	mSpeed = 10;
	mAttack = 10;
	mArmor = typeArmor::LIGHT;
	mArmorName = "Light";
	mEquipedWeapon = new weapon("Club", 12, 8, attackType::MELEE, typeWield::TWO_HANDED, 100, false);

	mSpecies = "Orc";
	mSize = typeSize::MEDIUM;
	mExpDropped = 30;

	mExtraStrength = false;
	mNumberOfOrcs++;
}

orc::orc(bool _extraStrength)
{
	mMaxHealth = 50;
	mCurrentHealth = mMaxHealth;
	mSpeed = 10;
	mAttack = 10;
	mArmor = typeArmor::LIGHT;
	mArmorName = "Light";
	mEquipedWeapon = new weapon("Club", 12, 8, attackType::MELEE, typeWield::TWO_HANDED, 100, false);

	mSpecies = "Orc";
	mSize = typeSize::MEDIUM;

	mExtraStrength = _extraStrength;

	if (mExtraStrength == true)
		mAttack += 5;

	mNumberOfOrcs++;
}

orc::~orc()
{
	mNumberOfOrcs--;
}

int orc::getSpeed() { return mSpeed; }

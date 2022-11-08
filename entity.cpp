#include "entity.hpp"


entity::entity()
{
	mMaxHealth = 20;
	mCurrentHealth = mMaxHealth;
	mSpeed = 20;
	mAttack = 2;
	mArmor = typeArmor::NONE;
	mArmorName = "None";
	mLevel = 1;
	mEquipedWeapon = new weapon;
}

entity::entity(int _maxHealth, int _speed, int _attack, int _level, typeArmor _armor)
{
	mMaxHealth = _maxHealth;
	mCurrentHealth = mMaxHealth;
	mSpeed = _speed;
	mAttack = _attack;
	mArmor = _armor;
	switch (mArmor)
	{
	case typeArmor::NONE:
		mArmorName = "None";
		break;
	case typeArmor::LIGHT:
		mArmorName = "Light";
		break;
	case typeArmor::MEDIUM:
		mArmorName = "Medium";
		break;
	case typeArmor::HEAVY:
		mArmorName = "Heavy";
		break;
	}
	mLevel = _level;
	mEquipedWeapon = new weapon;
}

entity::~entity()
{
	delete mEquipedWeapon;
	mEquipedWeapon = NULL;
}

int entity::attack(entity &_defender)
{
	float damage = mAttack + mEquipedWeapon->getRandomDamage();

	if (mEquipedWeapon->getIgnoreArmor() == false)
	{
		switch (_defender.mArmor)
		{
		case typeArmor::LIGHT:
			damage = damage * 0.8;
			break;
		case typeArmor::MEDIUM:
			damage = damage * 0.6;
			break;
		case typeArmor::HEAVY:
			damage = damage * 0.4;
			break;
		default:
			break;
		}
	}
	
	//Used to round damage to nearest whole number after it's multiplied due to armor.
	//This stops the attack doing extra damage if the damage is lower than X.5;
	damage = round(damage);

	_defender.mCurrentHealth -= damage;

	if (_defender.mCurrentHealth < 0)
		_defender.mCurrentHealth = 0;

	return damage;
}

int entity::getCurrentHealth() { return mCurrentHealth; }

int entity::getSpeed() { return mSpeed; }

int entity::getHitChance() { return mEquipedWeapon->getHitChance(); }

typeWield entity::getWeaponTypeWield() { return mEquipedWeapon->getTypeWield(); }

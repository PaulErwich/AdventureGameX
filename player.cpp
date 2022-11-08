#include "player.hpp"

player::player()
{
	mName = "Player";
	mExperience = 0;

	mSword = new weapon("Sword", 14, 10, attackType::MELEE, typeWield::ONE_HANDED, 100, false);
	mSpear = new weapon("Spear", 10, 8, attackType::EXTENDED_MELEE, typeWield::TWO_HANDED, 100, true);
	mDaggers = new weapon("Daggers", 6, 4, attackType::THROWABLE_MELEE, typeWield::DUEL_WIELD, 100, false);
	mBow = new weapon("Bow", 18, 14, attackType::RANGED, typeWield::TWO_HANDED, 80, false);
}

player::player(string _name, int _maxHealth, int _speed, int _attack, typeArmor _armor, int _level) : entity(_maxHealth, _speed, _attack, _level, _armor)
{
	mName = _name;
	mExperience = 0;

	mSword = new weapon("Sword", 14, 10, attackType::MELEE, typeWield::ONE_HANDED, 100, false);
	mSpear = new weapon("Spear", 10, 8, attackType::EXTENDED_MELEE, typeWield::TWO_HANDED, 100, true);
	mDaggers = new weapon("Daggers", 6, 4, attackType::THROWABLE_MELEE, typeWield::DUEL_WIELD, 100, false);
	mBow = new weapon("Bow", 18, 14, attackType::RANGED, typeWield::TWO_HANDED, 80, false);
}

player::~player() 
{
}

void player::playerAttack(entity &_defender)
{
	cout << "--------------------------\n";
	cout << "You attack the enemy with your " << mEquipedWeapon->getWeaponName() << "\n";

	int damage = attack(_defender);

	cout << "Your attack did " << damage << " damage.\n";
	cout << "The enemy has " << _defender.getCurrentHealth() << "hp left.\n";
	cout << "--------------------------\n";
}

void player::displayStats()
{
	cout << "=======DISPLAY STATS=======\n";
	cout << "Name: " << mName << "\n";
	cout << "Max health: " << mMaxHealth << "\n";
	cout << "Current health: " << mCurrentHealth << "\n";
	cout << "Speed: " << mSpeed << "\n";
	cout << "Attack: " << mAttack << "\n";
	cout << "Armor: " << mArmorName << "\n";
	cout << "Equiped weapon: " << mEquipedWeapon->getWeaponName() << "\n";
	cout << "Level: " << mLevel << "\n";
	cout << "Experience for level up: " << mExperience << "/100\n";
	mEquipedWeapon->displayWeaponStats();
}

void player::increaseExp(int _expGained)
{
	mExperience += _expGained;
}

void player::levelCheck()
{
	if (mExperience >= 100)
	{
		int extraExperience = (mExperience - 100);
		mExperience = extraExperience;
		levelUp();
	}
}

void player::levelUp()
{
	cout << "You have leveled up.\n";
	mMaxHealth += 10;
	mCurrentHealth += 50;
	mAttack += 2;
	mLevel++;
	displayStats();
}

void player::weaponSwap()
{
	int choice = 0;

	cout << "\nChoose the weapon you'd like to use.\n";
	cout << "1 - Sword, moderate damage\n";
	cout << "2 - Spear, less damage, ignores armor\n";
	cout << "3 - Daggers, less damage, two attacks\n";
	cout << "4 - Bow, higher damage, can miss\n";
	cout << "5 - Heal for 40 hit poitns\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		mEquipedWeapon = mSword;
		cout << "You have chosen the sword for this combat.\n";
		break;
	case 2:
		mEquipedWeapon = mSpear;
		cout << "You have chosen the spear for this combat.\n";
		break;
	case 3:
		mEquipedWeapon = mDaggers;
		cout << "You have chosen the daggers for this combat.\n";
		break;
	case 4:
		mEquipedWeapon = mBow;
		cout << "You have chosen the bow for this combat.\n";
		break;
	case 5:
		mCurrentHealth += 40;
		if (mCurrentHealth > mMaxHealth)
			mCurrentHealth = mMaxHealth;
		cout << "You have healed 40 hit points.\n";
		cout << "You now have " << mCurrentHealth << " hit points remaining.\n";
		break;
	default:
		mEquipedWeapon = mSword;
		cout << "Incorrect input, defaulting to Sword for this combat.\n";
		break;
	}

}

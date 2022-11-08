#include "goblin.h"

goblin::goblin()
{
	mExtraSpeed = false;
	mNumberOfGoblins++;
}

goblin::goblin(bool _extraSpeed)
{
	mExtraSpeed = _extraSpeed;
	if (mExtraSpeed == true)
		mSpeed += 5;
	mNumberOfGoblins++;
}

goblin::~goblin()
{
	mNumberOfGoblins--;
}

int goblin::getSpeed() { return mSpeed; }


int goblin::getNumberOfGoblins() { return mNumberOfGoblins; }

#include "grid.h"

grid::grid()
{
	x = 0;
	y = 0;
}

grid::grid(player *_player)
{
	mPlayer = _player;
	x = 0;
	y = 0;
}

grid::~grid()
{
	mPlayer = NULL;

}

void grid::setPlayer(player* _player)
{
	mPlayer = _player;
}

void grid::displayMaze()
{
	Sleep(1000);
	cout << "======MAP======\n";
	
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			Sleep(100);
			cout << " " << maze[j][i] << " ";
		}
		cout << "\n\n";
	}
	cout << "======MAP======\n";
}

void grid::playerMove()
{
	char playerChoice;
	int currentX = x;
	int currentY = y;

	cout << "You're currently here:\n";
	displayMaze();
	cout << "Which way do you want to go? (U, D, L, R)\n";
	cin >> playerChoice;


	switch (playerChoice)
	{
	case 'U':
	case 'u':
	{
		y--;
		moveChecker();
		maze[currentY][currentX] = 'X';
		maze[y][x] = 'O';
		break;
	}
	case 'D':
	case 'd':
	{
		y++;
		moveChecker();
		maze[currentY][currentX] = 'X';
		maze[y][x] = 'O';
		break;
	}
	case 'L':
	case 'l':
	{
		x--;
		moveChecker();
		maze[currentY][currentX] = 'X';
		maze[y][x] = 'O';
		break;
	}
	case 'R':
	case 'r':
	{
		x++;
		moveChecker();
		maze[currentY][currentX] = 'X';
		maze[y][x] = 'O';
		break;
	}
	default:
		cout << "Please enter a character listed\n";
		playerMove();
	}

	cout << "You've now entered a new room\n";
	
}

void grid::moveChecker()
{
	int outOfBounds = 0;

	// checks if the player has moved outside of the map
	// and if so returns them to their previous position
	if (x < 0 || y < 0 || x >(5 - 1) || y >(5 - 1))
	{
		x = (x > (5 - 1)) ? (5 - 1) : x;
		x = (x < 0) ? 0 : x;
		y = (y > (5 - 1)) ? (5 - 1) : y;
		y = (y < 0) ? 0 : y;
		outOfBounds = 1;
	}

	if (outOfBounds == 1)
	{
		cout << "You can't go that way!\n";

		playerMove();
	}
}

void grid::roomChecker()
{
	switch (mazeChecker[y][x])
	{
	case 1:
		startRoom();
		break;
	case 2:
		goblinRoomMK1();
		break;
	case 3:
		goblinRoomMK2();
		break;
	case 4:
		orcRoomMK1();
		break;
	case 5:
		orcRoomMK2();
		break;
	case 6:
		goblinRoomMK1();
		break;
	case 7:
		goblinRoomMK2();
		break;
	case 8:
		orcRoomMK1();
		break;
	case 9:
		orcRoomMK2();
		break;
	case 10:
		trollRoomMK1();
		break;
	case 11:
		goblinRoomMK2();
		break;
	case 12:
		orcRoomMK1();
		break;
	case 13:
		orcRoomMK2();
		break;
	case 14:
		trollRoomMK1();
		break;
	case 15:
		trollRoomMK2();
		break;
	case 16:
		orcRoomMK1();
		break;
	case 17:
		orcRoomMK2();
		break;
	case 18:
		trollRoomMK1();
		break;
	case 19:
		trollRoomMK2();
		break;
	case 20:
		giantRoom();
		break;
	case 21:
		orcRoomMK2();
		break;
	case 22:
		trollRoomMK1();
		break;
	case 23:
		trollRoomMK2();
		break;
	case 24:
		giantRoom();
		break;
	case 25:
		endRoom();
		break;
	}
}

void grid::startRoom()
{
	cout << "======START ROOM======\n";
	Sleep(1000);
	cout << "Hello and welcome to X.\n";
	Sleep(1000);
	cout << "You have been put in this maze because of your crimes against the state.\n";
	Sleep(1000);
	cout << "As i'm a generous person, AI, thingy. I will give you a chance at freedom.\n";
	Sleep(1000);
	cout << "If you manage to clear out EVERY room in this maze, you will be allowed to leave.\n";
	Sleep(1000);
	cout << "However, failure to do so will result in severe consequences.\n\n";
	Sleep(3000);
	cout << "Before you start, here's how to play:\n";
	Sleep(1000);
	cout << "Use U/D/L/R to move around, they stand for Up/Down/Left/Right, respectively.\n";
	Sleep(1000);
	cout << "Before each combat, you will be asked which weapon you'd like, or if you want to heal.\n";
	Sleep(1000);
	cout << "If you choose to heal, you won't be able to change your weapon from the last combat you did.\n";
	Sleep(1000);
	cout << "That's about it really, good luck! And don't die to fast.\n";
	Sleep(1000);

	displayMaze();
	maze[y + 1][x] = '!';
	maze[y][x + 1] = '!';
}

void grid::goblinRoomMK1()
{
	goblin goblinOne;

	cout << "======GOBLIN ROOM======\n";
	Sleep(500);
	cout << "Welcome to a Goblin room.\n";
	Sleep(500);
	cout << "There is 1 enemy in this room which you must defeat.\n";
	Sleep(500);
	cout << "After doing so you will unlock the adjacent rooms.\n";
	Sleep(500);
	cout << "In this room you will face a " << goblinOne.getSpecies() << ".\n";
	Sleep(500);
	cout << "Now combat will begin, good luck!\n";
	Sleep(500);

	fullCombat(goblinOne);

	afterCombat(goblinOne);
}

void grid::goblinRoomMK2()
{
	goblin goblinOne(true);

	cout << "======GOBLIN ROOM V2======\n";
	Sleep(500);
	cout << "Welcome to the second iteration of the Goblin room.\n";
	Sleep(500);
	cout << "There is still 1 enemy, but he's faster than before.\n";
	Sleep(500);
	cout << "As always, you will unlock adjacent rooms after completing this one.\n";
	Sleep(500);
	cout << "In this room you will face a " << goblinOne.getSpecies() << ".\n";
	Sleep(500);
	cout << "Now combat will begin, good luck!\n";
	Sleep(500);

	fullCombat(goblinOne);

	afterCombat(goblinOne);
}

void grid::orcRoomMK1()
{
	orc orcOne;

	cout << "======ORC ROOM======\n";
	Sleep(500);
	cout << "Welcome to the Orc room.\n";
	Sleep(500);
	cout << "There will be a new type of enemy in this room.\n";
	Sleep(500);
	cout << "This enemy is the " << orcOne.getSpecies() << ".\n";
	Sleep(500);
	cout << "As before, you will unlock adjacent rooms after completing this one.\n";
	Sleep(500);
	cout << "Now combat will begin, good luck!\n";
	Sleep(500);

	fullCombat(orcOne);

	afterCombat(orcOne);
}

void grid::orcRoomMK2()
{
	orc orcOne(true);

	cout << "======ORC ROOM MK2======\n";
	Sleep(500);
	cout << "Welcome to the second iteration of the Orc room.\n";
	Sleep(500);
	cout << "You will still fight 1 enemy in this room, but he's stronger than before.\n";
	Sleep(500);
	cout << "Like always, you will unlock adjacent rooms after completing this one.\n";
	Sleep(500);
	cout << "Now combat will beign, good luck!\n";
	Sleep(500);

	fullCombat(orcOne);

	afterCombat(orcOne);

}

void grid::trollRoomMK1()
{
	troll trollOne;

	cout << "======TROLL ROOM======\n";
	Sleep(500);
	cout << "Welcome to the Troll room.\n";
	Sleep(500);
	cout << "In this room you will be fighting a " << trollOne.getSpecies() << ".\n";
	Sleep(500);
	cout << "This enemy will regenerate some HP after each attack it makes, so hope you kill it quick!\n";
	Sleep(500);
	cout << "As normal, you will unlock adjacent rooms after completing this one.\n";
	Sleep(500);
	cout << "Now combat will begin, good luck!\n";
	Sleep(500);

	fullCombat(trollOne);

	afterCombat(trollOne);
}

void grid::trollRoomMK2()
{
	troll trollOne(10);

	cout << "======TROLL ROOM MK2======\n";
	Sleep(500);
	cout << "Welcome to the second iteration of the troll room.\n";
	Sleep(500);
	cout << "In this room you will still face 1 troll but he will have increased regeneration.\n";
	Sleep(500);
	cout << "Like usual, you will unlock rooms adjacent to this one if you win.\n";
	Sleep(500);
	cout << "Now combat will begin, good luck!\n";
	Sleep(500);

	fullCombat(trollOne);

	afterCombat(trollOne);
}

void grid::giantRoom()
{
	enemy giantOne("Giant", typeSize::GIANT, 100, 200, 5, 15, typeArmor::LIGHT, 1);
	
	cout << "======GIANTS ROOM======\n";
	Sleep(500);
	cout << "Welcome to the hardest room within the Maze.\n";
	Sleep(500);
	cout << "In this room you will be fighting a GIANT.\n";
	Sleep(500);
	cout << "The GIANT doesn't have anything special about him.\n";
	Sleep(500);
	cout << "On the other hand, he does have more health and deal more damage.\n";
	Sleep(500);
	cout << "If you win, you will unlock the end room of this maze.\n";
	Sleep(500);
	cout << "Now combat will begin, good luck!\n";
	Sleep(500);

	fullCombat(giantOne);

	afterCombat(giantOne);
}

void grid::endRoom()
{
	int roomsCleared = 0;

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (maze[j][i] == 'X')
				roomsCleared++;
		}
	}

	if (roomsCleared == 24)
	{
		cout << "Well done, you have managed to clear every room within the maze.\n";
		Sleep(1000);
		cout << "You have now completed the game and are free to leave whenever you're ready.\n";
		Sleep(3000);
		cout << "Just kidding :p.\n";
		Sleep(1000);
		cout << "You don't get to stay any longer, we're removing you from the maze, but at least you're now free.\n";
		Sleep(1000);
		cout << "If you're lucky, we won't need to see you again.\n";
		Sleep(1000);
		cout << "Alright goodbye!\n";
	}
	else if (roomsCleared < 24)
	{
		cout << "You have gone through the maze, but you have failed to clear every room!\n";
		Sleep(1000);
		cout << "For trying to leave the maze without clearing every room, you will be punished!\n";
		Sleep(3000);
		cout << "Due to you failing to clear every room before entering the last room, you will now die, goodbye.\n";

		exit(0);
	}

}

void grid::fullCombat(enemy &_enemy)
{	
	mPlayer->weaponSwap();
	Sleep(1000);

	while (mPlayer->getCurrentHealth() != 0 && _enemy.getCurrentHealth() != 0)
	{
		if (mPlayer->getSpeed() >= _enemy.getSpeed())
		{
			if (mPlayer->getWeaponTypeWield() == typeWield::DUEL_WIELD)
			{
				mPlayer->playerAttack(_enemy);
				Sleep(1000);
				mPlayer->playerAttack(_enemy);
				Sleep(1000);
			}
			else if (mPlayer->getHitChance() != 100)
			{
				int hit = random(0, 100);
				if (hit < mPlayer->getHitChance())
				{
					mPlayer->playerAttack(_enemy);
					Sleep(1000);
				}
				else if (hit > mPlayer->getHitChance())
				{
					cout << "--------------------------\n";
					cout << "You have missed your attack!\n";
					cout << "--------------------------\n";
					Sleep(1000);
				}
			}
			else
			{
				mPlayer->playerAttack(_enemy);
				Sleep(1000);
			}

			if (_enemy.getCurrentHealth() != 0)
				_enemy.enemyAttack(*mPlayer);
			Sleep(1000);
		}
		else if (mPlayer->getSpeed() < _enemy.getSpeed())
		{
			_enemy.enemyAttack(*mPlayer);
			Sleep(1000);

			if (mPlayer->getCurrentHealth() != 0)
				if (mPlayer->getWeaponTypeWield() == typeWield::DUEL_WIELD)
				{
					mPlayer->playerAttack(_enemy);
					Sleep(1000);
					mPlayer->playerAttack(_enemy);
					Sleep(1000);
				}
				else if (mPlayer->getHitChance() != 100)
				{
					int hit = random(0, 100);
					if (hit < mPlayer->getHitChance())
					{
						mPlayer->playerAttack(_enemy);
						Sleep(1000);
					}
					else if (hit > mPlayer->getHitChance())
					{
						cout << "--------------------------\n";
						cout << "You have missed your attack!";
						cout << "--------------------------\n";
						Sleep(1000);
					}
				}
				else
				{
					mPlayer->playerAttack(_enemy);
					Sleep(1000);
				}
		}
	}
}

void grid::afterCombat(enemy& _enemy)
{
	if (_enemy.getCurrentHealth() == 0)
	{
		cout << "Well done, you have managed to defeat the " << _enemy.getSpecies() << ".\n";
		cout << "You have now gained access to any locked rooms adjacent to this one.\n";
		mPlayer->increaseExp(_enemy.getExpDropped());
		cout << "You gained " << _enemy.getExpDropped() << "xp.\n";
		mPlayer->levelCheck();
		if (y != 4)
		{
			if (maze[y + 1][x] != '!' && maze[y + 1][x] != 'X')
				maze[y + 1][x] = '!';
		}

		if (y != 0)
		{
			if (maze[y - 1][x] != '!' && maze[y - 1][x] != 'X')
				maze[y - 1][x] = '!';
		}

		if (x != 4)
		{
			if (maze[y][x + 1] != '!' && maze[y][x + 1] != 'X')
				maze[y][x + 1] = '!';
		}

		if (x != 0)
		{
			if (maze[y][x - 1] != '!' && maze[y][x - 1] != 'X')
				maze[y][x - 1] = '!';
		}
	}
	else if (mPlayer->getCurrentHealth() == 0)
	{
		cout << "You have run out of health.\n";
		cout << "GAME OVER";
	}
}

int grid::atEnd()
{
	return x + y;
}

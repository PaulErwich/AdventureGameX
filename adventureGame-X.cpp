/*
   Paul Erwich
   Text-based adventure game - X
*/
#include <iostream>
#include <Windows.h> // Used for Sleep() function
#include <string> // Used for getline() function
#include "headers.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int goblin::mNumberOfGoblins = 0;
int orc::mNumberOfOrcs = 0;
int troll::mNumberOfTrolls = 0;

void clrscr()
{
    system("@cls||clear");
}

void enterToContinue()
{
    system("pause");
    clrscr();
}

int main()
{
    srand((unsigned)time(0)); // Ensures random numbers are random everytime the program is run.

    
    player playerOne("Paul", 250, 20, 4, typeArmor::MEDIUM, 1);
    grid map;

    cout << "=====WELCOME TO X=====\n";

    map.setPlayer(&playerOne);    
    
    map.startRoom();

    while (playerOne.getCurrentHealth() != 0 || map.atEnd() == 8)
    {
        enterToContinue();
        map.playerMove();

        map.displayMaze();
        enterToContinue();

        map.roomChecker();   
    }

    return 0;
}



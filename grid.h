#pragma once
#include <iostream>
#include <Windows.h> //For the Sleep() function
#include "player.hpp"
#include "enemy.h"
#include "goblin.h"
#include "orc.h"
#include "troll.h"
//#include "headers.hpp"

using std::cout;
using std::cin;
using std::string;


class grid
{
private:
    player *mPlayer;
    char maze[5][5] =
    {
        {'O', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?'}
    };
    int mazeChecker[5][5] =
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    }; // Made so i can check position using a switch case, does't work with maze attriubte
    // because of duplicate characters within the grid. 

    int x;
    int y;

public:
    grid();
    grid(player *_player);
    ~grid();

    void setPlayer(player *_player);

    void displayMaze();

    void playerMove();
    void moveChecker();
    void roomChecker();

    //Room functions
    void startRoom();
    
    void goblinRoomMK1();
    void goblinRoomMK2();
    
    void orcRoomMK1();
    void orcRoomMK2();

    void trollRoomMK1();
    void trollRoomMK2();

    void giantRoom();

    void endRoom();

    //Functions for rooms
    void fullCombat(enemy &_enemy);
    void afterCombat(enemy& _enemy);

    //Check if you're at the end
    int atEnd();
};

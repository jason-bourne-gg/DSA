#include <iostream>
#include <stdc++.h>
using namespace std;

class Dice
{
private:
    int min = 1;
    int max = 6;
    int count;

public:
    Dice(int count) : count(count) {}

    int rollDice()
    {
        return random(1, 6);
    }
};

class Game
{
};

int main()
{
    Game gameobj = new Game();
    gameobj.startGame();
    return 0;
};
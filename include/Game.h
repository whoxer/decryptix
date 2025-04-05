#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string.h>

#include "DefinedValues.h"

class Game
{
public:
    Game();
    ~Game();
    void Display(const char *charArray) const
    {
        cout << charArray << endl;
    }
    void Play();
    const char *GetSolution() const { return solution; }
    void Score(const char *thisGuess, int &correct, int &position);

private:
    inline int HowMany(const char *theString, char c);
    char solution[maxPos + 1];
    int howManyLetters;
    int howManyPositions;
    int round;
    bool duplicates;
};

#endif

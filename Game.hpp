#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>

#include "Def.hpp"

class Game {
    public:
        Game();
        ~Game();
        void Display(const char *charArray) const {
            cout << charArray << endl;
        }
        void Play();
        const char *GetSolution() const { return solution; }
	    inline int HowMany(const char *, char);
        void Score(const char *thisGuess, int &correct, int &position);
    private:
        char solution[maxPos + 1];
        int howManyLetters;
        int howManyPositions;
        bool duplicates;
        int round;
};

#endif

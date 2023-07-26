#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>

#include "definedValues.hpp"

using namespace std;

class Game {
    public:
        Game();
        ~Game();
        void Display(const char *charArray) const {
            cout << charArray << endl;
        }
        void Play();
        const char *GetSolution() const {
            return solution;
        }
        void Score(const char *thisGuess, int *correct, int *position);
        inline int howMany(const char *theString, char c);
    private:
        char solution[maxPos];
        bool duplicatedAllowed;
        int howManyLetters;
        int howManyPositions;
        int round;
};

#endif
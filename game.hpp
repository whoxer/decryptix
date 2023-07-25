#ifndef GAME_H
#define GAME_H

#include <iostream>

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
        void Score(int *ptr_correct, int *ptr_position);
    private:
        int howMany(const char *, char);
        char solution[maxPos];
        bool duplicatedAllowed;
        int howManyLetters;
        int howManyPositions;
        int round;
};

#endif
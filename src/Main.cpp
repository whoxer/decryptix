#include "Game.h"

int main()
{
    
    cout << "Decryptix - (C)Copyright 1999 Liberty" << endl;
    cout << "Associates, Inc. Versio 0.3\n\n" << endl;
    
    bool playAgain = true;

    while (playAgain)
    {
        char choice = ' ';
        Game theGame;
        theGame.Play();

        cout << "\n The answer: ";
        theGame.Display(theGame.GetSolution());
        cout << "\n\n" << endl;

        while (choice != 'y' && choice != 'n')
        {
            cout << "\nPlay again (y/n): ";
            cin >> choice;
        }
        
        playAgain = choice == 's' ? true : false;
    }

    return 0;
}

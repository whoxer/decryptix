#include "Game.hpp"

int main() {
    bool playAgain = true;

	cout << "< Decryptix - v0.5.14 >" << endl;
	cout << "> Há duas maneiras de jogar Decryptix: ";
	cout << "você pode adivinhar um padrão que eu criar ou criar o seu padrão." << endl;

    while (playAgain) {
        char choice = ' ';
        Game theGame;

        theGame.Play();
        cout << "\n A resposta: ";
        theGame.Display(theGame.GetSolution());
        cout << "\n\n" << endl;

        while (choice != 's' && choice != 'n') {
            cout << "\nJogar novamente (s/n): ";
            cin >> choice;
        }
        playAgain = choice == 's' ? true : false;
    }

    return 0;
}

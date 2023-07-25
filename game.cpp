#include "game.hpp"
#include "definedValues.hpp"


using namespace std;

Game::Game():round(1), howManyPositions(0),
howManyLetters(0), duplicatedAllowed(false) {

    enum BoundedValues {
        minPos = 2,
        maxPos = 10,
        minLetters = 2,
        maxLetters = 26
    };

    bool valid = false;

    while(!valid) {
        while (howManyLetters < minLetters ||
			   howManyLetters > maxLetters) {

				cout << "< Decryptix - v0.2 >" << endl;
				cout << "> Há duas maneiras de jogar Decryptix: ";
				cout << "você pode adivinhar um padrão que eu criar ou criar o seu padrão." << endl;

				cout << "quantas letras? (";
				cout << minLetters << "-" << maxLetters << "): ";
				cin >> howManyLetters;

				if (howManyLetters < minLetters ||
					howManyLetters > maxLetters) {
						cout << "por favor escolha um número entre ";
						cout << minLetters << " e " << maxLetters << endl;
				}
			}

		while (howManyPositions < minPos ||
			   howManyPositions > maxPos) {

				cout << "quantas posições? (";
				cout << minPos << "-" << maxPos << "): ";
				cin >> howManyPositions;	

				if (howManyPositions < minPos ||
					howManyPositions > maxPos) {
						cout << "por favor insira um número de posições entre ";
						cout << minPos << " e " << maxPos << endl;
				}
			}
        
        char choice = ' ';

		while (choice != 's' && choice != 'n') {
			cout << "permitir (s/n)? ";
			cin >> choice;
		}

        duplicatedAllowed = choice == 'y' ? true : false;

        if (!duplicatedAllowed && howManyPositions > howManyLetters) {
            cout << "eu não posso colocar " << howManyLetters;
			cout << " letras em " << howManyPositions;
			cout << " posições sem duplicatas! por favor tente novamente" << endl;
			howManyLetters   = 0;
			howManyPositions = 0;
        } else {
            valid = true;
        }
    }
}

Game::~Game() {}

void Game::Score(const char *thisGuess, int *correct, int *position) {
	correct = 0;
	position = 0;
	for (int i = 0; i < howManyLetters; i++) {
		int howManyInGuess = howMany(thisGuess, alpha[i]);
		int howManyInAnswer = howMany(solution, alpha[i]);
		correct += howManyInGuess < howManyInAnswer ? howManyInGuess : howManyInAnswer;
	}
	for (int j = 0; j < howManyPositions; j++) {
		if (thisGuess[j] == solution[j]) {
			position++;
		}
	}
}

void Game::Play() {
	char guess[80];
	int correct = 0;
	int position = 0;

	//...

	cout << endl;
	cout << "seu palpite: ";

	Display(guess);
	Score(guess, &correct, &position);

	cout << "\t\t" << correct << " correct, " << position << " in position." << endl;
}
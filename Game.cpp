#include "Game.hpp"
#include "Def.hpp"

using namespace std;

Game::Game():round(1), howManyPositions(0),
howManyLetters(0), duplicates(false) {

    bool valid = false;

    while(!valid) {
        while (howManyLetters < minLetters ||
	       howManyLetters > maxLetters) {
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
			cout << "permitir duplicatas (s/n)? ";
			cin >> choice;
		}

        duplicates = choice == 'y' ? true : false;

        if (!duplicates && howManyPositions > howManyLetters) {
            cout << "eu não posso colocar " << howManyLetters;
    	    cout << " letras em " << howManyPositions;
	    cout << " posições sem duplicatas! por favor tente novamente" << endl;
	    howManyLetters   = 0;
	    howManyPositions = 0;
        } else {
            valid = true;
        }

	int i;

	for (i = 0; i < maxPos; i++)
		solution[i] = 0;

	srand((unsigned)time(NULL));

	for (i = 0; i < howManyPositions;) {
		int nextValue = rand() % (howManyLetters);
		char c = alpha[nextValue];

		if (!duplicates && i > 0) {
			int count = HowMany(solution, c);
			if (count > 0) {
				continue;
			}
		}
		solution[i] = c;
		i++;
	}
		solution[i] = '\0';
	}
}

Game::~Game() {}

void Game::Score(const char *thisGuess, int &correct, int &position) {
	correct = 0;
	position = 0;

	ASSERT(strlen(thisGuess) == howManyPositions);
	ASSERT(strlen(solution) == howManyPositions);

	for (int i = 0; i < howManyLetters; i++) {
		int howManyInGuess = HowMany(thisGuess, alpha[i]);
		int howManyInAnswer = HowMany(solution, alpha[i]);
		correct += howManyInGuess < howManyInAnswer ? howManyInGuess : howManyInAnswer;
	}
	for (int j = 0; j < howManyPositions; j++) {
		if (thisGuess[j] == solution[j]) {
			position++;
		}
	}
	ASSERT(position <= correct);
}
void Game::Play() {
	char guess[80];
	int correct = 0;
	int position = 0;
	bool quit = false;
	
	while (position < howManyPositions) {
		cout << "\nrodada " << round  << ". Insira ";
		cout << howManyPositions << " letras entre ";
		cout << alpha[0] << " e ";
		cout << alpha[howManyLetters - 1] << ": ";

		cin >> guess;

		if (strlen(guess) != howManyPositions) {
			cout << "\n ** Por favor insira exatamente ";
			cout << howManyPositions << " letras. **\n";
			continue;
		}

		round++;

		cout << "\nseu palpite: ";
		Display(guess);
		Score(guess, correct, position);
		cout << "\t\t" << correct << " correto,";
		cout << " na posição " << position << endl;
	}

	cout << "\n\nParabéns! isso levou";

	if (round <= 6) {
		cout << "apenas ";
	}

	if (round - 1 == 1) {
		cout << "uma rodada!" << endl;
	} else {
		cout << round - 1 << " rodadas" << endl;		
	}

	// cout << "\t\t" << correct << " correct, " << position << " in position." << endl;
}
inline int Game::HowMany(const char *theString, char c) {
	int count = 0;
	for (int i = 0; i < strlen(theString); i++) {
		if (theString[i] == c)
			count++;
	}	
	return count;
}

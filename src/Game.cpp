#include <time.h>

#include "Game.h"
#include "DefinedValues.h"

using namespace std;

void Game::Score(const char *thisGuess, int &correct, int &position)
{
	correct = 0;
	position = 0;

	ASSERT(strlen(thisGuess) == howManyPositions);
	ASSERT(strlen(solution) == howManyPositions);

	int i;
	for (i = 0; i < howManyLetters; i++)
	{
		int howManyInGuess = HowMany(thisGuess, alpha[i]);
		int howManyInAnswer = HowMany(solution, alpha[i]);
		correct += howManyInGuess < howManyInAnswer ? howManyInGuess : howManyInAnswer;
	}
	for (i = 0; i < howManyPositions; i++)
	{
		if (thisGuess[i] == solution[i])
		{
			position++;
		}
	}
	ASSERT(position <= correct);
}

Game::Game() : 
	round(1), 
	howManyPositions(0),
	howManyLetters(0), 
	duplicates(false)
{

	bool valid = false;

	while (!valid)
	{
		while (howManyLetters < minLetters ||
			   howManyLetters > maxLetters)
		{
			cout << "How many letters? (";
			cout << minLetters << "-" << maxLetters << "): ";
			cin >> howManyLetters;

			if (howManyLetters < minLetters ||
				howManyLetters > maxLetters)
			{
				cout << "please enter a number between ";
				cout << minLetters << " and " << maxLetters << endl;
			}
		}
		while (howManyPositions < minPos ||
			   howManyPositions > maxPos)
		{

			cout << "How many positions? (";
			cout << minPos << "-" << maxPos << "): ";
			cin >> howManyPositions;

			if (howManyPositions < minPos ||
				howManyPositions > maxPos)
			{
				cout << "please enter a number between ";
				cout << minPos << " and " << maxPos << endl;
			}
		}

		char choice = ' ';

		while (choice != 'y' && choice != 'n')
		{
			cout << "Allow duplicates (y/n)? ";
			cin >> choice;
		}

		duplicates = choice == 'y' ? true : false;

		if (!duplicates && howManyPositions > howManyLetters)
		{
			cout << "I can't put " << howManyLetters;
			cout << " letters in " << howManyPositions;
			cout << " positions without duplicates!" << endl;
			howManyLetters = 0;
			howManyPositions = 0;
		}
		else
		{
			valid = true;
		}

		int i;

		for (i = 0; i < maxPos; i++)
			solution[i] = 0;

		srand((unsigned)time(NULL));

		for (i = 0; i < howManyPositions;)
		{
			int nextValue = rand() % (howManyLetters);
			char c = alpha[nextValue];

			if (!duplicates && i > 0)
			{
				int count = HowMany(solution, c);
				if (count > 0)
					continue;
			}
			solution[i] = c;
			i++;
		}
		solution[i] = '\0';
	}
}

Game::~Game() {}

void Game::Play()
{
	char guess[80];
	int correct = 0;
	int position = 0;
	bool quit = false;

	while (position < howManyPositions)
	{
		cout << "\nRound " << round << ". Enter ";
		cout << howManyPositions << " letters between ";
		cout << alpha[0] << " and ";
		cout << alpha[howManyLetters - 1] << ": ";

		cin >> guess;

		if (strlen(guess) != howManyPositions)
		{
			cout << "\n ** Please enter exactly ";
			cout << howManyPositions << " letters. **\n";
			continue;
		}

		round++;

		cout << "\nYour guess: ";
		Display(guess);

		Score(guess, correct, position);
		cout << "\t\t" << correct << " correct,";
		cout << position << " in position " << endl;
	}

	cout << "\n\nCongratulations! It took you ";

	if (round <= 6)
	{
		cout << "only ";
	}

	if (round - 1 == 1)
	{
		cout << "one round!" << endl;
	}
	else
	{
		cout << round - 1 << " rounds." << endl;
	}
}

inline int Game::HowMany(const char *theString, char c)
{
	int count = 0;
	for (int i = 0; i < strlen(theString); i++)
	{
		if (theString[i] == c)
			count++;
	}
	return count;
}

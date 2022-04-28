#include <iostream>
#include <ctime>
#include <string>

void PrintIntroduction(int Difficulty)
{
	std::cout << "Incognito:>Lets play the game, my little friend...\n";
	//std::cout << "." << '\n';
	std::cout << "Incognito:>The level is " << Difficulty << "..." << '\n';
	//std::cout << "." << '\n';
	std::cout << "Incognito:>Your need to enter the correct codes to survive...\n";
	//std::cout << "." << '\n'; 
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	// Declare 3 number of code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeMult = CodeA * CodeB * CodeC;

	// Print CodeSum and CodeMult to the terminal
	std::cout << '\n';
	std::cout << "+ There're 3 numbers in the code\n";
	std::cout << "+ The codes add-up to: " << CodeSum << '\n';
	std::cout << "+ The codes multiply to give: " << CodeMult << '\n';

	// Store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessMult = GuessA * GuessB * GuessC;

	// Check if the player guess is correct
	if (GuessSum == CodeSum && GuessMult == CodeMult)
	{
		std::cout << "*** You entered correct password! Goes to the next level! ***";
		return true;
	}
	else
	{
		std::cout << "*** HA-HA-HA Your lose! I'll give you one more chance! ***";
		return false;
	}
}

int main()
{
	srand(time(NULL));
	const int MaxDifficulty = 5;
	int LevelDifficulty = 1;


	while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Cleats any errors
		std::cin.ignore(); // Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}

	}
	std::cout << "\n*** Congratulations you've complete all levels ***\n";

	return 0;
}
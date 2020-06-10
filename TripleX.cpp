#include <iostream>
#include <ctime>

// Prints introduction message
void PrintIntroduction(int Difficulty) 
{
    // Print intro message to the terminal
    std::cout << "\n*** You are a cyborg bent on escaping from the cruel scientists by hacking your level " << Difficulty;
    std::cout << " cell door...\n*** Use your enhanced brain to find the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "- There are 3 numbers in the code";
    std::cout << "\n- The codes add-up to: " << CodeSum;
    std::cout << "\n- The codes multiply to: " << CodeProduct << std::endl;

    // Store 3 player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)  
    {
        std::cout << "\n*** It's open! One step closer to freedom!\n";
        
        return true;
    }
    else
    {
        std::cout << "\n*** Careful! You almost got electrocuted! Remember, Janitor Jerry doesn't like the smell of fried circuits. Try again!";

        return false;
    }
}


// Main function
int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** You escaped! Time to give those scientists a taste of their own medicine!\n";

    return 0;
}
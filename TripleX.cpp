#include <iostream>
#include <ctime>
void PrintIntroduction(int Diffculty)
{
    if (Diffculty == 1)
    {
        std::cout << "\n You are a secret agent breaking into a secure server room... \n";
        std::cout << "\n Enter the correct code to continue \n";
    }
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    //
    std::cout << std::endl;
    std::cout << "\n There are three numbers in the code" << std::endl;
    std::cout << "\n The code adds up to: " << CodeSum << std::endl;
    std::cout << "\n The product is: " << CodeProduct << std::endl;
    std::cout << "\n Enter your guess MOFO, what are the three numbers?" << std::endl;
    //
    int PlayerGuess;
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << "\n \n You entered: " << GuessA << GuessB << GuessC;
    if (GuessSum == CodeSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n \n  Well done agent, you have extracted a file, keep going!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "\n \n You entered the wrong code! Careful agent! Try again!" << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int const MaxDifficulty = 5;
    int Difficulty = 1;
    while (Difficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(Difficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete)
        {
            ++Difficulty;
        }
    }
    return 0;
}
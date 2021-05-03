#include <iostream>

void PrintIntroduction(int Diffculty)
{
    std::cout << "You are a secret agent breaking into a secure server room... \n";
    std::cout << "Enter the correct code to continue \n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;
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
    std::cout << "\n You entered: " << GuessA << GuessB << GuessC;
    if (GuessSum == CodeSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n You Win!";
        return true;
    }
    else
    {
        std::cout << "\n Loooooose";
        return false;
    }
}

int main()
{

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
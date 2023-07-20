#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int secretNumber = dist(gen);

    std::cout << "Guess a number between 1 and 100:" << std::endl;

    int guessNumber = 0;
    int dumpRange1 = 100;
    int dumpRange2 = 1;
    
    while (true) {
        std::cin >> guessNumber;

        if (guessNumber == secretNumber) {
            std::cout << "Congratulations! You guessed the number." << std::endl;
            break;
        } else if (guessNumber > secretNumber) {
            if (guessNumber > dumpRange1)
            {
                std::cout << "You're so dumb for this tiny game. The actual number was " << secretNumber << std::endl;
                break;
            }
            dumpRange1 = guessNumber;
            std::cout << "Too high. Try again:" << std::endl;
        } else {
            if (guessNumber < dumpRange2)
            {
                std::cout << "You're so dumb for this tiny game. The actual number was " << secretNumber << std::endl;
                break;
            }
            dumpRange2 = guessNumber;
            std::cout << "Too low. Try again:" << std::endl;
        }
    }
    return 0;
}

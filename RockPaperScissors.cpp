#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);

    std::string choices[] = {"Rock", "Paper", "Scissors"};

    std::cout << "Let's play Rock, Paper, Scissors!" << std::endl;

    while (true) {
        std::cout << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors): ";
        int playerChoice;
        std::cin >> playerChoice;

        if (playerChoice < 0 || playerChoice > 2) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }

        int computerChoice = dist(gen);

        std::cout << "You chose: " << choices[playerChoice] << std::endl;
        std::cout << "Computer chose: " << choices[computerChoice] << std::endl;

        if (playerChoice == computerChoice) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((playerChoice == 0 && computerChoice == 2) ||
                   (playerChoice == 1 && computerChoice == 0) ||
                   (playerChoice == 2 && computerChoice == 1)) {
            std::cout << "Congratulations! You win!" << std::endl;
        } else {
            std::cout << "Computer wins!" << std::endl;
        }

        std::cout << "Play again? (y/n): ";
        char playAgain;
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
        std::cout << std::endl;
    }

    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}

#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6);

    std::cout << "Welcome to the Dice Rolling Simulator!" << std::endl;

    while (true) {
        char choice;
        std::cout << "Press 'r' to roll the dice, or 'q' to quit: ";
        std::cin >> choice;

        if (choice == 'r') {
            int diceResult = dist(gen);
            std::cout << "You rolled a " << diceResult << std::endl;
        } else if (choice == 'q') {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "Thank you for using the Dice Rolling Simulator!" << std::endl;

    return 0;
}

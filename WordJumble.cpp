#include <iostream>
#include <string>
#include <random>
#include <algorithm>

int main()
{
    std::vector<std::string> words = {"apple", "banana", "orange", "grape", "melon"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, words.size() - 1);

    std::string word = words[dist(gen)];

    std::string jumbledWord = word;
    std::random_shuffle(jumbledWord.begin(), jumbledWord.end());

    std::cout << "Welcome to Word Jumble!" << std::endl;
    std::cout << "Unscramble the jumbled word to win." << std::endl;
    std::cout << "Jumbled word: " << jumbledWord << std::endl;

    std::string guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;

    std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

    if (guess == word) {
        std::cout << "Congratulations! You unscrambled the word correctly." << std::endl;
    } else {
        std::cout << "Oops! Your guess is incorrect." << std::endl;
        std::cout << "The correct word is: " << word << std::endl;
    }

    std::cout << "Thank you for playing Word Jumble!" << std::endl;

    return 0;
}

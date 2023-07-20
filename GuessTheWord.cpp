#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int main()
{
    std::vector<std::string> words = {"apple", "banana", "orange", "grape", "melon"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, words.size() - 1);

    std::string word = words[dist(gen)];
    int wordLength = word.length();
    int attempts = 5;
    std::string guessedLetters(wordLength, '_');
    std::vector<char> guessedChars;

    std::cout << "Welcome to Guess the Word!" << std::endl;
    std::cout << "The word has " << wordLength << " letters. You have " << attempts << " attempts to guess the word." << std::endl;

    while (attempts > 0) {
        std::cout << "Word: " << guessedLetters << std::endl;
        std::cout << "Attempts left: " << attempts << std::endl;

        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        if (std::find(guessedChars.begin(), guessedChars.end(), guess) != guessedChars.end()) {
            std::cout << "You already guessed that letter. Try again." << std::endl;
            continue;
        }

        guessedChars.push_back(guess);

        bool found = false;
        for (int i = 0; i < wordLength; ++i) {
            if (word[i] == guess) {
                guessedLetters[i] = guess;
                found = true;
            }
        }

        if (found) {
            std::cout << "Good guess!" << std::endl;
        } else {
            std::cout << "Wrong guess!" << std::endl;
            --attempts;
        }

        if (guessedLetters == word) {
            std::cout << "Congratulations! You guessed the word: " << word << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    if (attempts == 0) {
        std::cout << "Out of attempts. The word was: " << word << std::endl;
    }

    std::cout << "Thank you for playing Guess the Word!" << std::endl;

    return 0;
}

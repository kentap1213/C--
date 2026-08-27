#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<string> words = {
        "programming", "computer", "keyboard", "developer",
        "algorithm", "function", "variable", "software",
        "hangman", "graphics"
    };

    string word = words[rand() % words.size()];
    string guessed(word.size(), '_');
    int lives = 6;
    vector<char> triedLetters;

    cout << "===== Guess The Word =====" << endl;
    cout << "Word has " << word.size() << " letters. You have " << lives << " lives.\n\n";

    while (lives > 0 && guessed != word) {
        cout << "Word: ";
        for (char c : guessed) cout << c << ' ';
        cout << "\nLives left: " << lives << endl;

        cout << "Guessed letters: ";
        for (char c : triedLetters) cout << c << ' ';
        cout << "\n\nEnter a letter: ";

        char letter;
        cin >> letter;
        letter = tolower(letter);

        // check if already guessed
        bool alreadyTried = false;
        for (char c : triedLetters) {
            if (c == letter) {
                alreadyTried = true;
                break;
            }
        }

        if (alreadyTried) {
            cout << "\nYou already tried that letter!\n\n";
            continue;
        }

        triedLetters.push_back(letter);

        bool correct = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == letter) {
                guessed[i] = letter;
                correct = true;
            }
        }

        if (correct) {
            cout << "\nCorrect!\n\n";
        } else {
            lives--;
            cout << "\nWrong! Lives left: " << lives << "\n\n";
        }
    }

    if (guessed == word) {
        cout << "You guessed it! The word was: " << word << endl;
    } else {
        cout << "You ran out of lives. The word was: " << word << endl;
    }

    return 0;
}
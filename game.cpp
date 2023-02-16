#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_INCORRECT = 6;

void drawHangman(int incorrect) {
    switch (incorrect) {
        case 1:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
            break;
        case 2:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << " O     |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
            break;
        case 3:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << " O     |" << endl;
            cout << " |     |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
            break;
        case 4:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << " O     |" << endl;
            cout << "/|     |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
            break;
        case 5:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << " O     |" << endl;
            cout << "/|\\    |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
            break;
        case 6:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << " O     |" << endl;
            cout << "/|\\    |" << endl;
            cout << "/      |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
        case 7:
            cout << "  _____" << endl;
            cout << " |     |" << endl;
            cout << " O     |" << endl;
            cout << "/|\\    |" << endl;
            cout << "/\      |" << endl;
            cout << "       |" << endl;
            cout << "_______|" << endl;
            break;
    }
}

int main() {
    vector<string> questions;
    vector<string> answers;
    string input;

    // Get questions and answers from user
    while (true) {
        cout << "Enter a question (or \"done\" to finish): ";
        getline(cin, input);
        if (input == "done") {
            break;
        }
        questions.push_back(input);

        cout << "Enter the answer: ";
        getline(cin, input);
        answers.push_back(input);
    }

    // Randomly select a question and answer
    srand(time(0));
    int index = rand() % questions.size();
    string answer = answers[index];
    string hidden(answer.size(), '-');

    int incorrect = 0;
    string guessed;

 // Play game
    cout << "Welcome to Hangman!" << endl;
    while (incorrect < 6 && hidden != answer) {
        cout << "Question: " << questions[index] << endl;
        cout << "Current word: " << hidden << endl;
        cout << "Guessed letters: " << guessed << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        // Check if guess is correct
        bool correct = false;
        for (int i = 0; i < answer.length(); i++) {
            if (answer[i] == guess) {
                hidden[i] = guess;
                correct = true;
            }
        }

        if (correct) {
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect!" << endl;
            incorrect++;
        }

        guessed += guess;
    }

    // Display result
    if (incorrect == 6) {
        cout << "You lose! The answer was: " << answer << endl;
    } else {
        cout << "Congratulations, you win!" << endl;
        cout << "The answer was: " << answer << endl;
    }

    return 0;
}

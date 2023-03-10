#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawHangman(int incorrect) {
    switch (incorrect) {
    case 1:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 2:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 3:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 4:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 5:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 6:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\   |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 7:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\ |" << endl;
        cout << " / \\  |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    }
}

int main() {
    vector<string> questions;
    vector<string> answers;
    string input;

    while (true) {
        cout << "??veskite klausim?? (arba para??ykite baigta, kad prad??ti ??aidim??)";
        getline(cin, input);
        if (input == "baigta") {
            break;
        }
        questions.push_back(input);

        cout << "??veskite atsakym??: ";
        getline(cin, input);
        answers.push_back(input);
    }


    srand(time(NULL));
    int index = rand() % questions.size();
    string question = questions[index];
    string answer = answers[index];


    string soFar(answer.size(), '-');
    string used("");
    int incorrect = 0;

    cout << "Sveiki atvyke ?? Kartuv??s, ??tai j??s?? klausimai: " << endl;
    cout << question << endl;

    while ((incorrect < 7) && (soFar != answer)) {
        cout << "\nNeteisingi sp??jimai: " << incorrect << "/7" << endl;
        cout << "Panaudotos raid??s: " << used << " " << endl;
        cout << "Dabartinis ??odis: " << soFar << endl;

        string guess;
        char firstLetter;
        cout << "??veskite raid??: ";
        cin >> guess;
        firstLetter = guess[0];
        guess = firstLetter;

        while (used.find(guess) != string::npos) {
            cout << "J??s jau sp??jote ??i?? raid?? " << guess << " " << endl;
            cout << "??veskite raid??: ";
            cin >> guess;
            guess = guess;
        }

        used += guess;

        if (answer.find(guess) != string::npos) {
            cout << "Teisingai! " << guess << " yra ??odyje." << endl;

            for (int i = 0; i < answer.length(); i++) {
                if (answer[i] == firstLetter) {
                    soFar[i] = firstLetter;
                }
            }
        }
        else {
            cout << "Atsipra??au, " << guess << " n??ra ??odyje" << endl;
            incorrect++;
            drawHangman(incorrect);
        }
    }


    if (incorrect == 7) {
        cout << "\nJ??s buvote pakarti!" << endl;
    }
    else {
        cout << "\nSveikinu, atsp??jote ??od??!" << endl;
    }

    cout << "??odis buvo: " << answer << endl;

    return 0;
}

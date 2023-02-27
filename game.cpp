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
        cout << "Įveskite klausimą (arba parašykite baigta, kad pradėti žaidimą)";
        getline(cin, input);
        if (input == "baigta") {
            break;
        }
        questions.push_back(input);

        cout << "Įveskite atsakymą: ";
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

    cout << "Sveiki atvyke į Kartuvės, štai jūsų klausimai: " << endl;
    cout << question << endl;

    while ((incorrect < 7) && (soFar != answer)) {
        cout << "\nNeteisingi spėjimai: " << incorrect << "/7" << endl;
        cout << "Panaudotos raidės: " << used << " " << endl;
        cout << "Dabartinis žodis: " << soFar << endl;

        string guess;
        char firstLetter;
        cout << "Įveskite raidę: ";
        cin >> guess;
        firstLetter = guess[0];
        guess = firstLetter;

        while (used.find(guess) != string::npos) {
            cout << "Jūs jau spėjote šią raidę " << guess << " " << endl;
            cout << "Įveskite raidę: ";
            cin >> guess;
            guess = guess;
        }

        used += guess;

        if (answer.find(guess) != string::npos) {
            cout << "Teisingai! " << guess << " yra žodyje." << endl;

            for (int i = 0; i < answer.length(); i++) {
                if (answer[i] == firstLetter) {
                    soFar[i] = firstLetter;
                }
            }
        }
        else {
            cout << "Atsiprašau, " << guess << " nėra žodyje" << endl;
            incorrect++;
            drawHangman(incorrect);
        }
    }


    if (incorrect == 7) {
        cout << "\nJūs buvote pakarti!" << endl;
    }
    else {
        cout << "\nSveikinu, atspėjote žodį!" << endl;
    }

    cout << "Žodis buvo: " << answer << endl;

    return 0;
}

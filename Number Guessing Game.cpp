#include <bits/stdc++.h>
using namespace std;

void game() {
    srand(time(NULL)); 

    int lives = 5;
    int range = 100;
    int number = rand() % range + 1; 
    bool playerWon = false;

    map<string, string> superheroQuestions = {
        {"iron man", "a genius billionaire inventor who builds a suit of powered armor."},
        {"thor", "a Norse god of thunder who wields a mighty hammer called Mjolnir."},
        {"hulk", "a scientist who, when angered, transforms into a green, superhuman behemoth."},
        {"loki", "the mischievous Norse god of mischief and brother of Thor."},
        {"hulkbuster", "a suit of powered armor designed to combat the Hulk."},
        {"hydra", "a secret organization dedicated to world domination and a frequent enemy of S.H.I.E.L.D."},
        {"mjolnir", "Thor's enchanted hammer, which can only be wielded by the worthy."},
        {"asgard", "the realm of the Norse gods, including Thor and Odin."},
        {"thanos", "a powerful cosmic villain obsessed with obtaining the Infinity Stones."},
        {"groot", "a sentient, tree-like creature known for saying 'I am Groot.'"}
    };

    vector<string> keys;

    for (auto& pair : superheroQuestions) {
        keys.push_back(pair.first);
    }

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have " << lives << " lives to guess the number between 1 and " << range << "." << endl;

    while (lives > 0) {
        cout << "Enter your guess: ";
        int guess;
        cin >> guess;

        if (guess == number) {
            playerWon = true;
            break;
        }

        lives--;

        if (lives == 0) {
            break;
        }

        if (guess > number) {
            cout << "Too high! Try a lower number." << endl;
        } else {
            cout << "Too low! Try a higher number." << endl;
        }

        if (lives == 3) {
            string options;
            cout << "Unlucky Huh! Let's give you a chance to earn a hint." << endl;
            cout << "It's not free; you'll need to answer a question correctly! Are you a Marvel fan or DC fan [marvel/dc]?: ";
            cin >> options;

            if (options == "marvel") {
                cout << "You have good taste, buddy." << endl;
                
                int randomIndex = rand() % keys.size();
                string selectedQuestion = keys[randomIndex];
                string selectedAnswer = superheroQuestions[selectedQuestion];

                cout << "Question: " << selectedAnswer << endl;
                cout << "Your Answer: ";
                string userAnswer;
                cin.ignore();
                getline(cin, userAnswer);

                transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

                if (userAnswer == selectedQuestion) {
                    cout << "Correct! The lucky number is between " 
                         << max(1, number - 5) << " and " << min(range, number + 5) << "." << endl;
                } else {
                    cout << "Incorrect. No hint given." << endl;
                    cout << "The correct answer was: " << selectedQuestion << "." << endl;
                }
            } else {
                cout << "Your choice defines you. You don't want darkness to be gone. :( No hint for you." << endl;
            }
        }

        cout << "Lives remaining: " << lives << endl;
    }

    if (playerWon) {
        cout << "Congratulations! You've guessed the number!" << endl;
    } else {
        cout << "Sorry, you've run out of lives. The number was " << number << "." << endl;
    }
}

int main() {
    game();
    return 0;
}

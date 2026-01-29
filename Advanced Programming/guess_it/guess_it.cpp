#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int init() {
    return rand() % 100 + 1;
}

int readAGuess() {
    //1. hoi doan so may
    cout << "Enter your guess: ";
    //2. nhap so doan
    int guess;
    cin >> guess;
    return guess;
}

bool gameOver(int number, int guessed) {
    return number == guessed;
}

void process(int number, int guessed, int &score) {
    if(number == guessed)
        cout << "You've got it\n";
    else {
        score--;

        if(number > guessed)
            cout << "Too small\n";
        else
            cout << "Too big\n";
    }
}

void playGuessIt () {
    bool GameQuit = false;
    while(!GameQuit) {
        int number = init();
        int score = 100;
        int guessed;
        do {
            guessed = readAGuess();
            process(number, guessed, score);
        } while (!gameOver(number, guessed));
        cout << "Your score: " << score << endl;
        cout << "Do you want to continue? Press Y for YES or N for No:\n";
        char choice;
        cin >> choice;
        choice = tolower(choice);
        while (choice != 'n' && choice != 'y') {
            cout << "Please retry\n";
            cin >> choice;
        }
        if (choice == 'n')
            GameQuit = true;

    }
}

int main() {
    srand(time(0));
    playGuessIt();
}

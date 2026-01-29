#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string chooseWord(){
    return "chu be dan";
}

char readAGuess() {
    char guess;
    cout << "Make a guess: ";
    cin >> guess;
    return guess;
}

const string figure[] = {
    "  --------------    \n"
    "   |                \n"
    "   |                \n"
    "   |                \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |                \n"
    "   |                \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |                \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |           |    \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|    \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\   \n"
    "   |                \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\   \n"
    "   |          /     \n"
    "   |     \n"
    " -----   \n",

    "  --------------    \n"
    "   |           |    \n"
    "   |           O    \n"
    "   |          /|\   \n"
    "   |          / \   \n"
    "   |     \n"
    " -----   \n",
};


void render(string guessedWord, int badGuesscount) {
    cout << figure[badGuesscount] << endl;
    cout << "Your guessed word: " << guessedWord << endl;
	cout << "Number of wrong guesses: " << badGuesscount << endl;
}

bool contain(string secretWord, char guess) {
    return secretWord.find(guess) != string::npos;
}

void update(string &guessedWord, string secretWord, char guess) {
    for(int i = 0; i < secretWord.size(); i++)
        if(secretWord[i] == guess)
            guessedWord[i] = guess;
}

int main() {
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.size(), '-');
    for(int i = 0; i < secretWord.size(); i++)
        if(secretWord[i] == ' ')
            guessedWord[i] = ' ';
    int badGuesscount = 0;
    do {
        render(guessedWord, badGuesscount);
        char guess = readAGuess();
        if(contain(secretWord, guess)) {
            cout << "You made a correct guess!\n";
            update(guessedWord, secretWord, guess);
        } else {
            badGuesscount++;
            cout << "You made a wrong guess.\n";
        }
    } while(badGuesscount < 7 && secretWord != guessedWord);
    if(badGuesscount < 7)
        cout << "Congratulations! You win!" << endl << "The word is: " << secretWord;
    else
        cout << "You lost. The correct word is " << secretWord;

}


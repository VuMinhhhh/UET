#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int selectNumber(int left, int right) {
    return rand() % (right - left + 1) + left;
}

char getHostRespond(int guess) {
    cout << "Is " << guess << " your chosen number?\n";
    cout << "Please Respond: ";
    char respond;
    cin >> respond;
    while(respond != '<' && respond != '>' && respond != '=') {
        cout << "Please retry\n";
        cin >> respond;
    }
    return respond;
}

int getSecretNumber() {
    cout << "Please enter your number: ";
    int number;
    cin >> number;
    cout << endl;
    return number;
}

int main() {
    srand(time(0));
    int left = 1, right = 99;
    int secretnumber = getSecretNumber();
    cout << "I'm going to guess your number and you will respond: \n+ '=' if my guess is correct. \n+ '<' if my guess is higher than your number. \n+ '>' if my guess is lower than your number. \n\n";
    int guess;
    char respond;
    do{
        if(left > right) {
            cout << "It seems like you have given me wrong responces somewhere.\n";
        }
        guess = selectNumber(left, right);
        respond = getHostRespond(guess);
        if(respond == '>')
            left = guess + 1;
        else if(respond == '<')
            right = guess - 1;
    } while (respond != '=');
    if(guess != secretnumber)
        cout << "\nMy guess was " << guess << " and your number is " << secretnumber << "."
             << "\nIt seems like you have given me wrong responces somewhere.\n";
    else
        cout << "Wow good game!";
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int n;
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[8] = {0, 1, -1, 0, -1, 1, -1, 1};
const int bomb = 1;
const int blank = 0;

struct Mines_Game {
    char display_map[100][100];
    bool mine_field[100][100];
    bool end = 0;
    void display() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << display_map[i][j] << " ";
            cout << endl;
        }
    }
    void display2() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << mine_field[i][j] << " ";
            cout << endl;
        }
    }
};

void init (Mines_Game &game) {
    srand(time(0));
    cout << "Game rules: Enter the coordinate, if there is a bomb in that coordinate, it will be marked as 'B', meaning you lose.\nElse the coordinate will display the number of bombs nearby (blank means 0)" << endl;
    cout << "\nEnter your desired map size: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            game.display_map[i][j] = '*';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            game.mine_field[i][j] = rand() % 2;
}

void loang(Mines_Game &game, const int i, const int j) {
    int count = 0;
    for(int k = 0; k < 8; k++) {
        int inew = i + dx[k];
        int jnew = j + dy[k];
        if(inew >= 1 && inew <= n && jnew >= 1 && jnew <= n)
            count += game.mine_field[inew][jnew];
    }
    if(count == 0)
        game.display_map[i][j] = ' ';
    else
        game.display_map[i][j] = char(count + 48);
    for(int k = 0; k < 8; k++) {
        int inew = i + dx[k];
        int jnew = j + dy[k];
        if(inew >= 1 && inew <= n && jnew >= 1 && jnew <= n && dx[k] * dy[k] == 0 && game.mine_field[inew][jnew] == 0 && game.display_map[inew][jnew] == '*')
                loang(game, inew, jnew);
    }
}

int main() {
    Mines_Game game;
    init(game);
    game.display();
    cout << endl;
    int m, n;
    while(!game.end) {
        cout << "Enter your guess: ";
        cin >> m >> n;
        cout << m << " " << n << endl;
        if (game.mine_field[m][n] == bomb) {
            game.end = true;
            game.display_map[m][n] = 'B';
            game.display();
        } else if(game.mine_field[m][n] == blank) {
            loang(game, m, n);
            game.display();
        }
    }
    if(game.end == 1) {
        cout << "You lose!";
    }
    else {
        cout << "You win!" << endl;
        game.display();
    }
}




#include <iostream>

using namespace std;

int NoSolution = 1;
int n;
int count = 1;

void display(int a[100][100]) {
    cout << "Solution " << count++ << ": " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(a[i][j])
                cout << "Q ";
            else
                cout << ". ";
        cout << endl;
    }
    cout << endl;
}

bool IsSafe(int a[100][100], int row, int column) {
    for(int i = row - 1; i >= 0; i--)
        if(a[i][column])
            return 0;
    for(int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        if(a[i][j])
            return 0;
    for(int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
        if(a[i][j])
            return 0;
    return 1;
}

void solveProblem(int a[100][100], int row) {
    if(row >= n) {
        NoSolution = 0;
        display(a);
    }
    for(int i = 0; i < n; i++)
        if(IsSafe(a, row, i)) {
            a[row][i] = 1;
            solveProblem(a, row + 1);
            a[row][i] = 0;
        }
}

void init() {
    cin >> n;
    int a[100][100] = {0};
    solveProblem(a, 0);
    if(NoSolution)
        cout << "No solution for " << n << " queens";
}

int main() {
    init();
}

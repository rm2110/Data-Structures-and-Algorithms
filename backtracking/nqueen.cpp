#include <iostream>
using namespace std;

#define MAX 20  // supports up to 20×20 board

int board[MAX][MAX];  // 0 = empty, 1 = queen

// Check if placing queen at board[row][col] is safe
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check left side of this row
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to solve N-Queens
bool solveNQ(int col, int n) {
    // base case: all queens placed
    if (col >= n)
        return true;

    // Try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1; // place queen

            if (solveNQ(col + 1, n)) // recur for next column
                return true;

            board[i][col] = 0; // backtrack
        }
    }

    return false; // no place found
}

void printBoard(int n) {
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of queens (N): ";
    cin >> n;

    if (n > MAX) {
        cout << "N too large! Max supported: " << MAX << "\n";
        return 0;
    }

    // Initialize board to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (!solveNQ(0, n))
        cout << "No solution exists!\n";
    else
        printBoard(n);

    return 0;
}

/*
1 Start with an empty chessboard of size N×N (all cells empty).

2 Begin with the first column (col = 0).

3 For each row in this column:

Try placing a queen at (row, col).

4 Check if the position is safe:

No other queen already placed in the same row.

No queen in the upper-left diagonal.

No queen in the lower-left diagonal.

5 If the position is safe:

Place the queen at (row, col).

Move to the next column and repeat the process.

6 If the placement in this column leads to no solution later:

Remove the queen (backtrack) from (row, col).

Try placing it in the next row of the same column.

7 Continue until:

You have successfully placed queens in all N columns → Solution found.

OR all rows in a column fail → Go back (backtrack) to the previous column.

8 When all queens are placed safely:

Print the board (positions of all queens).
*/
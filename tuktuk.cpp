#include <iostream>
using namespace std;

// ANSI color codes for boxed in letters
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

char board [3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void DrawBoard (char board[3][3])
{
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "   " << board[i][j];
                if (j < 2)
                {
                    cout << "\t|";
                }
            }
            cout << endl;
            if (i < 2)
            {
                cout << "   _____|_______|_____" << endl;
            }
            else
            {
                cout << "        |       |    " << endl;
            }
        }
}

bool CheckStatus (char board[3][3], char move)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == move && board[i][1] == move && board[i][2] == move)
            return true;
        if (board[0][i] == move && board[1][i] == move && board[2][i] == move)
            return true;
    }
    if (board[0][0] == move && board[1][1] == move && board[2][2] == move)
        return true;
    if (board[2][0] == move && board[1][1] == move && board[0][2] == move)
        return true;
    return false;
}

int main()
{
    char move = 'X';
    int row, column;
    int USERi, USERj;
    int turn;   // Declare outside loop so you can check draw condition

    cout << GREEN "Welcome to Sam's Tic-Tac-Toe!" RESET<< endl;
    // Game Loop
    for (turn = 0 ; turn < 9; turn++)
    {
        // Draw Board
        DrawBoard(board);

        // Check Valid Input
        while(true)
        {
            cout << "Player " << move;
            cout << "\nEnter your move (row, column): ";
            cin >> USERi >> USERj;
            row = USERi - 1;
            column = USERj - 1;

            if (board[row][column] != ' ' || row < 0 || row > 2 || column < 0 || column > 2)
            {
                cout << RED "Invalid move." RESET << endl;;
            }
            else
                break;  
        }

        // Mark Move
        board[row][column] = move;

        // Check Status
        if (CheckStatus(board, move))
        {
            DrawBoard(board);
            cout <<  "      " GREEN "Player " << move << " wins!" RESET << endl;
            break;
        }

        // Switch players 
        move = (move == 'X') ? 'O' : 'X';
    }
    
    // Game End
    DrawBoard(board);
    cout << endl;

    // Check Draw
    if (turn == 9 && !CheckStatus(board, 'X') && !CheckStatus(board, 'O')) 
    {
        cout << YELLOW "It's a draw!" RESET "\n";
    }
    return 0;
}
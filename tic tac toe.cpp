#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';
bool gameWon = false;

void drawBoard()
{
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

void updateBoard(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << "Invalid Move! Please choose another.\n";
        return;
    }

    board[row][col] = currentPlayer;
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    }

    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main()
{
  cout <<"\n";
cout << "★彡[ᴛɪᴄ ᴛᴀᴄ ᴛᴏᴇ ɢᴀᴍᴇ!]彡★\n\n";

    while (!gameWon && !checkDraw())
    {
        drawBoard();

        int choice;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid Move! Please choose a number between 1 and 9.\n";
            continue;
        }

        updateBoard(choice);

        if (checkWin())
        {
            gameWon = true;
            break;
        }

        switchPlayer();
    }

    drawBoard();

    if (gameWon)
    {
        cout << "Player " << currentPlayer << " wins the game!\n";
    }
    else
    {
        cout << "It's a draw!\n";
    }

    return 0;
}

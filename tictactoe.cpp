#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <array>

using namespace std;

char gameData[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int winningCombos[8][3] = {
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 4, 8},
    {2, 4, 6},
};

int choice;
int row, column;
char currentPlayer = 'X';
bool draw = false;
bool gameOver = false;

// Function to show the current status of the gaming gameData

void displayBoard()
{

    //Rander Game gameData LAYOUT

    cout << "  " << gameData[0] << "  | " << gameData[1] << "  |  " << gameData[2] << " \n";
    cout << "  " << gameData[3] << "  | " << gameData[4] << "  |  " << gameData[5] << "\n";
    cout << "  " << gameData[6] << "  | " << gameData[7] << "  |  " << gameData[8] << " \n";
};

bool isWinner()
{

    for (int i = 0; i < 8; i = i + 1)
    {

        bool won = true;

        for (int j = 0; j < 3; j = j + 1)
        {

            int space = winningCombos[i][j];
            bool hasPlayerChecked;

            if (gameData[space] == currentPlayer)
            {
                hasPlayerChecked = true;
            }
            else
            {
                hasPlayerChecked = false;
            }

            won = hasPlayerChecked && won;
        }

        if (won)
        {
            return true;
        }
    }

    return false;
}

bool isTie()
{
    bool isBoardFull = true;
    for (int i = 0; i < 9; i = i + 1)
    {
        char space = gameData[i];
        if (space != 'X')
        {
            if (space != 'O')
            {
                isBoardFull = false;
            }
        }
    }

    return isBoardFull;
}

void startTurn()
{

    cout << "It is " << currentPlayer << "'s turn. What's your move?\n";

    int move;

    cin >> move;

    // check if valid move
    if (move < 1 || move > 9)
    {
        cout << "Please enter a number between 1 and 9\n";

        cin >> move;
    };

    // check if there's already a move in that given space
    if (gameData[move - 1] == 'X' || gameData[move - 1] == 'O')
    {
        cout << "Someone's already played there! Try again!\n";

        startTurn();
    }
    // make the move
    move = move - 1;
    gameData[move] = currentPlayer;

    displayBoard();

    // check if winner
    bool win = isWinner();
    if (win)
    {
        cout << "The winner is " << currentPlayer << "!\n";
        gameOver = true;
    }
    // check if tie
    bool tie = isTie();

    if (tie)
    {
        cout << "Tie game!\n";
        gameOver = true;
    }

    // if not, change the player and startTurn again
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
    if (gameOver == false)
    {
        startTurn();
    }
    else
    {

        cout << "Game Over!\n";
    }
}

int main()
{

    displayBoard();

    startTurn();
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

char square1 = '1', square2 = '2', square3 = '3', square4 = '4', square5 = '5', square6 = '6', square7 = '7', square8 = '8', square9 = '9';

int checkWin()
{
    // function to return game status
    // 1 for game is over with result
    // -1 game in progress
    // O game over and no result
    if (square1 == square2 && square2 == square3)
        return 1;
    else if (square4 == square5 && square5 == square6)
        return 1;
    else if (square7 == square8 && square8 == square9)
        return 1;
    else if (square1 == square4 && square4 == square7)
        return 1;
    else if (square2 == square5 && square5 == square8)
        return 1;
    else if (square3 == square6 && square6 == square9)
        return 1;
    else if (square1 == square5 && square5 == square9)
        return 1;
    else if (square3 == square5 && square5 == square7)
        return 1;
    else if (square1 != '1' && square2 != '2' && square3 != '3' && square4 != '4' && square5 != '5' && square6 != '6' && square7 != '7' && square8 != '8' && square9 != '9')
        return 0;
    else
        return -1;
}

void board() // FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
{
    cout << endl
         << "        Tic Tac Toe" << endl
         << endl;

    cout << "Player 1 : 'X'"<<endl<<"Player 2: 'O'" << endl
         << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square1 << "  |  " << square2 << "  |  " << square3 << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square4 << "  |  " << square5 << "  |  " << square6 << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square7 << "  |  " << square8 << "  |  " << square9 << endl;

    cout << "     |     |     " << endl
         << endl;
}

int main()
{
    int player = 1, i, choice, choice1;
    char mark;
    cout << "1: 2 player game" << endl;
    cout << "2: Single player game" << endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice1;
    if (choice1 == 1)
    {
        do
        {
            board();
            player = (player % 2) ? 1 : 2;
            cout << "Player " << player << ", enter a number: ";
            cin >> choice;
            mark = (player == 1) ? 'X' : 'O';
            if (choice == 1 && square1 == '1')
                square1 = mark;
            else if (choice == 2 && square2 == '2')
                square2 = mark;
            else if (choice == 3 && square3 == '3')
                square3 = mark;
            else if (choice == 4 && square4 == '4')
                square4 = mark;
            else if (choice == 5 && square5 == '5')
                square5 = mark;
            else if (choice == 6 && square6 == '6')
                square6 = mark;
            else if (choice == 7 && square7 == '7')
                square7 = mark;
            else if (choice == 8 && square8 == '8')
                square8 = mark;
            else if (choice == 9 && square9 == '9')
                square9 = mark;
            else
            {
                cout << "Invalid move ";
                player--;
                cin.ignore();
                cin.get();
            }
            i = checkWin();
            player++;
        } while (i == -1);
        board();
        if (i == 1)

            cout << "==>\aPlayer " << --player << " win ";
        else
            cout << "==>\aGame draw";
    }
    else if (choice1 == 2)
    {
        do
        {
            board();
            player = (player % 2) ? 1 : 2;
            if (player == 1)
            {
                cout << "Player " << player << ", enter a number: ";
                cin >> choice;
            }
            else
            {
                choice=rand()%9;
                cout<<"Computer generated number is : "<<choice<<endl;
            }            
            mark = (player == 1) ? 'X' : 'O';
            if (choice == 1 && square1 == '1')
                square1 = mark;
            else if (choice == 2 && square2 == '2')
                square2 = mark;
            else if (choice == 3 && square3 == '3')
                square3 = mark;
            else if (choice == 4 && square4 == '4')
                square4 = mark;
            else if (choice == 5 && square5 == '5')
                square5 = mark;
            else if (choice == 6 && square6 == '6')
                square6 = mark;
            else if (choice == 7 && square7 == '7')
                square7 = mark;
            else if (choice == 8 && square8 == '8')
                square8 = mark;
            else if (choice == 9 && square9 == '9')
                square9 = mark;
            else
            {
                cout << "Invalid move ";
                player--;
                cin.ignore();
                cin.get();
            }
            i = checkWin();

            player++;
        } while (i == -1);
        board();
        if (i == 1)

            cout << "==>\aPlayer " << --player << " win ";
        else
            cout << "==>\aGame draw";
    }

    cin.ignore();
    cin.get();
    return 0;
}


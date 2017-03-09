/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Assignment: Langton's ant simulation
***************************/

#include "Board.h"
#include <iostream>
using namespace std;

/*Prints out the board:
	white = -
	black = #
	ant = *
*/
void printBoard(int** boardArray, int rowCount, int colCount) {
	for (int i = 0; i < rowCount; i++) {
		cout << " ";
		for (int j = 0; j < colCount; j++) {
			if (j == 0) {
				if (boardArray[i][j] == 0)
					cout << " ";
				else if (boardArray[i][j] == 1)
					cout << "#";
				else if (boardArray[i][j] == 2)
					cout << "*";
			}
			else {
				cout << " ";
				if (boardArray[i][j] == 0)
					cout << " ";
				else if (boardArray[i][j] == 1)
					cout << "#";
				else if (boardArray[i][j] == 2)
					cout << "*";
			}
		}
		cout << endl;
	}
}

//Creates a 2D array and initializes each element to 0
int** makeBoard(int row, int column) {
	int** boardArray = new int*[row];

	for (int i = 0; i < row; i++) 
		boardArray[i] = new int[column];
	

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			boardArray[i][j] = 0;

	return boardArray;
}
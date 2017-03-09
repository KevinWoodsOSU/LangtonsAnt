/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Assignment: Langton's ant simulation
***************************/

#include <iostream>
#include <time.h>
#include "Ant.h"
#include "Board.h"
#include "Menu.h"

using namespace std;

int main() {
	
	cout << endl << "This program implements a simulation of Langton's Ant." << endl << endl;

	int row, column, steps, colCoord, rowCoord;

	//Get the size of the rows and column of the board as well as the number of steps the ant will take.
	row = getInt("Enter the number of rows for the 2D array: ");
	column = getInt("Enter the number of columns for the 2D array: ");
	steps = getInt("Enter how many steps the program will iterate. (A good number is between 300 and 10,000): ");
	cin.ignore();

	//Either let user choose the starting position of the ant or make it random.
	if (yesOrNo("Would you like to set the ant's starting position? (y/n): ")) {
		//Let user decide coordinates
		rowCoord = getIntLimited("Which row will the ant start in? (Choose an integer between ", 0, row - 1);
		colCoord = getIntLimited("Which column will the ant start in? (Choose an integer between ", 0, column - 1);
		cin.ignore();
	}
	else {
		//Assign random coordinates
		srand(time(0));
		rowCoord = rand() % row;
		colCoord = rand() % column;
		cout << "** The ant will start in row " << rowCoord << " and column " << colCoord << " **" << endl;
	}

	//Create the board and initialize all elements to white (0 = white, 1 = black, 2 = ant)
	int** boardArray = makeBoard(row, column);

	//Initialize an Ant object
	Ant ant(steps, boardArray, rowCoord, colCoord, row, column);
	
	//Either skip to the final board state or watch every step the ant takes.
	if (yesOrNo("Would you like to jump straight to the last step? (y/n): ")) {
		for (int i = 0; i < steps; i++) {
			ant.move();
		}
		clearScreenUnix();
		printBoard(boardArray, row, column);
	}
	else {
		//Print the initial board state
		clearScreenUnix();
		printBoard(boardArray, row, column);
		enterToContinue();

		//Iterate through user defined number of steps to simulate Langton's Ant and print the board for each step
		int count = 1;
		for (int i = 0; i < steps; i++) {
			clearScreenUnix();
			cout << "Step " << count << " of " << steps << endl;
			ant.move();
			printBoard(boardArray, row, column);
			enterToContinue();
			count++;
		}
	}

	cout << endl << "Finished!" << endl << endl;

	return 0;

}


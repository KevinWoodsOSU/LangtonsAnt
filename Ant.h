/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Assignment: Langton's ant simulation
***************************/

#include <iostream>
using namespace std;

enum direction { NORTH, SOUTH, EAST, WEST };

class Ant {

private:
	int rowCoord; //The ant's current row position
	int colCoord; //The ant's current column position
	int moveNum; //Number of steps the ant will take
	int** boardArray; //2D array 
	int prevColor; //Keeps track of color of the element the ant is currently occupying
	direction dir; //enum data type for which direction the ant is facing
	int rowMax; //Max row boundry
	int colMax; //Max column boundry

public:
	//get and set functions for each variable
	int getRowPos();
	void setRowPos(int x);
	int getColPos();
	void setColPos(int y);
	int getMoveNum();
	void setMoveNum(int m);
	int** getBoardArray();
	void setBoardArray(int** board);
	int getPrevColor();
	void setPrevColor(int c);
	direction getDirection();
	void setDirection(direction d);
	int getRowMax();
	void setRowMax(int r);
	int getColMax();
	void setColMax(int c);
	
	Ant(int moveNum, int** boardArray, int rowCoord, int colCoord, int rowMax, int colMax);
	
	//movement functions
	void turnLeft();
	void turnRight();
	void switchColor(); //Change the color of the square that the ant moves away from
	void setAnt(); //Change the current element to 2 (representing the ant)
	void move(); //Call turnRight or turnLeft depending on the square color the ant is standing on
	
	//If the ant reaches the array boundaries, wrap the ant to the other side.
	void rowWrap(); 
	void colWrap();
};

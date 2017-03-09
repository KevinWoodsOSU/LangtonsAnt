/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Assignment: Langton's ant simulation
***************************/

#include "Ant.h"

Ant::Ant(int move, int** ary, int x, int y, int rmax, int cmax) {
	setMoveNum(move);
	setBoardArray(ary);
	setRowPos(x);
	setColPos(y);
	setPrevColor(0);
	setRowMax(rmax);
	setColMax(cmax);
	boardArray[getRowPos()][getColPos()] = 2;
	setDirection(NORTH);
}

int Ant::getPrevColor() {
	return prevColor;
}

void Ant::setPrevColor(int c) {
	prevColor = c;
}

int Ant::getRowPos() {
	return rowCoord;
}

void Ant::setRowPos(int x) {
	rowCoord = x;
}

int Ant::getColPos() {
	return colCoord;
}

void Ant::setColPos(int y) {
	colCoord = y;
}

int Ant::getMoveNum() {
	return moveNum;
}

void Ant::setMoveNum(int m) {
	moveNum = m;
}

int** Ant::getBoardArray() {
	return boardArray;
}

void Ant::setBoardArray(int** board) {
	boardArray = board;
}

direction Ant::getDirection() {
	return dir;
}

void Ant::setDirection(direction d) {
	dir = d;
}

int Ant::getRowMax() {
	return rowMax;
}

void Ant::setRowMax(int r) {
	rowMax = r;
}

int Ant::getColMax() {
	return colMax;
}

void Ant::setColMax(int c) {
	colMax = c;
}

void Ant::turnLeft() {
	switch (dir) {
	case NORTH:
		switchColor();
		colCoord--;
		colWrap();
		setDirection(WEST);
		setAnt();
		break;
	case EAST:
		switchColor();
		rowCoord--;
		rowWrap();
		setDirection(NORTH);
		setAnt();
		break;
	case SOUTH:
		switchColor();
		colCoord++;
		colWrap();
		setDirection(EAST);
		setAnt();
		break;
	case WEST:
		switchColor();
		rowCoord++;
		rowWrap();
		setDirection(SOUTH);
		setAnt();
		break;
	default:
		cout << "Error" << endl;
	}
}
void Ant::turnRight() {
	switch (dir) {
	case NORTH:
		switchColor();
		colCoord++;
		colWrap();
		setDirection(EAST);
		setAnt();
		break;
	case EAST:
		switchColor();
		rowCoord++;
		rowWrap();
		setDirection(SOUTH);
		setAnt();
		break;
	case SOUTH:
		switchColor();
		colCoord--;
		colWrap();
		setDirection(WEST);
		setAnt();
		break;
	case WEST:
		switchColor();
		rowCoord--;
		rowWrap();
		setDirection(NORTH);
		setAnt();
		break;
	default:
		cout << "Error" << endl;
	}
}

void Ant::switchColor() {
	if (getPrevColor() == 0)
		boardArray[getRowPos()][getColPos()] = 1;
	else
		boardArray[getRowPos()][getColPos()] = 0;
}
//store the color of the element the ant will be placed on then set the ant on the new element
void Ant::setAnt() {	
	setPrevColor(boardArray[getRowPos()][getColPos()]);
	boardArray[getRowPos()][getColPos()] = 2;
}

void Ant::move() {
	if (getPrevColor() == 0)
		turnRight();
	else if (getPrevColor() == 1)
		turnLeft();
}

void Ant::rowWrap() {
	if (getRowPos() == getRowMax())
		setRowPos(0);
	else if (getRowPos() == -1)
		setRowPos(rowMax - 1);
}

void Ant::colWrap() {
	if (getColPos() == getColMax())
		setColPos(0);
	else if (getColPos() == -1)
		setColPos(colMax - 1);
}

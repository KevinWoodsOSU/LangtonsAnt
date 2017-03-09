#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <time.h>

using namespace std;

#ifndef MENU_H
#define MENU_H

int getInt(string prompt); //Input verification for an integer
int getIntLimited(string prompt, int min, int max); //Input verification for an integer between min and max
void clearScreenWindows(); //Clear console for Windows OS testing only
void clearScreenUnix(); //Clear console in Unix
void enterToContinue(); //Pause the program until a key is entered
bool yesOrNo(string prompt); //Input verfication for choose one

#endif

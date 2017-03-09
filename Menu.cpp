#include "Menu.h"

int getInt(string prompt) {
	int num;
	bool isInt = false;
	
	do {
		cout << prompt;
		cin >> num;
		if (cin.good() && num > 0) {
			isInt = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isInt);

	return num;
}

int getIntLimited(string prompt, int min, int max) {
	int num;
	bool isInt = false;

	do {
		cout << prompt << min << " and " << max << "): ";
		cin >> num;
		if (cin.good() && num >= min && num <= max) {
			isInt = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isInt);

	return num;
}

//This function is for testing on Windows OS and will not be used on FLIP
void clearScreenWindows() {
	system("CLS");
}

void clearScreenUnix() {
	cout << "\033[2J\033[1;1H" << endl;
}

void enterToContinue() {
	cout << "Press Enter to Continue (hold to speed through)" << flush;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

bool yesOrNo(string prompt) {
	string ans;
	bool isStr = false;
	
	do {
		cout << prompt;
		getline(cin, ans);
			if (ans == "y" || ans == "Y" || ans == "n" || ans == "N") 
				isStr = true;	
	} while (!isStr);

	if (ans == "y" || ans == "Y")
		return true;
	else if (ans == "n" || ans == "N")
		return false;
}

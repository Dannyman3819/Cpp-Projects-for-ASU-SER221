#include <iostream>

using namespace std;

// need to define the max amount of classes for array
static const int maxClasses = 50;

class Student {
private:
	string name;            			//string for name of student
	int numClasses;         			//int for amount of courses student has
	string classList[maxClasses];      	//array for the names of classes


public:
	//member function declaration and definitions using in-line function code
	//setters
	void setName(string newName) { name = newName; }
	void setNumClasses(int newNum) { numClasses = newNum; }
	void setClassList(string newClass, int p) { classList[p] = newClass; }

	//getters
	string getName() { return name; }
	int getNumClasses() { return numClasses; }
	string getClassList(int p) { return classList[p]; }

	//reset function
	void resetData() {
		// redeclare variables to clear
		string name;
		int numClasses;
		string classList[maxClasses];
	}
};

int main() {
	Student Student1;			// Declare Student1 of type Student

	while(true) {
		//Request name and save in Student1 using setName
		string tName;
		cout << "Enter students name: ";
		cin >> tName;
		Student1.setName(tName);

		//Request the number of classes and save using setNumClasses
		int tNumClass;
		cout << "Enter the number of enrolled classes: ";
		cin >> tNumClass;
		Student1.setNumClasses(tNumClass);

		// Init a temp Array for the class list plus 1 for any overflow errors that might happen
		string tClass;
		int tCount = 0;				// tCount used for while
		cout << "Enter a list of class names separated by a newline:\n";
		// Needed for clearing the input buffer so we don't get stray newlines in our array
		cin.ignore();
		while (true) {
			getline(cin, tClass);
			Student1.setClassList(tClass, tCount);

			// Check if we are done filling array, +1 because arrays are zero indexed the number of classes is not
			if ((tCount + 1) == Student1.getNumClasses()) {
				break;
			}
			tCount += 1;
		}

		cout << "You entered for your Name: " << Student1.getName() << "\n";
		cout << "You entered for the Number of Classes: " << Student1.getNumClasses() << "\n";

		for (int i = 0; i < Student1.getNumClasses(); i++) {
			cout << "Your classes: " << Student1.getClassList(i) << "\n";
		}

		// Prompt user
		while(true) {
			string response;
			cout << "Would you like to enter data again (Y/N)?\n";
			cin >> response;
			if (response == "n" || response == "N") {
				// Doesn't want to enter data again so we exit
				return 0;
			} else if (response == "y" || response == "Y") {
				// Wants to enter data again so we clear data the break out of this loop
				Student1.resetData();
				break;
			} else {
				// No valid response so we continue this loop
				cout << "Please enter valid response.\n";
			}
		}
	}
}
#include <iostream>
#include <stdlib.h>

using namespace std;

static int totalBox = 0;					// Variables used to track the number of boxes created
static const int maxFood = 5;				// The max amount of items we have
bool first = true;							// Used in the random function to seed
int randomNumberRange(int min, int max);	// Define the random function

class BoxOfProduce {
private:
	const string food[5] = {"Broccoli", "Tomato", "Kiwi", "Kale", "Tomatillo"};	//array for food items that never changes
	string boxFood[3];
public:
	//member function declaration and definitions using in-line function code
	//setters
	void changeItem(int itemFromList, int itemToBox) { boxFood[itemToBox] = food[itemFromList]; }

	//getters
	string getBoxItem(int p) { return boxFood[p]; }

	//reset function
	void resetData() {
		// redeclare variables to clear
		string boxFood[3];
	}
	void printBox(){		// Prints the list of the current box, with numbers
		for(int i=0; i<3; i++){
			cout << i+1 << ". " << boxFood[i] << "\n";
		}
	}
	void printList(){		// Prints the possible food list, with numbers for selecting food item
		for(int i=0; i<5; i++){
			cout << i+1 << ". " << food[i] << "\n";
		}
	}
};

int main() {
	BoxOfProduce myBox;			// Init new box

	while(true) {
		for (int i = 0; i < 3; i++) {
			myBox.changeItem(randomNumberRange(0, 5), i);
		}
		// A box was just created we want to increment by 1
		totalBox++;

		//Output current box and ask for changes
		cout << "Current Box of Produce:\n";
		myBox.printBox();

		while (true) {
			string response;
			cout << "Would you like to make a substitution (Y/other continues)? ";
			cin >> response;
			if (response == "Y" || response == "y") {
				// init variables used in this if block
				string replaceInBox;
				string replaceWithList;
				while(true) {
					cout << "\nPlease enter the number for the produce you don't want in your box:\n";
					myBox.printBox();
					cin.ignore();
					cin >> replaceInBox;

					if(replaceInBox == "1" || replaceInBox == "2" || replaceInBox == "3"){
						break;		//checks for valid user input
					}
				}

				while(true) {
					cout << "\nPlease enter the number for the produce you want to replace it:\n";
					myBox.printList();
					cin.ignore();
					cin >> replaceWithList;

					if(replaceWithList == "1" || replaceWithList == "2" || replaceWithList == "3" || replaceWithList == "4" || replaceWithList == "5"){
						break;		//checks for valid user input
					}
				}

				// Need to subtract 1 because arrays are 0 indexed and the list we displayed to user is not
				myBox.changeItem(std::stoi(replaceWithList) - 1, std::stoi(replaceInBox) - 1);
				cout << "Current Box of Produce:\n";
				myBox.printBox();
			} else {
				cout << "\n\nBox of produce to be delivered:\n";
				myBox.printBox();
				break;
			}
		}

		cout << "\nTotal Number of boxes to be delivered: " << totalBox << "\n";
		string response;
		cout << "\nWould you like to create another box(Y/other continues)?";
		cin >> response;
		if(response != "Y" && response != "y"){
			break;
		}
	}

	string response;
	cout << "\nThank you, Here's the total number of boxes you created: " << totalBox << "\n";

	return 0;
}

int randomNumberRange(int min, int max){
	//used for seeding rand() function call, seeding is only needed for the first call
	if ( first )
	{
		srand(time(NULL));
		first = false;
	}

	//rand() returns a large number, using the function (rand % difference + min) will return a
	//number between min and max
	return (rand() % (max - min)) + min;
}
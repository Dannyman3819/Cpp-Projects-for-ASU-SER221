#include <iostream>
using namespace std;

int main() {
    //Prompt for intructors name
    string instructorName;
    cout << "Please enter the first or last name of your Instructor\n";
    cin >> instructorName;

    //Prompt for users name
    string userName;
    cout << "Please enter your name\n";
    cin >> userName;

    //Prompt for food item
    string foodItem;
    cout << "Please enter a food item\n";
    cin >> foodItem;

    //Prompt for number between 100-120, then check
    int numberRange;
    bool continueLoop = true;
    while(continueLoop) {
        cout << "Please enter a number between 100-120\n";
        cin >> numberRange;
        if (numberRange >= 100 && numberRange <= 120) {
            continueLoop = false;
        } else {
            cout << "Try again...\n";
        }
    }

    //Adjective
    string userAdjective;
    cout << "Please enter an adjective\n";
    cin >> userAdjective;

    //Color
    string userColor;
    cout << "Enter a color\n";
    cin >> userColor;

    //Animal
    string userAnimal;
    cout << "Enter an animal\n";
    cin >> userAnimal;

    //Print message
    cout << "\n\nDear Professor " << instructorName << ",\n" << "I am sorry that I am unable to turn in my homework at this time. "
         "First, I ate a rotten " << foodItem << ", which made me turn " << userColor << " and extremely ill. I came down with a fever of "
         << numberRange << ". Next my " << userAdjective << " pet " << userAnimal << " must have smelled the remains of the "
         << foodItem << " on my homework, because he ate it. I am currently rewriting my homework and hope you will accept it late.\n"
         << "\n"
         << "Sincerely,\n"
         << userName;



    return 0;
}

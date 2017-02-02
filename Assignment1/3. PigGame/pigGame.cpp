#include <iostream>
#include <cstdlib>

using namespace std;

//Initilize global variables
int winningPoints = 100;
bool first = true;
int humanTotalScore = 0;
int compTotalScore = 0;

//initilize all functions
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int randomNumberRange(int min, int max);

int main() {
    cout << "Lets play a game of Pig\n\n";

    //Loop between human and computer till a score of 100 or above is reached
    while(humanTotalScore < 100 && compTotalScore < 100) {
        //call func humanTurn and add return value to total score
        humanTotalScore += humanTurn(humanTotalScore);
        cout << "\nYour Total Score is: " << humanTotalScore << "\n";

        //call function computerTurn then add return value to compTotalScore
        cout << "My turn!\n\n";
        compTotalScore += computerTurn(compTotalScore);
        cout << "My total score is: " << compTotalScore << "\n\n";
    }

    //When this is reached the game is over because either the human or computer have a score of 100 or more
    cout << "Game Over!!\n";
    cout << "Final Scores:\n";
    cout << "Human: " << humanTotalScore << "\n";
    cout << "Computer: " << compTotalScore << "\n\n";

    if(humanTotalScore > 100){
        cout << "You Win!!";
    }  else {
        cout << "I Win!!";
    }

    return 0;
}


int humanTurn(int humanTotalScore) {
    //initilize variables here because function loops
    string roll;
    int tempScore = 0;
    int tRandom;

    //This loops when user wants to roll again
    while (true) {
        cout << "Your turn, enter R(or r) to roll and H(or h) to hold: ";
        cin >> roll;
        if (roll == "R" || roll == "r") {
            //call random function to get a number between min and max numbers
            tRandom = randomNumberRange(1,6);

            //if tRandom is 1 then temp points are lost
            if (tRandom == 1){
                cout << "Bummer you rolled a 1, you lost these points\n";
                tempScore = 0;
                //return a score of 0
                return tempScore;
            } else {
                //if not 0 then add tRandom to tempScore till user decides to roll or hold
                tempScore += tRandom;
                cout << "You rolled a: " << tRandom << " for a temp score of: " << tempScore << "\n";
            }
        } else if (roll == "H" || roll == "h") {
            //Hold and return current tempScore to be added to totalScore in main function
            cout << "Holding at: " << tempScore << "\n";
            return tempScore;
        } else {
            //User didn't enter a correct value
            cout << "Error please enter R(or r) to roll or H(or h) to hold your current score\n";
        }
    }
}

int computerTurn(int computerTotalScore){
    //init variables
    int tempScore = 0;
    int tRandom;

    //begin loop, stops when score is more then 20
    while(tempScore < 20) {
        //call random function to get a random range between min and max
        tRandom = randomNumberRange(1,6);
        tempScore += tRandom;

        //if 1 was rolled then score id lost
        if (tRandom == 1){
            cout << "I rolled a 1, so I lost my temporary score\n";
            tempScore = 0;
            return tempScore;
        }
        //if 1 wasn't rolled then continue
        cout << "I rolled a: " << tRandom << " for a temp score of: " << tempScore << "\n";
    }
    //will reach here when tempScore is more than 20
    //will hold by returning current score
    cout << "Im holding with a score of: " << tempScore << "\n";
    return tempScore;
}


#include <iostream>
#include <cstdlib>
using namespace std;

bool first = true;
//init the 2d array of the possible card values, will be shuffled later
int cardValues[4][4] = {
        {1,1,2,2},
        {3,3,4,4},
        {5,5,6,6},
        {7,7,8,8}
};
//init the 2d array and set all the values to false because no cards are flipped over
bool cardFaceUp[4][4] = {
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false}
};

//init functions
void shuffleDeck();
int randomNumberRange(int min,int max);
void printDeck();
void clearTerm();
void promptUser();
bool isDone();

int main() {
    cout << "Lets begin!\n\n";
    shuffleDeck();
    printDeck();

    //start main loop
    bool loop = true;
    while(loop){
        //this funciton is where the the input is collected and compared
        promptUser();

        //isDone checks to see if all the cards are flipped over meaning game over
        if(isDone()){ loop = false; }
    }

    cout << "Congrats you won!!";
    return 0;
}

void clearTerm(){
    //prints 50 newlines
    for(int i = 0; i < 50; i++){
        cout << "\n";
    }
}

void promptUser(){
    //init variables that are in a loop
    int x1Coor;
    int y1Coor;
    int x2Coor;
    int y2Coor;
    int loop = true;
    //start the loop, will only loop if the user inputs something incorrectly
    while(loop) {
        cout << "Please enter x-Coordinate of the first number: ";
        cin >> x1Coor;
        cout << "Please enter y-Coordinate of the first number: ";
        cin >> y1Coor;
        cout << "\n\n";

        //check to make sure the coordinates we got are within the bounds
        if ((x1Coor > 4 || x1Coor < 1) || (y1Coor > 4 || x1Coor < 1)) {
            cout << "Please enter valid coordinates (1-4)\n";
        } else {
            //check to make sure the selected number isn't already face up
            if(cardFaceUp[x1Coor-1][y1Coor-1]) {
                cout << "That number has been found!! Try again\n";
            } else {
                //exit loop if all is good
                loop = false;
            }
        }
    }

    //need to subtract 1 because arrays are 0 indexed
    cardFaceUp[x1Coor-1][y1Coor-1] = true;
    clearTerm();
    printDeck();

    //start loop, will only loop if something the user entered is incorrect
    loop = true;
    while(loop) {
        cout << "Please enter x-Coordinate of the second number: ";
        cin >> x2Coor;
        cout << "Please enter y-Coordinate of the second number: ";
        cin >> y2Coor;
        cout << "\n\n";

        //check to make sure the first selected number is different than the second
        if(x2Coor == x1Coor && y2Coor == y1Coor){
            cout << "Please enter a different Coordinate than the first number\n";
        } else {
            //check to make sure coordinates are within grid
            if((x2Coor > 4 || x2Coor < 1) || (y2Coor > 4 || x2Coor < 1)){
                cout << "Please enter valid coordinates (1-4)";
            } else {
                //make sure the selected number isn't already face up
                if(cardFaceUp[x2Coor-1][y2Coor-1]) {
                    cout << "That number has been found!! Try again\n";
                } else {
                    //exit loop
                    loop = false;
                }
            }
        }
    }


    //need to subtract 1 because arrays are 0 indexed
    cardFaceUp[x2Coor-1][y2Coor-1] = true;
    clearTerm();
    printDeck();

    //check to see if values match
    if(cardValues[x1Coor-1][y1Coor-1] == cardValues[x2Coor-1][y2Coor-1]){
        //its a match, leave card face up and continue
        cout << "Its a Match!!\n";
    } else {
        //not a match, return cards to their original face down value(false)
        cout << "Try Again!!\n";
        cardFaceUp[x1Coor-1][y1Coor-1] = false;
        cardFaceUp[x2Coor-1][y2Coor-1] = false;
    }
}

bool isDone(){
    //test to see if any card is still facedown, if so then we aren't done yet
    for ( int i = 0; i < 4; i++ ) {
        for (int j = 0; j < 4; j++) {
            if(!cardFaceUp[i][j]){
                return false;
            }
        }
    }
    return true;
}

void shuffleDeck() {
    int loop = 0;
    int tempNumber = 0;
    int x1CoorRand;
    int y1CoorRand;
    int x2CoorRand;
    int y2CoorRand;

    while (loop < 100) {
        //get random coordinate for first card to swap
        x1CoorRand = randomNumberRange(1, 4);
        y1CoorRand = randomNumberRange(1, 4);
        //get random coordinate for second card to swap
        x2CoorRand = randomNumberRange(0, 4);
        y2CoorRand = randomNumberRange(0, 4);

        //store 1st value into temp, then put 2nd value into 1st place, put temp into 2nd value
        tempNumber = cardValues[x1CoorRand][y1CoorRand];
        cardValues[x1CoorRand][y1CoorRand] = cardValues[x2CoorRand][y2CoorRand];
        cardValues[x2CoorRand][y2CoorRand] = tempNumber;
        loop++;
    }
}

void printDeck(){
    //this function prints the deck array in a nice format
    cout << "        1  2  3  4\n";
    cout << "     ---------------\n";
    for ( int i = 0; i < 4; i++ ) {
        cout << "  " << i+1 << "  |  ";
        for (int j = 0; j < 4; j++) {
            if(cardFaceUp[j][i]){
                cout << cardValues[j][i] << "  ";
            } else {
                cout << "*  ";
            }


        }
        cout << "\n";
    }
    cout << "\n\n";
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
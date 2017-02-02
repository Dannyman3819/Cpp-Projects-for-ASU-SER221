#include <iostream>
using namespace std;

//init functions and variables
int whoWins(string p1Choice, string p2Choice);
int p1Score = 0;
int p2Score = 0;

int main() {
    //Player 1 choice
    string p1Choice;
    cout << "Player 1: Please enter either (R)ock, (P)aper, or (S)cissors : ";
    cin >> p1Choice;

    //player 2 choice
    string p2Choice;
    cout << "Player 2: Please enter either (R)ock, (P)aper, or (S)cissors : ";
    cin >> p2Choice;

    //Calls the function whiWins to determine who will win
    //Passes function the string R,P, or S for both players
    //Returns an int value of: 1 if Player 1 won, 2 if Player 2 won, and 3 if it was a draw
    int winner = whoWins(p1Choice, p2Choice);

    //Output who won and add to global score variable
    if(winner == 1){
        cout << "\nPlayer 1 wins.\n";
        p1Score++;
    } else if(winner == 2){
        cout << "\nPlayer 2 wins.\n";
        p2Score++;
    } else {
        cout << "\nNobody wins.\n";
    }

    //Output score
    cout << "\nScores after this play:\n";
    cout << "Player 1: " << p1Score << "\n";
    cout << "Player 2: " << p2Score << "\n";
    cout << "\nThanks!!\n\n";

    //Prompt user to play again
    string userAgain;
    cout << "Play again? Y/y continues, other quits: ";
    cin >> userAgain;

    //Test response, if user wants to play again main function is called to repeat process while global variables intact
    if(userAgain == "Y" || userAgain == "y"){
        main();
    }

    //If user pressed no then return 0 to exit program
    return 0;
}


int whoWins(string p1Choice, string p2Choice) {        
    
    //p1 = Rock vs p2 = Paper
    if((p1Choice == "R" || p1Choice == "r") && (p2Choice == "P" || p2Choice == "p")){
        return 2;
    }

    //p1 = Rock vs p2 = Scissors
    if(((p1Choice) == "R" || (p1Choice) == "r") && ((p2Choice) == "S" || (p2Choice) == "s")){
        return 1;
    }

    //p1 = Paper vs p2 = Rock
    if(((p1Choice) == "P" || (p1Choice) == "p") && ((p2Choice) == "R" || (p2Choice) == "r")){
        return 1;
    }

    //p1 = Paper vs p2 = Scissors
    if(((p1Choice) == "P" || (p1Choice) == "p") && ((p2Choice) == "S" || (p2Choice) == "s")){
        return 2;
    }

    //p1 = Scissors vs p2 = Rock
    if(((p1Choice) == "S" || (p1Choice) == "s") && ((p2Choice) == "R" || (p2Choice) == "r")){
        return 2;
    }

    //p1 = Scissors vs p2 = Paper
    if(((p1Choice) == "S" || (p1Choice) == "s") && ((p2Choice) == "P" || (p2Choice) == "p")){
        return 1;
    }

    return 3;
}
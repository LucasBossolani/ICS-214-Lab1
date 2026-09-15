#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int promptUserForMaxRange();
int pickRandomNumberInRange(int min, int max);
int promptUserForGuess(int maxRange);
bool promptForPlayAgain();
void playOneRound();
int getIntFromUser();
void ignoreLine();
int getIntFromUserInRange(int min, int max);

//main: runs the playOneRound function until promptForPlayAgain returns true and also seeds the randomizer. 
int main() {

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 20; i++) {
        int randomNumber = pickRandomNumberInRange(5, 7);
        std::cout << randomNumber;

    }
    
    do { 
        playOneRound(); 

    } while (promptForPlayAgain());

}

//ignoreLine: ignore all characters until it hits a "\n"
void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//gets an Int input from the user.  
//it keeps running on an infinite loop. If the input is invalid it throws an error. Otherwise, it returns the input
int getIntFromUser() {
    while (true) {
        int input;
        std::cin >> input;

        if (std::cin.fail()) {

            std::cout << "invalid input. try again: \n";
            std::cin.clear();
            ignoreLine();
        }
        else {
            ignoreLine();
            return input;
        }

      
    }

}
//gets an Int input from the user. 
//it uses int min and int max as parameters
//Runs on an infinite loop until user input is correct. Otherwise, displays the error message and gets another input. 
//returns the input
int getIntFromUserInRange(int min, int max) {
    
    while (true) {
        int input = getIntFromUser();
        if (input < min || input > max) {
            std::cout << "Invalid input.Range is [" << min << " to " << max << "].Please try again: \n";

           /* std::cin.clear();
            ignoreLine();*/

            //continue;
        }
        else {
            //ignoreLine();
            return input;
        }

    }

}
//asks for max range.
//defines maxChosen as the result of the getIntFromUserInRange call.
//getIntFromUserInRange uses 0 as minimum and INT_MAX as max.
//returns maxChosen once the input is correct. 
int promptUserForMaxRange() {
    std::cout << "Enter the maximum range: \n";
    int maxChosen = getIntFromUserInRange(0, INT_MAX);

    return maxChosen;

}
//pick a number within the range chosen by the user. uses int min and max as parameters. 
//returns the random number
int pickRandomNumberInRange(int min, int max) {
    //basic function that randomizes a number within any given range. 
    //necessary for cases where the minimum is not 0.
    int range = max - min + 1;

    //int randomNumberPicked{ rand() % (max - min + 1) };
    return min + (rand() % range);

    //return randomNumberPicked;
}
int promptUserForGuess(int max) {
    std::cout << "Enter a guess: \n";
    int userGuess = getIntFromUserInRange(0, max);
    
    return userGuess;

}
//asks user if they want to play again
//converts user response to a string and checks for: y,Y,n and N
//if the input doesn't meet the requirements it asks for it again until it works. 
//returns true/false depending on the user desire to play this awesome game again.
bool promptForPlayAgain() {
    std::string userResponse;
    std::cout << "do you wish to play again [y/n]: \n";
    std::cin >> userResponse;
    while (userResponse != "y" && userResponse != "n" && userResponse != "Y" && userResponse != "N") {
        std::cout << "Invalid input. Enter [y/n]: \n";
        std::cin >> userResponse;
    }
    if (userResponse == "y" || userResponse == "Y") {
        return true;
    }
    else {
        return false;
    }
}

//bool promptForPlayAgain() {
//    std::string userResponse;
//    std::cout << "do you wish to play again [y/n]: \n";
//    while (true) {
//        std::cin >> userResponse;
//        ignoreLine();
//
//        if (userResponse == "y" || userResponse == "Y") {
//            return true;
//        }
//        else if(userResponse == "N" && userResponse == "n") {
//            return false;
//        }
//        else {
//            std::cout << "Invalid input. Enter [y/n]: \n";
//        }
//    }   
//}

//Function that runs on the Main. 
//initializes that guess count and runs all the functions declared above in the correct order and passing all values from on to another. 
//adds one to the guess count every time that user guess.
//checks if the guess is either lower or higher than the picked random number (Out of bounds is handled by getIntFromUserInRange).
void playOneRound() {
    int guessesCount = 0;
    std::cout << "welcome to mystery number \n";
    int maxRange = promptUserForMaxRange();
    int randomNumber = pickRandomNumberInRange(0, maxRange);
//    int userGuess = promptUserForGuess(maxRange);
    guessesCount += 1;

    while(true){
        int userGuess = promptUserForGuess(maxRange);
        guessesCount += 1;

        if (userGuess < randomNumber) {
            std::cout << "guess higher...";
            
        }
        else if (userGuess > randomNumber) {
            std::cout << "guess lower...";
        }
        else {
            // we're done!
            break;
        }
    }
    std::cout << "correct. it took you " << guessesCount << " guesses" << "\n";






}

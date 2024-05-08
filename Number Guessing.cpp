/*Sahil_Sharma
Task_1_:a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    

int main() {
    
    srand(time(0));
    
    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Guess the number (between 1 and 100): ";

    while (userGuess != secretNumber) {
        std::cin >> userGuess;

        if (userGuess < secretNumber) {
            std::cout << "Too low. Try again: ";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high. Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the number!" << std::endl;
        }
    }

    return 0;
}

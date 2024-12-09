/*
Program Title: Chapter7 Rock Paper Scissors Part2
Programmer: Josh Richards
Date: December 9, 2024
Requirements:

Revise the Rock Paper Scissors using an array to store multiple games each with the best score for each player.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_GAMES = 5; 

struct Game {
    string userChoice;
    string computerChoice;
    string result;
};

int getComputerChoice();
string getUserChoice();
string convertChoice(int choice);
string determineWinner(string userChoice, string computerChoice);
void displayGameHistory(Game games[], int gameCount);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Game games[MAX_GAMES];
    int gameCount = 0;
    int userWins = 0;
    int computerWins = 0;

    while (gameCount < MAX_GAMES) {
        int computerChoice = getComputerChoice();
        string userChoice = getUserChoice();
        string computerChoiceStr = convertChoice(computerChoice);

        cout << "Computer chose: " << computerChoiceStr << endl;

        string result = determineWinner(userChoice, computerChoiceStr);

        if (result == "You Win!!!") {
            userWins++;
        }
        else if (result == "Computer Wins!") {
            computerWins++;
        }

        games[gameCount].userChoice = userChoice;
        games[gameCount].computerChoice = computerChoiceStr;
        games[gameCount].result = result;
        gameCount++;

        cout << result << endl;

        if (gameCount < MAX_GAMES) {
            char playAgain;
            cout << "Do you want to play another game? (y/n): ";
            cin >> playAgain;
            if (tolower(playAgain) != 'y') {
                break;
            }
        }
    }

    cout << "\nGame history:\n";
    displayGameHistory(games, gameCount);

    cout << "\n Final Scores:\n";
    cout << "User Wins: " << userWins << endl;
    cout << "Computer Wins: " << computerWins << endl;

    return 0;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

string getUserChoice() {
    string choice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors): ";
        cin >> choice;

        for (char& c : choice) c = tolower(c);

        if (choice == "rock" || choice == "paper" || choice == "scissors") {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'rock', 'paper', or 'scissors'.\n";
        }
    }
    return choice;
}

string convertChoice(int choice) {
    switch (choice) {
    case 1: return "rock";
    case 2: return "paper";
    case 3: return "scissors";
    default: return "unknown";
    }
}

string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "Draw";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "You Win!!!";
    }
    else {
        return "Computer Wins!";
    }
}

void displayGameHistory(Game games[], int gameCount) {
    for (int i = 0; i < gameCount; i++) {
        cout << "Game " << i + 1 << ":\n";
        cout << "    User Choice: " << games[i].userChoice << endl;
        cout << "    Computer Choice: " << games[i].computerChoice << endl;
        cout << "    Results: " << games[i].result << endl;
    }
}

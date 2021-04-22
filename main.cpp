//  Group Project of Group14_ENGG1340
//  Game : GUESS THE MOVIE !
//  Group Members:
//  1. BHATIA Divtej Singh : 3035832438
//  2. AGRAWAL Aryan : 3035812373


#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main(){

    //Introduction Output 
    cout << endl; //endline marking start of game
    cout << "ENGG1340 2020-21 Semester 2" << endl;
    cout << "WELCOME TO GROUP PROJECT OF GROUP 14" << endl;
    cout << "Group Members" << endl;
    cout << "1. BHATIA Divtej Singh" << endl;
    cout << "2. AGRAWAL Aryan" << endl;
    cout << "Press ENTER to Start" << endl;

    cin.get(); // detecting enter

    // Asking USER for Mode
    cout << "CHOOSE YOUR MODE: " << endl;
    cout << "Press S for Single Player" << endl;
    cout << "Press M for Multiplayer" << endl;

    char input_mode;
    cin >> input_mode ; 
    input_mode = toupper(input_mode); //even if lowercase is entered



}
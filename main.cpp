//  Group Project of Group14_ENGG1340
//  Game : GUESS THE MOVIE !
//  Group Members:
//  1. BHATIA Divtej Singh : 3035832438
//  2. AGRAWAL Aryan : 3035812373


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void print_movie(/*array containing movie name */){

}


int main(){

    //Introduction Output 
    cout << endl;
    cout << "***************************" << endl;
    cout << endl; //endline marking start of game
    cout << "ENGG1340 2020-21 Semester 2" << endl;
    cout << endl;
    cout << "WELCOME TO GROUP PROJECT OF GROUP 14" << endl;
    cout << "Group Members" << endl;
    cout << "1. BHATIA Divtej Singh" << endl;
    cout << "2. AGRAWAL Aryan" << endl;
    cout << "Press ANY KEY to Start" << endl;

    cin.get(); // detecting enter

    // Asking USER for Mode
    cout << "CHOOSE YOUR MODE: " << endl;
    cout << "Press S for Single Player" << endl;
    cout << "Press M for Multiplayer" << endl;

    char input_mode;
    cin >> input_mode ;
    input_mode = toupper(input_mode); // for case when lowercase is entered
    if (input_mode != 'S' || input_mode != 'M'){
        cout << "Incorrect Choice, Play Again Soon !" << endl;
        return 0;
    }

    //Using Fstream and Stringstream to Load a movie and hint

    //Make a dynamic array of the size of the movie name 
    //load hint string

    //Unguessed contains the number of total alphabets to be guessed
    int unguessed = 0;


    //game starts:
    cout << endl;
    cout << "GUESS THE MOVIE ALPHABETS UNTIL YOU COMPLETE THE MOVIE NAME " << endl;

    //SINGLEPLAYER Mode
    if (input_mode == 'S'){
        //enter Single Player Mode


    }







    //MULTIPLAYER MODE
    else{
        //enter Multiplayer Mode



    }


    return 0;
}
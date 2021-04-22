//  Group Project of Group14_ENGG1340
//  Game : GUESS THE MOVIE !
//  Group Members:
//  1. BHATIA Divtej Singh : 3035832438
//  2. AGRAWAL Aryan : 3035812373

//  Most Recent Error : movie name not being stored into the dynamic array.

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>

using namespace std;

void print_movie(int n ,char * movie_display){
    for ( int i = 0 ; i < n ; i ++ ){
        cout << movie_display[i] << " " ;
    }
    cout << endl;
}


char get_guess(){
    char g ;
    cin >> g ;
    g = toupper(g) ;
    return g;
}

bool is_guess( char g , int n , char * movie){
    for (int i = 0 ; i < n ; i ++){
        if (g == movie[i]){
            return true;
        }
    }
    return false;
}

void update_with_guess(char g, int n , char * movie , char * & movie_display, int & unguessed){
    for ( int i = 0 ; i < n ; i ++){
        if ( g == movie[i]){
            unguessed -=1 ;
            movie_display[i] = g;
        }
    }

}

bool isvowel(char x){
    if ( x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return true;
    else
        return false;
}

void print_hint(string hint){
    cout << "Hint: " << hint << endl;
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
    cout << "Press M for Multiplayer " <<endl;

    char input_mode;
    cin >> input_mode ;
    input_mode = toupper(input_mode); // for case when lowercase is entered

    //Using Fstream and Stringstream to Load a movie and hint

    //Make a dynamic array of the size of the movie name 
    //load hint string
    
    //assuming that fstream loads 
    string random_movie;
    random_movie = "T I T A N I C"; //**CHANGE THIS with fstream input
    string hint;
    char letter;

    //hint will come from other fstream file 
    hint = "A Movie about a ShipWreck" ;// **CHANGE THIS with fstream input

    istringstream name(random_movie);
    int n; //contains number of letters

    while(name >> letter){ //finding the length of the movie name 
        n +=1 ;
    }
    
    //Making Dynamic Array :
    char * movie = new char[n];
    char * movie_display = new char[n];

    int unguessed = 0;

    int t = 0 ;
    
    while ( name >> letter){
        movie[t] = letter;
        t += 1;
    }


    //removing the consonants from the letter
    for ( int i = 0 ; i < n; i ++){
        char q = movie[i]; 
        if ( isvowel(q) ){
            movie_display[i] = q;
        }
        else {
            movie_display[i] = '_';
            unguessed += 1;

        }
    }



    //Unguessed contains the number of total alphabets to be guessed
    int remaining_guess = 5 ;



    //game starts:
    cout << endl;
    cout << "GUESS THE MOVIE ALPHABETS UNTIL YOU COMPLETE THE MOVIE NAME " << endl;

    //SINGLEPLAYER Mode
    if (input_mode == 'S'){
        string player_name;
        cout << "Enter Player Name: " ;
        cin >> player_name;

        //enter Single Player Mode
        while( unguessed != 0 && remaining_guess >= 0 ){
            print_movie(n , movie_display);
            print_hint(hint);
            

            cout << "Enter Guess: " ;
            char g = get_guess();
            if (is_guess(g,n,movie) == false)
                remaining_guess -= 1;
            update_with_guess(g, n , movie , movie_display, unguessed);
    
        } 

        if (unguessed == 0 ){
            cout << "Congratulations " << player_name << " , you WON !!" << endl;
        }
        
        

    }







    //MULTIPLAYER MODE
    else if ( input_mode == 'M'){
        //enter Multiplayer Mode



    }

    else{
        cout << "INVALID CHOICE, Try Again Later" << endl;
    }

    delete [] movie;
    delete [] movie_display;
    return 0;

}
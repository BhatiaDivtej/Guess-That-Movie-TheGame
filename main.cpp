
//  Group Project of Group14_ENGG1340
//  Game : GUESS THE MOVIE !
//  Group Members:
//  1. BHATIA Divtej Singh : 3035832438
//  2. AGRAWAL Aryan : 3035812373

//  Most Recent Error : single player does not work properly.

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdlib>

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
  //  g = toupper(g) ;
    return g;
}

bool is_guess( char g , int n , char * movie){
    for (int i = 0 ; i < n ; i ++){
        if (toupper(g) == movie[i] || tolower(g) == movie[i] ){
            return true;
        }
    }
    return false;
}

void update_with_guess(char g, int n , char * movie , char * & movie_display,
   int & unguessed){
    for ( int i = 0 ; i < n ; i ++){
        if ( toupper(g) == movie[i] || tolower(g) == movie[i]){
            unguessed -=1 ;
            movie_display[i] = movie[i];
        }
    }

}

bool isvowel(char x){
    if ( x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
  x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
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
    cout << "Group Members:" << endl;
    cout << "1. BHATIA Divtej Singh" << endl;
    cout << "2. AGRAWAL Aryan" << endl;
    cout <<"\n***************************\n" << endl  ;
    cout << "Press ENTER to Start" << endl;

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
    ifstream fin ;
    fin.open("movie_name.txt");
    srand(time(0)) ;// random seed based on the current time
    int random = 0 , checker = 0 ;

    random = rand() % 122  + 1; // generating a number between 1 and 122

    while ( getline( fin , random_movie)) {
      checker += 1 ;
      if ( checker == random) { // once we get to the line number that random
        break ; // generated it breaks
      }
    }

    fin.close() ;


    string hint_1 , hint_2;
    char letter;




     ifstream fin1, fin2 ;
     fin1.open("movie_year.txt");
     fin2.open("movie_director.txt") ;
     checker = 0 ;

     while ( getline( fin1 , hint_1)) {
       checker += 1 ;
       if ( checker == random) { // once we get to the line number that random
         break ; // generated it breaks
       }
     }

     checker = 0 ;

     while ( getline( fin2 , hint_2)) {
       checker += 1 ;
       if ( checker == random) { // once we get to the line number that random
         break ; // generated it breaks
       }
     }
     fin1.close() ;
     fin2.close() ;


    int n = 0; //contains number of letters
    int num_of_words = 1; // number of words in the movie name

    for ( int i = 0 ; i < random_movie.length() ; i ++ ) { // finding the length
    //of the movie without spaces
      if(random_movie[i] != ' ')
        n += 1 ;
      else num_of_words += 1 ;
    }




    int length = random_movie.length() ;

    //Making Dynamic Array :
    char * movie = new char[n];
    char * movie_display = new char[n];

    int unguessed = 0;
    int t = 0 ;

    for ( int i = 0 ; i < length ; i ++ ) {
        movie[i] = random_movie[i] ;
    }


/* problem area
    istringstream name(random_movie);

    while ( name >> letter){ // this is a problem
        movie[t] = letter;  // it removes the space between the movie
        t += 1;// Thus when guessing the space is removed again
    }// so this while loop must be deleted. */

    //removing the consonants from the letter
    for ( int i = 0 ; i < length; i ++){
        char q = movie[i];
        if ( isvowel(q) || isalpha(q) == 0 ){ // If there is a punctuation mark
            movie_display[i] = q ; // it should be displayed
        }
        else if (q == ' '){
          movie_display[i] = ' ' ;

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
        cout << "\nThe movie is " << n << " letters long! and has "<< num_of_words
        << " word(s)! Good Luck!!\n";

        cout << "You have 5 guesses remaining \n";

        //enter Single Player Mode
        while (unguessed != 0 && remaining_guess > 0 ){
            print_movie(length , movie_display);
            //print_hint(hint);


            cout << "Enter Guess: " ;
            char g = get_guess();
            if (is_guess(g, length, movie) == false) {
                remaining_guess -= 1;
                cout << "\nYou now have "<< remaining_guess
                <<" guess(es) remaing\n";

                if ( remaining_guess == 3 ) {
                cout << "Here is your first hint:\n"
                << "This movie was released in "<< hint_1 << endl ;}

                else  if ( remaining_guess == 1 ){
                  cout << "Here is your second hint: \n"
                  <<"This movie was directed by " << hint_2 << endl ;
                }


              }
            update_with_guess(g, length , movie , movie_display, unguessed);

        }

        if (unguessed == 0 ){
            cout << random_movie << endl ; // if opponent wins the completed movie
            //should be shown.
            cout << "Congratulations " << player_name << ", You Win !!" << endl;
        }

        if (remaining_guess == 0 ) {
          cout << "Uh Oh, "<< player_name
          <<", You are out of guesses, The movie was: "<< random_movie << endl ;
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

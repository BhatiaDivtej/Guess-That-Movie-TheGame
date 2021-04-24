//  Group Project of Group14_ENGG1340
//  Game : GUESS THE MOVIE !

//  Group Members:
//  1. BHATIA Divtej Singh : 3035832438
//  2. AGRAWAL Aryan : 3035812373

//  Recent Comment : Game Works as expected ! Both Single and Multiplayer added.

/* IMPLEMANTATION of Code Requirements :

1 : Generation of random game sets or events:
* Used while importing a random_movie and its hints from the external file through fstream.
* Generated random number using rand()
* Used For loop to loop through movie name file and stop at random number.

2 : Data structures for storing game status:
* Used Array Data structures to store game status (movie_display) 

3 : Dynamic memory management
* Created a dynamic array 
* Array length is based on the length of the randomly generated movie

4 : File input/output (e.g., for loading/saving game status
* Used Fstream to input movie name and it's hints.

5 : Followed 
* Proper indentation and naming styles
* In-code documentation provided

*/


#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdlib>


using namespace std;


//  This function Prints the movie to display
//  All characters are printed in capital
//  Unknown characters are printed as "_"

void print_movie(int n ,char * movie_display){
    for ( int i = 0 ; i < n ; i ++ ){
      	char x = toupper(movie_display[i]);
    	cout << x << " " ;
    }
    cout << endl;
}



//  This function takes user input for a guess character
//  user input is case insensitive . 
//  means a guess "a" is same as "A"
//  done so that player need not enter in capital

char get_guess(){
    char g ;
    cin >> g ;
    return g;
}


//  This function checks if the user input is a correct guess 
//  of the movie name 
//  returns true for a correct guess
//  returns false for a incorrect guess

bool is_guess( char g , int n , char * movie, char * & movie_display){
    for (int i = 0 ; i < n ; i ++){
        if ((toupper(g) == movie[i] || tolower(g) == movie[i])
        && movie_display[i] == '_' ){
            return true;
        }
    }
    return false;
}



//  This function updates the movie_display array to include the correct guess
//  includes the correct guess
//  stores the game status and player inputs

void update_with_guess(char g, int n , char * movie , char * & movie_display,
   int & unguessed){
    for ( int i = 0 ; i < n ; i ++){
        if (( toupper(g) == movie[i] || tolower(g) == movie[i])
        && movie_display[i] == '_'){
            unguessed -=1 ;
            movie_display[i] = movie[i];
        }
    }

}


//  This function checks if the given character is a vowel.
//  returns true if the vowel is a vowel

bool isvowel(char x){
    if ( x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
  x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    else
        return false;
}



//  This function checks if the guess was made previously 
//  by the user
//  prevents repeated guesses.
//  returns true if user input is previously guessed by a player.

bool previous_guess(int n ,char g , char * movie_display){
	for (int i = 0 ; i < n ; i ++){

		if ( g == movie_display[i] || toupper(g) == movie_display[i]){
			return true;
		}
	}

	return false;
}



//  The MAIN function of the game
//  Contains the Output formatting and Input Requirents
//  Contains the User Interface for 
//  S = Single Player and 
//  M = Multiplayer

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

    string random_movie;
    ifstream fin ;
    fin.open("movie_name.txt");

    // 1 : GENERATING RANDOM GAME SET
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
        if(random_movie[i] != ' '){
            n += 1 ;

        }
        else {
            num_of_words += 1 ;
        }
    }

    int length = random_movie.length() ;

    // 3 : Making Dynamic Array :

    char * movie = new char[n];
    char * movie_display = new char[n];

    int unguessed = 0;
    int t = 0 ;

    for ( int i = 0 ; i < length ; i ++ ) {
        movie[i] = random_movie[i] ;

    }


    //removing the consonants from the letter to hide from players
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
    int remaining_guess = 5 ; //the number of max incorrect guesses set to be 5.

    //Game Starts:
    cout << endl;
    cout << "GUESS THE MOVIE ALPHABETS UNTIL YOU COMPLETE THE MOVIE NAME " << endl;

    //SINGLEPLAYER Mode
    if (input_mode == 'S'){
        //Taking user input
        string player_name;
        cout << "Enter Player Name: " ;
        cin >> player_name;
        cout << "\nTHIS MOVIE IS " << n << " LETTER LONG ! and has "<< num_of_words
        << " WORD(s)! Good Luck!!\n";

        cout << "You have 5 guesses remaining \n";
		cout << endl;

        //enter Single Player Mode
        while (unguessed != 0 && remaining_guess > 0 ){
            print_movie(length , movie_display);
            

            cout << "Enter Guess: " ;
            char g = get_guess();
			
			cout << endl;

			//checking for a Legit Guess
			if ( isvowel(g)){
				cout << "~ Don't Guess Vowels as they are already visible! Try Again !\n" << endl;
				continue;
			}

			if ( previous_guess(length, g , movie_display)){
				cout << "~ This Guess has already been made !! Try Again !\n" <<endl ;
				continue;
			}
			

            if (is_guess(g, length, movie , movie_display) == false) {//wrong guess
				cout << "INCORRECT! \n" << endl;
                remaining_guess -= 1; //deduct available guess by 1
                cout << "You now have "<< remaining_guess
                <<" guess(es) remaining\n";

                if ( remaining_guess == 3 ) { //first hint at 3 remaining guesses
                cout << "HERE IS YOUR 1st HINT \n"
                << "~~THIS MOVIE WAS RELEASED IN "<< hint_1 << "~~" << endl ;
				cout << endl;
				}

                else if ( remaining_guess == 1 ){ //second guess at 
                  cout << "HERE IS YOUR 2nd HINT: \n"
				  <<"~~THIS MOVIE WAS DIRECTED BY " << hint_2 << "~~"<<endl ;
                }


            }

			else{ //case for correct output
				cout << "CORRECT !!! Keep Going \n" << endl;
			}
			
            update_with_guess(g, length , movie , movie_display, unguessed);

        }

        if (unguessed == 0 ){ //Movie is fully guessed
			print_movie(length , movie_display);
			cout << "Yes, the movie is ~~  ";
            cout << random_movie << endl ; // if player wins the completed movie
            //should be shown.

            cout << "**** Congratulations !! **** " << player_name << ", You Win !!" << endl;
			cout << "Play Again Soon !\n" << endl ;
        }

        if (remaining_guess == 0 ) {

          cout << "Uh Oh, "<< player_name
          <<", You are out of guesses, The movie was: "<< random_movie << endl ;

		  cout << endl;
        }

    }

	//-----------------------

    //MULTIPLAYER MODE

    else if ( input_mode == 'M'){
        //enter Multiplayer Mode

        //Taking Input/Output
		string player1, player2;
		cout << "ENTER NAME OF PLAYER 1: " ;
		cin >> player1 ;

		cout << "ENTER NAME OF PLAYER 2: " ;
		cin >> player2 ;
		cout << endl;

		cout << "The Player to Complete the Movie Wins !! , ALL THE BEST \n" << endl ;

		cout << "GUESS THIS MOVIE: "  << endl;
		cout << "\nTHIS MOVIE IS " << n << " LETTER LONG ! and has "<< num_of_words
        << " WORD(s)! Good Luck!!\n";

		int pp = 0 ; //for printing hint only once


        //  Using a nested while loop to continue until the complete movie is guessed.
        //  Interior while loops are for player streaks.
        //  The player can continue to guess until he guesses incorrectly
        //  The last player to guess the complete movie wins!

		while ( unguessed != 0 ){ //movie contains unguessed letters

			int chance1 = 1 ; //	chance1 is 0 if player 1 guesses incorrectly.
			int chance2 = 1 ; //	chance2 is 0 if player 2 guesses incorrectly.


			//player1's turn:
			while ( chance1 == 1 && unguessed != 0){
				
				print_movie(length , movie_display);

				if ( pp == 0 ){ // pp = 0 means that hints havn't been printed before
					cout << "Hint 1 ~~ Released in " << hint_1 << endl;
					cout << "Hint 2 ~~ Directed By " << hint_2 << endl;
					cout << endl;

					pp = 1 ;
				}

				cout << "Enter your Guess PLAYER 1 ( " << player1 << " ) : " ;
				char g = get_guess();



				//checking for a Legit Guess
				if ( isvowel(g)){//if it is a vowel
					cout << "~ Don't Guess Vowels as they are already visible! Try Again !\n" << endl;
					continue;

				}

				if ( previous_guess(length, g , movie_display)){ //if same letter guessed before
					cout << "~ This Guess has already been made !! Try Again !\n" <<endl ;
					continue;

				}

                //Now checking the game conditions

                //case of incorrect guess

				if (is_guess(g, length, movie , movie_display ) == false){
					chance1 = 0;
					cout << "Incorrect Guess ! \n" << endl;

				}
                

				else{
					update_with_guess(g, length , movie , movie_display, unguessed);
					cout << "Correct Guess  ... ! \n" << endl;
				}

				if (unguessed == 0 ){
					cout << "**** Congratulations !! **** \n" << player1 << " Wins \n" << endl;
				}

			}

			//player2's turn 

			while ( chance2 == 1 && unguessed != 0){
				
				print_movie(length , movie_display);

				cout << "Enter your Guess PLAYER 2 ( " << player2 << " ) : " ;
                
				char g = get_guess();

				//checking for a Legit Guess
				if ( isvowel(g)){
					cout << "~Don't Guess Vowels as they are already visible! Try Again !\n" << endl ;
					continue;

				}

				if ( previous_guess(length, g , movie_display)){
					cout << "~ This Guess has already been made !! Try Again !\n" << endl ;
					continue;

				}
				

				if (is_guess(g, length, movie , movie_display ) == false){
					cout << "Incorrect Guess ! \n" << endl;
					chance2 = 0;

				}

				else{
					cout << "Correct Guess ... ! \n" << endl;
					update_with_guess(g, length , movie , movie_display, unguessed);
				}

				if (unguessed == 0 ){
					cout << "**** Congratulations !! **** \n" << player2 << "Wins " << endl;
				}

			}

		}

		//Printing the movie name 
		cout << "The movie was ~~  ";
        cout << random_movie << endl ;

    }

    // if "S" or "M" is not entered as a game mode choice input
    else{ 
        cout << "INVALID CHOICE, Try Again Later" << endl;
    }

	cout << "THANKS FOR PLAYING !\n" << endl ; 

    //Deleting the dynamic memory allocated.

    delete [] movie;
    delete [] movie_display;
    return 0;
    //Program ENDS

}

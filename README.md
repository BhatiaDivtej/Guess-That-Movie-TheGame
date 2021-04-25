# Group14_ENGG1340
<h1> Guess that Movie!</h1>
<br>Group Project of Group 14 for ENGG1340 by Divtej Singh Bhatia and Aryan Agrawal<br>
Aryan Agrawal - 3035812373<br>
Divtej Singh Bhatia - 3035832438<br>
<br> 
<h2> Introduction </h2> 
<br> Do you like chilling and watching movies on the weekend ?? If Yes, then this game is made for you . This game will test your trivia in the World Of Movies. <br>
<br> We plan to develop a <b>Movie Guessing Game</b> where you would have to guess the name of the movie. The game could be played as a single player or two players could go head to head. Don't Worry, To make the game more interesting ,  we would also give hints for the movie . <br>
A random movie will be generated from our list of 100 movies. Only the vowels in the name of the movie will be generated ; <br> for example : _ I _ A _ _ _ <br> The player can make use of the hints to guess the remaining consonants of the name . <br> <br>
Example :  <br>
  <ul> Guess the Name of the Movie : <br>
  _ I _ A _ _ _ <br>
  <ul> Hint : The Movie is based on a sea disaster , released in 1997 and casted by Leonardo DiCaprio <br> <br>
  </ul>
The player can guess the remaining consonants . If the guess is correct, the consonant will be filled in the space
   <ul> Guess : T <br>
   Guess the remaining letters  T I T A _ _ _ . <br>
   and so on..... <br>
  </ul>
 Answer : TITANIC <br> <br>
  </ul>
     
<h2>Game Rules</h2> 
<br> Single Player rules
  <ul> 
      <li> Player has to guess the name of the movie given some LIMITED number of guesses (larger movie names have more guesses ) </li>
      <li> You can also opt to take a hint but that would result in reduction of points </li> 
      <li> Try and beat your high score  ! </li> 
  </ul>
<br> Two Player rules 
  <ul>
      <li> Two players go head to head </li> 
      <li> Since you are going head to head no hints will be provided </li> 
      <li> The player will both be guessing the same movie turn by turn </li> 
      <li> Turns will be passed if a wrong guess is made . </li>
      <li> If Player 1 guesses a correct letter, player 1 can continue to guess the next letter. player 2 's turn will come when player 1 guesses incorrectely </li>
      <li> The player to guess the last remaining letter of the movie wins ( so be sure to think about your guess strategically ! ) </li>
  </ul>      
<h2> Functions to implement </h2> 
<br> A brief overview of most of the functions we are going to be implementing ( there may be changes in the given list, during the implementation stage.) 
  <ul> 
    <li> Taking Name of player(s) and choosing the Mode of gameplay ( Single Player or Multiplayer )  </li> 
    <li> Generating a random movie from our movie list ( Also making sure that same movies are not generated in one game ) </li> 
    <li> Take input letter from player </li> 
    <li> Checking if the guess made by user is a correct letter </li> 
    <li> Storing the points scored in successive rounds </li> 
    <li> Displaying the Winner Name and Total points </li>
  
    
 IMPLEMANTATION of Code Requirements :

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


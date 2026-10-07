#include <iostream>
#include <vector>
#include <cstdlib> //srand, rand
#include <ctime> //time(0)
#include <string>
#include <cctype>

using namespace std;

int main(){

    vector<string> lists = {"APPLE", "STRAWBERRY", "COCONUT", "DURIAN", "AVOCADO"};
    int lives = 6;

    srand(time(0)); //choose a number based on total of seconds from 1 jan 1970 --> starter number

    int pos = rand() % lists.size(); //rand generate random number based on starter number, 
                                //modulo restrict the number (mod 5 = 0,1,2,3,4)
    
    //answer
    string word = lists.at(pos);

    //hidden for display to players
    string hidden = "";
    for (int i = 0; i < word.length(); i++){
        hidden += "_"; //concatinate
    }
    
    //print hidden
    for (int i = 0; i < word.length(); i++){
        
        if (i == word.length() - 1){
            cout << hidden.at(i) << endl;
        } else {
            cout << hidden.at(i) << " ";
        }
    }

    //guessing game
    bool found = false; 
    vector <bool> check_letter(26, false); //isi vektor angka 0 sejumlah 26x
    while (found == false && lives > 0){

        bool answer = false;
 
        cout << "Choose a letter: "; 
        char guess;
        cin >> guess; 
        guess = toupper(guess); //make letter capital

        //check if guess is a letter or not
        if (isalpha(guess) == 0){
            cout << guess << " is not a letter." << endl;
            continue;
        }
        
        int repeat = guess - 'A';
        if (check_letter.at(repeat) == true){
            cout << "You have guessed this letter before. Try another." << endl;
            continue;
        }

        for (int i = 0; i < word.length(); i++){
            if (guess == word.at(i)){
                hidden.at(i) = guess; 
                answer = true; 
            }
        }

        if (answer == true) {
            cout << "\nThere is the letter " << guess << " in the word" << endl;
            check_letter.at(repeat) = true;
        }
        else{
            cout << "\nThere is no letter " << guess << " in the word" << endl;
            lives -= 1; 
            check_letter.at(repeat) = true;
            cout << "You have " << lives << " lives remaining" << endl;
        }
        
        //reprint the hidden word with guessed letter
        for (int i = 0; i < word.length(); i++){
        
            if (i == word.length() - 1){
                cout << hidden.at(i) << endl;
            } else {
                cout << hidden.at(i) << " ";
            }
        }

        //validation if player has successfully guessed the word
        if (word == hidden){
            found = true;
            cout << "You guessed the word " << word << " correctly! Congrats!" << endl;
            
        }

        //validation if player failed to guess the word
    }

    if (lives == 0) {
            cout << "You failed to guess the word. The word is " << word << endl;
        }
    

    return 0;
    
}
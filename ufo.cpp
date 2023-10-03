#include <iostream>
#include <vector>
#include <string>


#include "ufo_functions.hpp"
#include "question.hpp"


int main() {


    std::string codeword = "codecademy";
    
    std::string answer = BuildBlankAnswer(codeword); // generates a string of underscores with a length equal to the number of letters in codeword.
    std::string guess = ""; // user's guess 

    bool skip_displays = false; // if the user enters invalid guess, we use this flag to skip displaying the status 

    int misses = 0; // to track the number of wrong guesses

    std::vector<int> wrong_letter_pos; // contains the position of the wrongly guessed letters.
    std::vector<int> wrong_letter_red_pos; // the position of a wrongly guessed letter that exists in the codename but at another location. 
    std::string codeword_substring; // a subtring of codeword at wrong_letter_pos
    
    Greet(); 

    while (misses < 7 && answer !=  codeword) {

        if (!skip_displays) { // this flag is set to true if the user enters a string with invalid length 
            display_misses(misses);
            if (misses > 0) { // do not show the status if it's the first iteration
                display_status(answer, guess, wrong_letter_red_pos); 
            }
        } else {
            skip_displays = false;
        }

        wrong_letter_pos = {};
        wrong_letter_red_pos = {};

        std::cout << "Enter your guess for codename (" << codeword.size() << " letters): ";
        std::cin >> guess;

        if (codeword.size() == guess.size()) { // checks the length of the guessed string. If not valid, sets the skip_displays to true for the next iteration.
        
            for (int i = 0; i < guess.size(); i++) { // replace the underscores in answer with the correctly guessed letters. Also, keep record of the position of wrong ones.
                if (guess[i] == codeword[i]) {
                    answer[i] = guess[i];
                } else {
                    wrong_letter_pos.push_back(i);
                }
            }

            codeword_substring = get_substring(codeword, wrong_letter_pos);
            
            for (int i : wrong_letter_pos) { // find the letters that are guessed wrong but still exist in the answer at a different location. 
                int search_pos = codeword_substring.find(guess[i]);
                if  (search_pos != std::string::npos) {
                    wrong_letter_red_pos.push_back(i);
                    codeword_substring.erase(search_pos);
                }
            }
            misses++;

        } else {
            std::cout << "Your guess should have the same number of letters as the codename.\n";
            skip_displays = true;
        }
    }

    EndGame(codeword, answer);
    

}

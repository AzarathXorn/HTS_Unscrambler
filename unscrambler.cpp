/*
William Schultz
word unscrambler programming mission from hackthissite.org
Written in C++ to practice object oriented programming

Takes in a wordlist text file and a scrambled wordlist text file (placed within the executable directory),
and unscrambles the scrambled list using the unscrambled list.

Program must complete in ~25 seconds (30 second total time limit on HTS)

- List of scrambled words is to be entered in the following format:
s_word1
s_word2
.
.
s_word10

This way the user can copy the scrambled list from HTS into the input file.

- Output will be generated in the following format:
word1,word2,word3, ... word9,word10

Again, to facilitate easy copy/paste into HTS submission field.

*/

// Unscrambler class member function definitions
// class defined in unscrambler.h

#include <string>
#include <iostream>
#include <fstream>
#include "unscrambler.h"

// function to do the unscrambling work
void unscrambler::unscramble()
{
	std::string currWord;	// stores the current scrambled word
	std::string compWord;	// stores the next word to be compared
	std::string checkOff;	// holds a copy of the scrambled word to "check off"
							// characters as we find them by removing from the string

	std::ifstream scrambList("scramblist.txt");	// input stream object for the scrambled list

	for (int i = 0; i < 10; i++){

		std::ifstream wordList("wordlist.txt");		// input stream object for the word list

		// for the 10 scrambled words on the list
		scrambList >> currWord;
		// read a scrambled word in
		while (wordList >> compWord){
			// while there are still words to read from list, read one
			int len = compWord.length();
			if (currWord.length() == len){
				// if the lengths are the same, then continue comparing
				checkOff = currWord;
				// insert word into checkOff
				for (int j = 0; j < len; j++){
					// for the length of the word
					if (checkOff.find(compWord[j]) != std::string::npos){
						// check if the letter exists in the scrambled word
						checkOff.erase(checkOff.find(compWord[j]),1);
						// if it does, erase it from the checkOff
						if (checkOff.empty()){
							// if all the letters matched, 
							soln += compWord;
							// append the word to the solution string
							soln += ",";
							// with a comma
							wordList.close();
							// close the wordList
						}
					}
					else{
						// if a letter does not match, move on to the next word
						break;
					}
				}
			}
		}
	}
	scrambList.close();
}// end unscramble()

// function to output the solution string
void unscrambler::getSoln()
{
	std::cout << soln << std::endl;
}// end getSoln();

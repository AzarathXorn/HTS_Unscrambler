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

// Driver file for the unscrambler class to run

#include "unscrambler.h"
#include <iostream>

int main(){
	unscrambler uScramb;
	uScramb.unscramble();
	uScramb.getSoln();
	return 0;
}
#include <iostream>
#include "GenStack.h"
using namespace std;

class Checker{
public:
Checker();
~Checker();

void adjustSize();
//if the stack is full it adjust the size of the stack

bool isOpener(char c);
//returns if a character is an opening character

bool isCloser(char c);
//returns if character is a closing character

bool isMatch(char c);
//returns to see if closing character matches the top character

char findMatch();
//finds the match appropriate for the top of the stack

void fileCheck(const char* str);
//goes line by line through a file and checks to see if it is properly formatted

private:
GenStack <char> * G;
};

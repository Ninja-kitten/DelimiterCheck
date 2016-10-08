#include "Checker.h"
#include <iostream>
#include <fstream>
using namespace std;
Checker::Checker(){
	GenStack <char>* stck= new GenStack<char>(10);
	G=stck;
}
Checker::~Checker(){
	delete G;
}

void Checker::adjustSize(){
	GenStack<char>* oldStack = G;
	unsigned int oldSize = G->getSize();
	unsigned int newSize = 2*oldSize;
	GenStack<char> temp(oldSize);
	while(!G->isEmpty()){
		temp.push(oldStack->pop());
	}
	GenStack<char>* newStack= new GenStack<char>(newSize);
	G = newStack;
	while(!temp.isEmpty()){
		G->push(temp.pop());
	}
	delete oldStack;
}

bool Checker::isOpener(char c){
	return c=='(' || c=='[' || c == '{';
}

bool Checker::isCloser(char c){
	return c==')' || c==']' || c == '}';
}

bool Checker::isMatch(char c){

	if (G->peek() == '('){
		return c == ')';
	}
	else if (G->peek() == '['){
		return c == ']';
	}
	else if (G->peek() == '{'){
		return c == '}';
	}
}

char Checker::findMatch(){
	if (G->peek() == '('){
		return ')';
	}
	else if (G->peek() == '['){
		return ']';
	}
	else if (G->peek() == '{'){
		return '}';
	}
}
void Checker::fileCheck(const char* str){
	ifstream ifs(str);
	char c;
	ifs.get(c);
	int line = 1;
	while (c != '#')
	//while it's not the end of a file
	{
		if(isOpener(c)){
		//place c on top of the stack if its an opening delimiter
			G->push(c);
			if(G->isFull()){
				adjustSize();
			}
		}
		else if(isCloser(c)){
		//if its a closing delimiter
			if(G->isEmpty()){
			//if the stack is empty report unmatched delimiter in line
				cout<<"Error found in Line : "<<line<<" found unmatched "<<c<<" with no opening delimiter"<<endl;
				throw;
			}
			else if(isMatch(G->peek())){
			//if the delimiter matches the top pop it off
				G->pop();
			}
			else{
			//if they aren't a match report an error
				char d = findMatch();
				cout<<"Error found in Line : "<<line<<" expected "<<d<<" found "<<c<<endl;
				throw;
			}
		}
		else if(c == '\n')
		//if c is a new line character increment line count
		{
			line++;
		}
	}
	if(G->isEmpty()){
	//at the end of the file if the stack is empty, everything is fine
		cout<<"Delimiter syntax is A-O.K."<<endl;
	}
	else{
	//if thes tack is not empty, return an error
		cout<<"File has reached end missing ";
		while(!G->isEmpty()){
			cout<<findMatch()<<" ";
			G->pop();
		}	
		cout<<endl;
		throw;
	}
	
}

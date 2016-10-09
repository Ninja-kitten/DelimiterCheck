#ifndef _GEN_STACK
#define _GEN_STACK
#include <iostream>
#include <exception>
#include "RuntimeException.h"
using namespace std;

template <typename E>
class GenStack{

private:
unsigned int size;
unsigned int max;
int top;
E* S;

public:
GenStack();
GenStack(int s);
~GenStack();
int getSize(); //returns size of array
int getMax();
E pop() throw (StackEmpty); //takes off the top
E peek() throw (StackEmpty);
void push(E data) throw(StackFull);
bool isEmpty();
bool isFull();
};
template <typename E>
GenStack<E>::GenStack(){
size = 0;
top = -1;
}

template <typename E>
GenStack<E>::~GenStack(){}


template <typename E>
GenStack<E>::GenStack(int s){
	max = s;
	S = new E[max];
	size = 0;
	top = -1;
}

template <typename E>
int GenStack<E>::getSize(){
return size;
}

template <typename E>
int GenStack<E>::getMax(){
return max;
}
template <typename E>
E GenStack<E>::pop() throw(StackEmpty){

	if(!isEmpty()){
		size--;
		return S[top--];
	}
	else{
		throw StackEmpty("Stack is Empty");
	}
}

template <typename E>
E GenStack<E>::peek() throw(StackEmpty){
	if(!isEmpty()){
	return S[top];
	}
	else{
		throw StackEmpty("Stack is Empty");
	}
}
template <typename E>
void GenStack<E>::push(E data) throw(StackFull){
	if (!isFull()){
		S[++top] = data;
		size++;
	}
	else throw StackFull("Stack is Full");
}

template <typename E>
bool GenStack<E>::isEmpty(){
	return size==0;
}

template <typename E>
bool GenStack<E>::isFull(){
	return size == max;
}

#endif

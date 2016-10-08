#include <iostream>
#include <exception>
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
E pop(); //takes off the top
E peek();
void push(E data);
bool isEmpty();
bool isFull();
};
template <typename E>
GenStack<E>::GenStack(){}

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
E GenStack<E>::pop(){

	if(!isEmpty()){
		size--;
		return S[top--];
	}
	else{
		throw "Stack is Empty";
	}
}

template <typename E>
E GenStack<E>::peek(){
	if(!isEmpty()){
	return S[top];
	}
	else{
		throw "Stack is Empty";
	}
}
template <typename E>
void GenStack<E>::push(E data){
	if (!isFull()){
		S[++top] = data;
		size++;
	}
	else throw "Stack is Full";
}

template <typename E>
bool GenStack<E>::isEmpty(){
	return size==0;
}

template <typename E>
bool GenStack<E>::isFull(){
	return size == max;
}

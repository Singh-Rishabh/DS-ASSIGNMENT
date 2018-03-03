#ifndef CSTACK_HPP
#define CSTACK_HPP

#include <iostream>
#include <limits.h>
#include <cstdlib>
using namespace std;

template <typename T>
class cStack{
	private :
		int sizeR;
		int sizeB;
		int topR;
		int topB;
		int cap;
		T* arr;
	public:
		cStack(int cap = 100);		// constructor from capacity
		int redsize() const;		// number of items in stack
		bool redempty() const;		// is the stack empty?
		const T& redtop() const;	      		// the top element
		void redpush(const T& e); 		// push x onto the stack
		void redpop();	     	// remove the top element
		int bluesize() const;               // number of items in stack
		bool blueempty() const;             // is the stack empty?
		const T& bluetop() const;           // the top element
		void bluepush(const T& e);          // push x onto the stack
		void bluepop(); 
};

template <typename T>
cStack<T>::cStack(int cap){
	this->cap = cap;
	arr = new T[cap];
	topR = -1;
	topB = cap;
	sizeR = 0;
	sizeB = 0;
}

template <typename T>
int cStack<T>:: redsize() const{
	return sizeR;
}
template <typename T>
bool cStack<T>:: redempty() const {
	return (topR==-1);
}

template <typename T>
const T& cStack<T>:: redtop() const {
	if (this->redempty()){
		cout << "Red Stack is empty cannot return Top"<<endl;
	}
	else return arr[topR];
}

template <typename T>
void cStack<T> :: redpush(const T& e){
	if ((topB - topR )== 1){
		cout << "Red Stack Overflow Cannot push element"<< endl;
		return;
	}arr[++topR] = e;
	sizeR++;
}

template <typename T>
void cStack<T>::redpop(){
	if (sizeR == 0 ){
		cout << "Red Stack Underflow Cannot Pop an element"<< endl;	
		return;
	}
	topR = topR - 1;
	sizeR--;
}

template <typename T>
int cStack<T> :: bluesize() const{
	return sizeB;
}
template <typename T>
bool cStack<T>:: blueempty() const {
	return (topB==cap);
}

template <typename T>
const T& cStack<T> :: bluetop()const{
	if (this->blueempty()){
		cout << "Blue Stack is empty cannot return Top"<<endl;
	}
	else return arr[topB];
}

template <typename T>
void cStack<T> :: bluepush(const T& e){
	if (topB - topR == 1){
		cout << "Blue Stack Overflow Cannot push element"<< endl;
		return;
	}arr[--topB] = e;
	sizeB++;
}

template <typename T>
void cStack<T>::bluepop(){
	if (sizeB == 0 ){
		cout << "Blue Stack Underflow Cannot Pop an element"<< endl;	
		return;
	}
	topB = topB + 1;
	sizeB =sizeB - 1;
}

#endif

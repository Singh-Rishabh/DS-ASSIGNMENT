#ifndef DEQUE_H
#define DEQUE_H

#include<iostream>	
#include "cStack.hpp"
using namespace std;

template <typename T>
class Deque {
	private :
		int sizeD;
		cStack<T> s;		// deque as doubly linked list
	public:
		Deque();				// constructor
		int size() const;				// number of items in the deque
		bool empty() const;				// is the deque empty?
		const T& front() ; // the first element
		const T& back() ;	// the last element
		void insertFront(const T& e);		// insert new first element
		void insertBack(const T& e);		// insert new last element
		void removeFront();	// remove first element
		void removeBack();	// remove last element
};
	
template <typename T>
Deque<T> :: Deque(){
	sizeD = 0;
}
template <typename T>
int Deque<T>::size() const{
	//return (s.redsize() + s.bluesize());
	return sizeD;
}
template <typename T>
bool Deque<T> :: empty() const{
	return (this->size()==0);
}

template <typename T>
const T& Deque<T> :: front() {
	if (!s.redempty()) return s.redtop();
	else if (!s.blueempty()){
		while (!s.blueempty()){
			T top = s.bluetop();
			s.bluepop();
			s.redpush(top);
			//cout<<"dcdsvc"<<endl;
		}	
		return s.redtop();
	}else {
		cout << "Empty " << endl;
	}
}
template <typename T>
const T& Deque<T> :: back() {
	if (!s.blueempty()) return s.bluetop();
	else if (!s.redempty()){
		while (!s.redempty()){
			T top = s.redtop();
			s.redpop();
			s.bluepush(top);
			
		}	
		return s.bluetop();
	}else {
		cout << "Empty " << endl;
	}
}

template <typename T>
void Deque<T> :: insertFront(const T& e){
	s.redpush(e);
	sizeD++ ;
}

template <typename T>
void Deque<T>:: insertBack(const T& e){
	s.bluepush(e);
	sizeD++ ;
}

template <typename T>
void Deque<T> :: removeFront(){
	if (!s.redempty()) {
		s.redpop();
		sizeD--;
	}
	else if (!s.blueempty()){
		while (!s.blueempty()){
			T top = s.bluetop();
			s.bluepop();
			s.redpush(top);
		}s.redpop();
		sizeD--;
	}else {
		cout << "Deque is Empty cannot pop any element" << endl;
	}
}

template <typename T>
void Deque<T> :: removeBack(){
	if (!s.blueempty()) {
		s.bluepop();
		sizeD--;	
	}
	else if (!s.redempty()){
		while (!s.redempty()){
			T top = s.redtop();
			s.redpop();
			s.bluepush(top);
		}s.bluepop();
		sizeD--;
	}else {
		cout << "Deque is Empty cannot pop any element" << endl;
	}
}








#endif

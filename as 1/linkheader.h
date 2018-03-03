#ifndef LINKHEADER_H 
#define LINKHEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;
template <class T>
class linkList ;

// CLASS NODE

template <class T>
class Node{
private:
	T data;
    Node<T>* next;
public:
    Node(T data) : data(data), next(NULL) {}           // CONSTRUCTOR
    friend class linkList<T>;                          // FRIEND CLASS TO USE ITS PRIVATE VARIABLES
    friend class function;                             // FRIEND CLASS TO USE ITS PRIVATE VARIABLES
};


// CLASS LINK LIST

template <class T>
class linkList {
    private :
        Node<T>* head;
        int size;
    public :
        linkList();                                  // CONSTRUCTOR
        ~linkList();                                 // DESTRUCTOR 
        int getSize()const ;                         // GET SIZE OF LINK LIST
        void addNode(T data);                        // ADDITION OF NODE TO LINK LIST 
        Node<T>* getHead();                          // RETURNS HEAD OF LINKLIST
        void delNode(std::string s);                 // DELETE A NODE 
        void printC();                               // PRINT THE LINK LIST
        void printBookedVechile();                   //// PRINT BOOKED VECHILE OF LIST
        void bookVechile(std::string s);             // BOOK VECHILE
        void unBookVechile(std::string s);           // UNBOOK VECHILE
        void getDetails(std::string s);              // PRINTS DETAILS 
};

class function {
	private : 
		linkList<Bus> busList;
		linkList<Car> carList;
		linkList<Truck> tList;
	public : 
		void listCar();  
	    void listBus();
		void listTruck();
		void addcar();
		void addbus();
		void addtruck();
		void delbus();
		void delcar();
		void deltruck();
		void chooseOP();
		linkList<Bus>* getBusList();
		linkList<Car>* getCarList();
		linkList<Truck>* getTList();
		void getNumBuses();
		void getNumTrucks();
};


// FUNCTION DEFENETION OF LINLLIST CLASS

template <class T>
linkList <T>::linkList(){
    head = NULL;
    size = 0;
}
template <class T>
linkList<T>::~linkList(){
	Node<T>* current = head;
	while( current != NULL ) {
    	Node<T>* n = current->next;
    	delete current;
    	current = n;
	}
	head = NULL;
}

template <class T>
int linkList<T> :: getSize()const{
	return size;
}

template <class T>
void linkList <T>::printC(){
	Node<T>* temp = head;
	if (temp == NULL){
		cout << "EMPTY LIST !!" <<endl ;
		return;
	}
	while(temp != NULL ){
		temp->data.printc();
		temp = temp->next ;
	}
}

template <class T>
void linkList <T> :: addNode(T data){
	Node<T>* temp = new Node<T>(data);
	Node<T>* temp1 = head; 
	if (head == NULL){
		head = temp;
		return ;
	}while (temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;
	size = size + 1;
}

template <class T>
Node<T>* linkList<T> :: getHead(){
	return head;
}


template <class T>
void linkList<T> :: printBookedVechile(){
	Node<T>* temp = head;
	cout << "The List of the booked Vechile are" <<endl;
	int i = 0;
	while(temp != NULL ){
		if (temp->data.getBookStatus()){
			temp->data.printc();
			i++;
		}
		temp = temp->next;
	}if (i==0){
		cout << "NO Vechile booked till Now ||"<<endl;
	}
}

template <class T>
void linkList<T> :: bookVechile(string s){
	Node<T>* temp = head;
	while(temp != NULL ){
		if (temp->data.getname().compare(s) == 0){
			if (temp->data.getBookStatus()){
				cout << "Vechile Already Booked please try again !!"<<endl;			
			}else {
				cout << "Your vechile has been booked"<<endl;
				temp->data.setBookStatus(true);
			}break;
		}temp = temp->next;
	}if (temp == NULL ){
		cout << "NO VECHILE FOUND WITH THIS NAME "<< endl;
	}
}

template <class T>
void linkList<T> :: unBookVechile(string s){
	Node<T>* temp = head;
	while(temp != NULL ){
		if (temp->data.getname().compare(s) == 0){
			if (temp->data.getBookStatus()){
				cout << "Your Booking canceled Thank You for using our services !!"<<endl;
				temp->data.setBookStatus(false);
			}else {
				cout << "No Vechile has been biiked with this name please check your schedule"<<endl;
			}break;
		}temp = temp->next;
	}if (temp == NULL ){
		cout << "NO VECHILE FOUND WITH THIS NAME "<< endl;
	}
}

template <class T>
void linkList<T>:: getDetails(string s){
	Node<T>* temp = head;
	while(temp != NULL ){
		if (temp->data.getname().compare(s) == 0){
			temp->data.printc();
			break;
		}temp = temp->next;
	}
}

template <class T>
void linkList<T>:: delNode(string a){
	Node<T>* h = getHead();
	int i=0;
	if (h->data.getname().compare(a) == 0){                   // IF WE ARE DELETING HEAD NODE 
		head = h->next ;
		i=i+1;
		size -=1;
		cout <<"Vechile Deleted " << endl;
		delete h; 
		return;
	}
	while(h->next != NULL){
		if (h->next->data.getname().compare(a) == 0){
			Node<T>* temp = h;
			if (h->next->next==NULL){                         // IF WE ARE DELETING THE LAST NODE THEN 
				h->next=NULL;
			}else {
				h->next = h->next->next;                     // IF WE ARE DELETING ANY NODE EXCEPT HEAD
			}
			cout <<"Vechile Deleted " << endl;
			i = i + 1;
			size -=1;
			break;
		}if (h->next == NULL ){
			break;
		}else{
			h = h->next;
		}
	}
	if (h->next == NULL && i==0){
		cout << "Cannot delete ..No Object fount with this name "<<endl ;
	}
}

#endif


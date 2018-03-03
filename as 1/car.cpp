#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

// IMPLICT CONSTRUCTOR 
using namespace std;
Car::Car(){
	bookStatus = false;
}

// OVERLODED CONSTRUCTOR 

Car::Car(string cn ,string c, int m , int t , int n){
    color = c;
    name = cn;
    mileage = m ;
    topSpeed = t;
    numGear = n;
    bookStatus = false;
}

// TO GET BOOKING STATUS 

bool& Car :: getBookStatus(){
	return bookStatus;
}

// TO SET BOOKING STATUS 

void Car:: setBookStatus(const bool a){
	bookStatus = a;
}

// SETTING DATA TO CAR OBJECT 

void Car :: setdata(string cn,string c, int m , int t , int n){
	color = c;
	name = cn;
    mileage = m ;
    topSpeed = t;
    numGear = n;
}
void Car :: printc(){
    cout<< "Name : "<< name <<endl << "Color : "<<color << endl<< "Mileage : " << mileage << "   TopSpeed : " << topSpeed << "   No. of gears : " << numGear << "   Booking status : " << bookStatus << "   Booking status : " << bookStatus << endl<< endl;
}

string Car :: getname(){
	return name;
}


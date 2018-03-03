#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

// BUS DECLERATION FILE 

using namespace std;

Bus :: Bus (){

	bookStatus = false;
}

// CONSTRUCTOR 

Bus :: Bus(string cn ,string c, int m , int t , int n, int ns){
    color = c;
    name = cn;
    mileage = m ;
    topSpeed = t;
    numGear = n;
    numSeats = ns;
    bookStatus = false;
}

// SETTING DATA 

void Bus :: setdata(string cn ,string c, int m , int t , int n, int ns){
    color = c;
    name = cn;
    mileage = m ;
    topSpeed = t;
    numGear = n;
    numSeats = ns;
}
int Bus :: getSeat(){
	return numSeats;
}
// PRINTS BUS OBJECT 
void Bus :: printc(){
    cout << "Name : "<< name << endl << "Color : "<< color << endl<< "Mileage : " << mileage << "   Topspeed : " << topSpeed << "   No. of gears : " << numGear<<endl << "No. of seats : " << numSeats << "   Booking status : " << bookStatus << endl <<endl;
}

#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

Truck::Truck(){bookStatus = false;}

Truck::Truck(string cn ,string c, int m , int t , int n, int lcw , int lcv ){
    color = c;
    name = cn;
    mileage = m ;
    topSpeed = t;
    numGear = n;
    lcINw = lcw;
    lcINv = lcv;
    bookStatus = false;
}
void Truck :: setdata(string cn ,string c, int m , int t , int n, int lcw , int lcv ){
	color = c;
    name = cn;
    mileage = m ;
    topSpeed = t;
    numGear = n;
    lcINw = lcw;
    lcINv = lcv;
}

int Truck :: getVolume(){
	return lcINv;
}


void Truck :: printc(){
    cout <<"Name : " <<name << endl << "Color : "  << color <<endl << "Mileage : " << mileage << "   TopSpeed : " << topSpeed << "   No. of gears : " << numGear<<endl << "Loding capacity(Kg) : " << lcINw << "   Loding capacity(l) : " << lcINv << "   Booking status : " << bookStatus << endl << endl;
}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include"linkheader.h"
#include "header.h"
using namespace std;

// MAIN FUNCTION 

int main(){
    function f;
	f.listCar();
   	f.listBus();
	f.listTruck();
	linkList<Bus>* BusList = f.getBusList();
	linkList<Car>* CarList = f.getCarList();
	linkList<Truck>* TList = f.getTList();
	char re;
	do {
		f.chooseOP();
		int ans;
		cin >>ans;
		switch(ans){
			case 1 :
				do{ 
					int a;
					cout << "Enter 1 -- ADD Car  2 -- ADD Bus  3 -- ADD Truck : ";
					cin >> a;
					switch (a){
						case 1 :
							do {
								f.addcar();
								a = -1;
								cout << "Want to enter another car press 1 else press any other integer : ";
								cin >> a;
							}while(a == 1);
							break;
						case 2 : 
							do {
								f.addbus();
								a = -1;
								cout << "Want to enter another bus press 2 else press any other integer : ";
								cin >> a;
							}while(a == 2);
							break;
						case 3 : 
							do {
								f.addtruck();
								a = -1;
								cout << "Want to enter another truck press 3 else press any other integer : ";
								cin >> a;
							}while(a == 3);
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWnat to go to previous menu press 1 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while (ans == 1);
				break;
			case 2 :
				do {
					int a;
					cout << "Enter 1 -- DEL Car  2 -- DEL Bus  3 -- DEL Truck : ";
					cin >> a;
					switch (a){
						case 1 :
							do {
								f.delcar();
								a = -1;
								cout << "Want to delete another car press 1 else press any other integer : ";
								cin >> a;
							}while(a == 1);
							break;
						case 2 : 
							do {
								f.delbus();
								a = -1;
								cout << "Want to delete another bus press 2 else press any other integer : ";
								cin >> a;
							}while(a == 2);
							break;
						case 3 : 
							do {
								f.deltruck();
								a = -1;
								cout << "Want to delete another truck press 3 else press any other integer : ";
								cin >> a;
							}while(a == 3);
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWant to go to previous menu press 2 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while(ans == 2);
				break;
			case 3 : 
				do {
					int a;
					cout << "Enter 1 -- Book Car  2 -- Book Bus  3 -- Book Truck : ";
					cin >> a;
					switch (a){
						case 1 :
							do{
								a= -1;
								cout << "Enter the name of the car you want to book : ";
								string s ;
								cin >> s;
								CarList->bookVechile(s);
								cout << "Want to Book other car press 1 else press any other integer : ";
								cin >> a;
							}while(a == 1);
							break;
						case 2 : 
							do{
								a= -1;
								cout << "Enter the name of the Bus you want to book : ";
								string s ;
								cin >> s;
								BusList->bookVechile(s);
								cout << "Want to Book other Bus press 2 else press any other integer : ";
								cin >> a;
							}while(a == 2);
							break;
						case 3 : 
							do{
								a= -1;
								cout << "Enter the name of the Truck you want to book : ";
								string s ;
								cin >> s;
								TList->bookVechile(s);
								cout << "Want to Book other Truck press 41 else press any other integer : ";
								cin >> a;
							}while(a == 3);
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWant to go to previous menu press 3 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while(ans == 3);
				break;
			case 4 : 
				do {
					int a;
					cout << "Enter 1 -- UnBook Car  2 -- UnBook Bus  3 -- UnBook Truck : ";
					cin >> a;
					switch (a){
						case 1 :
							do{
								a= -1;
								cout << "Enter the name of the car you want to cancel booking : ";
								string s ;
								cin >> s;
								CarList->unBookVechile(s);
								cout << "Want to cancel other car booking press 1 else press any other integer : ";
								cin >> a;
							}while(a == 1);
							break;
						case 2 : 
							do{
								a= -1;
								cout << "Enter the name of the Bus you want to Unbook : ";
								string s ;
								cin >> s;
								BusList->unBookVechile(s);
								cout << "Want to UnBook other Bus press 2 else press any other integer : ";
								cin >> a;
							}while(a == 2);
							break;
						case 3 : 
							do{
								a= -1;
								cout << "Enter the name of the Truck you want to Unbook : ";
								string s ;
								cin >> s;
								TList->unBookVechile(s);
								cout << "Want to UnBook other Truck press 41 else press any other integer : ";
								cin >> a;
							}while(a == 3);
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWant to go to previous menu press 4 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while(ans == 4);
				break;
			case 5 :
				do{ 
					int a;
					cout << "Enter 1 -- Print Car Details  2 -- Print Bus Details  3 -- Print Truck Details : ";
					cin >> a;
					switch (a){
						case 1 :
							do{
								cout << "Enter the name of car you want to know details : ";
								string s;
								cin >> s;
								CarList->getDetails(s);
								a=-1;
								cout << "Want to know other car details press 1 else press any other integer : ";
								cin >> a;
							}while(a == 1);
							break;
						case 2 : 
							do{
								cout << "Enter the name of Bus you want to know details : ";
								string s;
								cin >> s;
								BusList->getDetails(s);
								a=-1;
								cout << "Want to know other Bus details press 2 else press any other integer : ";
								cin >> a;
							}while(a == 2);
							break;
						case 3 : 
							do{
								cout << "Enter the name of Truck you want to know details : ";
								string s;
								cin >> s;
								TList->getDetails(s);
								a=-1;
								cout << "Want to know other Truck details press 3 else press any other integer : ";
								cin >> a;
							}while(a == 3);
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWant to go to previous menu press 5 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while(ans == 5);
				break;
			case 6 :
				do {
					int a;
					cout << "Enter 1 -- Car LIST  2 -- Bus LIST  3 -- Truck LIST : ";
					cin >> a;
					switch (a){
						case 1 :
							CarList->printC();
							break;
						case 2 : 
							BusList->printC();
							break;
						case 3 : 
							TList->printC();
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWant to Print other list press 6 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while(ans == 6);
				break;
			case 7:
				do {
					int a;
					cout << "Enter 1 -- Print Booked Car  2 -- Print Booked Bus  3 -- Print Booked Truck : ";
					cin >> a;
					switch (a){
						case 1 :
							CarList->printBookedVechile();
							break;
						case 2 : 
							BusList->printBookedVechile();
							break;
						case 3 : 
							TList->printBookedVechile();
							break;
						default :
							cout << "Choose Correct options" << endl;
							break;
					}cout << "\nWant to know other Booked vechile press 7 else press any other integer : ";
					ans = -1;
					cin >> ans;
				}while(ans == 7);
				break;
			case 8 :
				do {
					f.getNumTrucks();
					ans = -1;
					cout << "\nPress 8 to enter another number of watermelons else press any other integer : ";
					cin >> ans;
				}while(ans == 8 );
				break;
			case 9:
				do{
					f.getNumBuses();
					ans= -1 ;
					cout << "\nPress 9 to enter the number of peoples else press any other integer : ";
					cin >> ans;
				}while(ans == 9 );
				break;
			case -1 : 
				break;
			default :
				cout << "\nYou have entered the wrong number Please enter the Correct options" << endl;
				break;
			
		}cout << "\nDo you want to continue y/n : ";
		cin >> re;
	}while (re == 'y' || re == 'Y');
	cout << "\n\nThanks For Visiting \n";
}


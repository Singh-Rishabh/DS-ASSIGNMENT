#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "header.h"
#include"linkheader.h"


using namespace std;

// FUNCTION TO INITIALISE CAR LINK LIST 

void function :: listCar(){
	ifstream carFile;
    carFile.open("car.txt");
    string c , c1;
    int m ,t ,n ;
    Car car ; 
    while (carFile>> c >> c1 >> m >> t >> n){
    	car.setdata(c,c1,m,t,n);
    	carList.addNode(car);
    }
    carFile.close();
}

// FUNCTION TO INITIALISE BUS LINK LIST 

void function :: listBus(){
	ifstream BusFile;
    BusFile.open("bus.txt");
    string c , c1;
    int m ,t ,n ,ns ;
    Bus bus ; 
    while (BusFile>> c >> c1 >> m >> t >> n >> ns){
    	bus.setdata(c,c1,m,t,n, ns);
    	busList.addNode(bus);
    }
    BusFile.close();
}

// FUNCTION TO INITIALISE TRUCK LINK LIST 

void function :: listTruck(){
	ifstream file;
    file.open("truck.txt");
    string c , c1;
    int m ,t ,n ,lcw,lcv ;
    Truck truck ; 
    while (file >> c >> c1 >> m >> t >> n >> lcw >>lcv){
    	truck.setdata(c,c1,m,t,n, lcw,lcv);
    	tList.addNode(truck);
    }
    file.close();
}

// FUNCTION TO ADD CAR TO LINKLIST

void function :: addcar(){
	Node<Car>* head = carList.getHead();
	cout << "Enter the details of the car : Name Color mileage Topspeed Number of gear"<< endl;
	string n,c;
	int m,t,na;
	cin >> n >> c >> m >> t >> na;
	Car car(n,c,m,t,na);
	while(head != NULL){
		 if (head->data.getname().compare(n)==0){
		 	cout << "CAR NAME ALREADY EXIST PLEASE ENTER AGAIN"<<endl;
		 	return;
		 }head = head->next;
	}
	cout << "Car added sucessfully " << endl;
	carList.addNode(car);
}

// FUNCTION TO ADD BUS TO LINKLIST

void function :: addbus(){
	Node<Bus>* head = busList.getHead();
	cout << "Enter the details of the Bus : Name Color mileage Topspeed Number of gear Number of seats"<< endl;
	string n,c;
	int m,t,na , ns;
	cin >> n >> c >> m >> t >> na >> ns;
	Bus bus(n,c,m,t,na,ns);
	while(head != NULL){
		 if (head->data.getname().compare(n)==0){
		 	cout << "BUS NAME ALREADY EXIST "<<endl;
		 	return;
		 }head = head->next;
	}
	cout << "Bus added sucessfully " << endl;
	busList.addNode(bus);
}

// FUNCTION TO ADD TRUCK TO LINKLIST

void function :: addtruck(){
	Node<Truck>* head = tList.getHead();
	cout << "Enter the details of the Truck : Name, Color, mileage, Topspeed, Number of gear, loding capacity in kg, loding capacity in liter"<< endl;
	string n,c;
	int m,t,na,lcinw , lcinl;
	cin >> n >> c >> m >> t >> na >> lcinw >> lcinl;
	Truck truck(n,c,m,t,na,lcinw,lcinl);
	while(head != NULL){
		 if (head->data.getname().compare(n)==0){
		 	cout << "TRUCK NAME ALREADY EXIST "<<endl;
		 	return;
		 }head = head->next;
	}
	cout << "Truck added sucessfully " << endl;
	tList.addNode(truck);
}

// FUNCTION TO DELETE CAR FROM LINKLIST

void function :: delcar(){
	cout << "ENter the name of car you want to delete : ";
	string a;
	cin >>a;
	carList.delNode(a);
}

// FUNCTION TO DELETE BUS FROM LINKLIST

void function :: delbus(){
	cout << "ENter the name of bus you want to delete : ";
	string a;
	cin >>a;
	busList.delNode(a);
}

// FUNCTION TO DELETE TRUCK FROM LINKLIST

void function :: deltruck(){
	cout << "ENter the name of Truck you want to delete : ";
	string a;
	cin >>a;
	tList.delNode(a);
}

// FUNCTION TO GET THE LINKED LIST's

linkList<Bus>* function :: getBusList(){
	return &busList;
}

linkList<Car>* function :: getCarList(){
	return &carList;
}

linkList<Truck>* function :: getTList(){
	return &tList;
}

// FUNCTION TO GET NUMBER OF BUSES REQUIRED TO ACCOMODATE THE GIVEN NUMBER OF PEOPLE

void function :: getNumBuses(){
	vector<dataName> x(busList.getSize());
	int i,sum = 0,count = 0,numSeat;
	Node<Bus>* h = busList.getHead();
	for (i=0;i<(busList.getSize()) && h != NULL ;i++){
		dataName y = {h->data.getname(),h->data.getSeat()};
		x[i]=y;
		h=h->next;
	}sort (x.begin() , x.end());
	cout<< "Enter the number of people : ";
	cin >> numSeat;
	i = 0;int j=0;
	cout << "Vechile required are "<<endl;
	while (sum < numSeat && i <busList.getSize() ){
		if ((sum + 5)>=numSeat && sum < numSeat ){
			sum += 5;
			j++;
			cout << "A car"<<endl; 
			break;
		}
		sum=sum+x[i].number;
		cout << x[i].str  << endl;
		
		i++;
	}if (i == busList.getSize()) cout << "Sorry Cannot accomodate this many People!!" << endl;
	else cout << "Total number of Vechile required are "<< i +j<< endl;
}


// FUNCTION TO GET NUMBER OF TRUCKS REQUIRED TO ACCOMODATE THE GIVEN NUMBER OF WATERMELON

void function :: getNumTrucks(){
	vector<dataName> x(tList.getSize());
	int i,sum = 0,count = 0,numWatermelon;
	Node<Truck>* h = tList.getHead();
	for (i=0;i<(tList.getSize()) && h != NULL ;i++){
		dataName y = {h->data.getname(),h->data.getVolume()};
		x[i]=(y);
		h=h->next;
	}sort (x.begin() , x.end());
	i=0;
	cout<< "Enter the number of watermelon : ";
	cin >> numWatermelon;
	cout << "Trucks required are "<<endl;
	numWatermelon = numWatermelon*30;
	while (sum < numWatermelon && i < tList.getSize()){
		sum=sum+x[i].number;
		cout << x[i].str << " " << endl;
		i++;
	}if (i == tList.getSize()) cout << "Sorry Cannot accomodate this many watermelons !!" << endl;
	else cout << "Total number of truck required are "<< i << endl;
}

// FUNCTION TO GIVE OPTIONS TO USER

void function :: chooseOP(){

	cout << "ENTER 1 TO ADD VECHILE"<<endl;
	cout << "ENTER 2 TO DELETE VECHILE "<<endl;
	cout << "ENTER 3 TO BOOK VECHILE"<<endl;
	cout << "ENTER 4 TO UNBOOK VECHILE "<<endl;
	cout << "ENTER 5 TO PRINT DETAILS "<<endl;
	cout << "ENTER 6 TO PRINT LIST "<<endl;
	cout << "ENTER 7 TO PRINT BOOKED VECHILE"<<endl;
	cout << "ENTER 8 TO KNOW NUMBER OF TRUCK REQUIRED TO ACCOMMODATE x NUMBER OF WATERMELONS"<<endl;
	cout << "ENTER 9 TO KNOW NUMBER OF VECHILE REQUIRED TO ACCOMMODATE GIVEN NUMBER OF PEOPLE" <<endl;
	cout << "ENTER -1 to EXIT!!!!!"<<endl;
}


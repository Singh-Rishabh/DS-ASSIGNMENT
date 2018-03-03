#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "nameMap.hpp"
#include "numberMap.hpp"

using namespace std;

int main(){
  ifstream file;
  file.open("names.txt");
  if(!file){
     cout<<"names.txt could not be read."<<endl;
     return 0;
  }
  string line;
   	Name_Map<string,string> map;
  string name,mean;
  while(file>>name){
     
     getline(file,mean);
     map.put(name, mean);
  }
  int k=0;
  	map.collision();
  ofstream ofile;
  ofile.open("2016csb1054_Output.txt");
  ofile<<"Table for Name_Map: "<<endl;
  for(int i=0;i<4;i++){
     if(i==0){
       ofile<<"              "<<"Division "<<"MAD "<<"Multiplication"<<endl<<"Integer cast    ";
     }
     else if(i==1){
       ofile<<"Component sum   ";
     }
     else if(i==2){
       ofile<<"Polynomial sum  ";
     }
     else{
       //cout<<"Cyclic sum      ";
       ofile<<"Cyclic sum      ";
     }
     for(int j=0;j<3;j++){
        //cout<<name_table[i][j]<<"   ";
        ofile<<map.coll[i+j]*100.0/map.size()<<"   ";
     }
     cout<<endl;
     ofile<<endl;
  }

  ifstream ifile;
  ifile.open("numbers.txt");
  if(!ifile){
     cout<<"numbers.txt could not be read."<<endl;
     return 0;
  }
  Number_Map<long long int,int> nummap;
  long long int a ;
  int b;
	while(ifile>>a>>b){
		//cout << a<<" " << b<< endl;
		nummap.put(a,b);
	}
	nummap.collision();
  
  cout<<endl;
  ofile<<endl;
  ofile<<"Table for Number_Map: "<<endl;
  for(int i=0;i<4;i++){
     if(i==0){
       //cout<<"              "<<"Division "<<"MAD "<<"Multiplication"<<endl<<"Integer cast    ";
       ofile<<"              "<<"Division "<<"MAD "<<"Multiplication"<<endl<<"Integer cast    ";
     }
     else if(i==1){
       //cout<<"Component sum   ";
       ofile<<"Component sum   ";
     }
     else if(i==2){
       //cout<<"Polynomial sum  ";
       ofile<<"Polynomial sum  ";
     }
     else{
       //cout<<"Cyclic sum      ";
       ofile<<"Cyclic sum      ";
     }
     for(int j=0;j<3;j++){
        //cout<<num_table[i][j]<<"   ";
        ofile<<nummap.coll[i+j]*100.0/nummap.size()<<"   ";
     }
     //cout<<endl;
     ofile<<endl;
  }

  ofile.close();
  int n;
  while(1){
     cout<<"Please​ enter​ \n1 TO KNOW BALANCE OF A PHONE NUMBER​ \n2 ​TO KNOW MEANING OF NAME \n0 TO EXIT : ";
     cin>>n;
     if(n==1){
        long long int no;
        cout<<"Please enter number: ";
        cin>>no;
        int abc = nummap.find(no);
        if(abc == -1){
           cout<<"This number is not available in the data base."<<endl;
           continue;
        }
        cout<<"Number: "<<no<<", Balance: "<<abc;
     }
     else if(n==2){
        string name;
        cout<<"Please enter Name ";
        cin>>name;
        string xyz = map.find(name);
        if(xyz.compare("NOT FOUND")==0){
           cout<<"This name is not available in the data base."<<endl;
           continue;
        }
        cout<<"Name: "<<name<<", Meaning: "<<xyz;
     }
     else{
        break;
     }
  }
  return 0;  
}

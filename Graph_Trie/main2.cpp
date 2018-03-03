#include<iostream>
#include<fstream>
#include"graph.hpp"

using namespace std;

int main(int argc , char* argv[]){
	if (argc < 2){
		cout << "Wrong input format "<<endl;
		cout << "$./a.out <filename> <filename>"<<endl;
		return 0;
	}
	ifstream file;
	file.open(argv[1]);
	if(file.fail()){
		cout << "Error opening "<< argv[1] << endl ; 
		return 0;
	}
	string course;
	int duration;
	int count=0;
	while( file >> course >> duration ){
		count++;
	}
	int dur[count];
	int h = course[1] - '0';
	Graph G(count,h);
	file.close();
	file.open(argv[1]);
	int xx=0;
	while( file >> course >> duration ){
		dur[xx]=duration;
		xx++;
	}
	file.close();
	ifstream file2;
	file2.open(argv[2]);
	if( file2.fail()){
		cout << "Error opening"<< argv[2] << endl ; 
		return 0;
	}
	string s1,s2;
	xx=0;
	while( file2 >> s1 >> s2){
		G.insertEdge(s1,s2,dur[s1[1]-1]);
	}
	G.callDfs();
	G.longestPath();
}


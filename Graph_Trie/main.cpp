#include<iostream>
#include<fstream>
#include"trie.hpp"

using namespace std;

int main(){
	ifstream file("name_number.txt");
	string s;
	long long v;
	Trie t;
	while(file>>s>>v){
		//cout << s<< " \t " << v << endl;
		t.insert(s,v);
	}
	int a=1;
	while(a){
		cout<<"Please​ ​ enter​ ​ full/partial​ ​ contact​ ​ name : ";
		string s;
		cin>>s;
		t.search(s);
		cout << "Enter 0 to exit : ";
		int x;cin>>x;
		a=x;
	}
}

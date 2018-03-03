#ifndef TRIE_H
#define TRIE_H

#include<iostream>
#include<string>
#include <iomanip>
#include<vector>
using namespace std;

struct data{
	string s;
	long long v;
};

class Trie;
class node{
private:
	node* children[26];
	char key;
	long long value;
	bool isComplete;
	friend class Trie;
public:
	node(){
		key = '1';
		value = -1;
		//children = new node[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}isComplete = false;
	}
	node(char k , long long v){
		key = k;
		value = v;
		//children = new node[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
		isComplete = false;
	}
};

class Trie{
	private:		
		node* root;
		char lower(char);
		int find(node*,string , int*, data*);
	public:
		Trie();
		void insert(string , long long);
		void search(string );
};


Trie :: Trie(){
	root = new node;
}

char Trie :: lower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
}

void Trie :: insert(string k, long long v){
	for(int i=0;i<k.length();i++){
		k[i] = lower(k[i]);
	}
	node* temp = root;
	for(int i=0;i<k.length();i++){
        if (temp->children[k[i]-'a'] == NULL){
            temp->children[k[i] - 'a'] = new node;
        }
 
        temp = temp->children[k[i] - 'a'];
    }
	temp->isComplete = true;
	temp->value = v;
	
}

int Trie :: find(node* t, string k, int * counter, data* arr){
	if (*counter <5 && t->isComplete){
		data d;
		d.s=k;d.v=t->value;
		arr[*counter] = d;
		//cout << "sss "<< k << " val "<< t->value<<endl;
		*counter = *counter + 1;
	}
	else if(t->isComplete) *counter = *counter + 1;;
	for(int i=0;i<26;i++){
		if (t->children[i] != NULL ){
			find(t->children[i],k + (char)('a' + i), counter,arr);
		}
	}return *counter;
}

void Trie :: search(string k){
	node* temp = root;
	string tempStr = k;
	for(int i=0;i<k.length();i++){
		k[i] = lower(k[i]);
	}int c=0;
	for(int i=0;i<k.length() ; i++){
		if (temp->children[k[i] - 'a'] != NULL ){
			c++;
		}
		else break;
		temp = temp->children[k[i] - 'a'];
	}
	if (c != k.length()){
		cout << "NOT FOUND"<<endl;
		return;
	}
	int counter = 0;
	data arr[5];
	for(int i=0;i<5;i++){
		data d = {"",-1};
		arr[i] = d;
	}
	counter = find(temp, k , &counter, arr);
	int size = 0;
	for(int i=0; i<5 && (arr[i].s != "" || arr[i].v != -1) ; i++){
		size++;
	}
	
	cout << "We found "<< counter << " contacts matching with "<< tempStr << " The top " << size << " as follows: "<<endl;
	//cout << arr.size()<<endl;
	for(int i=0;i<5 && (arr[i].s != "" || arr[i].v != -1) ;i++){
		//cout << "hhhh"<<endl;
		cout << arr[i].s << "\t"<<arr[i].v <<endl; 
	}

}

#endif

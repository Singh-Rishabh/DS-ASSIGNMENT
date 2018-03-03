#ifndef Graph_h
#define Graph_h

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include <limits.h>
using namespace std;

class adjList;
class Graph;
class node{
	private:
		string source;
		int duration ;
		int dest;
		node* next;
		friend class adjList;
		friend class Graph;
	public:
		node(){
			this->duration = -1;
			this->dest = -1;
			this->next = NULL;
			this->source = "";
		}
		node(string s , int de,int dur){
			this->source = s;
			this->duration = dur;
			this->dest = de;
			this->next = NULL;
		}
};

 
class adjList{

    node *head;
	friend class Graph;
};

class Graph{
	private :
		int numV;
		adjList *arr;
		bool isDag;
		int graph_s;
		int graph_d;
		bool checkCycle(int v, bool visited[], bool *stack);
		void dfs(int v ,bool visit[],int *,int * , int );
		void topologicalSort(int v, bool visit[] , stack<int> &Stack);
	public:
		Graph();
		Graph(int ,int);
		void insertEdge(string src,string dest, int dur);
		bool isCyclic();
		void printGraph();
		void callDfs();
		void longestPath();
};

Graph :: Graph(){
	
}

Graph :: Graph(int v,int d){
	this->numV = v;
	isDag = true;
	graph_d = d;
	graph_s = 0;
	arr = new adjList[v];
	for(int i=0;i<v;i++){
		arr[i].head = NULL;
	}
}

void Graph::insertEdge(string src1, string dest1, int dur){
	int src = 0;
	int j=1;
	for (int i=src1.length()-1;i>0; i=i-1){
		src = src + (src1[i] - '0')*j;
		j=j*10;
	}src--;
	static int start = src;
	graph_s = start;
	int dest=0;
	j=1;
	for (int i=dest1.length()-1;i>0; i=i-1){
		dest = dest + (dest1[i] - '0')*j;
		j=j*10;
	}dest--;
	if (src > numV-1 || dest > numV-1){
		return;
	}
	
	node* temp2 = new node(src1,dest,dur);
    temp2->next = arr[src].head;
    arr[src].head = temp2;
}

void Graph :: printGraph(){

    int v;
    for (v = 0; v < numV; ++v){
        node* pCrawl = arr[v].head;

        cout<<"\n Adjacency list of vertex "<<v<<"\n head ";

        while (pCrawl){
            cout<<"-> "<<pCrawl->dest;
            pCrawl = pCrawl->next;
        }
        cout<<endl;
    }

}

void Graph:: callDfs() {
	bool *visited = new bool[numV];
	int arrival[numV];
	for(int i=0;i<numV;i++){
		visited[i] = false;
		arrival[i] = 0;
	}
	int c=0, time = 0;
	bool isDag = true;
	dfs(graph_s,visited,&c,arrival,time);
}

void Graph :: dfs(int v ,bool visit[], int* c, int arri[] ,int time ){
	visit[v] = true;
	arri[v] = time++;
	node* temp = arr[v].head;
	while(temp ){
		if (!visit[temp->dest]){
			dfs(temp->dest,visit,c,arri,time);
			
		}else if (isDag == true && arri[temp->dest] < arri[v] ) {
			*c = *c + 1;
			cout << "NOT A DAG "<<endl;
			isDag = false;
		}
		temp =temp->next;
	}
}
void Graph::topologicalSort(int v, bool visit[] , stack<int> &Stack){
	visit[v] = true;
	node* temp = arr[v].head;
	while(temp ){
		if (!visit[temp->dest]){
			topologicalSort(temp->dest,visit,Stack);	
		}
		temp = temp->next;
	}Stack.push(v);
}

void Graph :: longestPath(){

	this->callDfs();
	if(isDag){
		stack<int> Stack;
		bool *visited = new bool[numV];
		for(int i=1; i<numV ; i++)	visited[i] = false;
		topologicalSort(graph_s,visited,Stack);
		//cout << "hello"<<endl;
		int data[2][numV];
		for(int i=1 ; i<numV ; i++){
			data[0][i] = INT_MIN;
			data[1][i] = 0;
		}
		data[0][graph_s] = 0;
		while( !Stack.empty()){
			int u = Stack.top();
			Stack.pop();
			int i=0;
			if( data[0][u] != INT_MIN ){
				node* temp = arr[u].head;
				while(temp ){
					if( data[0][temp->dest] < data[0][u] + temp->duration ){
						data[0][temp->dest] = data[0][u] + temp->duration;
						data[1][temp->dest] = u;
					}temp = temp->next;
				}
			}
		}
		int temp2 = graph_d;
		stack <int> tempStack;
		while ( temp2!=graph_s ){
			tempStack.push(data[1][temp2]);
			temp2 = data[1][temp2-1];
		}
		cout << "The longest path is " ;
		while( !tempStack.empty() ){
			int h = tempStack.top();
			tempStack.pop();
			cout << "C" << h+1 << " -> " ;
		}
		cout << "C" << graph_d << endl;
		cout << "The longest duration is " ;
		cout << data[0][graph_d] + arr[graph_d].head->duration << " months" << endl;
	}else{
		return;
	}
}











#endif

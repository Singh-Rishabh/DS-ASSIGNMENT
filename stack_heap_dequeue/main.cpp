#include <iostream>
#include "deque.hpp"

using namespace std;

template <typename E>
void print(Deque <E> d)
{	
	int size = d.size();
	cout<<"Front -> ";
	for(int i=0;i<size;i++)
	{
		cout<<d.front()<<" ";
		d.removeFront();
	}
	cout<<"<- Rear"<<endl;
}

int main()
{
	Deque <int> d;
	print(d);
	//cout<<endl;
	//cout<<d.size()<<" "<<d.empty()<<endl;
	d.insertFront(1);
	//print(d);//cout<<d.size()<<" ";
	//cout<<d.front()<<" ";
	//cout<<d.back()<<endl;
	d.insertFront(2);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertFront(3);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertFront(4);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertFront(5);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertBack(6);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertBack(7);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertBack(8);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertBack(9);
	//print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	d.insertBack(10);
	///print(d);//cout<<d.size()<<" "<<d.front()<<" "<<d.back()<<endl;
	print(d);
	d.removeFront();
	//print(d);
	d.removeFront();
	//print(d);
	d.removeFront();
	//print(d);
	d.removeFront();
	//print(d);
	d.removeFront();
	//print(d);
	d.removeBack();
	print(d);
	return 0;
}

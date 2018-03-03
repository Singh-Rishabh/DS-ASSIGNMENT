#include<iostream>
#include<fstream>
#include "fmavl.hpp"
using namespace std;
int main()
{
	MAVLTree t;
	ifstream obj;
	obj.open("entries.txt");
	int key;
	string s;
	while ( obj>>key>>s )
	{
	  t.insert(key,s);
	}cout << "Tree created"<<endl;
	obj.close();
	//preorder(t.getroot_t1());cout <<endl;
	//preorder(t.getroot_t2());cout <<endl;
	loop:char ans = 'y';
	while(ans == 'y'){
		int x ;
		cout<<"Please enter \n1 TO INSERT\n2 TO DELETE BY KEY\n3 TO GET PLACE OF KEY\n4 TO DELETE BY PLACE\n5 TO SEARCH\n-1 TO EXIT"<<endl;
		cin>>x;
		if(x==1){
			cout<<"Enter key and string to be inserted"<<endl;
			int a;string b;
			cin>>a;cin>>b;
			t.insert(a,b);
			cout<<"inserted key "<<a << " value "<< b<<endl;
		}
		else if(x==2){
				cout<<"Enter the key to be deleted"<<endl;
				int a;
				cin>>a;
				cout<<"deleting key "<<a<<endl;
				t.remove(a);
		}
		else if(x==3)
		{
			cout<<"Enter the key to get the place"<<endl;
			int a;
			cin>>a;
			cout<<t.get_place(a)<<endl;
		}
		else if(x==4){
			cout<<"Enter place to delete by place"<<endl;
			int a;
			cin>>a;
			t.delete_by_place(a);
		}else if (x==5){
			cout<<"Enter the key to serch"<<endl;
			int a;
			cin>>a;
			cout<<t.search(a)<<endl;
		}else if (x==-1) break;
		else cout<<"wrong index"<<endl;
		cout<<"Want to conyinue(y/n)"<<endl;
		cin>>ans;
	}//preorder(t.getroot_t1());cout <<endl;
	//preorder(t.getroot_t2());cout <<endl;
	return 0;
}

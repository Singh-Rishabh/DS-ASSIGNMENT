#ifndef NAME_MAP_H
#define NAME_MAP_H

//#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define PRIMEE 33
#define A 100001
#define B 500000

class node{
	node* link;
	string value;
	string key;
	template <typename K, typename V> friend class Name_Map;
	public :
		node(){
			link = NULL;
		}
		node(string k , string v ){
			value = v;
			key = k;
			link = NULL;
		}
		
};


template <typename K, typename V>
class Name_Map {					// map interface
	private: 
		node** harray[12];
		int cap;
		int Tsize;
		string ssss;
		unsigned int integer_casting(const K& k);
		unsigned int component_sum(const K& k);
		unsigned int polynomial_sum(const K& k);
		unsigned int cyclic_sum(const K& k);
		unsigned int  division(unsigned int k);
		unsigned int mad(unsigned int k);
		unsigned int multiplication(unsigned int k);
		int sizeB(node*& head);
		//bool remove(node* &h,int,int,const K& x);
		
	public:
		//Name_Map();
		int coll[12];
		Name_Map(int capacity=2531);			// constructor
		int size() const;				// number of entries in the map
		bool empty() const;				// is the map empty?
		V& find(const K& k);		// find entry with key k
		void put(const K& k, const V& v);	// insert/replace pair (k,v)
		void erase(const K& k)	;		// remove entry with key k
		void insert(node* x, node* &h1,int index );
		void collision();
};


template <typename K, typename V>
int Name_Map<K,V>::sizeB(node* & head){
	int s=0;
	while(head!=NULL){
		s++;
		head = head->link;
	}
	return s;
}

template <typename K, typename V>
void Name_Map<K,V>::insert(node* x, node* &h1,int index ){
	if (h1 == NULL){
		h1 = x;
		return;
	}
	node* t = NULL;
	node* h=h1;
	while(h != NULL){
		t=h;
		h = h->link;
	}t->link = x;
	coll[index]++;
	x->link = NULL;
}


template <typename K, typename V>
Name_Map<K,V>::Name_Map(int capacity ){
	cap = capacity;
	ssss="NOT FOUND";
	for(int i=0;i<12;i++){
		harray[i] = new node*[cap];
		for(int j=0;j<cap;j++){
			harray[i][j] = NULL;
		}
	}
	for(int i=0;i<12;i++){
		coll[i] = 0;
	}
	Tsize=0;
}

template <typename K, typename V>
int Name_Map<K,V>::size()const{
	return Tsize;
}


template <typename K, typename V>
void Name_Map<K,V>::collision(){
	
 	cout<<"Table for Name_Map: "<<endl;
 	 for(int i=0;i<4;i++){
     if(i==0){
       cout<<"              "<<"Division "<<"MAD "<<"Multiplication"<<endl<<"Integer cast    ";
       //ofile<<"              "<<"Division "<<"MAD "<<"Multiplication"<<endl<<"Integer cast    ";
     }
     else if(i==1){
       cout<<"Component sum   ";
       //ofile<<"Component sum   ";
     }
     else if(i==2){
       cout<<"Polynomial sum  ";
      // ofile<<"Polynomial sum  ";
     }
     else{
       cout<<"Cyclic sum      ";
       //ofile<<"Cyclic sum      ";
     }
     for(int j=0;j<3;j++){
        cout<<coll[i+j]*100.0/this->size()<<"   ";
        //ofile<<name_table[i][j]<<"   ";
     }
     cout<<endl;
     //ofile<<endl;
  }
	
}

template <typename K, typename V>
bool Name_Map<K,V>::empty()const{
	return (Tsize == 0);
}


template <typename K, typename V>
void Name_Map<K,V>::put(const K& k, const V& v){
	int a[4];
	Tsize++;
	a[0] = integer_casting(k);
	a[1] = component_sum(k);
	a[2] = polynomial_sum(k);
	a[3] = cyclic_sum(k);
	int b[12];
	int c = 0;
	for (int i=0;i<12;i = i+3){
		b[i] = division(a[c]);
		b[i+1] = mad(a[c]);
		b[i+2] = multiplication(a[c]);
		c++;
	}//cout << "HEllo"<<endl;
	node* x = new node(k,v);
	for(int i=0;i<12;i++){
		int index = b[i];
		//cout<<index<<endl;
		insert(x,harray[i][index], i);
	}
}

template <typename K, typename V>
unsigned int Name_Map<K,V>:: integer_casting(const K& k){
	unsigned int sum = 0;
	int i=0;
	while( ( k.length() )> (i+3)){
		int temp = 0;
		int p1 = k[i];
		i++;
		int p2 = k[i];
		i++;
		int p3 = k[i];
		i++;
		int p4 = k[i];
		i++;
		temp = ( p1 | p2<<8 | p3 <<16 | p4<<24 );
		sum = sum + temp;
	}
	int abc = k.length()-i;
	int p;
	for( int j = 0 ; j<abc ; j++){
		int p1 = k[j+abc];
		int shift = 8*j;
		p1 = p1<<shift ;
		p = p | p1;
	}
	sum = sum + p;
	return sum;
}

template <typename K, typename V>
unsigned int Name_Map<K,V>:: component_sum(const K& k){
	int sum = 0;
	for (int i=0;i<k.length();i++){
		sum = sum + (unsigned int)k[i];
	}return sum;
}
template <typename K, typename V>
unsigned int Name_Map<K,V>:: polynomial_sum(const K& k){
	//int sum = 0; 
	int p=k[k.length()-1];
	int i=k.length()-2;
	while(i>=0){
		p=p*PRIMEE + (unsigned int)k[i];i--;
	}return p;
}

template <typename K, typename V>
unsigned int Name_Map<K,V>:: cyclic_sum(const K& k){
	unsigned int h=0;
	for(int i=0;i<k.length();i++){
		h = (h<<5)|(h>>27);
		h=h+(unsigned int)k[i]; 
	}return h;
}

template <typename K, typename V>
unsigned int Name_Map<K,V>:: division(unsigned int k){
	int x = k%cap;
	return x;
}


template <typename K, typename V>
unsigned int Name_Map<K,V>:: mad(unsigned int k){
	int x=(100001*k + 50000)%cap;
	return (x);
}


template <typename K, typename V>
unsigned int Name_Map<K,V>:: multiplication(unsigned int k){
	double a = (k*0.618033);
	double z = a-(unsigned long long int)a;
	unsigned int x = (unsigned int)(z*cap);
	//cout <<"bkghskhg.s" <<x<<endl;	
	return (x);
}
template <typename K,typename V>
V& Name_Map<K,V>::find(const K& k){
	int min=0;
	for(int i=1;i<12;i++){
		if (coll[min]>coll[i]) min = i;
	}int a = polynomial_sum(k);
	int b = division(a);
	//cout << "b is "<<b<<" min "<<min <<endl;
	
	node* h = harray[6][b];
	while( h!=NULL && h->key != k ){
		h=h->link;
	}//cout <<(h==NULL)<<endl;
	if (h==NULL){
		return ssss;
	}
	return h->value;
}

template <typename K,typename V>
void Name_Map<K,V>::erase(const K& k){
	int a = polynomial_sum(k);
	int b = division(a);
	node* h = harray[6][b];
	node* prev = NULL;//cout <<"deleting " << k<<endl; 
	while( h!=NULL && h->key != k ){
		prev = h;
		h=h->link;
	}
	if (h==NULL){
		cout << "cant del"<<endl;
		return;
	} Tsize--;
	if (prev != NULL && h->link !=NULL){
		prev->link = h->link;
		delete (h);
	}else if (prev != NULL && h->link == NULL){
		prev->link = NULL;
		delete(h);
	}else if (prev == NULL && h->link !=NULL){
		harray[6][b] = h->link;
		delete(h);
	}else if (prev == NULL && h->link ==NULL){
		harray[6][b] = NULL;
		delete (h);
	}
}

#endif

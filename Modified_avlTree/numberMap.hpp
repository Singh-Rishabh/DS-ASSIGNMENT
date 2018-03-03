#ifndef NUMBER_MAP_H
#define NUMBER_MAP_H

//#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define PRIME 33
#define A 100001
#define B 500000
class noden{
	noden* link;
	int value;
	long int key;
	template <typename K, typename V>
	friend class Number_Map;
	public :
		noden(){
			link = NULL;
		}
		noden(long int k , int v ){
			value = v;
			key = k;
			link = NULL;
		}
		
};


template <typename K, typename V>
class Number_Map {					// map interface
	private: 
		noden** harray[12];
		int cap;
		int Tsize;
		int ssss;
		
		unsigned int integer_casting(const K& k);
		unsigned int component_sum(const K& k);
		unsigned int polynomial_sum(const K& k);
		unsigned int cyclic_sum(const K& k);
		unsigned int  division(unsigned int k);
		unsigned int mad(unsigned int k);
		unsigned int multiplication(unsigned int k);
		int sizeB(noden*& head);
		
	public:
		int coll[12];
		//Number_Map();
		Number_Map(int capacity = 743);				// constructor
		int size() const;							// number of entries in the map
		bool empty() const;							// is the map empty?
		V& find(const K& k);						// find entry with key k
		void put(const K& k, const V& v);			// insert/replace pair (k,v)
		void erase(const K& k)	;					// remove entry with key k
		void insert(noden* x, noden* &h1,int index );
		void collision();
};

template <typename K, typename V>
Number_Map<K,V>::Number_Map(int capacity ){
	cap = capacity;
	ssss=-1;
	for(int i=0;i<12;i++){
		harray[i] = new noden*[cap];
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
int Number_Map<K,V>::sizeB(noden* & head){
	int s=0;
	while(head!=NULL){
		s++;
		head = head->link;
	}
	return s;
}

template <typename K, typename V>
void Number_Map<K,V>::insert(noden* x, noden* &h1,int index ){
	if (h1 == NULL){
		h1 = x;
		return;
	}
	noden* t = NULL;
	noden* h=h1;
	while(h != NULL){
		t=h;
		h = h->link;
	}t->link = x;
	coll[index]++;
	x->link = NULL;
}




template <typename K, typename V>
int Number_Map<K,V>::size()const{
	return Tsize;
}


template <typename K, typename V>
void Number_Map<K,V>::collision(){
	
	cout<<"Table for Number_Map: "<<endl;
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
bool Number_Map<K,V>::empty()const{
	return (Tsize == 0);
}


template <typename K, typename V>
void Number_Map<K,V>::put(const K& k, const V& v){
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
	noden* x = new noden(k,v);
	for(int i=0;i<12;i++){
		int index = b[i];
		insert(x,harray[i][index], i);
	}
}

template <typename K, typename V>
unsigned int Number_Map<K,V>:: integer_casting(const K& k){
	unsigned int s = k;
	return s;
	
}

template <typename K, typename V>
unsigned int Number_Map<K,V>:: component_sum(const K& k){
	unsigned int sum = 0;
	unsigned int x1 = (k & 4294967295);
	unsigned int x2 = (k & (4294967295<<32));
	sum = x1 + x2;
	return sum;
	
}
template <typename K, typename V>
unsigned int Number_Map<K,V>:: polynomial_sum(const K& k){
	unsigned int sum = 0;
	unsigned int x1 = (k & 4294967295);
	unsigned int x2 = (k & (4294967295<<32));
	sum = x1 + x2*PRIME;
	return sum;
}

template <typename K, typename V>
unsigned int Number_Map<K,V>:: cyclic_sum(const K& k){
	unsigned int h=0;
	unsigned int x[2];
	x[0] = (k & 4294967295);
	x[1] = (k & (4294967295<<32));
	for(int i=0;i<2;i++){
		h = (h<<5)|(h>>27);
		h=h+x[i]; 
	}return h;
}

template <typename K, typename V>
unsigned int Number_Map<K,V>:: division(unsigned int k){
	int x = k%cap;
	return x;
}


template <typename K, typename V>
unsigned int Number_Map<K,V>:: mad(unsigned int k){
	int x=(A*k + B)%cap;
	return (x);
}


template <typename K, typename V>
unsigned int Number_Map<K,V>:: multiplication(unsigned int k){
	double a = (k*0.618033);
	double z = a-(unsigned long long int)a;
	unsigned int x = (unsigned int)(z*cap);
	//cout <<"bkghskhg.s" <<x<<endl;	
	return (x);
}
template <typename K,typename V>
V& Number_Map<K,V>::find(const K& k){
	int a = polynomial_sum(k);
	int b = division(a);
	noden* h = harray[6][b];
	while( h!=NULL && h->key != k ){
		h=h->link;
	}//cout <<(h==NULL)<<endl;
	if (h==NULL){
		return ssss;
	}
	return h->value;
}

template <typename K,typename V>
void Number_Map<K,V>::erase(const K& k){
	int a = polynomial_sum(k);
	int b = division(a);
	
	noden* h = harray[6][b];
	noden* prev = NULL;//cout <<"deleting " << k<<endl; 
	while( h!=NULL && h->key != k ){
		prev = h;
		h=h->link;
	}
	if (h==NULL){
		//cout << "cant del"<<endl;
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

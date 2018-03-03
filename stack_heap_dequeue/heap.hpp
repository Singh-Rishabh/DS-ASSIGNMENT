#ifndef HEAP_H
#define HEAP_H

using namespace std;
#include<vector>

template <typename E>
class node {
	private:
		E data;
		node<E>* parent;
		node<E>* left;
		node<E>* right;
		template <typename T , typename C> friend class Heap;
	public :
		node(){
			parent = NULL;
			left = NULL;
			right = NULL;
		}
		node(const E& e){
			data = e;
			parent = NULL;
			left = NULL;
			right = NULL;
		}
};


template <typename E, typename C>					// element and comparator
class Heap {				       					// priority-queue interface
	private :
		int size_h;
		node<E>* root;
		node<E>* last;
		C isless;
	public:
		Heap(); 									//Constructor
		int size() const;							// number of elements
		bool isEmpty() const;						// is the queue empty?
		void insert( E& e);							// insert element
		const E& min() const;						// minimum element
		void removeMin();							// remove minimum
		void mergeHeaps(Heap<E,C> H); 				//MODIFIED 
		void buildHeap(E A[], int size);
		const bool isLeft(node<E>* x);
		const bool isRight(node<E>* x);
		node<E>* sibling(node<E>* x);
		void upHeapBubling(node<E>* t);
		void heapify(node<E>* x );
		void inorder(node<E>* x , E* a , int index);
		node<E>* getRoot();
		void deleteHeap(node<E>* node); 
	//One function to do the traversal 
};

template <typename E, typename C>
Heap<E,C> :: Heap(){
	size_h = 0;
	root = NULL;
	last = NULL;
}
template <typename E, typename C>
node<E>* Heap<E,C> :: getRoot(){
	return root;
}


template <typename E, typename C>	
int Heap<E,C>::size() const{
	return size_h;
}

template <typename E, typename C>	
bool Heap<E,C> :: isEmpty() const {
	return (size_h == 0);
}
template <typename E, typename C>	
const bool Heap<E,C> :: isLeft(node<E>* x){
	if (x->parent != NULL && x->parent->left == x ) return true;
	return false; 	
}
template <typename E, typename C>	
const bool Heap<E,C> :: isRight(node<E>* x){
	if (x->parent != NULL && x->parent->right == x ) return true;
	return false; 	
}

template <typename E, typename C>
node<E>* Heap<E,C> :: sibling(node<E>* x){
	if (/*x->parent != NULL && */isLeft(x) ) return x->parent->right;
	if (/*x->parent != NULL && */isRight(x) ) return x->parent->left; 
}


template <typename E, typename C>	
void Heap<E,C> :: insert(E& e ){
	
	node<E>* temp = new node<E>(e);
	if (root == NULL ){
		root = temp;
		last = temp;
		size_h++;
		return; 
	}if (size_h==1){
		root->left = temp;
		last = temp;
		temp->parent = root;
		size_h++;
		upHeapBubling(last);
		return;
	}
	if (isLeft(last)){
		last->parent->right = temp;
		temp->parent = last->parent;
		last = temp;
		size_h++;
		upHeapBubling(last);
		return;
	}if (isRight(last)){
		node<E>* t = last;
		while(t->parent != root && isRight(t)){
			t = t->parent;
		}if (t != root) t = sibling(t);
		while(t->left != NULL ){
			t = t->left;
		}t->left = temp;
		temp->parent = t;
		last = temp;
		size_h++;
		upHeapBubling(last);
		return;
	}
}

template <typename E, typename C>
const E& Heap<E,C> :: min()const {
	if (size_h != 0 ) return root->data;
	else cout << "EMpty "<<endl;
}



template <typename E, typename C>
void Heap<E,C>::removeMin(){
	if(size_h==0){ cout << "Empty Cannot return minimum" << endl; return; }
	else if(size_h==1){
		node<E>* temp1 = root;
		root = last = NULL;
		delete temp1;
		size_h--;
		return;
	}
	else{
		size_h--;
		root->data =last->data ;
		node<E>* temp = last;
		if(isRight(last)){
			node<E>* temp1 = last;
			last = last->parent->left;
			last->parent->right = NULL; 
			delete(temp1);
		}
		else{
			while( temp!=root ){
				if(isRight(temp)) break;
				temp=temp->parent;
			}
			if(temp!=root) temp=sibling(temp);
			while(temp->right !=NULL) temp = temp->right;
			node<E>* temp1 = last;
			last->parent->left = NULL;
			last = temp;
			delete(temp1);
		}
		heapify(root);
	}
}
template <typename E, typename C>
void Heap<E,C> :: upHeapBubling(node<E>* x){
	if (x==NULL || x->parent == NULL ) return;
	while (x->parent != NULL &&  isless(x->data,x->parent->data) ){
		E temp = x->data;
		x->data = x->parent->data;
		x->parent->data = temp;
		x = x->parent;
	}
}

template <typename E, typename C>
void Heap<E,C> :: heapify(node<E>* x){
	node<E>* l = x->left;
	node<E>* r = x->right;
	node<E>* s = x;
	if (l != NULL ){
		if (isless(l->data,s->data))
			s = l;
	} if ( r != NULL) {
		if (isless(r->data,s->data))
			s = r;
	}
	if ( x != s ){
		E temp = x->data;
		x->data = s->data;
		s->data = temp;
		heapify(s);
	}
}
template <typename E, typename C>
void Heap<E,C>:: inorder(node<E>* x , E* a , int index ){
	if (x == NULL) return;
	inorder(x->left , a, 2*index + 1);
	a[index] = x->data;
	inorder(x->right , a , 2*index + 2);
}

template <typename E, typename C>
void Heap<E,C> :: deleteHeap(node<E>* node) {
    if (node == NULL) return;
 
    deleteHeap(node->left);
    deleteHeap(node->right);
    delete (node);
} 

template <typename E, typename C>
void Heap<E,C> :: buildHeap(E a[] , int size){
	if (size == 0) return ; 
	this->deleteHeap(root);
	size_h = 0;
	node<E>* node_arr[size];
	for (int i = 0 ; i< size ; i++ ){
		node_arr[i] = new node<E>(a[i]);
	}
	
	for (int i=size/2 -1 ; i>=0 ; i--){
		int l = 2*i + 1;
		int r = 2*i + 2;
		if (l<size){
			node_arr[i]->left = node_arr[l];
			node_arr[l]->parent = node_arr[i];
		}
		if (r<size){
			node_arr[i]->right = node_arr[r];
			node_arr[r]->parent = node_arr[i];
		}heapify(node_arr[i]);
	}
	root = node_arr[0];
	last = node_arr[size-1];
	size_h = size;
	
}
template <typename E, typename C>
void Heap<E,C> :: mergeHeaps(Heap<E,C> H){
	node<E>* head = H.getRoot();
	E* heap2 = new E[H.size()];
	inorder(head , heap2 , 0);
	E* heap1 = new E[size()]; 
	inorder(root , heap1 , 0);
	E a[size() + H.size()];
	int s1 = size(), s2 = H.size();
	for (int i=0;i<s1+s2;i++){
		if (i<s1) a[i] = heap1[i];
		else a[i] = heap2[i-s1];
	}
	buildHeap(a,s1+s2);
}


#endif




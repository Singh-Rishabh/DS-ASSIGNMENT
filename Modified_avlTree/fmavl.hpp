#ifndef FMAVL_H
#define FMAVL_H

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class node;
class MAVLTree;
void preorder(node* r);
class node{
	private:
		int roll,Nsize,position;
		string name;
		int Nheight;
		node* parent;
		node* left;
		node* right;
		node* link;
	public:
		node(){
			parent = NULL;
			left=link=right=NULL;
			Nheight = 1;
			Nsize=1;
		}
		node(int r , string data){
			roll = r;
			Nheight = 1;
			name = data;
			parent = NULL;
			left=link=right=NULL;
			Nsize = 1;
		}	
		friend class MAVLTree;
		friend void preorder(node*);
};
void preorder(node* r){
	if (r==NULL)return;
	cout << r->roll << " "<<r->name<<endl;
	preorder(r->left);
	preorder(r->right);
}
class MAVLTree{
	private : 
		int Tsize;
		node* root_t1;
		node* root_t2;
		int isBalnode(node*);
		void leftRotation(node* ,node* ,node* );
		void rightRotation(node* ,node* ,node* );
		node* minValueNode(node* );
		void searchU(int,node*);
		int max (int , int);
		void deleteNode(int);
		void updateHeight(node*);
		void updateSize(node*);
		void updatePosition(node* , int);
		int nodesize(node* a) ;
		node* insert1(node* ,const int k, string s);
		void deleteNode1(node* curr);
		friend void preorder(node*);
		
	public:
		MAVLTree(); 
		int height(node*);						//Initialize the ADT	
		int size() const;						// number of elements
		bool isEmpty() const;					// is the queue empty?
		void insert(const int k, string s);		//insert k k,s into the tree
		void remove(const int k);			    //remove k from the tree, if exists
		string search(const int k);				//search for k k in the tree
		void delete_by_place(int i); 			//Delete from the entry at the  ith place (as determined by the order of insertion)
		int get_place(int k);					//Return the place (which is determined by the order of insertion), if x does not exist, return -1 
		node* getroot_t1(){
			return root_t1;
		}node* getroot_t2(){
			return root_t2;
		}
};

MAVLTree :: MAVLTree(){
	Tsize = 0;
	root_t1 = NULL;
	root_t2 = NULL;
}

int MAVLTree:: size()const {
	return Tsize;
}
int MAVLTree:: nodesize(node* a) {
	if (a == NULL) return 0;
	return a->Nsize;
}

int MAVLTree:: max(int a, int b) {
	return ((a>b)?a:b);
}
bool MAVLTree :: isEmpty() const{
	return (Tsize == 0);
}

void MAVLTree:: updateHeight(node* temp2){
	while(temp2 != NULL){
		temp2->Nheight = max(height(temp2->left ),height(temp2->right)) + 1;
		temp2 = temp2->parent;
	}
}

void MAVLTree:: updateSize(node* temp2){
	//cout << "lkfnvafs;li;"<<endl;
	while(temp2 != NULL){
		temp2->Nsize = nodesize(temp2->left) + nodesize(temp2->right) + 1;
		temp2 = temp2->parent;
	}
}

void MAVLTree :: updatePosition(node* a,int z){
	if (a==NULL )return;
	if (a->roll == 7)//cout << "7 place is "<<a->position <<endl;
	if ( a->position > z ) a->position--;
	
	updatePosition(a->left,z);
	updatePosition(a->right,z);
}
int MAVLTree :: height(node* t){
	if (t == NULL) return 0;
	else return t->Nheight;
}

int MAVLTree :: isBalnode(node* t){
	if (t == NULL) return 0;
	return height(t->left)-height(t->right);
}

void MAVLTree:: leftRotation(node* a, node * b,node* root){
	node* a_p = a->parent;	
	node* b_l = b->left;
	b->left = a;
	a->parent = b;
	a->right = b_l;
	if (b_l != NULL) b_l->parent = a;
	b->parent = a_p;
	if (a_p != NULL){
		if ((a_p)->left == a){
			(a_p)->left = b;
		}
		else{ 
			(a_p)->right = b;
		}
	}else {
		if (root_t1 == root)
			root_t1 = b;
		else root_t2 = b;
	}a->Nheight = max(this->height(a->left) , this->height(a->right)) + 1;
	b->Nheight = max(this->height(b->left) , this->height(b->right)) + 1;
	a->Nsize = nodesize(a->left) + nodesize(a->right) + 1;
    b->Nsize = nodesize(b->left) + nodesize(b->right) + 1;
}
void MAVLTree:: rightRotation(node* a, node* b,node* root){
	node* a_p = a->parent;
	node* b_r = b->right;
	b->right = a;
	a->parent = b;
	a->left = b_r;
	if (b_r != NULL) b_r->parent = a;
	b->parent = a_p;
	if (a_p != NULL){
		if (a_p->left ==a) {
			a_p->left = b;
		}
		else {
			a_p->right = b;
		}
	}else {
		if (root_t1 == root)
			root_t1 = b;
		else root_t2 = b;
	}a->Nheight = max(this->height(a->left) , this->height(a->right)) + 1;
	a->Nsize = nodesize(a->left) + nodesize(a->right) + 1;
    b->Nsize = nodesize(b->left) + nodesize(b->right) + 1;
	//cout << "height "<< a->roll<< " is "<<a->Nheight<<endl;
	b->Nheight = max(this->height(b->left) , this->height(b->right)) + 1;
	//cout << "height "<< b->roll<< " is "<<b->Nheight<<endl;
}
node* MAVLTree:: insert1(node* root , const int k , string s){
	node* temp = new node(k , s);
	//this->insert(k,pos)
	//cout << "inside T2 of inserting roll "<<k << endl;
	if (root_t2 == NULL ) {
		root_t2 = temp;
		return temp;
	}else{
		node* curr = root_t2;
		//cout << "IN T2 curr->data "<< curr->roll<<endl;;
		node* p = NULL;
		while(curr != NULL){
			p=curr;
			curr = curr->right;
		}//cout << "IN T2 p->data "<< p->roll<<endl;;
		
		p->right = temp;
		temp->parent = p;
		//node* temp2 = p;
		//updateHeight(temp2);
		node* abc = p;
		while(abc != NULL){
			abc->Nsize   = nodesize(abc->left) + nodesize(abc->right) + 1;
			abc = abc->parent;
		}
		
		node* temp2 = p;
		updateHeight(temp2);
		node* x = NULL;
		node* y = temp;
		node* ret = temp;
		int b = isBalnode(p);
		while ( p != NULL && b<=1 && b>=-1) {
			///cout << "IN T2 p->data "<< p->roll<<endl;;
			x=y;
			y=p;
			p=p->parent;
			//cout << "p is null "<<(p == NULL)<<endl;
			b = isBalnode(p);
			
		}//if (p!=NULL)cout << "IN T2 p->data "<< p->roll<<endl;;
		//cout << "b is "<<b<<endl;
		if(b>1 || b<-1){
				//cout << "Inside T2 Undergoig righr rotation" << endl;
				leftRotation(p,y,root_t2);
				updateHeight(p);
		}return ret;
	}
}

void MAVLTree:: insert(const int k , string s){
	node* pnode = this->insert1(root_t1,k,s);
	node* temp = new node(k , s);
	temp->position = Tsize+1;
	temp->link = pnode;
	//cout << "inserting roll "<<k << endl;
	if (root_t1 == NULL ) {
		root_t1 = temp;
		Tsize++;
	}else{
		Tsize++;
		node* curr = root_t1 ;
		node* p = NULL;
		while(curr != NULL){
			p=curr;
			if (k < curr->roll)	curr = curr->left;
			else curr = curr->right;
		}
		if (k < p->roll) {
			p->left = temp;
			temp->parent = p;
		}
		else {
			p->right = temp;
			temp->parent = p;
		}node* temp2 = p;
		updateHeight(temp2);
		node* x = NULL;
		node* y = temp;
		int b = isBalnode(p);
		while ( p != NULL && b<=1 && b>=-1) {
			x=y;
			y=p;
			p=p->parent;
			b = isBalnode(p);
		}
		if(b>1 || b<-1){
			if (p->roll > y->roll && y->roll > x->roll ){
				//cout << "Undergoig righr rotation" << endl;
				rightRotation(p,y,root_t1);
			}else if (p->roll > y->roll && x->roll > y->roll && x->roll < p->roll){
				//cout << "Undergoig left rigt rotation" << endl;
				leftRotation(y,x,root_t1);
				//preorder(this->getroot_t1());cout << endl;
				rightRotation(p,x,root_t1);
			}else if (p->roll < y->roll && y->roll < x->roll){
				//cout << "Undergoig left rotation" << endl;
				//cout << "p->data "<< p->roll<<endl;;
				leftRotation(p,y,root_t1);
				//cout << "rotation comp L " << endl;
			}else if (p->roll < y->roll && y->roll > x->roll && x->roll > p->roll){
				//cout << "Undergoig right left rotation" << endl;
				rightRotation(y,x,root_t1);
				//preorder(this->getroot_t1());cout << endl;
				leftRotation(p,x,root_t1);
			}updateHeight(p);
		}
	}
}

node* MAVLTree :: minValueNode(node* n)
{
    node* curr = n;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

void MAVLTree :: deleteNode(const int k){
	if (root_t1 == NULL ) return;
	node* curr = root_t1;
	node* p = NULL;
	node* del_par = NULL;
	while (curr->roll != k && curr != NULL){
		p = curr;
		if (curr->roll > k) curr = curr->left;
		else curr = curr->right;
	}if (curr == NULL ) return;
	del_par = p;
	if (curr->left == NULL || curr->right == NULL){
		node* t = curr->left ? curr->left : curr->right;
	    if (t != NULL) {
	    	curr->roll = t->roll;
         	curr->Nheight = t->Nheight;
        	curr->position = t->position;
        	curr->name = t->name;
        	curr->Nsize = t->Nsize;
        	curr->link = t->link;
        	if(p == NULL ) root_t1 = curr;
         	//if (curr->left == t) curr->left = NULL;
         	//else curr->right = NULL;
	    	p = curr;
	    	curr = t;
	    }else {
	    	if(p == NULL ) root_t1 = curr;
	    }
	    if (p->left == curr) {
        	p->left = NULL;
        }else{
        	p->right = NULL;
        }//curr->parent = NULL;
        //Tsize--;
        delete (curr);
        //updateSize(curr->parent);
	}else{
		//cout << "Not root_t1 , deleting "<< k << endl;
		node* t = this->minValueNode(curr->right);
		//cout << "min value is "<< t->roll << endl;
		curr->roll = t->roll;
        curr->Nheight = t->Nheight;
        curr->name = t->name;
        curr->position = t->position;
        curr->Nsize = t->Nsize;
        curr->link = t->link;
        if (p == NULL){
        	root_t1 = curr;
        }//cout << "root is "<<root_t1->roll<<endl;
		node* z = curr->right;
		//cout << "z->roll "<<z->roll<<endl; 
	    //if (curr == root_t2 ) root_t2 = curr;
	    curr = NULL;
	    while(z != NULL){
	    	curr=z;
	    	//cout << "curr->roll "<<curr->roll<<endl; 
	    	z=z->left;
	    }del_par = curr->parent;
	    p = curr->parent;
	    if (curr->left == NULL || curr->right == NULL){
	    	//cout << "555"<<endl;
			t = curr->left ? curr->left : curr->right;
			if (t != NULL) {
				curr->roll = t->roll;
	         	curr->Nheight = t->Nheight;
	        	curr->position = t->position;
	        	curr->name = t->name;
	        	curr->Nsize = t->Nsize;
	        	curr->link = t->link;
	         	//if (curr->left == t) curr->left = NULL;
	         	//else curr->right = NULL;
				p = curr;
				curr = t;
			}
			if (p->left == curr) {
		    	p->left = NULL;
		    }else{
		    	p->right = NULL;
		    }//curr->parent = NULL;
		    //Tsize--;
		    delete (curr);
			//this->remove(c_roll);
			//cout << "deleted two child parent "<< k<<endl;
		}
	}updateHeight(del_par);
	//updateSize(del_par);
	p = del_par;
	int b = isBalnode(p);
    while (p != NULL){
    	//cout << "curr "<<p->roll << " is "<<b<<endl;
    	if ( (b>=1 || b <=-1) ){
			if ( b>1 && isBalnode(p->left)>=0){
				//cout << "Undergoig righr rotation" << endl;
				rightRotation(p, p->left,root_t1);
			}
			else if (b>1 && isBalnode(p->left)<=0)
			{
				//cout << "Undergoig left righr rotation" << endl;
				leftRotation(p->left, p->left->right,root_t1);
				//cout << "curr left is " << curr->left->roll<<endl;
			   	rightRotation(p,p->left,root_t1);
			   	//preorder(this->getroot_t1());cout << endl;
			}
			else if (b<-1 && isBalnode(p->right)<=0){
				//cout << "Undergoig left rotation" << endl;
				leftRotation(p, p->right,root_t1);
				/// cout << "parent od curr is "<< curr->parent->roll<<endl;
			}
			else if (b<-1 && isBalnode(p->left)>=0){
			   //cout << "Undergoig righr left rotation" << endl;
			   rightRotation(p->right, p->right->left,root_t1);
			   leftRotation(p,p->right,root_t1);
			}//updateSize(p);
		}p = p->parent;
		b = isBalnode(p);
    }
}
	

void MAVLTree :: remove(const int k){
	if (root_t1 == NULL)return;
	node* curr = root_t1;
	while (curr != NULL && curr->roll != k){
		if (curr->roll > k) curr = curr->left;
		else curr = curr->right;
	}if (curr == NULL ) return;
	//cout << "Deeting " << k << endl;
	//int place = curr->position;
	//cout << "curr ->link"<< curr->link->parent->roll << " position "<< curr->position<<endl;
	deleteNode1(curr->link);
	//cout << "deleted in t2"<< endl;
	
	deleteNode(k);
	//cout << "deleted in t1"<< endl;
	//updatePosition(root_t1,place);
	Tsize--;
	
}


void MAVLTree::searchU(int r, node* c){
	//cout << "\n\ncurr "<<c<<" point "<< r<< endl<<endl;
	node* temp = root_t1;
	while(temp->roll != r){
		if (temp->roll < r) temp = temp->right;
		else temp = temp->left;
	}if (temp == NULL)return;
	//cout << "link "<<temp->link <<endl;
	temp->link = c;
	//cout << "link "<<temp->link <<endl;
}
void MAVLTree :: deleteNode1(node* curr){
    if (curr == NULL){
        return ;
    }node* del_par = curr;
    node* p=NULL;
    //cout << "inside T2 deleting "<<curr->roll<<endl;
    if((curr->left == NULL) || (curr->right == NULL)){
        node* t;
        //cout << "inside T2 deleting "<<curr->roll<<endl;
        (curr->left != NULL ) ? (t = curr->left) : (t = curr->right);
        if (t == NULL && curr != root_t2){
            t = curr;
            //cout << "inside T2 deleting "<<curr->roll<<endl;
            p=curr->parent;
            if (p->left == curr) p->left = NULL;
         	else p->right = NULL;
            //cout << "HELLO no child"<<endl;
            //curr = NULL;
        }else if(t == NULL && curr == root_t2){
        	t=curr;
        	p=curr->parent;
            if (p->left == curr) p->left = NULL;
         	else p->right = NULL;
        	root_t2 = NULL;
        	curr = NULL;
        }
        else{
         	p=curr->parent;
         	curr->roll = t->roll;
         	curr->Nheight = t->Nheight;
        	curr->position = t->position;
        	curr->name = t->name;
        	curr->Nsize = t->Nsize;
        	searchU(t->roll,curr);
         	if (curr->left == t) curr->left = NULL;
         	else curr->right = NULL;
         	if (curr == root_t2 ) root_t2 = curr;
        }           
        delete(t);
        //cout << "1\n";
        //cout << "curr->parent " << curr->parent->roll <<endl;	
        updateSize(curr->parent);
        //cout << "1\n";
        //cout << "HELLO deleted "<<endl;
    }
    else{
        node* t = minValueNode(curr->right);
        //cout << "min value "<<t->roll<<endl; 
        curr->roll = t->roll;
        curr->Nheight = t->Nheight;
        curr->name = t->name;
        curr->position = t->position;
        curr->Nsize = t->Nsize;
        searchU(t->roll,curr);
        node* z = curr->right;
        if (curr == root_t2 ) root_t2 = curr;
        node* y = NULL;
        while(z != NULL){
        	y=z;
        	z=z->left;
        }//p = y->parent;
        
        deleteNode1(y);
        return;
        del_par = y->parent;
        //curr->right = deleteNode(curr->right, t->roll);
    }updateHeight(p);
    updateSize(del_par);
    //cout << "sklhvdlsv ;V :UVS;svb ;asv"<<endl;
    //int b = isBalnode(p);
    //cout << "balance "<<b<<endl;
    int b = isBalnode(p);
    while (p != NULL){
    	//cout << "curr "<<p->roll << " is "<<b<<endl;
    	if ( (b>=1 || b <=-1) ){
			if ( b>1 && isBalnode(p->left)>=0){
				//cout << "Undergoig righr rotation" << endl;
				rightRotation(p, p->left,root_t2);
			}
			else if (b>1 && isBalnode(p->left)<=0)
			{
				//cout << "Undergoig left righr rotation" << endl;
				leftRotation(p->left, p->left->right,root_t2);
				//cout << "curr left is " << curr->left->roll<<endl;
			   	rightRotation(p,p->left,root_t2);
			   	//preorder(this->getroot_t1());cout << endl;
			}
			else if (b<-1 && isBalnode(p->right)<=0){
				//cout << "Undergoig left rotation" << endl;
				leftRotation(p, p->right,root_t2);
				 //cout << "parent od curr is "<<endl;
			}
			else if (b<-1 && isBalnode(p->left)>=0){
			   //cout << "Undergoig righr left rotation" << endl;
			   rightRotation(p->right, p->right->left,root_t2);
			   leftRotation(p,p->right,root_t2);
			}updateSize(p);
		}p = p->parent;
		b = isBalnode(p);
    }
    
}

string MAVLTree:: search(const int k){
	node* curr = root_t1;
	while(curr != NULL && curr->roll != k){
		if (curr->roll < k) curr = curr->right;
		else curr = curr->left;
	}if (curr == NULL ) return "NOT FOUND";
	return curr->name;
}

int MAVLTree::get_place(int k){
	node* temp2 = root_t1;
	while(temp2!=NULL){
		if ( k==temp2->roll) break ;
		else if ( k < temp2->roll) temp2=temp2->left;
		else temp2=temp2->right;
	}
	if( temp2==NULL )return -1;
	//cout << " temp2 "<< temp2->roll<<endl;
	node* temp = temp2->link;
	int place=1;
	//cout << " temp1 "<< temp->roll<<endl;
	if( temp->left !=NULL) place = place + temp->left->Nsize;
	//cout << "place till now "<<place<<endl;
	while( temp->parent != NULL){
		if( temp->parent->left != temp){
			//cout<< "kvfsli"<<endl;
			if( temp->parent->left != NULL){
				//cout<< "size "<< temp->parent->left->Nsize<< " parent "<< temp->parent->left->roll<< endl;
				place = place + 1 + temp->parent->left->Nsize;
				//cout << "left not null"<<endl;
			}
			else place = place +1;
		}//cout << "place till now "<<place<< " temp "<< temp->roll<<endl;
		temp = temp->parent;
	}
	return place;
}

void MAVLTree::delete_by_place(int i){
	int z=0;
	node* temp = root_t2;
	if( temp->Nsize < i) return;
	while( temp!=NULL){
		if( temp->left==NULL) z=0;
		else z = temp->left->Nsize;
		if( i<=z) temp = temp->left;
		else if( i=z+1){
			remove(temp->roll);
			break;
		}
		else{
			i = i-z-1;
			temp = temp->right;
		}
	}	
}



#endif

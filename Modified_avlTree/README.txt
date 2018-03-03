

******************************************************************* HASH TABLE *******************************************************************************
To run code :
	$g++ main.cpp
	$./a.out


Hashing implementation using 4 different hash codes and 3 hash functions.

In case of number map we had a total of 1099 entries , and with separate chaining there were approximately 50% collisions in all the cases , minimum collisions were observed in integer casting hash code with Division function(47.4067 %) , while maximum collisions were observed in Component Sum hashcode with division(49.4995 %) as the hash function.
Average load factor (m/n) = 1099/743 = 1.47


Similarly in name map we had a total of 4351 entries , and with separate chaining there were approximately 60% collisions , minimum collisions were observed in Integer Cast hash code with MAD function (53.3256 %), while maximum collisions were observed in Cyclic Sum hashcode with Multiplication(86.9293 %) as the hash function.
Average load factor (m/n) = 4315/2351 = 1.83


******************************************************************* AVL TREE *********************************************************************************

To run code :
	$g++ main2.cpp
	$./a.out

MAVLTree has following functions
		int size() const;						// number of elements
		bool isEmpty() const;					// is the queue empty?
		void insert(const int k, string s);		//insert k k,s into the tree
		void remove(const int k);			    //remove k from the tree, if exists
		string search(const int k);				//search for k k in the tree
		void delete_by_place(int i); 			//Delete from the entry at the  ith place (as determined by the order of insertion)
		int get_place(int k);					//Return the place (which is determined by the order of insertion), if x does not exist, return -1 
		
		
	My code implement two trees T1 and T2. Each node in T1 is linked to T2 by pointer.
Time complexity :
	size() 		: O(1) time complexity
	isEmpty() 	: O(1) time complexity
	insert() 	: insert an element by key into T1, insert the element as the biggest to T2, and update the pointers. Update the in T2 the field x.size in 						the insertion path. (The insertion is a in AVL tree)
				All the operation is O(log(n))
	
	remove(k) 	: find the element in T1 (regular search), and delete it from both the trees. In T2 go up from the deleted element to the root and update 					x.size for all the nodes in this path. (The deletion is as in AVL tree)
				All the operation is O(log(n))
				
	search(k)	: simple bst search. Hence is order O(logn)
	
	get_place(i): find x in T1, go by its pointer to T2, then calculate the index of x in the tree – Go up from x to the root. In this path sum the 					number of nodes that are in the left subtree of the nodes in the path that are smaller than x.
					All the operation is O(log(n))
						
	delete_by_place(i) : with the help of 'i' find the node to be deleted in T2. from node find the roll to be deleted and pass it to remove function. 
						All the operation is O(log(n)).


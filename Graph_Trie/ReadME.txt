

******************************************************************* TRIE *******************************************************************************
To run code :
	$g++ main.cpp
	$./a.out

Trie has the following function :

	Trie();												// CONSTRUCTOR
	void insert(string , long long);					// FOR INSERTING A STRING IN TRIE
	void search(string );								// FOR REMOVING A STRING IN TRIE
	
TIME COMPLEXITY :
	
	void insert(string , long long);  Insert takes time of the order of size of the string that you want to insert i.e. 'O(m)' where m is the length of the string.
	void search(string );	          Search also takes the size of string that u want to search.
									  Since we have to find atmost the numbers of the string with a prefix so it takes O(m)*5 i.e O(m) to fins the strings
									  where 'm' is the average length of the string.
									  



******************************************************************* Graph *********************************************************************************

To run code :
	$g++ main2.cpp 
	$./a.out courses.txt​ dependencies.txt
	
	*** It assumes that the file coueses.txt and dependencies.txt has courses name as C1, C2 ......

Graph has the following function :
	
	Graph();														// IMPLICT CONSTRUCTOR
	Graph(int ,int);												// CONSTRUCTOR
	void insertEdge(string src,string dest, int dur);				// FUNCTION TO ADD EDGE
	void printGraph();												// PRINTS THE GRAPH
	void callDfs();													// FUNCTION TO DO DFS ON THE GRAPH
	**void longestPath();											// FUNCTION TO PRINT THE LONGEST PATG=H BETWEEN TWO NODES (INCOMPLETE)
	
TIME COMPLEXITY :
	
	void insertEdge(string src,string dest, int dur);	 IT TAKES "O(1)" TIME TO INSERT AN EDGE. IT JUST GO THO THAT INDEX AND THEN INSERT THE EDGE N=BETWEEN TWO NODES.
	**void longestPath();								 IT FINDS THE LONGEST PATH BETWEEN THE TWO START AND END NODES.
	void callDfs();										 WITH THE HELP OF THIS WE CAN KNOW THAT WETHER THE GRAPH IS CYCLIC OT ACYCLIC.
	
	
***************************************************************************************************************************************************************

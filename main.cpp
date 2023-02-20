/*
Qn 1:	What is the time complexity (Big-O) in the worst-case for the 
		BST::empty() algorithm? Explain.
Ans:	The BST::empty() algorithm has a time complexity of O(1) in the 
		worst-case.	This is because the function only needs to check if 
		the root node of the binary search tree is nullptr. If the root 
		node is nullptr, it means that the tree is empty and the function
		can return true. Checking if a single opinter is nullptr takes 
		constant time.

Qn 2:	What is the time complexity (Big-O) in the worst-case for the 
		BST::add() algorithm? Explain. 
Ans:	The BST::add() algorithm has a time complexity of O(h), whereby
		h is the height of the binary search tree, in the worst-case,
		which assumingly is when the tree is completely unbalanced. An
		unbalanced tree is one with all nodes to one side of the root.
		In such a case, every new node added will form a single linear
		path from the root to the enw node. The height of this tree will
		be equal to the number of nodes added, and the time complexity
		for adding a new node to the tree will be proportional to the
		height of the tree.

Qn 3:	What is the time complexity (Big-O) in the worst-case for the 
		BST::makeEmpty() algorithm? Explain. 
Ans:	The BST::makeEmpty() algorithm has a time complexity of O(n),
		whereby n is the number of nodes in the tree, in the worst-case,
		which assumingly is when the tree is fully populated and balanced.
		BST::makeEmpty() traverses the tree in post-order, recursively
		deleting each node. In the assumed worst-case, the number of
		nodes is proportional to 2^h - 1, where h is the height of the
		tree. Thus, the time complexity in the worst-case of
		BST::makeEmpty() is O(2^h - 1) = O(n).

Qn 4:	What is the time complexity (Big-O) in the worst-case for the
		BST::printLevelOrder() algorithm? Explain.
Ans:	The BST::printLevelOrder() algorithm has a time complexity of
		O(n), where n is the number of nodes, in the worst-case, which
		assumingly is when the binary search tree is a complete binary
		tree. This is when the tree has a maximum number of nodes
		for a given height. This is because the function needs to 
		traverse every node in the tree to print them in level order,
		and the operation of printing each node's value is done in 
		constant-time. 

Qn 5:	What is the time complexity (Big-O) in the worst-case for the
		BST::cloneTree() algorithm? Explain.
Ans:	The BST::cloneTree() algorithm has a time complexity of O(n),
		whereby n is the number of nodes in the tree, in the worst-case.
		The algorithm visits each node in the original tree and creates 
		a new node in the cloned tree, resulting in a linear time 
		complexity of O(n). This is because the algorithm performs a
		depth-first traversal of the tree, which means that it visits
		all the nodes in the left subtree before visiting the nodes in
		the right subtree. Though copying one node to another takes 
		constant time (time complexity of O(1)), it has to repeat this
		for each node in the tree, resulting in the aforementioned time
		complexity of O(n).
*/

#include <iostream>
#include "BST.h" 

int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/
	BST<string> bst_test;
	bst_test.add("C");
	bst_test.add("p");
	bst_test.add("t");
	bst_test.add("s");
	bst_test.add("2");
	bst_test.add("2");
	bst_test.add("3");
	bst_test.add("B");
	bst_test.add("S");
	bst_test.add("T");
	
	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    b. Level-order print
	    c. Post-order print
	    d. Pre-order print */
	cout << "In-order print:" << endl;
	bst_test.printInOrder(cout);
	cout << endl << endl;

	cout << "Level-order print" << endl;
	bst_test.printLevelOrder(cout);
	cout << endl << endl;

	cout << "Post-order print" << endl;
	bst_test.printPostOrder(cout);
	cout << endl << endl;

	cout << "Pre-order print" << endl;
	bst_test.printPreOrder(cout);
	cout << endl << endl;

	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	BST<string> bst_copy1(bst_test);
	
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/

	if (bst_copy1.size() == bst_test.size() && bst_copy1.getNode("B") && bst_copy1.getNode("S") && bst_copy1.getNode("T")) {
		cout << "Copy constructor test-1 passed!";
	} else {
		cout << "Copy construtor test-1 failed!" << endl;
		cout << "bst_test:" << endl;
		bst_test.printLevelOrder(cout);
		cout << "bst_copy1:" << endl;
		bst_copy1.printLevelOrder(cout);
	}

	cout << endl << endl;

	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   // bst_copy1.getNode("B")->setValue("A");
	bst_copy1.getNode("B")->setValue("A");
	
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/
	
	if (bst_test.contains("B") && !bst_test.contains("A")) {
		cout << "Copy constructor test-2 passed!";
	} else {
		cout << "Copy constructor test-2 failed!" << endl;
		cout << "bst_test:" << endl;
		bst_test.printLevelOrder(cout);
	}

	cout << endl << endl;

	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	BST<string> bst_copy2;
	bst_copy2 = bst_test;
	
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/

	if (bst_copy2.size() == bst_test.size() && bst_copy2.contains("B") && bst_copy2.contains("S") && bst_copy2.contains("T")) {
		cout << "Copy assignment operator test passed!";
	} else {
		cout << "Copy assignment operator test failed!" << endl;
		cout << "bst_test:" << endl;
		bst_test.printLevelOrder(cout);
		cout << endl << "bst_copy2:" << endl;
		bst_copy2.printLevelOrder(cout);
	}

	cout << endl << endl;

	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	BST<string> bst_move1(move(bst_test));
	
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/

	if (bst_move1.size() == 9 && bst_move1.contains("B") && bst_move1.contains("S") && bst_move1.contains("T") && bst_test.empty()) {
		cout << "Move constructor test passed!";
	} else {
		cout << "Move constructor test failed!" << endl;
		cout << "bst_move1:" << endl;
		bst_move1.printLevelOrder(cout);
		cout << endl << "Reason is because size is 10, not 9, though move was completed properly.";
	}

	cout << endl << endl;

	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	BST<string> bst_move2;
	bst_move2 = BST<string>({"B", "S", "T"});
	
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the mesaage: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/

	if (bst_move2.size() == 3 && bst_move2.contains("B") && bst_move2.contains("S") && bst_move2.contains("T")) {
		cout << "Move assignment operator test passed!";
	} else {
		cout << "Move assignment operator test failed" << endl;
		cout << "bst_move2:" << endl;
		bst_move2.printLevelOrder(cout);
	}

	cout << endl << endl;

	return 0;
}
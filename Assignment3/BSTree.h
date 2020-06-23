/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();
	Node* getRoot()const;

private:
	Node* root;
	bool search(Node* T, const Customer& searchCustomer); //this helps the search member function
	void insert(Node* T, Customer newCustomer);           //helps the insert function
	Node* remove(Node* T, Customer removeCustomer);    //helps the remove function
	Node* findMin(Node* removeNode);                      //helps the remove function by finding minimum value
	void printOrder(Node* T);                             //helps my print function
	void destructorHelp(Node* T);                         //helps destructor
	void copyHelper(Node* T);                             //helps the copy customer
	void rangeHelper(Node* T, Customer startCus, Customer endCus, vector<Customer>& rangeCustomers);  //helps make the vector
};

#endif /* BSTREE_H_ */

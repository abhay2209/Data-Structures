/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
	Customer newCustomer; //makes a new customer
	Node* rightChild;     //pointer to right child
	Node* leftChild;      //pointer to left child
	Node* parent;         //pointer to parent
	public:
	Node();               //constructor for node class
	Node(Customer A , Node* left, Node* right, Node* parent);
	friend class BSTree;

};

#endif /* NODE_H_ */

/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"
Node::Node(){         //default constructor
	rightChild=0;
	leftChild=0;
}
Node::Node(Customer A , Node* left, Node* right,Node* p)  //defining my non-default constructor
{
	newCustomer=A;
	leftChild=left;
	rightChild=right;
    parent=p;
}


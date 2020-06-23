/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "BSTree.h"


BSTree::BSTree() {
	root=0;
}

BSTree::~BSTree() { // checks if root is pointing to NULL
	if(root==0)
		return;

	destructorHelp(root);

}
void BSTree::destructorHelp(Node* T){
	//Recursively deletes all nodes
	if(T->leftChild!=0)
		destructorHelp(T->leftChild);
	if(T->rightChild!=0)
		destructorHelp(T->rightChild);
	delete T;
	return;


}
//To insert
bool BSTree::insert(string x, char y, int z) {  
	Customer newCustomer(x,y,z);
	if(root==0)
		root= new Node(newCustomer,0,0,0);   //adding the root
	else
		insert(root, newCustomer);  //adding its children
	if(search(root,newCustomer))  //searching for it, if found then returns true
		return true;
	return false;
}

void BSTree::insert(Node* T, Customer newCustomer){
	if((T->newCustomer)>=newCustomer){      //cehcks where to insert the new node and then inserts it
		if(T->leftChild==0)
			T->leftChild= new Node(newCustomer, 0,0,T);
		else
			insert(T->leftChild, newCustomer);

	}
	else{
		if(T->rightChild==0)
			T->rightChild=new Node(newCustomer, 0 ,0,T);
		else
			insert(T->rightChild,newCustomer);
	}
}





bool BSTree::search(string x, char y) {
	Customer check(x,y,0);   //converts the data into customer object
	return search(root, check);
}
bool BSTree::search(Node* T, const Customer& searchCustomer){  // then searches for that object
	if(T==0)                                                   //searches for the customer, transversing through the list
		return false;
	if(T->newCustomer==searchCustomer)
		return true;
	if((T->newCustomer)<(searchCustomer))
		return search(T->rightChild, searchCustomer);
	else
		return search(T->leftChild, searchCustomer);
}
Node* BSTree::getRoot()const{   //incase i need to access the root
	return root;
}

//copy constructor
BSTree::BSTree(const BSTree & rbt){     
	if(rbt.getRoot()==0)   //checks if the new tree is empy or not
		return;
	root =new Node(rbt.getRoot()->newCustomer,0,0,0); // if not empty starts by creating root
	copyHelper(rbt.getRoot());  //passes it the helper
}

void BSTree::copyHelper(Node* T){
	if(T==0)
		return; //helper sees if null point is reached for the tree which is getting copied
	copyHelper(T->leftChild);    //inorder transversal to copy all elements, i could have created an O(logn) by going to each child(but that needed some modifications in my insert)
	insert(this->root,T->newCustomer);
	copyHelper(T->rightChild);

}

//creates range
vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {  //makes vector and passes it with boundaries
	Customer firstCustomer(x,y,0),lastCustomer(z,a,0);
	vector<Customer> rangeCustomers;
    rangeHelper(root,firstCustomer,lastCustomer,rangeCustomers);
    return rangeCustomers;
}
void BSTree::rangeHelper(Node* T, Customer startCus, Customer endCus, vector<Customer>& rangeCustomers){
	if(T==0)          //chevcks all elements and adds them in the vector according to the condition
		return;
	if((startCus <= T->newCustomer)&&(endCus>=T->newCustomer)){
		rangeHelper(T->leftChild,startCus,endCus,rangeCustomers);
		rangeCustomers.push_back(T->newCustomer);
		rangeHelper(T->rightChild,startCus,endCus,rangeCustomers);
	}
	else if (startCus>T->newCustomer){
		rangeHelper(T->rightChild,startCus,endCus,rangeCustomers);
	}
	else if(endCus<T->newCustomer){
		rangeHelper(T->leftChild,startCus,endCus,rangeCustomers);
	}

}

//prints node
void BSTree::inOrderPrint() {  //prints tree
	printOrder(root);
}
void BSTree::printOrder(Node* T){
	if(T==0)
		return;
	printOrder(T->leftChild);  //inorder transversal to print
	cout<<T->newCustomer<<endl;
	printOrder(T->rightChild);
}

//removes node
bool BSTree::remove(string x, char y) {
	Customer removeCustomer(x,y,0);
	if(root==0)
		return root;                           //if empty dont delete
	bool found = search(root,removeCustomer);
	if(root->newCustomer==removeCustomer){        //this if is to delete the root
		if(root->rightChild==0){
			Node* temp=root;
			this->root=root->leftChild;
			delete temp;
		}
		else if(root->leftChild==0){
			Node* temp=root;
			this->root=root->rightChild;
			delete temp;
		}
		else{
			Node* temp=findMin(root->rightChild);
			root->newCustomer=temp->newCustomer;
			root->rightChild=remove(root->rightChild,temp->newCustomer);
		}
		return found;

	}

	remove(root,removeCustomer); //if root has not to be deleted the helper is used
	return found;

}

Node* BSTree::remove(Node* T, Customer removeCustomer){
	if(T==0)                                            //Checks if its null
		return T;
	else if(removeCustomer<(T->newCustomer))            //transverses to find element to be deleted
		T->leftChild=remove(T->leftChild,removeCustomer);
	else if(removeCustomer>(T->newCustomer))
		T->rightChild=remove(T->rightChild,removeCustomer);
	else{
		if((T->leftChild==0)&&(T->rightChild==0)){  //deletes if no children
			delete T;
			T=0;
		}
		else if(T->leftChild==0){      //deletes if one child
			Node* temp=T;
			if(T=T->parent->rightChild)
			   T->parent->rightChild=T->rightChild;
		    else
		    	T->parent->leftChild=T->rightChild;
			delete temp;
		}
		else if(T->rightChild==0){
			Node* temp=root;
			if(root=root->parent->leftChild)
			   T->parent->leftChild=T->leftChild;
		    else
		    	T->parent->rightChild=T->leftChild;
			delete temp;
		}
		else{                //deletes if 2 children
			Node* temp = findMin(T->rightChild);
			T->newCustomer=temp->newCustomer;
			T->rightChild=remove(T->rightChild,temp->newCustomer);

		}
	}
	return T;
}
Node* BSTree::findMin(Node* removeNode){   //finds the minimum node
	Node* min=removeNode;
	while(min&&min->leftChild!=0){
		min=min->leftChild;
	}
	return min;
}



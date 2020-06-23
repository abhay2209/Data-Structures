/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer();              //constructors for customer
	Customer(string,char,int); 
	string getName()const;   //getters for customer
	char getInitial()const;
	int getAmount()const;
	void setAmount(const int &amount); //setter for amount
	bool operator<(const Customer &contact2)const;   //overloading all operators
	bool operator>(const Customer &contact2)const;
	bool operator<=(const Customer &contact2)const;
	bool operator>=(const Customer &contact2)const;
	bool operator==(const Customer &contact2)const;
	bool operator!=(const Customer &contact2)const;

private:
	string name;
	char initial;
	int amount;

	friend ostream& operator<<(ostream & os,  Customer & c);

};

#endif /* CUSTOMER_H_ */

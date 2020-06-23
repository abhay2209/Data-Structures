/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"
using namespace std;
Customer::Customer(){
	amount=0;
}
Customer::Customer(string x, char y, int z){  //implementing constructors, setters, getters
	name=x;
	initial=y;
	amount=z;
}
string Customer::getName()const{
return name;
}
char Customer::getInitial()const{
return initial;
}
int Customer::getAmount()const{
return amount;
}
void Customer::setAmount(const int &amount){
this->amount=amount;
}


//Comparision operators
ostream& operator<<(ostream & os,  Customer & c) {
os<<c.getName()<<", "<<c.getInitial()<<". ("<<c.getAmount()<<")";
return os;
}


bool Customer::operator<(const Customer &contact2)const{
	if(name<contact2.name)
		return true;
	else if((name==contact2.name)&&(initial<contact2.initial))
		return true;
	return false;
}
bool Customer::operator>(const Customer &contact2)const{
	if(name>contact2.name)
		return true;
	else if((name==contact2.name)&&(initial>contact2.initial))
		return true;
	return false;
}
bool Customer::operator<=(const Customer &contact2)const{
	if(name<contact2.name)
		return true;
	else if((name==contact2.name)&&(initial<=contact2.initial))
		return true;
	return false;
}
bool Customer::operator>=(const Customer &contact2)const{
	if(name>contact2.name)
		return true;
	else if((name==contact2.name)&&(initial>=contact2.initial))
		return true;
	return false;
}
bool Customer::operator==(const Customer &contact2)const{
	if((name==contact2.name)&&(initial==contact2.initial))
		return true;
	return false;
}
bool Customer::operator!=(const  Customer &contact2)const{
	return !(*this==contact2);
}



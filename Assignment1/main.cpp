#include<iostream>
#include<string>
#include"charlistnode.h"
#include"charlistnode.cpp"
using namespace std;

int main()
{
CharList first("abcd");
if(first.empty())
	cout<<"fail"<<endl;
else 
	cout<<"passed empty"<<endl;
if(first.size()>>0)
	cout<<"passed size"<<endl;
else
	cout<<"fail"<<endl;
first.append('e');
if(first.toString()!="abcde")
cout<<"fail"<<endl;
else
cout<<"passed append"<<endl;
first.append('l','c');
if(first.toString()!="abclde")
	cout<<"fail"<<endl;
else
	cout<<"passed append after d"<<endl;
first.insert('d');
if(first.toString()!="dabclde")
cout<<"fail";
else
cout<<"passed insert"<<endl;
first.append('r','d',2);
if(first.toString()!="dabcldre")
	cout<<"fail";
else
	cout<<"passed for append after nth occurence d"<<endl;
first.insert('r','c');
 if(first.toString()!="dabrcldre")
 	cout<<"fail";
 else
 	cout<<"passed for insert after d"<<endl;
 first.insert('t','d',3);
 if(first.toString()!="dabrcldret")
 	cout<<"fail";
 else
 	cout<<"passed for insert after nth occurence of d"<<endl;
 first.remove('a');
 if(first.toString()!="dbrcldret")
 	cout<<"fail";
 else
 	cout<<"passed to remove"<<endl;
 first.remove('d',2);
 if(first.toString()!="dbrclret")
 	cout<<"fail";
 else
 	cout<<"passed to remove at nth"<<endl;

  
	return 0;
}

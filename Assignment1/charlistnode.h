#pragma once
#include<iostream>
#include<string>
using namespace std;

class CharListNode
{
private:
	char e;
	CharListNode* next;
	CharListNode* prev;
	friend class CharList;
};
class CharList
{
private:
	CharListNode* header;
	CharListNode* trailer;
	void addNode(CharListNode* w, char e);
public:
	bool empty();
	int size();
	void insert(char c);
	void append(char c);
	void insert(char c, char d);
	void append(char c, char d);
	void insert( char c, char d, int n);
	void append(char c, char d, int n);
	void remove(char c);
	void remove(char c, int n);
	string toString();
	CharList(string s);
	~CharList();
};

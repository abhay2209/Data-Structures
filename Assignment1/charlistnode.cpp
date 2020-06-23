#include"charlistnode.h"
// chcks the size of string
int CharList::size()
{ 
CharListNode* h = header;
int size=0;
while(h->next!=trailer)   
{
	size++;
	h=h->next;
}
return size;
}
bool CharList::empty()
{
	if(header->next==trailer)
		return true;
	return false;
}
// I added this as a private function which i can use to insert a node 
void CharList::addNode(CharListNode* w, char c) //node is inserted before w
{
	CharListNode* u=new CharListNode;
	u->e=c;
	u->next=w;
	u->prev=w->prev;
	w->prev->next=u;
	w->prev=u;
}
void CharList::insert(char c)  // adds a node just after head
{
addNode(header->next,c);
}

void CharList::insert(char c , char d) //insert just before d or at the end
{
	CharListNode* h = header;
	h=h->next;
	while(h->e!=d)
{
	
	if(h==trailer)   // goes until the very end to check if not then adds node at the very last
		break;
	h=h->next;
}
	addNode(h,c);
}

void CharList::insert(char c, char d, int n)
{
	 CharListNode* h = header;
	h=h->next;
	int check=0;
	while(h!=trailer)
{
	if(h->e==d)    // this if check the occurences with the n to stop the loop at that point
	check++;
	if(check==n)
		break;
	h=h->next;
}
	addNode(h,c);
}
void CharList::append(char c)  // works similar to insert but creates a node after
{
addNode(trailer,c);
}

void CharList::append(char c, char d)
{
	CharListNode* h = header;
	h=h->next;
	while(h->e!=d)
{
	
	if(h->next==trailer)
		break;
	h=h->next;
}
	addNode(h->next,c);
}
void CharList::append(char c, char d, int n)
{
    CharListNode* h = header;
	h=h->next;
	int check=0;
	while(h->next!=trailer)
{
	if(h->e==d)
	check++;
	if(check==n)
		break;
	h=h->next;
}
	addNode(h->next,c);
}
string CharList::toString()
{
	string s="";
	CharListNode* h=header;
	h=h->next;
	while(h!=trailer)
	{
		s=s+h->e;
		h=h->next;
	}
	return s;
}
CharList::CharList(string s) 
{
	header = new CharListNode;
	trailer = new CharListNode;
	header->next=trailer;
	trailer->prev=header;
	int i = s.length();
	for(int j=0;j<i;j++)
	{
		append(s[j]); // adds nodes from the back starting from the first element of the string, hence creates a list
	}
	return;
}
CharList::~CharList()
{
	if(!empty())
	{
		string s=this->toString();
		for(int i=0;i<s.length();i++)
		{
			remove(s[i]);        //removes the whole string
		}
	}
	delete header;  // then delete head and trailer
	delete trailer;
}
void CharList::remove(char c)
{
CharListNode* h=header;
h=h->next;
while(h->e!=c)
{
	
	if(h==trailer)
		break;
	h=h->next;
}
if(h!=trailer)  // this prevents the deletion of trailer
{
CharListNode* u=h->prev;
CharListNode* v=h->next;
u->next=v;
v->prev=u;
delete h;
}
}
void CharList::remove(char c, int n)
{
CharListNode* h=header;
h=h->next;
int check=0;
while(h!=trailer)
{
	if(h->e==c)
	check++;
	if(check==n)
		break;
	h=h->next;
}
if((h!=trailer)&&(check==n))
{
CharListNode* u=h->prev;
CharListNode* v=h->next;
u->next=v;
v->prev=u;
delete h;

}
}


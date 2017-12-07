#include "MyDLinkList_HaoWang.h"



MyDLinkList::MyDLinkList() : size(0)
{
	head = new DLinkNode();
	tail = new DLinkNode();
	head->next = tail;
	tail->prev = head;
}


MyDLinkList::~MyDLinkList()
{
	DLinkNode* temp = head;
	while (temp->next)
	{
		head = temp->next;
		delete temp;
		temp = head;
	}
	delete temp;
}

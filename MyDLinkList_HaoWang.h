#pragma once
#include <string>
using std::string;
class DLinkNode
{
	friend class MyDLinkList;
public:
	DLinkNode(string sb = "", int shs = 0) : shares(shs), symbol(sb), prev(0), next(0) {}
	~DLinkNode() {}
private:
	string symbol;
	int shares;
	DLinkNode *prev;
	DLinkNode *next;
};

class MyDLinkList
{
public:
	MyDLinkList();
	~MyDLinkList();
	void insert_node(string, int);
	void delete_node(DLinkNode* dln);
	void sort(string);
private:
	DLinkNode *head;
	DLinkNode *tail;
	int size;
};


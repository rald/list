#ifndef LIST_H
#define LIST_H

typedef struct List_Node List_Node;
struct List_Node {
	void *data;
	struct List_Node *next;
};

List_Node *List_NodeNew();
void List_Push(List_Node **head,void *data);

#endif
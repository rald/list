#ifndef LIST_H
#define LIST_H

typedef struct List_Node List_Node;
struct List_Node {
	void *data;
	List_Node *next;
};

List_Node *List_NodeNew(void *data,List_Node *next);
List_Node *List_AddFirst(List_Node **head,void *data);
List_Node *List_AddLast(List_Node **head,void *data);
List_Node *List_InsertAfter(List_Node **head,void *key,void *data,int(*compareFunction)(void *lhs,void *rhs));
List_Node *List_InsertBefore(List_Node **head,void *key,void *data,int(*compareFunction)(void *lhs,void *rhs));
List_Node *List_Remove(List_Node **head,void *key,int(*compareFunction)(void *lhs,void *rhs));
List_Node *List_Search(List_Node **head,void *key,int(*compareFunction)(void *lhs,void *rhs));
void List_Print(List_Node *head,void (*printFunction)(void *data));

#endif
#include<stdlib.h>

#include "list.h"

List_Node *List_NodeNew(void *data,List_Node *next) {
	List_Node *node=malloc(sizeof(*node));
	if(node) {
		node->data=data;
		node->next=next;
	}
	return node;
}

List_Node *List_AddFirst(List_Node **head,void *data) {
	return *head=List_NodeNew(data,*head);
}

List_Node *List_AddLast(List_Node **head,void *data) {
	if(!*head) {
		return List_AddFirst(head,data);
	} else {
		List_Node *iter=*head;
		while(iter->next) iter=iter->next;
		return iter->next=List_NodeNew(data,NULL);
	}
}

List_Node *List_InsertAfter(List_Node **head,void *key,void *data,int(*compareFunction)(void *lhs,void *rhs)) {
	List_Node *iter=*head;
	while(iter && compareFunction(iter->data,key)) iter=iter->next;
	if(iter) return iter->next=List_NodeNew(data,iter->next);
	return NULL;
}

List_Node *List_InsertBefore(List_Node **head,void *key,void *data,int(*compareFunction)(void *lhs,void *rhs)) {
	List_Node *prev;
	List_Node *curr;
	if(!*head) return NULL;
	if(!compareFunction((*head)->data,key)) {
		return List_AddFirst(head,data);
	}
	prev=NULL;
	curr=*head;
	while(curr && compareFunction(curr->data,key)) {
		prev=curr;
		curr=curr->next;
	}
	if(curr) return prev->next=List_NodeNew(data,curr);
	return NULL;
}

List_Node *List_Remove(List_Node **head,void *key,int(*compareFunction)(void *lhs,void *rhs)) {
	List_Node *prev;
	List_Node *curr;
	if(!*head) return NULL;
	if(!compareFunction((*head)->data,key)) {
		return *head=(*head)->next;
	}
	prev=NULL;
	curr=*head;
	while(curr && compareFunction(curr->data,key)) {
		prev=curr;
		curr=curr->next;
	}
	if(!curr) return NULL;
	prev->next=curr->next;
	return curr;
}

List_Node *List_Search(List_Node **head,void *key,int(*compareFunction)(void *lhs,void *rhs)) {
	List_Node *curr=*head;
	while(curr && compareFunction(curr->data,key)) {
		curr=curr->next;
	}
	return curr;
}

void List_Print(List_Node *head,void (*printFunction)(void *data)) {
	List_Node *iter=head;
	while(iter) { printFunction(iter->data); iter=iter->next; }
}

#include<stdlib.h>
#include "list.h"

List_Node *List_NodeNew() {
	List_Node *node=malloc(sizeof(*node));
	if(node) {
		node->data=NULL;
		node->next=NULL;
	}
	return node;
}

void List_Push(List_Node **head,void *data) {
  List_Node *node=List_NodeNew();
  node->data=data;
  node->next=*head;
  *head=node;
}

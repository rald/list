#include<stdlib.h>
#include<stdio.h>

#include "list.h"

int compareFunction(void *lhs,void *rhs) {
	return (*(int*)rhs)-(*(int*)lhs);
}

void printFunction(void *data) {
	printf("%d ",*(int*)data);
}

int main(int argc,char **argv) {
	List_Node *head=NULL;
	int i;

	for(i=0;i<10;i++) {
		int *j=malloc(sizeof(*j));
		*j=i;
		List_AddLast(&head,(void*)j);
	}
	
	List_Print(head,printFunction);
	printf("\n");

	int *key=malloc(sizeof(*key));
	*key=1;
	if(!List_Remove(&head,key,compareFunction)) {
		printf("key not found\n");
	};
		
	List_Print(head,printFunction);
	printf("\n");

	return 0;
}

#include<stdlib.h>
#include<stdio.h>

#include "list.h"

int main(int argc,char **argv) {
	List_Node *head=NULL,*iter=NULL;
	int i;

	for(i=0;i<10;i++) {
		int *j=malloc(sizeof(*j));
		*j=i;
		List_Push(&head,(void*)j);
	}

	iter=head;
	while(iter) {
		printf("%d ",*(int*)iter->data);
		iter=iter->next ;
	}

	return 0;
}

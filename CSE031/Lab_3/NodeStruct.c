
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
    printf("%d %p %p %p %p\n", head, &head, &head->iValue, &head->fValue, &head->next);
	// Insert code here
    printf("%d\n", head);
	
	return 0;
}
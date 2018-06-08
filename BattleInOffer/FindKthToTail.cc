
// FindKthToTail.cc

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	
	int i;

	if(NULL == pListHead){
		printf("null pointer transfered . \n");
		return nullptr;
	}

	if(k <= 0){
		printf("argument error , k value invalid . \n");
		return nullptr;
	}

	ListNode* pAhead = pListNode;
	ListNode* pBehind = nullptr;

	for(i = 0; i < k-1; i++){
		if(NULL == pAhead){
			printf("argument error, k exceeds list length . \n");
		}
		pAhead = pAhead->next;
	}

	pBehind = pListHead;

	while(pAhead->next != NULL){
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	
	return pBehind;
}
























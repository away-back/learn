#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#define Len sizeof(struct DuLNode)
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    *L=(DuLinkedList)malloc(Len);
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
  DuLinkedList p,q;
   p=(*L)->next;
   while(p)
   {
   	q=p->next;
   	free(p);
   	p=q;
   }
   *L=NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
     if(q==NULL)  return ERROR;
     DuLNode *v=p->prior;
     q->next=p;
     p->prior=q;
     v->next=q;
     q->prior=v;
     return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
     if(q==NULL)  return ERROR;
     q->next=p->next;
     p->next=q;
     q->prior=p;
     q->next->prior=p->next;
     return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL||p->next==NULL)  return ERROR; 
    DuLNode  *v=p->next;
    *e=v->data;
    if(p->next->next==NULL)
      p->next=NULL;
    else
    p->next=v->next;
    v->next->prior=p;
    free(v);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    if(!L) return ;
	 DuLinkedList v=L;
	 while(v)
	 {
	 	visit(v->data);
	 	v=v->next;
	 }
}






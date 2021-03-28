#include"linkedList.h"
#include<stdlib.h>
#include<stdio.h>
#define Len sizeof(struct LNode)
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList*L) 
{
    *L=(LinkedList)malloc(Len);
	if(!(*L))
	   return ERROR;
	(*L)->next=NULL;
	 return SUCCESS;
	
}
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
   LinkedList p,q;
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{
if(q!=NULL)
  {
   LinkedList t;
   t=p->next;
   p->next=q;
   q->next=t;
   return SUCCESS;
   }
else return ERROR;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e)
{
   if((p->next)!=NULL)
  {
   LNode *t;
   t=p->next; 
   p->next=t->next;
   *e=t->data;
   free(t);
   return SUCCESS;
  }
  else ERROR;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	int i=1;
     while(L!=NULL)
    {
    	(*visit)(L->data);
    	L=L->next;
    	i++;
	}
	return ;
} 

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
   	int i=0;
     while((L->next)!=NULL&&L->data!=e)
    {   i++;
    	L=L->next;
    	
	}
	if(L->data==e)
	 return SUCCESS;
	else
	 return ERROR;
   
}


/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LNode *Cur = NULL, *Pre = NULL, *Next = NULL;
 
	Pre = *L;
	Cur = (*L)->next;
	Next = Cur->next;
 
	//	反转第一个节点
	Cur->next = Pre;
	Pre = Cur;
	Cur = Next;
    (*L)->next = NULL;
	while( NULL != Cur )
	{
		Next = Cur->next;
		Cur->next = Pre;
		Pre = Cur;
		Cur = Next;
   }
   *L=Pre;

}



/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList t,p;
	t=L;
	p=L->next;
   while(t!=p&&p!=NULL)
   {
   	t=t->next;
   	p=p->next->next;
   }
   if(p==NULL)  return ERROR;
   else         return SUCCESS;
}


/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) 
{
   
	LNode* p = (LinkedList)malloc(Len);
    p->next = *L;
    LNode* t;
    LNode* p1;
    LNode* p2;
    LNode* temp1;
    LNode* temp2 = p;
    t=*L;
    while(t->next != NULL) {
        p1 = t;
        p2 = t->next;
        temp1 = p2->next;
        p2->next = p1;
        p1->next = temp1;
        temp2->next = p2;
        temp2 = temp2->next->next;
        t = temp1;
    }
    return p->next;

    
	
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList fast,slow;
	fast=*L;
	slow=*L;
	while(fast!=NULL&&fast->next!=NULL)
	{   
	    fast = fast->next ->next ;
		slow = slow->next;
	}
	   return slow;
}





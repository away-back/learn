#include <stdio.h>
#include <stdlib.h>
#include"dulinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


	 void face()
 {
 	printf("--------选择链表功能--------\n");
	printf("--1.消去一个链表\n");
	printf("--2.在节点p之前插入新节点q并赋值\n");
	printf("--3.在节点p之后插入新节点q并赋值\n");
	printf("--4.删除节点p之后的第一个节点，并将其值赋给e\n");	
    printf("--5.遍历链表并调用函数访问\n");
    printf("--0.退出程序\n");
	printf("-------------------------------------\n");
 }
 void push(ElemType e)
 {
    printf("%d->",e);
 }

 int main()
 {  int i,c=100,d,e;
    char str[100];
    char a;
    DuLinkedList head,p,t,v;
    while(1)
	{
	system("cls");
    printf("-------------操作选项-----------\n");
    printf("0:退出程序 \n");
    printf("1:执行操作建立双向链表 \n");
    printf("--------------------------------\n");
    printf("输入选择：");
    scanf("%s",str);
    a=str[0];
    switch(a)
    {
    	case '0': c=0;break;
    	case '1': c=1;break;
    	defaut: break;
	}
	if(c==0||c==1) break;
	printf("错误\n");
    system("pause");
   }
	if(c==0) return;
    system("cls");
	printf("输入链表长度(输入非数字程序将会终止)");
	scanf("%d",&e);
	InitList_DuL(&head);
	t=head;
	v=head;
	for(i=1;i<e;i++)
	{
		InitList_DuL(&p);
     	t->next=p;
	    p->prior=t;
	    t=p;
	}
	p->next=NULL;
	head->prior=NULL;
	i=0;
	while(v!=NULL)
	  {
	  	system("cls");
        printf("输入链表数据(输入非数字程序将会终止)");
		scanf("%d",&v->data);
	  	v=v->next;
	  }
	printf("当前链表：");
	TraverseList_DuL(head, push);
	printf("\n"); 
	system("pause");
	system("cls");
	while(1){
	system("cls");
	face();
	printf("输入选择："); 
	scanf("%s",str);
    a=str[0];
    switch(a)
    {
    	case '0':  c=0; break;
    	case '1':{
    		system("cls");
    		DestroyList_DuL(&head);
    		if(head==NULL) 
    		printf("删除成功\n"); 
    		system("pause");
			break;
		}
    	case '2': {
    		system("cls");
    		int x;
    		DuLinkedList p=head,q;
    		printf("当前链表：");
	        TraverseList_DuL(head, push); 
	        printf("\n");
    		printf("选择第几个为p节点");
			scanf("%d",&x);
			while(x>e||x<=0)
			{
			printf("错误，重新选择");
			system("pause");
			printf("当前链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
			printf("选择第几个为p节点");
			scanf("%d",&x);
			}
		    for(i=1;i<x;i++)
		    {
		    	p=p->next;
			}
			InitList_DuL(&q);
			printf("对新节点q赋值");
			scanf("%d",&q->data);
			printf("旧链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
			InsertBeforeList_DuL(p,q);
			printf("新链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
	        system("pause");
			e++;
			break;
			
		}
    	case '3': {
    		system("cls");
    		int x;
    		DuLinkedList p=head,q;
    		printf("当前链表：");
	        TraverseList_DuL(head, push);
			printf("\n"); 
    		printf("选择第几个为p节点");
			scanf("%d",&x);
			while(x>e||x<=0)
			{
			system("cls");
			printf("错误，重新选择");
			printf("\n");
			system("pause");
			printf("当前链表：");
	        TraverseList_DuL(head, push);
			printf("\n"); 
			printf("选择第几个为p节点");
			scanf("%d",&x);
			}
		    for(i=1;i<x;i++)
		    {
		    	p=p->next;
			}
			InitList_DuL(&q);
			printf("对新节点q赋值");
			scanf("%d",&q->data);
			printf("旧链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
			InsertAfterList_DuL(p,q);
			printf("新链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
	        system("pause");
	        e++;
			break;
		}
    	case '4': {
    		system("cls");
    		int x,num=0;
    		int *s=&num;
    		DuLinkedList h=head,q;
    		printf("当前链表：");
	        TraverseList_DuL(head, push); 
    		printf("选择第几个为p节点");
			scanf("%d",&x);
			while(x>e||x<=0)
			{
			printf("错误，重新选择");
			system("pause");
			printf("当前链表：");
	        TraverseList_DuL(head, push); 
			printf("选择第几个为p节点");
			scanf("%d",&x);
			}
		    for(i=1;i<x;i++)
		    {
		    	h=h->next;
			}
			printf("旧链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
		    DeleteList_DuL(h,  s);
			printf("新链表：");
	        TraverseList_DuL(head, push);
	        printf("\n");
	        printf("e的值：%d",num);
	        printf("\n");
	        system("pause");
	        if(x<e&&x>=0)
	        e--;
		    break;
		}
    	case '5': {
    		system("cls");
    		printf("当前链表：");
	        TraverseList_DuL(head, push);
			printf("\n"); 
	        system("pause");
			break;
		}
    	default: break;
	}
	if(c==0) break;
	 
    }	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
  } 

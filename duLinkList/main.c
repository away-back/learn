#include <stdio.h>
#include <stdlib.h>
#include"dulinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


	 void face()
 {
 	printf("--------ѡ��������--------\n");
	printf("--1.��ȥһ������\n");
	printf("--2.�ڽڵ�p֮ǰ�����½ڵ�q����ֵ\n");
	printf("--3.�ڽڵ�p֮������½ڵ�q����ֵ\n");
	printf("--4.ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e\n");	
    printf("--5.�����������ú�������\n");
    printf("--0.�˳�����\n");
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
    printf("-------------����ѡ��-----------\n");
    printf("0:�˳����� \n");
    printf("1:ִ�в�������˫������ \n");
    printf("--------------------------------\n");
    printf("����ѡ��");
    scanf("%s",str);
    a=str[0];
    switch(a)
    {
    	case '0': c=0;break;
    	case '1': c=1;break;
    	defaut: break;
	}
	if(c==0||c==1) break;
	printf("����\n");
    system("pause");
   }
	if(c==0) return;
    system("cls");
	printf("����������(��������ֳ��򽫻���ֹ)");
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
        printf("������������(��������ֳ��򽫻���ֹ)");
		scanf("%d",&v->data);
	  	v=v->next;
	  }
	printf("��ǰ����");
	TraverseList_DuL(head, push);
	printf("\n"); 
	system("pause");
	system("cls");
	while(1){
	system("cls");
	face();
	printf("����ѡ��"); 
	scanf("%s",str);
    a=str[0];
    switch(a)
    {
    	case '0':  c=0; break;
    	case '1':{
    		system("cls");
    		DestroyList_DuL(&head);
    		if(head==NULL) 
    		printf("ɾ���ɹ�\n"); 
    		system("pause");
			break;
		}
    	case '2': {
    		system("cls");
    		int x;
    		DuLinkedList p=head,q;
    		printf("��ǰ����");
	        TraverseList_DuL(head, push); 
	        printf("\n");
    		printf("ѡ��ڼ���Ϊp�ڵ�");
			scanf("%d",&x);
			while(x>e||x<=0)
			{
			printf("��������ѡ��");
			system("pause");
			printf("��ǰ����");
	        TraverseList_DuL(head, push);
	        printf("\n");
			printf("ѡ��ڼ���Ϊp�ڵ�");
			scanf("%d",&x);
			}
		    for(i=1;i<x;i++)
		    {
		    	p=p->next;
			}
			InitList_DuL(&q);
			printf("���½ڵ�q��ֵ");
			scanf("%d",&q->data);
			printf("������");
	        TraverseList_DuL(head, push);
	        printf("\n");
			InsertBeforeList_DuL(p,q);
			printf("������");
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
    		printf("��ǰ����");
	        TraverseList_DuL(head, push);
			printf("\n"); 
    		printf("ѡ��ڼ���Ϊp�ڵ�");
			scanf("%d",&x);
			while(x>e||x<=0)
			{
			system("cls");
			printf("��������ѡ��");
			printf("\n");
			system("pause");
			printf("��ǰ����");
	        TraverseList_DuL(head, push);
			printf("\n"); 
			printf("ѡ��ڼ���Ϊp�ڵ�");
			scanf("%d",&x);
			}
		    for(i=1;i<x;i++)
		    {
		    	p=p->next;
			}
			InitList_DuL(&q);
			printf("���½ڵ�q��ֵ");
			scanf("%d",&q->data);
			printf("������");
	        TraverseList_DuL(head, push);
	        printf("\n");
			InsertAfterList_DuL(p,q);
			printf("������");
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
    		printf("��ǰ����");
	        TraverseList_DuL(head, push); 
    		printf("ѡ��ڼ���Ϊp�ڵ�");
			scanf("%d",&x);
			while(x>e||x<=0)
			{
			printf("��������ѡ��");
			system("pause");
			printf("��ǰ����");
	        TraverseList_DuL(head, push); 
			printf("ѡ��ڼ���Ϊp�ڵ�");
			scanf("%d",&x);
			}
		    for(i=1;i<x;i++)
		    {
		    	h=h->next;
			}
			printf("������");
	        TraverseList_DuL(head, push);
	        printf("\n");
		    DeleteList_DuL(h,  s);
			printf("������");
	        TraverseList_DuL(head, push);
	        printf("\n");
	        printf("e��ֵ��%d",num);
	        printf("\n");
	        system("pause");
	        if(x<e&&x>=0)
	        e--;
		    break;
		}
    	case '5': {
    		system("cls");
    		printf("��ǰ����");
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

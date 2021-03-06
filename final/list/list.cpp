#include "list.h"
//#include<stdio.h>
#include <iostream>
using namespace std;

//创建链表,仅有头结点
List* CreateList()
{
	List* p = new List;
	EleType data = (EleType)0;
	p->head = NewChainNode(data);
	if(NULL != p && NULL !=p->head) 
	{
		p->head->data = data;
		p->head->next = NULL;
		return p;
	}
	cout<<"分配内存失败"<<endl;
	return NULL;
}
	

//删除链表
void DestoryLIst(List* lp)
{
	if(NULL != lp)
	{
		ClearList(lp);
		delete lp;
	}
}	

//清空链表
void ClearList(List* lp)
{
	if(NULL != lp)
	{
		while(ListDelete(lp, 1) );
	}
	
}

//追加元素，成功返回1,失败返回0
int ListAppend(List* lp, EleType ele)
{
	ChainNode* p=NULL;
	ChainNode* newp= NewChainNode(ele);
	if(NULL != lp && NULL != newp)
	{
		for(p=lp->head; p->next; p=p->next);
		p->next = newp;	
		return 1;
	}
	return 0;
}	

//插入元素，在第n个元素位置插入元素
int ListInsert(List* lp, int n, EleType ele)
{
	ChainNode* p=NULL;
	ChainNode* newp= NewChainNode(ele);

	if(NULL != lp && NULL != newp)
	{
		p = GetAddr(lp, n-1);	//第 n 个元素编号为 n-1
		newp->next = p->next;
		p->next = newp;
		return 1;
	}
	return 0;
}	

//删除元素，删除第 n 个元素
int ListDelete(List* lp, int n)
{
	ChainNode* temp = NULL;
	if(NULL != lp && NULL != lp->head->next)
	{
		temp = GetAddr(lp, n-1);	//第 n 个元素编号为 n-1
		if(NULL != temp && NULL != temp->next)
		{
			ChainNode* pt = temp->next;
			temp->next = pt->next;
			delete pt;	// 增加内存释放，2017.11.27 
			return 1;
		}
	}
	return 0;
}

//取元素
int GetElememt(List* lp, int n, EleType * ele)
{
	ChainNode* p = NULL;
	if(NULL != lp && NULL != lp->head->next)
	{
		p =GetAddr(lp, n-1);
		if(NULL != p)
		{
			*ele = p->data;
			return 1;
		}
	}
	return 0;
}

//取元素地址，取编号为 n 的元素的地址。
ChainNode* GetAddr(List* lp,int n )
{
	if(n >= 0)
	{
		ChainNode* p = lp->head;
		if(NULL != lp && NULL != p->next)
		{
			int i = 0;
			while(NULL !=p && i<n)
			{
				p = p->next;
				i++;
			}
			return p;
		}
	}
	cout<<"n应该大于等于1"<<endl;
	return NULL;
}

//创建一个元素节点
ChainNode* NewChainNode(EleType ele)
{
	ChainNode* p =new ChainNode;
	if(p != NULL)
	{
		p->data = ele;
		p->next = NULL;
		
	}
	return p;
}

/*遍历元素，遍历所有元素，并通过函数指针对元素进行处理，遍历完所有元素返回0 ，否则返回当前元素编号。
 *链表为空，返回-1
 */
int TraverseList(List* lp, int (*f) (EleType *) )	
{	
	if(NULL != lp)
	{
		ChainNode* p = lp->head->next;
		int i =0;
		for( ; NULL != p; p= p->next)
		{
			if( !f(&(p->data)) )
			{
				return i+1;
			}
			i++;
		}
		return 0;

	}
	return -1;
}

void ShowList(List* lp)
{
	TraverseList(lp, PrintElement);
	cout<<endl;
}

int PrintElement(EleType *data)
{
	cout<<" "<<*data;
	return 1;
}
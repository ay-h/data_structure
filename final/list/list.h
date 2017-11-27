#ifndef  __LIST_H_
#define  __LIST_H_

typedef char EleType;	//定义链表存储的数据类型 

//链表节点结构
typedef struct node
{
	EleType data;
	struct node * next;
}ChainNode;

//头结点，把头结点独立出来，方便修改第一个元素
typedef struct {
	ChainNode* head;
} List;


List* CreateList();		//创建链表
void DestoryLIst(List* );		//删除链表
void ClearList(List* );
int ListAppend(List*, EleType);		//追加元素
int ListInsert(List*, int, EleType);	//插入元素
int ListDelete(List*, int);		//删除元素
int GetElememt(List*, int, EleType *);	//取元素
ChainNode* GetAddr(List*,int );		//取元素地址
ChainNode* NewChainNode(EleType);	//创建一个元素节点
int TraverseList(List*, int(*) (EleType*) );	//遍历元素
void ShowList(List*);	//显示链表
int PrintElement(EleType *);	//输出元素
#endif
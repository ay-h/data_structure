
#ifndef __LINE_LIST_H__
#define __LINE_LIST_H__


typedef int EleType;

typedef struct {
	EleType* pData;	//定义成指针，可以存放任意类型
	unsigned int num;
	unsigned int maxlength;   //线性表最大长度
	
}List;

List* CreateList(const int );	//创建线性表
void DestoryList(List*);	//删除线性表
void ClearList(List*);	//清空线性表
int ListAppend(List*, EleType);	 // 追加元素
int IsEmpty(List *);	//判空
int IsFull(List *);		//判满
int ListDelete(List *,int);	//删除元素
int GetElement(List *,int,EleType *);	// 取元素
int ListInsert(List *,int ,EleType);   //插入元素
int TraverseList(List *,int (*)(EleType ));  //遍历线性表
void ShowList(List*);	//显示线性表
int PrintElement(EleType );	//输出元素

#endif
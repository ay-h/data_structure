
#include <stdio.h>
#include "line_list.h"

void ShowList(List*);	//显示线性表
int PrintElement(EleType* );	//输出元素

int main()
{
	int i;
	EleType ele;

	//创建线性表
	List* ls = CreateList(100);		
	if (NULL == ls)
	{
		printf("创建线性表失败\n");
		return 0;
	}
	
	//测试判空函数
	i =IsEmpty(ls);		
	if(i)
	{
		printf("线性表为空\n");
	}



	for (i=0;i<100;i++)
	{
		ListAppend(ls,i+1);
	}
	ShowList(ls);

	//测试判满函数
	i =IsFull(ls);
	if(i)
	{
		printf("线性表已满\n");
	}

	//测试取元素
	GetElement(ls,3,&ele);
	printf(" ele = %d\n",ele);

	//测试插入
	ListInsert(ls,5,23);
	ShowList(ls);
	ListInsert(ls,1,23);
	ShowList(ls);
	
	//测试删除
	ListDelete(ls,1);
	ShowList(ls);

	ListDelete(ls,5);
	ShowList(ls);



	return 1;
}


//显示线性表
void ShowList(List* ls)
{
	TraverseList(ls,PrintElement);
	printf("\n");
}

//输出元素
int PrintElement(EleType* ele)
{
	printf("%d ",*ele);
	return 1;
}
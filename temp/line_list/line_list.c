#include <stdio.h>
#include <stdlib.h>
#include "line_list.h"

//创建线性表
List* CreateList(const int maxlength)
{
	List* ls = (List*)malloc(sizeof(List));
	if(NULL != ls)
	{
		ls->pData = (EleType*)malloc((maxlength + 1)*sizeof(EleType));
		if(NULL != ls->pData)
		{
			ls->maxlength = maxlength;
			ls->num = 0;
			return ls;
		}
	}
	printf("out of place.\n");
	return NULL;
}

//删除线性表
void DestoryList(List* ls)
{
	free(ls->pData);
	free(ls);
}

	//清空线性表
void ClearList(List* ls)
{
	ls->num = 0;
}



//判空,为空返回1
int IsEmpty(List* ls)
{
	return (0 == ls->num);
}


//判满
int IsFull(List* ls)
{
	return (ls->num == ls->maxlength);
}


// 追加元素
int ListAppend(List* ls, EleType ele)
{
	if(!IsEmpty(ls))
	{
		ls->pData[ls->num++] = ele;	//注意这里
		return 1;
	}
	return 0;
}

//删除元素
int ListDelete(List* ls, int n)
{
	if (!IsEmpty(ls))
	{
		if (n<1 || n>ls->num)
		{
			printf("n输入错误");
			return 0;
		}

		for( ;n<ls->num;n++ )
		{
			ls->pData[n] = ls->pData[n+1];
			ls->num--;
			return 1;
		}
	}
	return 0;
}


// 取元素
int GetElement(List* ls, int n, EleType * ele)
{
	if(!IsEmpty(ls))
	{
		if(n<1 || n>ls->maxlength)
		{
			printf("n输入错误");
			return 0;
		}
		*ele = ls->pData[n];
		return 1;
	}
	return 0;
}

 //插入元素
int ListInsert(List* ls, int n, EleType ele)
{
	int i=0;
	if(!IsFull(ls))
	{
		if(n<1 || n>ls->num+1)
		{
			printf("n输入错误");
			return 0;
		}

		for(i=ls->num; i>=n;i--)
		{
			ls->pData[i+1] = ls->pData[i];
			ls->pData[i] = ele;
			ls->num++;
			return 1;
		}
	}
	return 0;
}

//遍历线性表
int TraverseList(List* ls, int (*f)(EleType ))
{
	int i=0;
	if (!IsEmpty(ls))
	{
		for (i=1;i<ls->num;i++)
		{
			if(!f(ls->pData[i]))
				return i+1;
		}
		return 0;
	}
	return -1;
}

//显示线性表
void ShowList(List* ls)
{
	TraverseList(ls,PrintElement);
}

//输出元素
int PrintElement(EleType ele)
{
	printf("%d ",ele);
	return 1;
}
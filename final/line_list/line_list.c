#include <stdio.h>
#include <stdlib.h>
#include "line_list.h"


//创建线性表， maxlength为线性表最大长度
List* CreateList(const int maxlength)
{
	List* ls = (List*)malloc(sizeof(List));
	if(NULL != ls)
	{
		ls->pData = (EleType*)malloc((maxlength )*sizeof(EleType));
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



//判空,，线性表为空返回 1 ，否则返回 0
int IsEmpty(List* ls)
{
	return (0 == ls->num);
}


//判满，线性表已满返回 1 ，否则返回 0
int IsFull(List* ls)
{
	return (ls->num == ls->maxlength);
}


// 在末尾追加元素，成功返回1，失败返回0
int ListAppend(List* ls, EleType ele)
{
	if(!IsFull(ls))
	{
		ls->pData[ls->num++] = ele;	//注意这里
		return 1;
	}
	return 0;
}

//删除元素，删除编号为 n 的元素，编号为 n 的元素，索引为 n-1，成功返回1，失败返回0
int ListDelete(List* ls, unsigned int n)
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
			ls->pData[n-1] = ls->pData[n];			
		}
		ls->num--;
		return 1;
	}
	return 0;
}


// 取元素编号为 n 的元素，索引为 n-1，成功返回1，失败返回0
int GetElement(List* ls,unsigned int n, EleType * ele)
{
	if(!IsEmpty(ls))
	{
		if(n<1 || n>ls->maxlength)
		{
			printf("n输入错误");
			return 0;
		}
		*ele = ls->pData[n-1];
		return 1;
	}
	return 0;
}

 //插入元素，在位置 n 插入元素，编号为 n 的元素，索引为 n-1，成功返回1，失败返回0
int ListInsert(List* ls,unsigned int n, EleType ele)
{
	unsigned int i=0;
	if(!IsFull(ls))
	{
		if(n<1 || n>ls->num)
		{
			printf("n输入错误");
			return 0;
		}

		for(i=ls->num; i>=n;i--)
		{
			ls->pData[i] = ls->pData[i-1];			
		}

		ls->pData[n-1] = ele;
		ls->num++;
		return 1;
	}
	return 0;
}

//遍历线性表，遍历线性表，并对元素进行操作，遍历完成返回 -1，否则返回当前元素编号。
int TraverseList(List* ls, int (*f)(EleType* ))
{
	unsigned int i=0;
	if (!IsEmpty(ls))
	{
		for (i=0;i<ls->num;i++)
		{
			if(!f(&ls->pData[i]))
				return i+1;
		}
		return 0;
	}
	return -1;
}


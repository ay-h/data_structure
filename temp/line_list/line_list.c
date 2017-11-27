#include <stdio.h>
#include <stdlib.h>
#include "line_list.h"

//�������Ա�
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

//ɾ�����Ա�
void DestoryList(List* ls)
{
	free(ls->pData);
	free(ls);
}

	//������Ա�
void ClearList(List* ls)
{
	ls->num = 0;
}



//�п�,Ϊ�շ���1
int IsEmpty(List* ls)
{
	return (0 == ls->num);
}


//����
int IsFull(List* ls)
{
	return (ls->num == ls->maxlength);
}


// ׷��Ԫ��
int ListAppend(List* ls, EleType ele)
{
	if(!IsEmpty(ls))
	{
		ls->pData[ls->num++] = ele;	//ע������
		return 1;
	}
	return 0;
}

//ɾ��Ԫ��
int ListDelete(List* ls, int n)
{
	if (!IsEmpty(ls))
	{
		if (n<1 || n>ls->num)
		{
			printf("n�������");
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


// ȡԪ��
int GetElement(List* ls, int n, EleType * ele)
{
	if(!IsEmpty(ls))
	{
		if(n<1 || n>ls->maxlength)
		{
			printf("n�������");
			return 0;
		}
		*ele = ls->pData[n];
		return 1;
	}
	return 0;
}

 //����Ԫ��
int ListInsert(List* ls, int n, EleType ele)
{
	int i=0;
	if(!IsFull(ls))
	{
		if(n<1 || n>ls->num+1)
		{
			printf("n�������");
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

//�������Ա�
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

//��ʾ���Ա�
void ShowList(List* ls)
{
	TraverseList(ls,PrintElement);
}

//���Ԫ��
int PrintElement(EleType ele)
{
	printf("%d ",ele);
	return 1;
}
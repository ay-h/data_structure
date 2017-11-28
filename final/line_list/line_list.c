#include <stdio.h>
#include <stdlib.h>
#include "line_list.h"


//�������Ա� maxlengthΪ���Ա���󳤶�
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



//�п�,�����Ա�Ϊ�շ��� 1 �����򷵻� 0
int IsEmpty(List* ls)
{
	return (0 == ls->num);
}


//���������Ա��������� 1 �����򷵻� 0
int IsFull(List* ls)
{
	return (ls->num == ls->maxlength);
}


// ��ĩβ׷��Ԫ�أ��ɹ�����1��ʧ�ܷ���0
int ListAppend(List* ls, EleType ele)
{
	if(!IsFull(ls))
	{
		ls->pData[ls->num++] = ele;	//ע������
		return 1;
	}
	return 0;
}

//ɾ��Ԫ�أ�ɾ�����Ϊ n ��Ԫ�أ����Ϊ n ��Ԫ�أ�����Ϊ n-1���ɹ�����1��ʧ�ܷ���0
int ListDelete(List* ls, unsigned int n)
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
			ls->pData[n-1] = ls->pData[n];			
		}
		ls->num--;
		return 1;
	}
	return 0;
}


// ȡԪ�ر��Ϊ n ��Ԫ�أ�����Ϊ n-1���ɹ�����1��ʧ�ܷ���0
int GetElement(List* ls,unsigned int n, EleType * ele)
{
	if(!IsEmpty(ls))
	{
		if(n<1 || n>ls->maxlength)
		{
			printf("n�������");
			return 0;
		}
		*ele = ls->pData[n-1];
		return 1;
	}
	return 0;
}

 //����Ԫ�أ���λ�� n ����Ԫ�أ����Ϊ n ��Ԫ�أ�����Ϊ n-1���ɹ�����1��ʧ�ܷ���0
int ListInsert(List* ls,unsigned int n, EleType ele)
{
	unsigned int i=0;
	if(!IsFull(ls))
	{
		if(n<1 || n>ls->num)
		{
			printf("n�������");
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

//�������Ա��������Ա�����Ԫ�ؽ��в�����������ɷ��� -1�����򷵻ص�ǰԪ�ر�š�
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


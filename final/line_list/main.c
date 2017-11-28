
#include <stdio.h>
#include "line_list.h"

void ShowList(List*);	//��ʾ���Ա�
int PrintElement(EleType* );	//���Ԫ��

int main()
{
	int i;
	EleType ele;

	//�������Ա�
	List* ls = CreateList(100);		
	if (NULL == ls)
	{
		printf("�������Ա�ʧ��\n");
		return 0;
	}
	
	//�����пպ���
	i =IsEmpty(ls);		
	if(i)
	{
		printf("���Ա�Ϊ��\n");
	}



	for (i=0;i<100;i++)
	{
		ListAppend(ls,i+1);
	}
	ShowList(ls);

	//������������
	i =IsFull(ls);
	if(i)
	{
		printf("���Ա�����\n");
	}

	//����ȡԪ��
	GetElement(ls,3,&ele);
	printf(" ele = %d\n",ele);

	//���Բ���
	ListInsert(ls,5,23);
	ShowList(ls);
	ListInsert(ls,1,23);
	ShowList(ls);
	
	//����ɾ��
	ListDelete(ls,1);
	ShowList(ls);

	ListDelete(ls,5);
	ShowList(ls);



	return 1;
}


//��ʾ���Ա�
void ShowList(List* ls)
{
	TraverseList(ls,PrintElement);
	printf("\n");
}

//���Ԫ��
int PrintElement(EleType* ele)
{
	printf("%d ",*ele);
	return 1;
}
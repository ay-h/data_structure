#include "list.h"
#include <iostream>
using namespace std;

int main()
{
	char arr[20] ="hello world";

	List* lp = CreateList();
	if(NULL ==lp ) return 0;
	// ������׷��Ԫ��
	for(int i = 0; arr[i]; i++)
	{
		ListAppend(lp,arr[i]);
	}
	ShowList(lp);	//��ʾ����

	ListAppend(lp,'o');
	ListAppend(lp,'v');
	ListAppend(lp,'e');
	ListAppend(lp,'r');
	ShowList(lp);

	ListInsert(lp,1,'a');	//�ڵ�һ��Ԫ��λ�ò���Ԫ��
	ListInsert(lp,2,'b');
	ShowList(lp);

	ListDelete(lp,1);	//ɾ����һ��Ԫ��
	ShowList(lp);
	ListDelete(lp,1);
	ShowList(lp);
	ListDelete(lp,2);
	ShowList(lp);



	return 0;
}
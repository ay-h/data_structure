#include "list.h"
#include <iostream>
using namespace std;

int main()
{
	char arr[20] ="hello world";

	List* lp = CreateList();
	if(NULL ==lp ) return 0;
	// 给链表追加元素
	for(int i = 0; arr[i]; i++)
	{
		ListAppend(lp,arr[i]);
	}
	ShowList(lp);	//显示链表

	ListAppend(lp,'o');
	ListAppend(lp,'v');
	ListAppend(lp,'e');
	ListAppend(lp,'r');
	ShowList(lp);

	ListInsert(lp,1,'a');	//在第一个元素位置插入元素
	ListInsert(lp,2,'b');
	ShowList(lp);

	ListDelete(lp,1);	//删除第一个元素
	ShowList(lp);
	ListDelete(lp,1);
	ShowList(lp);
	ListDelete(lp,2);
	ShowList(lp);



	return 0;
}
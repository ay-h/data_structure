#include "list.h"
#include <iostream>
using namespace std;

int main()
{
	char arr[20] ="hello world";

	List* lp = CreateList();
	if(NULL ==lp ) return 0;
	for(int i = 0; arr[i]; i++)
	{
		ListAppend(lp,arr[i]);
	}
	ShowList(lp);

	ListAppend(lp,'o');
	ListAppend(lp,'v');
	ListAppend(lp,'r');
	ListAppend(lp,'y');
	ShowList(lp);

	ListInsert(lp,1,'a');
	ListInsert(lp,2,'b');
	ShowList(lp);

	ListDelete(lp,1);
	ShowList(lp);
	ListDelete(lp,1);
	ShowList(lp);



	return 0;
}
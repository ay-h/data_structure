#include <stdio.h>
#include "stack.h"

int main()
{
	//���Դ���ջ����
	Stack* stack = CreateStack();
	printf("StackTopElement =  %d \n",GetTopElement(stack));

	//������ջ����
	PushStack(stack,5);	
	printf("StackTopElement =  %d \n",GetTopElement(stack));

	PushStack(stack,6);
	printf("StackTopElement =  %d \n",GetTopElement(stack));

	PushStack(stack,7);
	printf("StackTopElement =  %d \n",GetTopElement(stack));

	//���Գ�ջ����
	PopStack(stack);
	printf("StackTopElement =  %d \n",GetTopElement(stack));
	PopStack(stack);
	printf("StackTopElement =  %d \n",GetTopElement(stack));

	//�������ջ����
	StackEmpty(stack);
	printf("StackTopElement =  %d \n",GetTopElement(stack));

	//���Գ���ջ����
	DestoryStack(stack);

	return 0;
}

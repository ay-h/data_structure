/*
	һ����������ʵ�ֵ�ջ�ļ����ӣ�û���������������̶����ȵ����ơ����⣬���������Ҳ��ʵ��ջ��
	��������ʾջ�Ƚ������ԭ����һ��Ԫ�ش洢�� stack->next ��

*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//����ջ����ʱջ��û���κ�Ԫ��
Stack* CreateStack()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	if(NULL != stack)
	{
	   stack->next = NULL;
	   return stack;
	}
	printf("out of place.\n");
	return NULL;
}

//���ջ
void StackEmpty(Stack* stack)
{
	while(!IsEmpty(stack))
	{
		PopStack(stack);
	}
	printf("now stack is empty. \n");
}

//����ջ
void DestoryStack(Stack* stack)
{
	free(stack);
	printf("now stack is destoryed. \n");
	exit(0);
}

int IsEmpty(Stack* stack)
{
	return (stack->next == 0);
}

//��ջ���ɹ�����1��ʧ�ܷ���0�� ��Ԫ�� data ���� ջ stack ��
int PushStack(Stack* stack, DataType data)
{
	Stack* newst = (Stack*)malloc(sizeof(Stack));
	if(NULL != newst)
	{
		newst->data = data;
		newst->next = stack->next;	//s->next = NULL;
		stack->next = newst;
		return 1;
	}
	printf("out of place PushStack.\n");
	return 0;
}

/*
	��ջ���ɹ�����1��ʧ�ܷ���0����ջ��ȡ��Ԫ��ֵ��ֻ��ɾ��ջ��Ԫ�ء�
	���ջҪʵ�֣�ȡ��Ԫ��ֵ�����ͷſռ䣬�ɽ��ȡջ��Ԫ�غ������޸ģ����ﲻ�ٸ�����
 */

int PopStack(Stack* stack)
{
	Stack* tmpst;
	if(!IsEmpty(stack))
	{
		tmpst = stack->next;
		stack->next = tmpst->next;
		free(tmpst);
		return 1;
	}
	return 0;
}

//ȡջ��Ԫ�أ���ȡ��ջ��Ԫ�ص�ֵ��ȡ��֮�󣬸�Ԫ�أ���Ȼ����ջ�С��ɹ�����Ԫ��ֵ��ʧ�������ʾ��Ϣ�������� -1
DataType GetTopElement(Stack* stack)
{
	if(!IsEmpty(stack))
	{
		return stack->next->data;
	}
	printf("stack is empty GetTopElement.\n");
	return -1;
}
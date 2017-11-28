
#ifndef  __STACK_H__
#define  __STACK_H__

typedef int DataType;
typedef struct node{
	DataType data;
	struct node * next;
}Stack;

Stack* CreateStack();	//����ջ
void StackEmpty(Stack* );  //���ջ
void DestoryStack(Stack*); //����(ɾ��)ջ
int IsEmpty(Stack*);	//�п�
int PushStack(Stack*, DataType);	//��ջ
int PopStack(Stack*);	//��ջ
DataType GetTopElement(Stack*);	//ȡջ��Ԫ��


#endif

#ifndef __LINE_LIST_H__
#define __LINE_LIST_H__


typedef int EleType;

typedef struct {
	EleType* pData;	//�����ָ�룬���Դ����������
	unsigned int num;
	unsigned int maxlength;   //���Ա���󳤶�
	
}List;

List* CreateList(const int );	//�������Ա�
void DestoryList(List*);	//ɾ�����Ա�
void ClearList(List*);	//������Ա�
int ListAppend(List*, EleType);	 // ׷��Ԫ��
int IsEmpty(List *);	//�п�
int IsFull(List *);		//����
int ListDelete(List *,int);	//ɾ��Ԫ��
int GetElement(List *,int,EleType *);	// ȡԪ��
int ListInsert(List *,int ,EleType);   //����Ԫ��
int TraverseList(List *,int (*)(EleType ));  //�������Ա�
void ShowList(List*);	//��ʾ���Ա�
int PrintElement(EleType );	//���Ԫ��

#endif
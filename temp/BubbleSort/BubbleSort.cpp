
#include<iostream>
using namespace std;

const int BUFFSIZE = 10;
int Bubble_Sort(int Arr[]);
int Bubble_Sort_r(int Arr[]);

int main()
{
	int Arr[BUFFSIZE] = { 88,1,59,105,9,2,8,15,6,10 };  // ������Ԫ��
	Bubble_Sort(Arr);  // ����
	cout << "-------------------------" << endl;
	int Arr2[BUFFSIZE] = { 88,1,59,105,9,2,8,15,6,10 };  // ������Ԫ��
	Bubble_Sort_r(Arr2);  // ����

	
	return 0;
}


int Bubble_Sort(int Arr[])
{
	int Counts = BUFFSIZE - 1; // ����������
	for (int i = 0; i < Counts; i++)
	{
		for (int j = 0; j < Counts - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j + 1];
				Arr[j + 1] = Arr[j];
				Arr[j] = tmp;
			}
		}
		for (int i = 0; i < BUFFSIZE; i++) //ÿһ����������Ԫ��˳��
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}


int Bubble_Sort_r( int Arr[])
{
	bool SwapFlag = true;  // ��־λ����¼ÿ�������Ƿ���Ԫ��λ�ý���
	int Counts = BUFFSIZE - 1;
	for (int i = 0; i < Counts&&SwapFlag!=false; i++) // ����ϴ�����Ԫ��λ��δ�ı䣬��������ɡ�
	{
		SwapFlag = false;  // ÿ������ǰ����־λ��λ
		for (int j = 0; j < Counts - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				SwapFlag = true;  //����λ�ý�������־λ��λ
				int tmp = Arr[j + 1];
				Arr[j + 1] = Arr[j];
				Arr[j] = tmp;
			}
		}
		for (int i = 0; i < BUFFSIZE; i++)
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
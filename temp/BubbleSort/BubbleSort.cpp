
#include<iostream>
using namespace std;

const int BUFFSIZE = 10;
int Bubble_Sort(int Arr[]);
int Bubble_Sort_r(int Arr[]);

int main()
{
	int Arr[BUFFSIZE] = { 88,1,59,105,9,2,8,15,6,10 };  // 待排序元素
	Bubble_Sort(Arr);  // 排序
	cout << "-------------------------" << endl;
	int Arr2[BUFFSIZE] = { 88,1,59,105,9,2,8,15,6,10 };  // 待排序元素
	Bubble_Sort_r(Arr2);  // 排序

	
	return 0;
}


int Bubble_Sort(int Arr[])
{
	int Counts = BUFFSIZE - 1; // 排序总轮数
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
		for (int i = 0; i < BUFFSIZE; i++) //每一轮排序后输出元素顺序
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}


int Bubble_Sort_r( int Arr[])
{
	bool SwapFlag = true;  // 标志位，记录每次排序是否有元素位置交换
	int Counts = BUFFSIZE - 1;
	for (int i = 0; i < Counts&&SwapFlag!=false; i++) // 如果上次排序元素位置未改变，则排序完成。
	{
		SwapFlag = false;  // 每次排序前，标志位复位
		for (int j = 0; j < Counts - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				SwapFlag = true;  //发生位置交换，标志位置位
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
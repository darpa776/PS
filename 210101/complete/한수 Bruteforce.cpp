#include <iostream>
#include <vector>
#include <string>
using namespace std;

int number2(int N, int ret)//�ٸ������ ����
{
	int arr[3];
	if (N <= 99)
	{
		cout << N;
		return 0;
	}
	for (int j = 100; j <= N; ++j)
	{
		if (j == 1000) break;//1000�� ��� arr interrupt
		int i = j;
		int index = 0;
		while (i)
		{
			arr[index] = i % 10;
			i/= 10;
			++index;
		}
		if (arr[0]-arr[1]==arr[1]-arr[2])
			++ret;
	}

	ret = 99 + ret;
	cout << ret;
	return 0;
	//�迭�� ���ڸ� ���� ������ �����ϰ� ���Ѵ�
	
}

int number(int N,int ret)//�� ���̵��
{
	int back = 0;
	int front = 0;
	if (N <= 99)
	{
		cout << N;
		return 0;
	}
	for (int j = 100; j <= N; ++j)
	{
		if (j == 1000) break;
		int i = j;
		//i==100
		back = i % 10; //0
		front = i / 10;//10
		int memo = back - (front % 10);


		//i==10
		i /= 10;
		back = i % 10; //0
		front = i / 10;//1
		if (memo == back - (front % 10))
		{
			++ret;
		}

	}
	ret = 99 + ret;
	cout << ret;
	return 0;
}//1000�̸� �Ѽ��� �ƴ�.�׻� 999�� ������ ��

int main()
{
	int N;
	cin >> N;
	int ret = 0;
	number(N, ret);//���1
	//number2(N, ret);//���2

	return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int number2(int N, int ret)//다른사람거 참고
{
	int arr[3];
	if (N <= 99)
	{
		cout << N;
		return 0;
	}
	for (int j = 100; j <= N; ++j)
	{
		if (j == 1000) break;//1000일 경우 arr interrupt
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
	//배열에 각자리 수를 나눠서 저장하고 비교한다
	
}

int number(int N,int ret)//내 아이디어
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
}//1000이면 한수가 아님.항상 999로 생각할 것

int main()
{
	int N;
	cin >> N;
	int ret = 0;
	number(N, ret);//방법1
	//number2(N, ret);//방법2

	return 0;
}


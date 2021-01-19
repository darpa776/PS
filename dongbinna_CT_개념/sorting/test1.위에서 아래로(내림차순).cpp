#include <iostream>
#include <algorithm>
using namespace std;

//**reverse함수형과 매개변수, 리턴값 기억하기
bool reverse(int a, int b)
	{
		return a > b;
	}

int main()
{
	int n;
	cin >> n;

	int arr[500];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, reverse);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	return 0;
}
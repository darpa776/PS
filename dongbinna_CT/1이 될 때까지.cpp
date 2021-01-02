#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int cnt=0;
	while (1)
	{
		if (n == 1)
		{
		
			break;
		}
    //K가 2이상이기만 하면 k로 나누는 것이 1을 빼는 것보다 항상 빠르게 n의 값을 줄일 수 있다. 따라서 k로 최대한 많이 나눌 수 있도록 하는 것이 최적의 해를 보장하는 것이다.
		else if (n%k == 0)
		{
			n /= k;
			cnt++;
		}
		else
		{
			n--;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
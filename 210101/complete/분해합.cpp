#include <iostream>
#include <cmath>

using namespace std;
int n;//입력받는 자연수
int cnt;//자릿수 세기
int sum;

void main()
{
	cin >> n;
	int num=n;
	
	while (1)
	{
		num /= 10;
		if (num !=0)
			++cnt;
		else
			
			break;

	}
	num = n;
	int range = (cnt+1) * 9;
	for (int i = num - range; i <= num; ++i)
	{
		sum = 0;
		int temp = i;
		while (temp) {//**각 한자리씩 떼기***
			sum += temp % 10;
			temp /= 10;
		}

		if (num == sum + i)
		{

			cout << i;
			return;
		}
	}

	cout << "0";
	return;
}
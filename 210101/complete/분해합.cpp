#include <iostream>
#include <cmath>

using namespace std;
int n;//�Է¹޴� �ڿ���
int cnt;//�ڸ��� ����
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
		while (temp) {//**�� ���ڸ��� ����***
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
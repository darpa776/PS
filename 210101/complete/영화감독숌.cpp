#include <iostream>

using namespace std;
int n;//�Է¹޴� ����, n��°�� ���� �������� ����ؾ� ��
int temp;
int cnt=1;//���� temp�� ���° �������� count

int main()
{
	cin >> n;

	//n=1�̸� 666
	//n=2�̸� 1666
	if (n == 1)
	{
		cout << 666; return 0;
	}
	else
	{
		for (int i = 1666;; ++i)
		{
			temp = i;
			while (temp >= 666)
			{
				if (temp % 1000 == 666)
				{
					++cnt;
					if (cnt == n)
					{
						cout << i;
						return 0;
					}
					break;//6666���� �ߺ����� �ɸ��� �ʱ� ���� ��i���� 666�� ������ Ȯ���ϰ� ���� ���� i�� �Ѱ��ش�(++i)
				}
				
				else
					temp /= 10;

				
				
			}

		}
	}
	return 0;
}
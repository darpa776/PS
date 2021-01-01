#include <iostream>

using namespace std;
int n;//입력받는 숫자, n번째는 무슨 숫자인지 출력해야 함
int temp;
int cnt=1;//현재 temp가 몇번째 숫자인지 count

int main()
{
	cin >> n;

	//n=1이면 666
	//n=2이면 1666
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
					break;//6666에서 중복으로 걸리지 않기 위해 한i에서 666이 있음을 확인하고 나면 다음 i로 넘겨준다(++i)
				}
				
				else
					temp /= 10;

				
				
			}

		}
	}
	return 0;
}
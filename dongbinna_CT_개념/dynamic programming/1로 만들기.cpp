#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//bottom-up
	int x;
	int m[30000] = { 0 };

	cin >> x;
	m[2] = 1;
	m[3] = 1;
	m[5] = 1;
	for (int i = 2; i <= x; i++)
	{
		
		if (i % 5 == 0)
		{
			int ni = i/5;
			if (m[i] == 0)//저장된 값이 없으면
			{
				m[i] = m[ni] + 1;
			}
			else if (m[i] != 0)//저장된 값이 있으면
			{
				m[i] = min(m[ni] + 1, m[i]);
			}
		}
		if (i % 3 == 0)
		{

			int ni = i / 3;
			if (m[i] == 0)//저장된 값이 없으면
			{
				m[i] = m[ni] + 1;
			}
			else if (m[i] != 0)//저장된 값이 있으면
			{
				m[i] = min(m[ni] + 1, m[i]);
			}
		}
		if (i % 2 == 0)
		{

			int ni = i / 2;
			if (m[i] == 0)//저장된 값이 없으면
			{
				m[i] = m[ni] + 1;
			}
			else if (m[i] != 0)//저장된 값이 있으면
			{
				m[i] = min(m[ni] + 1, m[i]);
			}
		}
		//ni와 i를 잘 구별해서 배열을 만들 것
		//12같은건 3으로도,2로도 나눌 수 있기 때문에 else if가 아니라 if문으로 짜야함
		int ni = i - 1;
		if (m[i] == 0)//저장된 값이 없으면
		{
			m[i] = m[ni] + 1;
		}
		else if (m[i] != 0)//저장된 값이 있으면
		{
			m[i] = min(m[ni] + 1, m[i]);
		}

	}
	cout << m[x];
	return 0;
}
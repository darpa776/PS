#include <iostream>
#include <math.h>
int n;
int ans;
int check[16];//n�� �ִ� 15
using namespace std;
int flag=1;
int dfs(int row,  int cnt)//��,��,���° queen�� �ξ���
{
	if (cnt == n)
	{
		ans++;
		return 0;
	}

	for (int i = row; i <= n; ++i)//i�� ���� ��
	{
		for (int j = 1; j <= n; ++j)//j�� ��
		{
			
			if (i == 1)//ù���� ���ϴ� ���� ������ ���
			{
				check[i] = j;

				dfs(i + 1, cnt + 1);//j�� ������ ó������ ���ϱ� �ʿ�������� ����
				check[i] = 0;//**ã���� �����ɷȴ٤̤�**
				continue;//**ã���� �����ɷȴ٤̤�**
				//���� ��ġ�� �ʰ� ���� ������ �ѱ��
			}
			flag = 1;
			for (int k = 1; k < i; ++k)
			{
				if (j == check[k] || abs(j - check[k]) == abs(k - i))//����, �밢���̸� �Ѿ��
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				check[i] = j;
				dfs(i + 1, cnt + 1);//j�� ������ ó������ ���ϱ� �ʿ�������� ����
					//���� ��ġ�� �ʰ� ���� ������ �ѱ��
				check[i] = 0;
			}
			
		}
		return 0; //**ã���� �����ɷȴ٤̤�**
	}
	return 0;
}

int main()
{
	cin >> n;
	dfs(1,  0);//queen�� ���� �ʾҴٰ� �����ϱ� ������ check�迭 ������ 0�� ���� �ʵ��� �Ѵ�.
	cout << ans;
	return 0;
}
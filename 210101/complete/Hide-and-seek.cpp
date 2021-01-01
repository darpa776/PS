#include <iostream>
#include <queue>

using namespace std;
#define MAX 200000
int n, k;
int check[MAX];

int main()
{
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	int now;
	while (!q.empty())
	{
		//�� ��� ��� �� �湮�� ��쿡�� �ѹ��� ������ pop�ϰ� ��
		now = q.front();
		q.pop();
		if (now == k)
			break;
		if (now - 1 >= 0)
		{
			if (check[now - 1]==0)
			{
				check[now - 1] = check[now] + 1;
				q.push(now - 1);
				
			}
		}
		if (now + 1 <= MAX)//check[MAX]�� ������ �� ���� check[MAX-1]�� �ִ� �ε����̱� ������
			//�׻� ��ȣ�� ����� �����Ѵ�.��ȣ�� ���� ���� �����ϴ� ���� MAX������ �ε������� �������� �ʱ� ����
		{
			if (check[now + 1]==0)//�湮�������� �湮�ϱ�
			{
				check[now + 1] = check[now] + 1;
				q.push(now + 1);

			}
		}
		if (now*2 <= MAX)
		{
			if (check[now*2] == 0)
			{
				check[now * 2] = check[now] + 1;
				q.push(now * 2);

			}
		}
	}

	cout << check[now] << endl;

	return 0;
}
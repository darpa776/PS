#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

queue<int> q;
int _new = -99;//0�� ȥ������ �ʰ� �����Ⱚ �ֱ�
int n;
int visited[1000050];

void bfs(int n)
{
	q.push(n);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now % 3 == 0)
		{
			_new = now / 3;

			if (visited[_new] == 0 && _new >= 1)//���� �湮��������
			{
				visited[_new] = visited[now] + 1;//�湮�ϰ�
				q.push(_new);
			}
		}

		if (now % 2 == 0)
		{
			_new = now / 2;

			if (visited[_new] == 0 && _new >= 1)//���� �湮��������
			{
				visited[_new] = visited[now] + 1;//�湮�ϰ�
				q.push(_new);
			}
		}

		_new = now - 1;
		if (visited[_new] == 0 && _new >= 1)//���� �湮��������
		{
			visited[_new] = visited[now] + 1;//�湮�ϰ�
			q.push(_new);
		}


	}
	cout << visited[1] << endl;
	return;
}
int main()
{
	cin >> n;
	bfs(n);
	return 0;
}



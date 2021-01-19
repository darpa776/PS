#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;//강의 수
int _time[101];
queue<int> q;
int indegree[101];
vector<int> graph[101];
int result[101];

void topology()
{
	for (int i = 1; i <= n; i++)
	{//진입차수가 0인 노드부터 시작한다.
		if (indegree[i] == 0)
		{
			q.push(i);

		}
	}

	while (!q.empty())
	{
		int now = q.front();

		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + _time[graph[now][i]]);
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0)
			{
				q.push(graph[now][i]);

			}
		}

	}
}

int main()
{
	//위상정렬
	cin >> n;



	for (int i = 1; i <= n; i++)
	{

		cin >> _time[i];
		int x;
		cin >> x;
		while (x != -1)
		{
			graph[x].push_back(i);//**
			
			indegree[i]++;
			cin >> x;
		}

	}
	//**
	for (int i = 1; i <= n; i++)
	{
		result[i] = _time[i];
	}

	topology();
	//결과 출력

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}
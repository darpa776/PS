#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<int> graph[101];
int indegree[101] = { 0 };//진입차수 초기화
queue<int> q;
vector<int> result;

int topologysort()
{
	// 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= v; i++) 
	{
		if (indegree[i] == 0) 
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now=q.front();
		q.pop();
		result.push_back(now);

		//해당 노드에서 출발하는 간선 제거
		for(int i=0;i<graph[now].size();i++)
		{
			indegree[graph[now][i]] -= 1;
			//now의 다음 노드의 진입차수를 삭제하는 것
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
			//진입차수가 0인 노드를 push
		}
	}

	return 0;
}

int main()
{
	cin >> v >> e;

	//간선 입력받기
	for (int i = 0; i <e; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		indegree[y] += 1;
	}
	topologysort();
	
	//정답출력
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}
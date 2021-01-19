//다익스트라 알고리즘
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, start;
//노드개수, 간선개수, 시작할 노드
vector<pair<int, int>> graph[100001];
int d[100001];
int visited[100001];

int smallestNode()
{
	int index;
	int minv = INF;
	for (int i = 1; i <=n;i++ )
	{
		if (!visited[i] && minv > d[i])
		{
			minv = d[i];
			index = i;
		}
	}
	return index;
}

int dijkstra(int start)
{
	visited[start] = true;
	d[start] = 0;

	for (int i = 0; i < graph[start].size(); i++)
	{
		d[graph[start][i].first] = graph[start][i].second;
	}
	//그다음 노드 고르기
	
	for (int i = 0; i < n - 1; i++)
	{
		int now = smallestNode();
		visited[now] = true;
		for (int j = 0; j < graph[now].size(); j++)
		{
			if(d[graph[now][i].first]>d[now]+graph[now][i].second)
			d[graph[now][i].first] = d[now] + graph[now][i].second;
			//d[graph[now][i].first]: 이전노드에서 바로 도착하는 cost
			//d[now]: 현재 출발하려는 노드의 cost
			//graph[now][i].second: 현재 도착하려는 노드의 cost
			//d의 값을 갱신시켜줘야하기 때문에 d[graph~~]에 대입하는 것임
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m >> start;
	//그래프 입력
	for (int i = 0; i < m; i++)
	{
		int x, y,z;
		cin >> x>>y>>z;
		graph[x].push_back({ y,z });
	}

	//초기화
	fill_n(d, 100001, INF);
	//다익스트라 알고리즘 수행
	dijkstra(start);

  // 모든 노드로 가기 위한 최단 거리를 출력
  for (int i = 1; i <= n; i++) 
  {
   // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
    if (d[i] == INF) 
    {
      cout << "INFINITY" << '\n';
    }
   // 도달할 수 있는 경우 거리를 출력
    else 
    {
      cout << d[i] << '\n';
    }
  }
}
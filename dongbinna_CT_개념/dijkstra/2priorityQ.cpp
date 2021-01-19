#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[100001];
int d[100001];
priority_queue<pair<int,int>> q;
int n,m, start;

void dijkstra(int start)
{
	d[start] = 0;
	q.push({ 0, start });
	while (!q.empty())
	{
		int dist = -q.top().first;
		//최소비용순으로 정렬해야하기 때문에 음의 부호로 바꿔준다
    int now= q.top().second;
    q.pop();
    //현재 노드가 더 작으면 이미 방문한 노드
    if(d[now] <dist)   continue;

    for(int i=0;i<graph[now].size();i++)
    { 
      if(d[graph[now][i].first]>d[now] + graph[now][i].second)
      { 
        d[graph[now][i].first]=d[now]+graph[now][i].second;
        q.push(make_pair(-(d[now]+graph[now][i].second), graph[now][i].first));
      }
    }
	}
	
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
//fill_n(변경하려는 원소의 범위 시작주소, 변경하려는 원소 갯수, 변경 값)
//fill_n(변경하려는 원소의 범위 시작주소, 변경하려는 원소의 범위 종료주소, 변경 값)
	//초기화
	fill(d, d+100001, INF);
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
	return 0;
}
#include <vector>
#include <iostream>
//메모리 초과 때문에 bfs로 다시 풀자
#define INF 1e9
using namespace std;

int dist[300001];
vector<int> city[300001];

void dfs(int x)
{//x에서부터 시작해서 최소거리를 city별로 저장하기
	for (int i = 0; i < city[x].size(); i++)
	{
			dist[city[x][i]] = min(dist[x] + 1,city[x][i]);
			dfs(city[x][i]);
	}
	return;
}

int main()
{
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	//도시개수, 도로개수, 원하는 최단거리, 출발도시

	//dist 초기화
	fill_n(dist, 300000, INF);

	for (int i = 0; i < m; i++)
	{//x->y 도시로 이동하는 도로
		int x, y;
		cin >> x >> y;
		city[x].push_back(y);
	}
	//출발하는 도시로 다시 도착하는 거리는 0
	dist[x] = 0;
	//x도시에서부터 출발한다.
	dfs(x);

	//최단거리를 저장한 배열을 처음부터 검사한다.
	//값이 k이면 출력한다.
	//iterator가 끝났는데도 k인 값이 없으면 -1을 출력한다.
	int flag = 0;//for문 다돌았는데 flag가 여전히 0이면 -1 출력
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == k)
		{
			cout << i << " ";
			flag = 1;
		}
	}
	if (flag == 0)
		cout << -1 << endl;
	return 0;
}

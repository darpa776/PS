#include <iostream>
#include <queue>
using namespace std;

bool map[1001][1001];
bool visited[1001];
int n, m, v;
queue<int> q;

//방문할 정점이 여러개인 경우 정점번호가 작은 것 부터 방문
void dfs(int node)
{
	visited[node] = 1;
	cout << node << " ";

	for (int i = 1; i <= n; ++i)
	{
		if (map[node][i] && !visited[i])//다음 갈 곳을 방문안했으면
		{
			dfs(i);//다음 정점 방문
		}
	}
	return;
}

void bfs(int node)
{
	q.push(node);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (!visited[now])
		{
			visited[now] = 1;
			cout << now << " ";

			for (int i = 1; i <= n; ++i)
			{
				if (map[now][i]&&!visited[i])
				{
					q.push(i);
					//여기에 visit=1해주면 큐에 더 넣는게 없어서 프로그램 실행시간이 더 짧아진다
				}
			}
		}
	}

	//https://twpower.github.io/73-how-to-implement-dfs-and-bfs-in-cpp 참고
	//위의 링크에서는 push하고 바로 visit한다. visit한 vertex면 더이상 큐에 넣어주지 않기

	return;
}

int main()
{
	cin >> n >> m >> v;
	for (int a = 0; a < m; ++a)//m줄 입력
	{//인접행렬 만들기
		int i, j;
		cin >> i >> j;
		map[i][j]=1;
		map[j][i]=1; //양방향 연결
	}

	//dfs
	dfs(v);
	cout << endl;
	//초기화
	for (int i = 1; i <= n; ++i)
		visited[i] = 0;
	//bfs
	bfs(v);
	cout << endl;
	return 0;
}
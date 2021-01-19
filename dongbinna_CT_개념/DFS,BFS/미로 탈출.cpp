#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[200][200];
int visited[200][200];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
//int count_=0;
//count는 전역변수이니까 현재위치에 상관없이 변경될 위험이 있다.
//그래서 visited에 count 값을 넣는다.

void bfs(int y, int x)
{
	queue<pair<int,int>> q;
	visited[y][x] = 1;
	q.push({ y,x });
	//count_++;

	int nx, ny;
	while (!q.empty())
	{
		int y= q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			//방문안한 곳이고 미로(1)이고 유효한 범위이면
			if (!visited[ny][nx]&&map[ny][nx]==1&&ny>=0 && nx >= 0 && ny < n && ny < m)
			{
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x]+1;
				//최단경로 찾을 때는 거리 개념으로 생각할 것!
				//count_++;
			}
					
		}
	}
	return;
}

int main()
{
	cin >> n >> m;
	//한줄통째로 입력이 들어옴->scanf로 숫자 한개(%1digit) 입력받기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}
	bfs(0,0);
	cout << visited[n-1][m-1] << endl;
	//문제에서 지정한, 오른쪽 하단 값(ans, distance) 출력
	return 0;
}

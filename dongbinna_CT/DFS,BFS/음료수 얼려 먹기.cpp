#include <iostream>
using namespace std;

int visited[1000][1000];
int num = 0;
int map[1000][1000];
//상하좌우를 뒤져서 연결되어 있는지 확인해보자
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n, m;

void dfs(int y,int x)
{
	visited[y][x] = 1;
	//갈 곳이 map 범위 내이고 0이면 연결
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx>=0&& ny >= 0 && nx <m && ny < n &&map[ny][nx] == 0 && visited[ny][nx] == false)
		{
			dfs(ny, nx);
		}

	}
	
	return; 
	
}

void main()
{
	//1, 기본 입력
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<m;j++)
		{
			//얼음인데 방문안했으면 새로운 덩어리 시작
			if (map[i][j] == 0 && !visited[i][j])
			{
				num++;
				dfs(i, j);
			}
		}
	}
	
	cout << num << endl;
	return;
}
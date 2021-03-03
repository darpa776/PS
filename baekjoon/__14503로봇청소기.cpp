#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n, m;
int r, c, d;//로봇청소기 위치, 방향
int dx[4] = {-1,0,1,0};//상우하좌
int dy[4] = {0,1,0,-1};
int map[50][50];
int visited[50][50];
pair<int, int> position;//현재 위치
int dir_idx;//현재 방향
int ans = 0;

int dfs(int x, int y, int dir) {

		//1. 현재 위치를 청소한다.
		/*int x = position.first;
		int y = position.second;*/
		//int dir=dir_idx;
		/*visited[x][y] = 1;
		ans++;*/

		//2. 현재 방향을 기준으로 왼쪽방향으로 탐색을 진행한다.
		for (int i = 0; i < 4; i++) {
			//왼쪽으로 방향 회전
			if (dir == 0)
				dir = 3;
			else
				dir--;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (!visited[nx][ny] && map[nx][ny] == 0) {//왼쪽을 청소 안했으면 회전 후 전진
				visited[nx][ny] = 1;
				ans++;
				return dfs(nx, ny, dir);
				
				/*position.first = nx;
				position.second = ny;*/
				
			}
			else if (visited[nx][ny] || map[nx][ny] == 1)//왼쪽 방향에 청소가 필요없으면 왼쪽으로 한번 더 회전
			{
				continue;
			}

		}
		//네 방향모두 청소되어 있거나 벽이면
		//후진
		int nx = x - dx[dir];
		int ny = y - dy[dir];
		if (map[nx][ny] == 1)//벽이 있으면 종료
		{
			return 0;
		}
		else//후진 후 다시 왼쪽부터 검사
		{
			dfs(nx, ny, dir);
		}

		return 0;
}


int main()
{
	cin >> n >> m;//톱니바퀴의 개수 입력받기
	cin >> r >> c >> d;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//빈칸은 0, 벽은 1
			cin >> map[i][j];
		}
	}

	
	
	/*position.first = r;
	position.second = c;
	dir_idx = d;*/
	visited[r][c] = 1;
	ans++;
	dfs(r, c, d);
	
	cout << ans << endl;
	return 0;
}

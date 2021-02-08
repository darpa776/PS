#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, l, r;
int map[50][50];
int dx[4] = { -1,1,0,0 };//상하좌우
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
int visited[50][50];
int unit;
int answer = 0;

void bfs(int x, int y) {
	
	
	int num = 0;
	int sum = 0;

	q.push({ x,y });
	sum = map[x][y];
	num = 1;//연합 국가 수
	visited[x][y] = unit;


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			else if (l <= abs(map[nx][ny] - map[x][y]) && abs(map[nx][ny] - map[x][y]) <= r) {
				if (-1==visited[nx][ny]) {
					q.push({ nx,ny });
					sum += map[nx][ny];
					num++;//연합수
					visited[nx][ny] = unit;
					
				}
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == unit)
				map[i][j] = sum / num;
		}
	}
	// 연합 국가끼리 인구를 분배
	return;
}
int main()
{
	cin >> n >> l >> r;
	//각 나라의 인구수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = -1;
			}
		}
		unit = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (-1==visited[x][y])
				{
					bfs(x, y);
					unit++;
				}

			}
		}
		if (unit == n * n) break;
		//각 나라가 모두 하나의 유닛이 되어 
		//나라의 문을 모두 폐쇄했을 때
		answer++;

	}
	cout << answer << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//#include <stdlib.h>
using namespace std;

int cluster_num = 1;
int n;
int map[100][100];
int visited[100][100];
int cluster[100][100];

//상하좌우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 1e9;

void cluster_bfs(queue<pair<int, int>> clusterq) {


	while (!clusterq.empty()) {
		int x = clusterq.front().first;
		int y = clusterq.front().second;
		cluster[x][y] = cluster_num;
		clusterq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (cluster[nx][ny] || map[nx][ny] == 0) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			cluster[nx][ny] = cluster_num;
			clusterq.push({ nx,ny });
		}
	}
	return;
}


void length_bfs(queue<pair<int, int>> q ,int now) {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			//갈 수 없는 곳은 가지 않는다.
			if (visited[nx][ny] != 0 || cluster[nx][ny]==now) continue;
			//이미 방문했거나 내 클러스터이면 continue;

			//다른 클러스터에 도착했으면 종료
			if (map[nx][ny]==1&& cluster[nx][ny] != now) {
				ans = min(visited[x][y],ans);
				return;
			}
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
		}
	}


	return;
}

int main()
{

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	//클러스터에다가 그룹별로 표시
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) continue;
			if (cluster[i][j]) continue;
			queue<pair<int, int>> clusterq;
			clusterq.push({ i,j });
			cluster_bfs(clusterq);
			cluster_num++;
		}
	}

	//아무 클러스터나 땅이 있으면 일단 출발
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			queue<pair<int, int>> q;
			if (map[i][j] == 0) continue;
			q.push({ i,j });
			length_bfs(q,cluster[i][j]);
			//매번 초기화
			for (int i = 0; i < n; i++)
				fill_n(visited[i], n, 0);
		
		}
	}
	//가장 짧은 길이를 출력
	cout << ans << endl;
	return 0;
}

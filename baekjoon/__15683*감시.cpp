#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://jongnan.tistory.com/entry/%EB%B0%B1%EC%A4%80-15683-%EA%B0%90%EC%8B%9C

int ans = 1e9;
int n, m;
int map[8][8];
vector<pair<int,pair<int, int>>> CCTV;//CCTV 번호, 위치
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//12시방향부터 시계방향으로 돌아감
//상,우,하,좌
int visited[8][8];
//방향수만큼 dfs 돌리기
//벽이 있으면 통과할수 없고, cctv는 통과할 수 있다.

void copy(int a[8][8], int b[8][8]) {//a배열을 b로 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
		}
	}
	return;
}

int cal(int x, int y, int dir) {

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	while (visited[nx][ny] != -1) {
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
		
		visited[nx][ny] = 1;
		nx += dx[dir];
		ny += dy[dir];
	}

	return 0;
}

void dfs(int idx) {
	if (idx >= CCTV.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0)
					cnt++;
			}
		}
		ans = min(cnt, ans);
		return;
	}

	int x = CCTV[idx].second.first;
	int y = CCTV[idx].second.second;

	switch (CCTV[idx].first)
	{
	case 1://0,1,2,3
		for (int i = 0; i < 4; i++) {
			//모든 cctv 가 돌때까지 visited가 유지되다가, 모든 cctv가 다 돌면=cnt가 다 차면=dfs가 종료되면 visited가 그 상태 바로 이전으로 돌아감
			int temp[8][8];//백트래킹을 위한 임시 방문배열
			copy(visited, temp);//dfs 이전 visited를 temp에 임시 저장
			cal(x, y, i);//i방향으로 x,y에 위치한 cctv를 기준으로 감시할수 있는 위치 표시
			dfs(idx + 1);//그다음 CCTV추가
			copy(temp,visited);//dfs가 종료되면 visited가 해당 i의 cal함수가 시작되기 전에 임시로 저장해둔 맵(temp)으로 돌아가야한다.
		}
		break;
	case 2://상하,좌우
		for (int i = 0; i <= 1; i++) {
			int temp[8][8];
			copy(visited, temp);//dfs 이전 visited를 temp에 임시 저장
			cal(x, y, i);
			cal(x, y, i + 2);
			dfs(idx + 1);//그다음 CCTV추가
			copy(temp, visited);
		}
		break;
	case 3://01,12,23,30
		for (int i = 0; i < 4; i++) {
			int temp[8][8];
			copy(visited, temp);
			cal(x, y, i);
			cal(x, y, (i + 1) % 4);
			dfs(idx + 1);//그다음 CCTV추가
			copy(temp, visited);
		}
		break;
	case 4:
		//012,123,230,301
		for (int i = 0; i < 4; i++) {
			int temp[8][8];
			copy(visited, temp);
			cal(x, y, i);
			cal(x, y, (i + 1) % 4);
			cal(x, y, (i + 2) % 4);
			dfs(idx + 1);//그다음 CCTV추가
			copy(temp, visited);
		}
		break;
	case 5://0123
		int temp[8][8];
		copy(visited, temp);
		for (int i = 0; i < 4; i++) {
			cal(x, y, i);//i방향으로 x,y에 위치한 cctv를 기준으로 감시할수 있는 위치 표시
		}
		dfs(idx + 1);//그다음 CCTV추가
		copy(temp, visited);
		break;
	}
	return;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5)
			{
				CCTV.push_back({ map[i][j],{i,j} });
				visited[i][j] = 1;
			}
			if (map[i][j] == 6)
				visited[i][j] = -1;
		}//1~5: CCTV, 6: 벽, 0: 빈칸
	}
	dfs(0);
	
	cout << ans << endl;
	//사각지대의 최소 크기를 구해라
	return 0;
}

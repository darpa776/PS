#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
//#define _crt_secure_no_warnings
//#pragma warning(disable:4996)
using namespace std;

int n, m;
int map[50][50];
char lab[50][50];
int visited[50][50];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
//활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.
//bfs로 *를 건드리면 *칸은 다음번에 0 으로 시작
int dx[4] = { -1,1,0,0 };//상하좌우
int dy[4] = { 0,0,-1,1 };
int ans = 1e9;
int flag = 0;
//bfs 들어가기 전에 빈칸이 몇개인지 세아리기, bfs 끝나고 나서 빈칸 수 만큼 visited 했으면 해당 초를 ans과 비교
//만약 bfs 끝났는데도 빈칸수가 더 많다면 모든 칸을 다 방문할 수 없는 것

int check(int cnt) {
	// 모든 칸이 바이러스로 가득 찼는지 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (lab[i][j] == '-')//방문해야할 빈칸의 수
				cnt++;
		}
	}
	return cnt;
}

void bfs() {
	int t = 0;
	int blank_cnt =check(0);//채워야할 빈칸의 수
	int visit_cnt = 0;//방문한 칸의 수
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (lab[nx][ny] == '*') {//비활성 바이러스를 만나는 경우
				if (visited[nx][ny] == 0) {
					visited[nx][ny] = visited[x][y] + 1;
					//활성화해주기
					lab[nx][ny] = '0';
					q.push({ nx,ny });
				}
			}

			else //방문한적 없는 빈칸이면
			{
				if (lab[nx][ny] == '-' && visited[nx][ny] == 0) {//아직 방문하지 않은 빈칸이면
					visited[nx][ny] = visited[x][y] + 1;
					visit_cnt++;
					lab[nx][ny] = '0';//바이러스로 채워짐
					q.push({ nx,ny });
				}
			}
		}
		if (blank_cnt <= visit_cnt) {//모든 칸을 다 방문했다면
			t = visited[x][y] + 1;
			ans = min(ans, t);
			while (!q.empty())
				q.pop();
			return;
		}
	}
	if(blank_cnt > visit_cnt){//q에 있는거 다했는데도 빈칸이 있으면
		flag = 1;//바이러스를 모두 퍼트릴 수 없다.
	}
	return;
}

void lab_init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0)//빈칸
				lab[i][j] = '-';
			else if (map[i][j] == 1)//벽
				lab[i][j] = '#';
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });

		}
	}
	lab_init();

	//바이러스 중에서 m개를 고른다.
	vector<int> binary(virus.size(), 0);
	fill(binary.end() - m, binary.end(), 1);//바이러스 중 m개를 골라 활성화시킨다.
	do {
		for (int i = 0; i < virus.size(); i++) {
			if (binary[i] == 1)//활성화할 바이러스면 활성화
			{
				lab[virus[i].first][virus[i].second] = '0';
				q.push({ virus[i].first , virus[i].second });
			}
			else//바이러스 비활성화
				lab[virus[i].first][virus[i].second] = '*';
		}
		if (check(0) == 0)
		{//빈칸 없이 바이러스가 퍼졌다면 현재가 가장 짧은 시간
			cout << 0 << endl;
			exit(0);
		}//예제 7

		bfs();//lab의 활성화된 바이러스에서부터 출발한다.

		//초기화
		lab_init();
		for (int i = 0; i < n; i++)
			fill_n(visited[i], n, 0);
	} while (next_permutation(binary.begin(), binary.end()));

	if (flag == 1 && ans == 1e9)//어떤 경우에도 모든 칸을 바이러스로 채울 수 없으면
		ans = -1;
	cout << ans << endl;
	return 0;
}

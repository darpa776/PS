//모든 승객을 성공적으로 데려다줄수 있는지
//데려다줄수 있는 경우 최종적으로 남는 연료의 양을 출력
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans;
int map[21][21];
pair<int, int> taxi;
vector<pair<pair<int, int>, pair<int, int>>> person;
vector<int> dist;
int p_done[400];//최대 400명
int dx[4] = { -1,1,0,0 };//상하좌우
int dy[4] = { 0,0,-1,1 };

pair<int, int> bfs1(int taxi_x, int taxi_y) {	//현재 택시의 위치로부터 bfs를 시작한다.
	int visited[21][21];
	for (int i = 1; i <= n; i++)
		fill_n(visited[i]+1, n, 0);

	queue<pair<int, int>> q;
	q.push({ taxi_x ,taxi_y });
	visited[taxi_x][taxi_y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
			if (map[nx][ny]) continue;//벽이라면
			if (visited[nx][ny]) continue;

			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });

		}

	}

	//가장 가까운 거리의 승객 idx 번호와 거리를 저장
	pair<int, int> answer;//idx 번호, 거리

	vector<pair<pair<int, int>, pair<int, int>>> candidate;//후보들(거리, x,y, idx)
	for (int i = 0; i < m; i++) {
		if (p_done[i]==0)//i번째 승객을 태워야한다면
		{
			//그 승객의 위치에 해당하는 visited 값이 거리.
			int x = person[i].first.first;
			int y = person[i].first.second;
			int dist = visited[x][y]-1;
			if (dist < 0)
				continue;//이 승객을 태우러 갈수 없는 거리에 있습니다.
			candidate.push_back({ {dist,x},{y,i} });
		}
	}
	if (candidate.size() == 0) {
		//태우러 갈 수 있는 승객이 없다면
		cout << -1 << endl;
		exit(0);
	}
	sort(candidate.begin(), candidate.end());
	//택시에 태울 수 있는 승객 중 가장 가까운 승객
	answer.second = candidate[0].first.first;//거리
	answer.first = candidate[0].second.second;//idx 번호


	return answer;
}

int bfs2(int st_x, int st_y, int dst_x, int dst_y) {//start, destination 
	//태운 승객을 목적지까지 모셔드립니다.
	int visited[21][21];
	for (int i = 1; i <= n; i++)
		fill_n(visited[i] + 1, n, 0);
	queue<pair<int, int>> q;
	q.push({ st_x ,st_y });
	visited[st_x][st_y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
			if (map[nx][ny]) continue;//벽이라면
			if (visited[nx][ny]) continue;
		
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });

		}

	}
	if (visited[dst_x][dst_y]<=0)//만약 도착지까지 택시가 못갔다면
	{
		cout << -1 << endl;
		exit(0);
	}

	return visited[dst_x][dst_y]-1;
}

int main() {
	cin >> n >> m >> ans;//n행 n열, m명의 승객, 초기 연료의 양

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			//0은 빈칸, 1은 벽
		}
	}
	//운전을 시작하는 칸의 행 번호화 열 번호
	int x, y;
	cin >> x >> y;
	taxi.first = x; taxi.second = y;


	for (int i = 0; i < m; i++) {
		//승객의 출발지 행열, 목적지 행열
		int st_x, st_y, dst_x, dst_y;//start, destination
		cin >> st_x >> st_y >> dst_x >> dst_y;
		person.push_back({ {st_x,st_y}, {dst_x,dst_y} });
	}
	while (1) {
		//모든 손님을 이동시키고 연료를 충전했을때 남은 연료의 양을 출력
		//이동 도중 연료가 바닥날 때 -1 출력


		//현재 택시의 위치에서 각 승객을 태우기 위해 이동해야할 거리를 계산한다.
		pair<int, int> go;
		go = bfs1(taxi.first, taxi.second);
		int idx = go.first;//승객의 idx 번호
		int dist = go.second;//이동해야할 거리

		//가장 가까운 거리에 있는 승객을 태우러 이동한다.
		ans -= dist;
		if (ans <= 0) {
			cout << -1 << endl;
			return 0;
		}

		//승객을 태우고 목적지로 이동한다.
		//해당 승객에서 부터 목적지까지의 거리를 계산후 ans-= dist;
		dist = bfs2(person[idx].first.first, person[idx].first.second, person[idx].second.first, person[idx].second.second);
		ans -= dist;
		if (ans < 0) {
			cout << -1 << endl;
			return 0;
		}
		//목적지에 도착하면 이동에 사용한 연료량을 두배로 더해준다.
		//택시 위치 갱신
		taxi.first = person[idx].second.first;
		taxi.second = person[idx].second.second;
		p_done[idx] = 1;
		//더 이상 태워줄일 없음
		ans += (2 * dist);

		//모든 손님을 이동시키고 연료를 충전했을때 남은 연료의 양을 출력
		//만약 모든 손님이 이동되었다면
		int flag = 0;
		for (int i = 0; i < m; i++) {
			if (p_done[i]==0)
				flag = 1;
		}
		if (flag == 0) {//for문이 다 돌도록 데려다 주어야할 사람이 없었으면
			//남은 연료의 양을 출력하고 종료하자
			cout << ans << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}

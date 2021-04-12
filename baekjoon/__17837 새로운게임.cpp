#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
int color[12][12];
vector<int> map[12][12];//map에 올려진 말의 개수, 순서
vector< pair<pair<int, int>,int>> mark;//말의 상태
//right, left, up, down
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

void white(int i,int x, int y, int nx, int ny, int t) {

	//말을 그대로 올린다

	auto idx = find(map[x][y].begin(), map[x][y].end(), i);

	//idx부터 끝까지 x,y에 있던 말(*idx)을 nx,ny로 옮긴다.
	int tmp = map[x][y].end() - idx;
	for (; idx != map[x][y].end(); idx++) {
		mark[*idx].first.first = nx;
		mark[*idx].first.second = ny;
		map[nx][ny].push_back(*idx);
	}
	while (tmp) {
		map[x][y].pop_back();
		tmp--;
	}


	if (map[nx][ny].size() >= 4)
	{//놓으려는 곳에 말이 4개 이상이면
		cout << t << endl;
		exit(0);
	}

	return;
}

void red(int i, int x, int y, int nx, int ny, int t) {

	//말을 거꾸로 올린다.
	auto idx = find(map[x][y].begin(), map[x][y].end(), i);
	int fix=map[x][y].size();
	//tmp부터 끝까지 x,y에 있던 말(*idx)을 nx,ny로 옮긴다.
	int tmp = map[x][y].end()-idx;
	while (tmp) {
		mark[map[x][y][fix-1]].first.first = nx;
		mark[map[x][y][fix-1]].first.second = ny;

		map[nx][ny].push_back(map[x][y].back());
		map[x][y].pop_back();

		fix--;
		tmp--;
	}

	if (map[nx][ny].size() >= 4)
	{//놓으려는 곳에 말이 4개 이상이면
		cout << t << endl;
		exit(0);
	}

	return;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color[i][j];
			//0흰색, 1빨간색, 2파란색
		}
	}
	for (int i = 0; i < k; i++) {//1번 말부터 k번말까지
		//행,열,이동방향
		//right, left, up, down
		int x, y, z;
		cin >> x >> y >> z;
		mark.push_back({ {x-1,y-1},z });

		//같은 칸에 말이 두 개 이상 있는 경우는 입력으로 주어지지 않는다.
		//말을 map에 배치

		map[x - 1][y - 1].push_back(i);
	}

	//이동하는 방향의
	//1번 말부터 k번말까지 다 돌아야 t++
	int t = 1;
	while (1) {
		if (t > 1000)
		{//턴이 1000보다 크거나 절대로 게임이 종료되지 않는 경우는 -1
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < k; i++) {
			int x = mark[i].first.first;
			int y = mark[i].first.second;
			int dir = mark[i].second;

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {//out
				//방향을 바꾸고 한칸 이동한다.
				if (dir % 2 == 0)
					mark[i].second--;
				else
					mark[i].second++;
				//1<->2, 3<->4
				dir = mark[i].second;
				nx = x + dx[dir];
				ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					continue;
				}
				else if (color[nx][ny] == 0) {//흰색
					white(i, x, y, nx, ny, t);
				}
				else if (color[nx][ny] == 1) {
					red(i, x, y, nx, ny, t);
				}
				else if (color[nx][ny] == 2) {
					continue;
				}
			}
			else if (color[nx][ny] == 0) {//흰색
				white( i,  x,  y,  nx,  ny,  t);
			}
			else if (color[nx][ny] == 1) {//빨간색
				red(i, x, y, nx, ny, t);
			}
			else if (color[nx][ny] == 2) {//파란색
				//방향을 바꾸고 한칸 이동한다.
				if (dir % 2 == 0)
					mark[i].second--;
				else
					mark[i].second++;
				//1<->2, 3<->4
				dir = mark[i].second;
				nx = x + dx[dir];
				ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					continue;
				}
				else if (color[nx][ny] == 0) {//흰색
					white(i, x, y, nx, ny, t);
				}
				else if (color[nx][ny] == 1) {
					red(i, x, y, nx, ny, t);
				}
				else if (color[nx][ny] == 2) {
					continue;
				}

			}
		}
		
		t++;
	}
	
	return 0;
}

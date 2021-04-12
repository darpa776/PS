#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
int n, l, r;//l이상 r이하
int map[51][51];
int visited[51][51];
queue<pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int,int>> unit;//sum,cnt
int idx = 1;//unit구분


//하나의 연합(unit)내 국가수: cnt
//연합국가(unit) 수: idx==unit.size()-1

int bfs(int a,int b) {
	q.push({ a,b });
	int sum = 0;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (visited[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			int tmp = abs(map[x][y] - map[nx][ny]);
			if (l <= tmp && tmp <= r) {
				visited[nx][ny] = unit.size()+1;
				q.push({ nx,ny });
				sum += map[nx][ny];
				cnt++;
			}
		}
	}

	if(cnt>0)
		unit.push_back({ sum, cnt});
	return 0;
}


int main() {
	//국경선
	cin >> n >> l >> r;
	//국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {//인구이동이 더이상 없을때까지
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				bfs(i, j);
			}
		}
		if (unit.size()==0) break;
		//연합 도시마다 visited 배열에서 같은 번호를 가짐
		//이제 같은 번호를 가지는 배열끼리 더하고 나눠준다.
		//(연합의 인구수) / (연합을 이루고 있는 칸의 개수)
		for (int i = 0; i < unit.size(); i++) {
			int person = unit[i].first / unit[i].second;
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (visited[x][y] == i+1)
						map[x][y] = person;
				}
			}
		}


		//이제 연합을 해체하고, 모든 국경선을 닫는다.
		//초기화
		for (int i = 0; i < n; i++) {
			fill_n(visited[i], n, 0);
		}
		unit.clear();


		ans++;
	}
	//인구이동이 몇번 발생하는지 출력한다.
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T, test_case;
int ans;
int map[50][50];
int n, m, r, c, l;
int visited[50][50];
//상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int nx, ny;
queue<pair<int,int>> q;
//x,y에서 nx,ny로
//상:(하가 뚫린 곳)1,2,5,6
//하:(상이 뚫린 곳)1,2,4,7
//좌:(우가 뚫린 곳)1,3,4,5
//우:(좌가 뚫린 곳)1,3,6,7
vector<vector<int>> dest = { {0,1,2,3}, {0,1},{2,3},{0,3},{1,3},{1,2},{0,2} };




int go2(int nx,int ny, int i)//i는 상하좌우를 나타내는 인덱스
{
	if (i == 0)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6) return 1;
		else return 0;
	}

	else if (i == 1)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7)
			return 1;
		else return 0;
	}
	else if (i == 2)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
			return 1;
		else return 0;
	}
	else if (i == 3)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7)
			return 1;
		else return 0;
	}
	
}

void go(int x, int y)
{
	q.push(make_pair(x,y));
	visited[x][y] = 1;
	//맨홀에서는 1시간까지 있다

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;

		q.pop();
		if (map[now_x][now_y])//&&!visited[now_x][now_y]
		{
			for (int i = 0; i < dest[map[now_x][now_y]-1].size(); ++i)//map[now_x][now_y]==1이면 dest[0]으로 접근
			{
				nx = now_x + dx[dest[map[now_x][now_y] - 1][i]];
				ny = now_y + dy[dest[map[now_x][now_y] - 1][i]];
				// 맵 밖을 벗어났다면
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				//연결되어있는지 확인
				if (go2(nx, ny, dest[map[now_x][now_y]-1][i]) && !visited[nx][ny])//연결가능하고 방문한적 없는 경우
				{//연결되어있으면
					q.emplace(make_pair(nx, ny));
					visited[nx][ny] = 1 + visited[now_x][now_y];
				}
			}
		}

	}
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin>>n >>m >>r >> c>>l;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>map[i][j];

		go(r,c);

		//지하통로 visited를 돌고 이동시간 L이하인 경우가 몇 개인지 출력
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visited[i][j]>0 && visited[i][j] <= l)
					//***0도 같이 세아리부맀다, ㅣ포함해야함
				{
					ans++;
				}

			}
		}

		
		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		
		//초기화
		ans = 0;
		
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}*/


		for (int i = 0; i < n; i++) {
			memset(map[i], 0, sizeof(int) * m); //모든 값 0으로 초기화
			memset(visited[i], 0, sizeof(int) * m);
		}
		//출처: https://dahyeee.tistory.com/entry/c-2차원-배열-초기화memset사용

			
	}
	return 0;
}

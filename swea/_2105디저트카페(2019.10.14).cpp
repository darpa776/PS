
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
int sx, sy;//시작점
int T, test_case;
int ans;
bool visited[20][20];
int n;//한변의 길이
int map[20][20];
//int direction[4];
//find 함수사용, 원소 있으면 contine써서 다음 for문
vector<int> dessert;

//대각선 아래 좌측,우측, 위 우측, 좌측
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
//pair<int, int> start;

//0,0부터 시작해서 dfs 해나가기
void dfs(int x, int y, int len, int dir)
{
	for (int i = 0; i < 2; ++i)
	{//nx,ny 설정
		int nx, ny;

		if (i == 0)//방향유지
		{
			nx = x + dx[dir];
			ny = y + dy[dir];
			//dir은 그대로
		}

		else if (i == 1)//방향변경
		{
			// 시작노드는 방향전환 X
			if (x == sx && y == sy) continue;

		
			++dir;
			nx = x + dx[dir];
			ny = y + dy[dir];

		}

		if ((nx == sx) && (ny == sy) && (dir == 3))
		{
			ans = max(ans, len);	return;
		}

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)//map 외부이면
			continue;

		if (dessert.end() !=find(dessert.begin(), dessert.end(), map[nx][ny]))//먹었던 메뉴인경우
			continue;

		if (!visited[nx][ny]) {
			visited[nx][ny] = true;
			dessert.push_back(map[nx][ny]);
			dfs(nx, ny, len + 1, dir);
			visited[nx][ny] = false;
			dessert.pop_back();
		}
	}
	return;
}

int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];

		//0,0부터 시작해서 dfs 해나가기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = true;
				sx = i; sy = j;
				dessert.push_back(map[sx][sy]);
				dfs(i, j, 1, 0);
				visited[i][j] = false;
				dessert.pop_back();
			}
		}
	
		++test_case;
		cout << "#" << test_case << " " << ans << endl;

		//초기화
		ans = -1;
		dessert.clear();
		for (int i = 0; i < n; ++i)
		{
			memset(visited[i], 0, sizeof(int)*n);
			memset(map[i], 0, sizeof(int)*n);
		}
	}
	return 0;
}

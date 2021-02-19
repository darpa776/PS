#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int n, m, ans;
bool map[21][21];
bool visited[21][21];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
//상하좌우
int home;
//int profit;
void simul(int x, int y)
{
	queue<pair<int, int>> q;
	int tmp = 0;
	int k = 1;

	q.push(make_pair(x, y));
	visited[x][y] = 1;
	if (map[x][y])//집이 있다면
		++home;
	tmp = m * home - (pow(k, 2) + pow(k - 1, 2));//이익계산
	if (tmp >= 0)//지금 계산한게 더 크면
		ans = max(home, ans);//답 갱신
	int q_size = 1;
	while (!q.empty())
	{
		++k;// k++영역연산
		while (q_size--)
		{
			int now_x = q.front().first;
			int now_y = q.front().second;
			q.pop();
			//if (visited[now_x][now_y] >= n + 1) return;
			for (int i = 0; i < 4; ++i)
			{	//nx,ny 설정
				int nx = now_x + dx[i];
				int ny = now_y + dy[i];
				//예외처리
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)//nx,ny가 map을 벗어나면
					continue;
				if (!visited[nx][ny])//방문하지 않은 곳이고
				{
					if (map[nx][ny])//집이 있다면
						++home;
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}q_size = q.size();

		if (k <= n + 1)
		{
			tmp = m * home - (pow(k, 2) + pow(k - 1, 2));//이익계산
			if (tmp >= 0)
				ans = max(home, ans);//답 갱신
		}
		//or연산으로 집 몇개가 영역안에 있는지 알아내기
		//mask 키울 때 마다 보안회사의 이익과 최대값을 비교/저장
		else
			return;
		
			
	}
	return;

}
int main()
{
	freopen("sample_input.txt", "r", stdin);
	int test_case = 0;
	int T;
	cin >> T;

	//입력으로 n,m,map
	while (test_case < T)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				simul(i, j);
				//초기화
				home = 0;
				
				for (int i = 0; i < n; ++i) 
					memset(visited[i], 0, sizeof(int)* n);
			}
		}
		cout << "#" << ++test_case << " " << ans << endl;

		//초기화
		ans = 0;
		for (int i = 0; i < n; ++i) {

			memset(map[i], 0, sizeof(int)* n);
		}

	}
	return 0;
}

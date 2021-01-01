#include iostream
#include stack
#include vector
#include algorithm
#include queue

using namespace std;

int T, h, test_case, k, n;
int map[8][8];
vectorpairint, int max_pos;

int dx[4] = { -1, 1,0,0 }; 상하좌우
int dy[4] = { 0,0,-1,1 };
int visited[8][8];
int ans;
int dfs(int x, int y, int len, int cut)
{
	ans = max(ans, len);
	visited[x][y] = true;

	a, b 이용해서 사방 탐색
		for (int i = 0; i 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			맵 밖을 벗어난다면
				if (nx  0  ny  0  nx = n  ny = n) continue;
			cut과 상관없이 해당좌표의 주변이 봉우리보다 낮고 방문한 적이 없으면
				if (!visited[nx][ny])
				{
					if (map[x][y]  map[nx][ny])
					{
						visited[nx][ny] = true;
						dfs(nx, ny, len + 1, cut); 등산로 잇기, 깎지 않음
							visited[nx][ny] = false;
					}
					else if (!cut && (map[x][y]  map[nx][ny] - k))최대 k만큼 깎았는데도 봉우리보다 높으면 pass.
						깎았을 때 봉우리보다 낮을 경우&& 안깎을 때
					{
						visited[nx][ny] = true;
					int t = map[nx][ny]; 변경할 위치의 높이 저장
						map[nx][ny] = map[x][y] - 1; 현재 높이를 최대높이 보다 낮게 변경
						dfs(nx, ny, len + 1, 1); 깎을 때 1, 안깎을 때 0
						map[nx][ny] = t; 원상복귀
						visited[nx][ny] = false;
					}
				}

		}
	visited[x][y] = false;
	return len;
}
int main() {
	freopen(sample_input.txt, r, stdin);
	cin  T;
	while (test_case  T)
	{
		cin  n  k;
		int max_ = -1;
		for (int i = 0; i n; ++i)
		{
			for (int j = 0; j n; ++j)
			{
				cin map[i][j];
				if (max_  map[i][j])
					max_ = map[i][j]; 봉우리들의 최댓값을 저장
			}
		}

		높이가 최대인 곳 알아내기
			for (int i = 0; i n; ++i)
			{
				for (int j = 0; j n; ++j)
				{
					if (max_ == map[i][j])
						max_pos.push_back(make_pair(i, j)); 높이가 최대인 곳 위치 저장
				}
			}
		int cnt = max_pos.size();
		max_pos에서 위치 불러오기
			for (int i = 0; i cnt; ++i)
			{
				벡터 안의 내용 순서대로 불러오기
					int x = max_pos[i].first;
				int y = max_pos[i].second;
				dfs(x, y, 1, 0);
			}
		max_pos.clear(); 벡터 비우기

			++test_case;
		cout# test_case  ansendl;
		ans = 0; 초기화

	}
	return 0;
}
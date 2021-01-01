#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool map[25][25];
bool visited[25][25];
int n;
vector<int> vil;
int home;

void dfs(int x, int y)
{
	if ((x >= 0 && y >= 0 && x < n&&y < n) && map[x][y] && !visited[x][y])
		//map내부이고 집이 있고 방문한 적이 없으면
	{
		visited[x][y] = true;
		home++;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			dfs(nx, ny);
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			//cin >> map[i][j];
			scanf("%1d", &map[i][j]);//*******한글자씩 받을 때는 scanf
		}
	}
	//map입력 완료
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j]&&!visited[i][j])//방문한 적이 없고 집이 있으면
			{
				dfs(i,j);
				vil.push_back(home);
				home = 0;
			}
		}
	}
	//총 단지수 출력(vector의 size를 출력하자)
	cout << vil.size() << endl;
	//각 단지내 집의 수를 오름차순으로 출력
	sort(vil.begin(), vil.end());
	for (int i = 0; i < vil.size(); ++i)
	{
		cout << vil[i] << endl;
	}
	return 0;
}
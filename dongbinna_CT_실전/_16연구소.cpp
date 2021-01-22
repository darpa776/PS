#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
int map[8][8];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int cnt = 0;
int safe = 0;//안전영역
int new_safe = 0;
int temp[8][8];



void virus(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m)
		{
			
			if (temp[ny][nx] == 0)
			{
				temp[ny][nx] = 2;
				virus(ny, nx);
			}
		}
		
	}
}

void dfs()
{
	if (cnt >= 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//바이러스 퍼트리기
				if(temp[i][j]==2)
				virus(i, j);
			}
		}
		new_safe = 0;
		//바이러스를 다 퍼트렸으면 안전영역을 검사한다.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (temp[i][j] == 0)
					new_safe++;
			}
		}
		safe = max(safe, new_safe);
		//cnt를 dfs함수에서 제자리로 돌려놔 주기때문에 초기화할필요 없음
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//벽세우기
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				cnt++;
				dfs();
				map[i][j] = 0;
				cnt--;
			}
		}
	}



}

int main()
{//연구소

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	//dfs나 bfs 모두 사용가능하다
	//우선 dfs로 2 옆에 1을 설치한다.

	dfs();

	cout << safe << endl;
	return 0;

}

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	//캐릭터의 위치(A,B) 입력
	int y, x;
	cin >> y >> x;
	//캐릭터 방향 입력
	int dir;
	cin >> dir;
	//map 입력
	int map[50][50];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	//위(0), 오른(1), 아래(2), 왼(3)
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	int visited[50][50] = { 0 };
	int turn = 0;
	int count = 0;//방문한 칸 수

	//현재 위치
	visited[y][x] = 1;
	count += 1;

	while (1)
	{
		//왼쪽 회전
		dir--; turn++;
		if (dir == -1)
		{
			dir = 3;
		}

		if (map[y + dy[dir]][x + dx[dir]] == 0 && !visited[y + dy[dir]][x + dx[dir]])
			//회전한 곳이 육지이고 아직 안가본 곳이면
		{
			visited[y + dy[dir]][x + dx[dir]] = 1;
			y += dy[dir];
			x += dx[dir];
			turn = 0;
			count += 1;
			continue;
		}
		//4면이 다 바다이거나 가본 곳이면
		if (turn == 4)
		{
			//방향은 유지하고 뒤로간다**
			y -= dy[dir];
			x -= dx[dir];
			//**turn을 0으로 만드는 것이 중요**
			turn = 0;

			if (map[y][x] == 1)
				//뒤쪽이 바다라 더이상 이동할 수 없는 경우
				break;

		}

	}
	cout << count << endl;
	return 0;
}
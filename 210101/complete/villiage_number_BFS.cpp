#include <iostream>
#include <queue>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
//상하좌우
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int visited[25][25];
queue<pair<int,int>> q;
int n;
int map[25][25]; // 지도
int village;
int vilnum[700];//1가정 1마을일 경우 25를 넘을 수도 있다.
void bfs(int, int);

int main()
{
	freopen("input.txt", "r", stdin);
	
	cin >> n;
	//cin을 하면 띄어쓰기 해야 하나의 값으로 입력된다.
	//따라서 띄어쓰기 안해도 하나의 값으로 입력받으려면 한자씩 떼야한다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			//cin >> map[i][j];
			scanf("%1d", &map[i][j]);//*******한글자씩 받을 때는 scanf
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 집이면서 방문하지 않았다면 -> 방문
			if (map[i][j] == 1 && visited[i][j] == 0) {
				++village;//village가 항상 1부터 시작한다.
				
				bfs(i, j);
			}
		}
	}
	//마을이 총 몇개인가
	cout << village << endl;
	//몇가정이 있는지(vilnum) 오름차순으로 출력
	sort(vilnum+1,vilnum+village+1);//끝나는지점 + 1 = a(배열의 포인터) + 배열의 크기
	for(int i=1; i<= village ;++i)//village가 항상 1부터 시작한다.
	cout << vilnum[i] <<endl;
	return 0;
}

void bfs(int x, int y)
{
	visited[x][y] = 1;
	q.push(make_pair(x, y));
	++vilnum[village];
	//본인검사

	//이제 주변검사
	while (!q.empty())
	{
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 25 && ny < 25)//범위안인지 검사
			{
				if (visited[nx][ny]==0 && map[nx][ny] == 1 )//방문하지 않은 경우
				{
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					++vilnum[village];//village변수는 항상 1부터 시작이기 때문에 
					//sort 함수에서 begin이 vilnum+1이다.
				}
			}

		}


	}
	return;
}

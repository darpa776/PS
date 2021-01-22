#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int s, x, y;
int map[200][200];
int dx[4] = { 0,0,-1,1 };//상하좌우
int dy[4] = { -1,1,0,0 };
int t = 0;
int visited[200][200];


class Virus {
public:
	int index;
	int second;
	int x; int y;

	Virus(int index, int second, int x, int y) {
		this->index = index;
		this->second = second;
		this->x = x;
		this->y = y;
	}
	bool operator<(Virus& other){
		return this->index < other.index;
	}
};
//queue에 하나의 자료형만 들어갈 수 있기 때문에 새로운 클래스를 만들어줘야함
queue<Virus> q;
vector<Virus> list;

void bfs()
{
	//bfs 안쓰니까 시간초과 남

	while (!q.empty())
	{

		int i = q.front().x;
		int j = q.front().y;
		int now = q.front().index;
		int t=q.front().second;
		//Virus virus=q.front();
		q.pop();

		if (t >=s)
		{
			break;
		}
		if (visited[i][j])
			continue;
		else
			visited[i][j] = 1;
		for (int p = 0; p < 4; p++)
		{
			int ny = i + dy[p];
			int nx = j + dx[p];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)//범위밖이면 전염시키지 않음
				continue;
			else if (map[ny][nx] == 0 && !visited[ny][nx])
			{
				map[ny][nx] = now;
				q.push(Virus(now,t+1,ny,nx));
			}

		}

	}
	return;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j])//0이 아니면
			{
				list.push_back(Virus(map[i][j],0,i,j));
				
			}
		}
	}
	//낮은 번호순대로 정렬
	sort(list.begin(), list.end());
	//정렬한대로 큐에 넣기
	for (int i = 0; i < list.size(); i++)
	{
		
		q.push(list[i]);
	}
	
	cin >> s >> x >> y;

	bfs();
	cout << map[x - 1][y - 1] << endl;
	return 0;

}

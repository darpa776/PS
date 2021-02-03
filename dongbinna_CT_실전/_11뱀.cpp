#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int map[101][101];
vector<pair<int,int>> snake;//뱀이 지나가고 있는 위치
int snake_dir = 0;//뱀 진행방향
queue<pair<int, string>> leftright;
pair<int, int> head;
pair<int, int> tail;

int main() {

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		//사과 위치
		int x, y;
		cin >> y >> x;
		map[y][x] = 1;//사과가 있음을 나타내기
	}
	int l;
	cin >> l;//뱀의 방향변환 횟수
	for (int i = 0; i < l; i++) {
		int x;
		string c;
		cin >> x >> c;
		leftright.push({ x,c });
	}//x초 후 c방향으로 회전
	int t = 0;
	//vector<string> dir = {"R","U","L","D"};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,-1,0,1 };//right, up, left, down
	snake.push_back({ 1,1 });

	while (1) {
		if (leftright.front().first == t)
		{
			if (leftright.front().second == "L")//왼쪽으로 90도 회전
				snake_dir = (snake_dir + 1) % 4;
			else//오른쪽으로 90도 회전
			{
				if (snake_dir == 0) snake_dir = 3;
				else snake_dir--;
			}
			leftright.pop();
		}

		//다음 헤드의 위치를 임의로 이동
		head.first = snake[snake.size()-1].first;
		//head.first = snake.front().first;
		head.first += dy[snake_dir];
		head.second = snake[snake.size() - 1].second;
		//head.second = snake.front().second;
		head.second += dx[snake_dir];



		//head가 존재해야할 위치는 1~n
		if (head.first <1 || head.second <1 || head.first > n || head.second > n)
			//head의 위치가 벽인가? 
		{
			cout << t +1<< endl; return 0;
		}
		//head가 자기자신에게 닿았는가?
		for (int i = 0; i < snake.size(); i++) {
			if (snake[i].first == head.first && snake[i].second == head.second)
			{
				cout << t+1 << endl; return 0;
			}
		}

		//head가 존재해도 되는 위치면
		snake.push_back({ head.first ,head.second });//snake가 지나가고 있는 자리에 head 붙이기
		
		if (map[head.first][head.second] == 1)//사과가 있는가
		{
			map[head.first][head.second] = 0;//사과 없애기
			//tail 유지하기
		}
		else {
			//tail 따라오기
			snake.erase(snake.begin());//snake 길에서 tail 없애기
			//뒤에 들어오는 값이 머리이므로 첫 원소를 없애야한다.
		}
		t++;
	}
	return 0;
}

#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
void _while();
int test_n, T;
int N;//방의 한변의 길이
int map[10][10];// (4 ≤ N ≤ 10)
int ans = 987654321, _time;
int visited[10];//사람들이 어느 계단을 선택할지 나타내는 배열
int left_move[2][10];
queue<int> waitingQ[2];

enum State {
	none, arrive, down, finish, wait
};

struct Stair {
	int x, y;//계단의 위치
	int length;//계단 길이
	int people = 0;//계단에 몇명이 있나
};

struct Person {
	int x, y;//사람의 위치=사람 구분
	int left_stair;//남은 계단수
	int leftmove;//남은 이동수
	State state = none;
	//계단 입구 도착, 계단 내려가기 시작, 이동 완료
};

//출처: https://boycoding.tistory.com/179 [소년코딩]
vector<Stair> stair;//구조체 벡터
vector<Person> person;//구조체 벡터
//vector<Stair> stair2;//구조체 벡터
//vector<Person> person2;//구조체 벡터
int s;//계단구조체벡터 인덱스
int p;//사람구조체벡터 인덱스
//int people_st[2];


int change_state()
{
	//stair check
	for (int i = 0; i < p; ++i)
	{
		if (person[i].state == none && person[i].leftmove == 0)
		{//도착했을경우
			if (stair[visited[i]].people > 3)//계단을 이용하는 사람이 3명이상일 경우
			{
				waitingQ[visited[i]].push(i);
				person[i].state = wait;

			}
			else {
				if (!waitingQ[visited[i]].empty())//큐가 차있는 경우
				{
					person[i].state = wait;
					person[waitingQ[visited[i]].front()].state = down;
					waitingQ[visited[i]].pop();
					stair[visited[i]].people++;
				}
				else//큐가 비어있는 경우
				{
					person[i].state = down;
					stair[visited[i]].people++;
				}
			}
		}
		else if (person[i].state == down && person[i].left_stair == 0)
		{//다 내려온사람의 상태변경
			person[i].state = finish;
			stair[visited[i]].people--;
		}
	}
	_while();
	return 0;
}



////이동하기 위해 남은 함수 계산
void movetime()
{
	for (int i = 0; i < p; ++i) {
	left_move[0][i] = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
	left_move[1][i] = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
}
	return;
}

int _move()
{//한칸이동, 남은 이동수 줄이기
	for (int i = 0; i < p; ++i)
	{
		if (person[i].state == none && person[i].leftmove > 0)
			person[i].leftmove--;
		else if (person[i].state == down && person[i].left_stair > 0)
			person[i].left_stair--;
	}
	change_state();
	//state 변경
	return 0;
}

//사람마다 내려가야하는 계단 길이 계산
void makestairlen() {
	for (int i = 0; i < p; ++i)
	{
		person[i].left_stair = stair[visited[i]].length;
	}

	return;
}
void _while()
{

	while (1)
	{
		for (int i = 0; i < p; ++i)
		{
			if (person[i].state != finish)//한명이라도 도착하지 않았다면
			{
				_time++;
				_move();
			}
			if (i == p - 1 && person[i].state == finish)//모두 도착했다면
			{
				cout << _time << endl;
				ans = _time;
				return;

			}
		}
	}


	//		if (flag)
	//		{//다 내려왔으면 답 도출
	//			if (_time - 1 < ans)
	//				ans = _time - 1;

	//			for (int i = 0; i < p; ++i)
	//			{
	//				person2[i].state = none;
	//			}
	//			//초기화
	//			_time = 0;
	//			numcase++;
	//			break;
	//		}
	//		++_time;
	//		stair2[0].people -= people_st[0];
	//		stair2[1].people -= people_st[1];
	//		people_st[0] = 0, people_st[1] = 0;



	//	++test_n;
	//	cout << "#" << test_n << " " << ans << endl;

	//	//초기화
	//	ans = 987654321, _time = 0, s = 0, p = 0;

	return;
}
int dfs(int idx, int num,int chooseperson)
{
	if (num == chooseperson)
	{
		//출력해보자
		/*for (int i = 0; i<p; ++i)
		{
			cout << visited[i];
		}
		cout << endl;*/

		//left_move의 인덱스가 visited의 값이 된다.
		for(int i=0;i<p;++i){
			person[i].leftmove=left_move[visited[i]][i];
			
		}
		makestairlen();
		_move();

		return 0;
	}
	
	for (int i = idx; i < p; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			dfs(i,num+1, chooseperson);
			visited[i] = 0;
		}

	}
	return 0;
}
void Init()
{
	return;
}

int main()
{
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	//총 테스트 개수 T
	while (T > test_n)
	{
		cin >> N;//방의 한변의 길이
		int map_num;//map을 입력받는 변수
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> map_num;
				if (map_num > 1)//계단인 경우, 계단 자료구조에 위치 저장
				{
					Stair ST;
					stair.push_back(ST);
					stair[s].y = i;
					stair[s].x = j;
					stair[s].length = map_num;
					++s;
				}

				else if (map_num == 1)//사람인 경우, 사람 자료구조에 저장
				{
					Person PS;
					person.push_back(PS);
					person[p].y = i;
					person[p].x = j;
					++p;
				}
			}

		}
		//모든 사람들의 모든 계단에 대한 이동거리 계산
		movetime();

		//조합구하기
		//111111/000000, 111110/000001, ....
		for (int i = 0; i < p; ++i)
		{
			dfs(0, 0, i);//0명 선택부터 p명 선택하는 것까지
			//한번의 경우의 수에 대해서 탐색해보고 다음 경우의 수 탐색해야 함 
		}
		Init();
	}
		return 0;
}


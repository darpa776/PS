#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
void _while();
int test_n, T;
int N;//���� �Ѻ��� ����
int map[10][10];// (4 �� N �� 10)
int ans = 987654321, _time;
int visited[10];//������� ��� ����� �������� ��Ÿ���� �迭
int left_move[2][10];
queue<int> waitingQ[2];

enum State {
	none, arrive, down, finish, wait
};

struct Stair {
	int x, y;//����� ��ġ
	int length;//��� ����
	int people = 0;//��ܿ� ����� �ֳ�
};

struct Person {
	int x, y;//����� ��ġ=��� ����
	int left_stair;//���� ��ܼ�
	int leftmove;//���� �̵���
	State state = none;
	//��� �Ա� ����, ��� �������� ����, �̵� �Ϸ�
};

//��ó: https://boycoding.tistory.com/179 [�ҳ��ڵ�]
vector<Stair> stair;//����ü ����
vector<Person> person;//����ü ����
//vector<Stair> stair2;//����ü ����
//vector<Person> person2;//����ü ����
int s;//��ܱ���ü���� �ε���
int p;//�������ü���� �ε���
//int people_st[2];


int change_state()
{
	//stair check
	for (int i = 0; i < p; ++i)
	{
		if (person[i].state == none && person[i].leftmove == 0)
		{//�����������
			if (stair[visited[i]].people > 3)//����� �̿��ϴ� ����� 3���̻��� ���
			{
				waitingQ[visited[i]].push(i);
				person[i].state = wait;

			}
			else {
				if (!waitingQ[visited[i]].empty())//ť�� ���ִ� ���
				{
					person[i].state = wait;
					person[waitingQ[visited[i]].front()].state = down;
					waitingQ[visited[i]].pop();
					stair[visited[i]].people++;
				}
				else//ť�� ����ִ� ���
				{
					person[i].state = down;
					stair[visited[i]].people++;
				}
			}
		}
		else if (person[i].state == down && person[i].left_stair == 0)
		{//�� �����»���� ���º���
			person[i].state = finish;
			stair[visited[i]].people--;
		}
	}
	_while();
	return 0;
}



////�̵��ϱ� ���� ���� �Լ� ���
void movetime()
{
	for (int i = 0; i < p; ++i) {
	left_move[0][i] = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
	left_move[1][i] = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
}
	return;
}

int _move()
{//��ĭ�̵�, ���� �̵��� ���̱�
	for (int i = 0; i < p; ++i)
	{
		if (person[i].state == none && person[i].leftmove > 0)
			person[i].leftmove--;
		else if (person[i].state == down && person[i].left_stair > 0)
			person[i].left_stair--;
	}
	change_state();
	//state ����
	return 0;
}

//������� ���������ϴ� ��� ���� ���
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
			if (person[i].state != finish)//�Ѹ��̶� �������� �ʾҴٸ�
			{
				_time++;
				_move();
			}
			if (i == p - 1 && person[i].state == finish)//��� �����ߴٸ�
			{
				cout << _time << endl;
				ans = _time;
				return;

			}
		}
	}


	//		if (flag)
	//		{//�� ���������� �� ����
	//			if (_time - 1 < ans)
	//				ans = _time - 1;

	//			for (int i = 0; i < p; ++i)
	//			{
	//				person2[i].state = none;
	//			}
	//			//�ʱ�ȭ
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

	//	//�ʱ�ȭ
	//	ans = 987654321, _time = 0, s = 0, p = 0;

	return;
}
int dfs(int idx, int num,int chooseperson)
{
	if (num == chooseperson)
	{
		//����غ���
		/*for (int i = 0; i<p; ++i)
		{
			cout << visited[i];
		}
		cout << endl;*/

		//left_move�� �ε����� visited�� ���� �ȴ�.
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
	//�� �׽�Ʈ ���� T
	while (T > test_n)
	{
		cin >> N;//���� �Ѻ��� ����
		int map_num;//map�� �Է¹޴� ����
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> map_num;
				if (map_num > 1)//����� ���, ��� �ڷᱸ���� ��ġ ����
				{
					Stair ST;
					stair.push_back(ST);
					stair[s].y = i;
					stair[s].x = j;
					stair[s].length = map_num;
					++s;
				}

				else if (map_num == 1)//����� ���, ��� �ڷᱸ���� ����
				{
					Person PS;
					person.push_back(PS);
					person[p].y = i;
					person[p].x = j;
					++p;
				}
			}

		}
		//��� ������� ��� ��ܿ� ���� �̵��Ÿ� ���
		movetime();

		//���ձ��ϱ�
		//111111/000000, 111110/000001, ....
		for (int i = 0; i < p; ++i)
		{
			dfs(0, 0, i);//0�� ���ú��� p�� �����ϴ� �ͱ���
			//�ѹ��� ����� ���� ���ؼ� Ž���غ��� ���� ����� �� Ž���ؾ� �� 
		}
		Init();
	}
		return 0;
}


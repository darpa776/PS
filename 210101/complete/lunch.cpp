#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int test_n, T;
int N;//���� �Ѻ��� ����
int map[10][10];
int map_num;
int ans=987654321,_time;
enum State {
	none,arrive, down, finish, wait
};

struct Stair{
	int x, y;//����� ��ġ
	int length;//��� ����
	int people=0;//��ܿ� ����� �ֳ�
};

struct Person{
	int x, y;//����� ��ġ=��� ����
	int left_stair[2];//���� ��ܼ�
	int left_move[2];//���� �̵���
	State state=none;
	//��� �Ա� ����, ��� �������� ����, �̵� �Ϸ�
};

	//��ó: https://boycoding.tistory.com/179 [�ҳ��ڵ�]
vector<Stair> stair;//����ü ����
vector<Person> person;//����ü ����
vector<Stair> stair2;//����ü ����
vector<Person> person2;//����ü ����
int s;//��ܱ���ü���� �ε���
int p;//�������ü���� �ε���
int people_st[2];
//�̵��ϱ� ���� ���� �Լ� ���
void movetime(int p)
{
	person[p].left_move[0] = abs(person[p].x - stair[0].x) + abs(person[p].y - stair[0].y);
	person[p].left_move[1] = abs(person[p].x - stair[1].x) + abs(person[p].y - stair[1].y);
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	//�� �׽�Ʈ ���� T
	while (T > test_n)
	{
		cin >> N;//���� �Ѻ��� ����
		for(int i=0;i<N;++i)
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
					
				else if(map_num==1)//����� ���, ��� �ڷᱸ���� ����
				{
					Person PS;
					person.push_back(PS);
					person[p].y = i;
					person[p].x = j;
					++p;
				}
			}

		}


		for (int i = 0; i < p; ++i)
		{
			//�̵��ϱ� ���� ���� �Լ� ���
			movetime(i);
		}
		
		
		int numcase=0;//��� ��츦 �� Ž���ϱ� ���� ����� ��==�����^2
		int case_num = pow(2, p);
		while (numcase < case_num)
		{//���� ����� ���, ��� ����ü ����.
			stair2 = stair;
			person2 = person;

			bitset<10> bitset(numcase);//bitset ����
			//cout << std::bitset<10>(numcase) << ", " << numcase << endl;
			//bitsetũ��==�����==person.size::������ �����ȵǼ� �ִ밪�� 10���� ����
			//[��ó] ��������, ��Ʈ������ ��� | �ۼ��� �ǲ�

			//bitset��� ������� �� ��� ���ϱ�
			//person[0]�� bitset[9]�� ���� ���Ѵ�.person[p](������ ���)�� bitset[6]�� ���� ���Ѵ�.
			//person index+ bitset index+1=10
			//bitset index=9-person index
			/*int wait_flag = 0;*/
			int flag = 1;//�� ���������� flag�� 1, 1���̶� ���������� 0
			while (_time>=0)
			{
				flag = 1;
				for (int i = 0; i < p; ++i)
				{//i==person index
					/*for (int ii = 0; ii < p; ii++)
					{
						if (person2[i].state == wait)
							wait_flag = 1;
					}*/
					//�� ���� �Դ��� Ȯ��
					if (person2[i].state != finish)//::none,arrive, down
					{
						flag = 0;
						if (person2[i].left_move[bitset[i]])//person2[i].state == none
							person2[i].left_move[bitset[i]]--;

						else if (person2[i].left_move[bitset[i]] == 0)//person2[i].state == arrive or down
							//������� �� �̵�������, ����� �����ο� �ľ��� �������� ����
						{
							//none->arrive
							if (person2[i].state == none)
							{
								person2[i].state = arrive;
								person2[i].left_stair[bitset[i]] = stair2[bitset[i]].length;
							}
							else if ( person2[i].state == wait)
							{//wait->down
							
								if (stair2[bitset[i]].people < 3)
								{
									person2[i].state = down;
									person2[i].left_stair[bitset[i]]--;
									stair2[bitset[i]].people++;
								}
								else
								{
								//wait->wait
									person2[i].state = wait;
								}
							}
							else if (person2[i].state == arrive)
							{
								// arrive->down
								
								if (stair2[bitset[i]].people < 3)
								{
									
									/*if (wait_flag == 0)
									{*/
										person2[i].state = down;
										person2[i].left_stair[bitset[i]]--;
										stair2[bitset[ i]].people++;
									//}
									//else
									//	//arrive->wait
									//	person2[i].state = wait;
								}
								else
								{
									//arrive->wait
									person2[i].state = wait;
								}
									
							}
							else if (person2[i].state == down)
							{//down->down
								if (person2[i].left_stair[bitset[  i]] > 0)
								{
									if(person2[i].left_stair[bitset[  i]]==1)
										people_st[bitset[  i]]++;
									person2[i].left_stair[bitset[  i]]--;
								
								}
								else {//down->finish
									person2[i].state = finish;
								}

							}
						}

					}
				}

				if (flag)
				{//�� ���������� �� ����
					if (_time-1 < ans)
						ans = _time-1;
					
					for (int i = 0; i < p; ++i)
					{
						person2[i].state = none;
					}
					//�ʱ�ȭ
					_time = 0;
					numcase++;
					break;
				}
				++_time;
				stair2[0].people -= people_st[0];
				stair2[1].people -= people_st[1];
				people_st[0] = 0, people_st[1] = 0;
			}		
		}	

		++test_n;
		cout << "#" << test_n << " " << ans << endl;
		
		//�ʱ�ȭ
		ans = 987654321, _time=0, s = 0, p = 0;
	}
	return 0;
}


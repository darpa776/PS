#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int test_n, T;
int N;//방의 한변의 길이
int map[10][10];
int map_num;
int ans=987654321,_time;
enum State {
	none,arrive, down, finish, wait
};

struct Stair{
	int x, y;//계단의 위치
	int length;//계단 길이
	int people=0;//계단에 몇명이 있나
};

struct Person{
	int x, y;//사람의 위치=사람 구분
	int left_stair[2];//남은 계단수
	int left_move[2];//남은 이동수
	State state=none;
	//계단 입구 도착, 계단 내려가기 시작, 이동 완료
};

	//출처: https://boycoding.tistory.com/179 [소년코딩]
vector<Stair> stair;//구조체 벡터
vector<Person> person;//구조체 벡터
vector<Stair> stair2;//구조체 벡터
vector<Person> person2;//구조체 벡터
int s;//계단구조체벡터 인덱스
int p;//사람구조체벡터 인덱스
int people_st[2];
//이동하기 위해 남은 함수 계산
void movetime(int p)
{
	person[p].left_move[0] = abs(person[p].x - stair[0].x) + abs(person[p].y - stair[0].y);
	person[p].left_move[1] = abs(person[p].x - stair[1].x) + abs(person[p].y - stair[1].y);
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	//총 테스트 개수 T
	while (T > test_n)
	{
		cin >> N;//방의 한변의 길이
		for(int i=0;i<N;++i)
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
					
				else if(map_num==1)//사람인 경우, 사람 자료구조에 저장
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
			//이동하기 위해 남은 함수 계산
			movetime(i);
		}
		
		
		int numcase=0;//모든 경우를 다 탐색하기 위한 경우의 수==사람수^2
		int case_num = pow(2, p);
		while (numcase < case_num)
		{//실제 사용할 사람, 계단 구조체 복사.
			stair2 = stair;
			person2 = person;

			bitset<10> bitset(numcase);//bitset 선정
			//cout << std::bitset<10>(numcase) << ", " << numcase << endl;
			//bitset크기==사람수==person.size::변수로 지정안되서 최대값인 10으로 지정
			//[출처] 논리연산자, 비트연산자 고급 | 작성자 뽀꾸

			//bitset대로 사람들이 갈 계단 정하기
			//person[0]은 bitset[9]의 값을 취한다.person[p](마지막 사람)은 bitset[6]의 값을 취한다.
			//person index+ bitset index+1=10
			//bitset index=9-person index
			/*int wait_flag = 0;*/
			int flag = 1;//다 내려왔으면 flag가 1, 1명이라도 덜내려오면 0
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
					//다 내려 왔는지 확인
					if (person2[i].state != finish)//::none,arrive, down
					{
						flag = 0;
						if (person2[i].left_move[bitset[i]])//person2[i].state == none
							person2[i].left_move[bitset[i]]--;

						else if (person2[i].left_move[bitset[i]] == 0)//person2[i].state == arrive or down
							//계단으로 다 이동했으면, 계단의 현재인원 파악후 내려가기 시작
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
				{//다 내려왔으면 답 도출
					if (_time-1 < ans)
						ans = _time-1;
					
					for (int i = 0; i < p; ++i)
					{
						person2[i].state = none;
					}
					//초기화
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
		
		//초기화
		ans = 987654321, _time=0, s = 0, p = 0;
	}
	return 0;
}


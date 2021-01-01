#include <iostream>

using namespace std;

//typedef struct desks
//{
//	int person, time;
//}desks;
//접수대, //정비대
int n[10][1001], m[10][1001];

int N, M, K, A, B;
//접수창구가 고장을 접수하는데 걸리는 시간
int ai[10];
//정비창구가 차량을 정비하는데 걸리는 시간
int bj[10];
int tk[1001];
//int person = 0;//손님
int flag;
int  ttt = 1;//최소시간 만큼만 돌자
int nj,mj;
struct person {
	int num;
	int time;
}; 
int desk(int mn[10][1001], struct person*);
int desk_time(int nm[10][1001], int, int);

int main()
{
	int T;

	cin >> T;
	int test_case = 1;

	struct person person[1001];
	while ( T>=test_case) {
		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> ai[i];

		for (int i = 1; i <= M; i++) 
			cin >> bj[i];
		
		for (int i = 1; i <= K; i++)
			cin >> tk[i];

		//---------------입력
		//1. setting
		
		
		//시간 단위 별로 사람을 어떻게 읽어올 수 있는가?
		//tk에 어떻게 접근할 것인가?
		for (int t = 0; ;t++)//시간 증가
		{
			cout << t << "초 상황"<<endl;
			for (int i = ttt;i<=ttt;)//end조건 생각해내기
			{
				cout << i << "번째 사람부터 scan 합니다"<<endl;
				if (tk[i] == t)//해당하는 시간의 사람들 불러내기
				{//i++해줘야 함
					person[i].num = i;
					//person[i].time = 1;
					cout << i<<"번째 손님이 등장했습니다." <<endl;
					for (int j = 0;; j++)
					{
						int time_n = desk(n, &person[j]);
					}

					/////////////
					//만약 데스크가 꽉찻으면 기다리기
					flag = desk_time(n, p->time, i);
					if (flag) { i++; }
				}

				else
				{
					break;
				}
				int out=0;
			//접수처에 있는 사람들 내보내기
			//struct로 해도 매시간 마다 나가도록 검사해야한다.
				for(int i=1;out=0;i++)
				{
					out=desk_time (n, person[i].time+i, i);
				if (!out)
				{
					cout << i << "번째 사람이 나갔습니다." << endl;
					
					
				}
				}
				//마지막 출력

				//ndesk A와 mdeskB의 교집합 구해서 출력
				
			}
			
		}
		test_case++;
	}

}

int desk(desks mn[10],struct person* p)//대기번호가 인자.
{
	//int flag=0;
	//밑부분부터는 함수로 작성해도 괜찮을 듯
	//N_desk에 사람이 없다면 사람을 받자
	for (int i = 1; i <= N; )
	{
		flag = desk_time(n, p->time, i);
		//i번 데스크에 nj번째에 person.num이 앉음
			if (!mn[i][nj]) {//아무도 안 앉았을 때
				


				cout << i << "번 ";
				if (mn == n)
				{
					cout << "접수처에 " ;
					//시간진행함수사용
					//flag = desk_time(n, p->time, i);
					if (flag)
					{
						mn[i] = p->num;//앉히기 성공
					}
					ttt++;
				}
				else if (mn == m)
				{
					cout << "정비소에" ;
					//flag = desk_time(m, p->time, i);
					if (flag)
					{
						mn[i][0] = p->num;
					}
					ttt++;
				}
				//cout <<p->time<< "초 째 앉아있습니다" << endl;

				p->time++;
				//flag = i;
				break;
			}
			else//desk에 사람이 있다면
			{
				i++;//index 증가시켜서 또 확인
				flag = 0;
			}
		
	}
	//for문 다 돌고 사람이 다 차있다면
	return flag;
}

int desk_time(int nm[10],int ptime,int desk_number)
{
	if (nm == n)
	{
		if (ptime == ai[desk_number])
		{
			cout << "더 이상 앉아 있을 수 없습니다.\n" << endl;
			desk_number++;
			nj++;
			return 0;
		}
		else
		{
			cout << "계속 앉아 있을 수 있습니다.\n" << endl;
			return 1;
		}


	}

	else if (nm == m)
	{
		if (ptime == bj[desk_number])
		{
			cout << "더 이상 앉아 있을 수 없습니다.\n" << endl;
			desk_number++;
			mj++;
			return 0;
		}
		else
		{
			cout << "계속 앉아 있을 수 있습니다.\n" << endl;
			return 1;
		}
	}
}
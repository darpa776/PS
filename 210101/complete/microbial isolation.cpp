#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, k, m;
int T, test_case;
int ans;
int chem[100][100];
//int visit[100][100];//n*n*k(최대 깊이)//int형 2차원배열에다가 vector를 넣어보자
vector<int> visit[100][100];//???***???


typedef struct microbial {//미생물 군집
	//pair<int, int> pos;
	int x; int y;//군집 위치
	int num;//미생물 수
	int dir;//방향
	int alive=1;//살아있는지
}microbial;

//queue<microbial> q;
vector<microbial> dic;
void direction(microbial* now, int dir)
{//now의 값 변경이 유효하려면 포인터를 써야함**
	if(dir==1) //상 
		now->x -= 1;
	else if(dir==2)//하
		now->x += 1;
	else if(dir==3)//좌
		now->y -= 1;
	else if(dir==4)//우
		now->y += 1;
}
//******dic은 초기화0과 헷갈리지 않기위해 1부터 시작한다(1~k)
int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin>>n>>m>>k;
		//1. 약품 발린곳 선정
		for (int i = 0; i < n; ++i)
		{
			chem[0][i] = 1;//위 테두리
			chem[n - 1][i] = 1;//아래 테두리
			chem[i][0] = 1;//왼쪽 테두리
			chem[i][n - 1] = 1;//오른쪽 테두리
		}
		microbial trash;
		trash.alive = 0;
		dic.push_back(trash);
		//2.q에 기본 setting
		for(int i=1;i<=k;++i)
		{
			microbial input;
			cin >> input.x>>input.y>>input.num>>input.dir;//군집 입력
			
			dic.push_back(input);
		}
		//입력완료
 		while (m > 0)
		{
			for (int i = 1; i <=k; ++i)
			{
				/*microbial now = q.front();
				q.pop();*/
				
				//1) 방향을 고려해서 다음 갈 곳을 선정
				if (dic[i].alive) {
					direction(&dic[i], dic[i].dir);//새 x,y로 변경됨
					visit[dic[i].x][dic[i].y].push_back(i);//다음 갈 곳에 방문예정 표시
				}
			}
			//2) 다음위치가 중복되는 경우 처리
			//다 돌고 났을 때 2이상인 곳은 충돌한다
			//2 이상인 경우 여기를 방문하겠다고 한 곳을 찾아서 
			//(queue 대신에 벡터로? 좌표들을 저장해놓고 비교할 수 있으니까)
			//미생물수와 방향을 비교하고 합쳐야한다
				//chem인곳도 예외처리 해주기

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (visit[i][j].size() > 1)
					{
						int max_bio = 0;
						int sum_bio = 0;
						//미생물수와 방향을 비교하고 합쳐야한다

						for (int l = 0; l < visit[i][j].size(); ++l)//살아있는 것들만 visit에 적혀있을 것임
						{
							max_bio=max(max_bio,dic[visit[i][j][l]].num);//충격실화 이렇게 쓸수 있다니**
							//벡터 자료형 https://hibee.tistory.com/273 참조
							sum_bio += dic[visit[i][j][l]].num;
						}
						for (int l = 0; l < visit[i][j].size(); ++l)
						{
							if (max_bio == dic[visit[i][j][l]].num)
								//**alive 변수 이용하기 (위의 사이트 참조함)
								//큐가 아니라서 죽은 군집을 pop하기 까다로움
								//dir 바꿀 필요없고 그냥 이 군집에 죽은 미생물들을 넣어주면됨
								dic[visit[i][j][l]].num=sum_bio;
							else
								dic[visit[i][j][l]].alive = 0;//다 주거따
						}

						
					}
				}
			}
			//chem인곳도 예외처리 해주기*************
			for (int i = 1; i <= k; ++i)
			{
				if (dic[i].alive&&chem[dic[i].x][dic[i].y])//살아있고 nx ny가 chem인곳이면
				{//방향바꾸고
					if (dic[i].dir % 2)//홀수면
						dic[i].dir++;
					else//짝수면
						dic[i].dir--;
					//1이면 2로,2이면 1으로, 3면 4로,4이면 3로
					//1또는 3이면 --,2또는 0이면++

				//반틈 죽이기
					if (dic[i].num % 2)//홀수면
						dic[i].num = (dic[i].num - 1) / 2;
					else//짝수면
						dic[i].num /= 2;
				}
			}
			--m;//1시간 경과
			//visit 초기화***
			for (int i = 0; i < 100; ++i)
				for (int j = 0; j < 100; ++j)
				
					visit[i][j].clear();//???***???


			
		}

		//살아있는 미생물의 총합
		
		for (int i = 1; i <=k; ++i)
		{
			if (dic[i].alive)
				ans+=dic[i].num;

		}
		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		ans = 0;//초기화
		dic.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)

				chem[i][j] = 0;
		}
	}
	return 0;
}

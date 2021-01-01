#include <iostream>
using namespace std;
//접수대[]번에 사람이 []+1명 지나갔다.
int n[10][1001];
//정비대
int m[10][1001];
int N, M, K, A, B;
//접수창구가 고장을 접수하는데 걸리는 시간
int ai[10];
//정비창구가 차량을 정비하는데 걸리는 시간
int bj[10];
int tk[1001];
int nj, mj;//지나간 사람의 index
int waitinglist1[1001];
struct person {
	int num;
	int time;
};

int main()
{
	int T;
	cin >> T;
	int test_case = 1;
	struct person person[1001];
	while (T >= test_case) {
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> ai[i];
		for (int i = 1; i <= M; i++)
			cin >> bj[i];
		for (int i = 1; i <= K; i++)
			cin >> tk[i];

		for (int t = 0; ; t++)//시간 증가
		{
			cout << t << "초 상황" << endl;
			for (int j = 0; ;)
			{
				for (int i = 1; i <= K;)//i는 대기번호
				{
						if (tk[i] == t)//손님이 제때 등장하면
						{
							waitinglist1[j] = i;//대기리스트로 부르고
							j++; i++;
						}
						else
						{
							break;
						}
						i++;
					
				}
			}
		}
	}
}
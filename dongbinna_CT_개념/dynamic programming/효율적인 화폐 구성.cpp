#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	//n은 화폐종류,m은 만들고 싶은 돈
	cin >> n >> m;
	//반복문을 이용한 bottomup 접근방식

	//화폐가치 단위를 담을 배열
	int list[100] = { 0 };
	//0으로 초기화할 때말고는 위 초기화 방식은 안먹힘
	//따라서 이렇게 초기화 해줄것..
	vector<int> d(m + 1, 10001);
	//10001값을 가지는 m+1개의 원소


	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	//가장 큰 화폐단위보다 작은 돈을 만들경우
	//가장 큰 화폐만큼 vector를 생성해놓지 않아서= 출력할 답까지만 벡터를 만들어 놓아서
	//에러가 남.
	/*for (int j = 0; j < n; j++)
	{
		d[list[j]] = 1;
	}*/

	//dp 시작
	//**화폐를 아무것도 사용하지 않으면 0원도 만들 수 있는 돈이다.
	d[0] = 0;

	//j가 현재 돈
	//i가 index
	for (int i = 0; i < n; i++)
	{//화폐종류를 바꿔가며 만든다
		for (int j = list[i]; j <= m; j++)
		{//만들고 싶은 돈이 될때까지

			if (d[j - list[i]] != 10001) //**가진 화폐종류로 만들 수 없던 돈이면 현재 j원도 못 만든다
			{
				d[j] = min(d[j], d[j - list[i]] + 1);
				//만약 이전 화폐가 d[j]를 만들어 놓지 않았다면 d[j]=10001일 것임-> 비교후->d[j]=d[j-list[j]]+1
				//만약 이전 화폐가 d[j]를 만들어 놓았다면
				//만들어 놓은 d[j]와 지금 화페가치로 만드려고 하는 값인 d[j-list[j]]+1을 비교
			}
		}
	}


	if (d[m] == 10001) cout << -1;
	else cout << d[m];
	return 0;
}
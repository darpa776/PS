#include <iostream>
#include <vector>
using namespace std;

int n;//사람수
//vector<pair<int, int>> person;//사람 정보 저장
int person[100][3];//사람 정보 저장+등수
int cnt;
int k;
int main()
{
	cin >> n;
	int a, b = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		person[i][0] = a;//몸무게
		person[i][1] = b;//키

	}
	//입력 다받음
	//비교시작
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)//i는 기준 j가 비교대상
		{
			if (i == j)
				continue;

			if ((person[i][0] < person[j][0]) && person[i][1] < person[j][1])//덩치큰 사람(k) 세아리기
				++k;

		}
		person[i][2] = k + 1;
		k = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << person[i][2] << endl;
	}

	return 0;
}
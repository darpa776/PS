#include <iostream>
#include <vector>
using namespace std;

int n;//사람수
//vector<pair<int, int>> person;//사람 정보 저장
int person[100][3];//사람 정보 저장+등수
int cnt;

int main()
{
	cin >> n;
	int a, b = 0;
	int equal=0;
	person[0][2] = -200;//나중에 shift한 후의 값(+부호)이 기존값과 헷갈리지 않도록
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		person[i][0] = a;//몸무게
		person[i][1] = b;//키


		for (int j = 0; j < i; ++j)
		{
			if (person[j][0] > a)//새 입력이 기존보다 몸무게 가벼우면 --;
				--cnt;
			else if (person[j][0] < a)
				++cnt;
			else if (person[j][0] < a)
				++equal;
			if (person[j][1] > b)
				--cnt;
			else if (person[j][1] < b)
				++cnt;
			else if (person[j][1] < b)
				++equal;

			if (cnt == 0||equal)
				person[i][2] = person[j][2];
			else if (cnt < 0)
				person[i][2] = person[j][2] + 1;
			else if (cnt > 0)
				person[i][2] = person[j][2] - 1;
			cnt = 0;
			equal = 0;
		}


	}

//	for (int i = 0; i < n; ++i)
//	{
//		cout << person[i][2] << endl;
//	}


	//shift
	signed int min = 5000;//임의

	for (int i = 0; i < n; ++i)
	{
		if (min > person[i][2])
		{
			min = person[i][2];
			//동일한 min 등수값을 가진 친구들이 많을 수 있다.
		}

	}
	//2. 최소값인 친구가 몇명인지 세아리기
		//1등부여

	int k = 0;
	int rank = 1;//등수 저장
	while (rank <= n)//퇴근 조건 잘 살피기
	{
		for (int i = 0; i < n; ++i)
		{
			if (min == person[i][2])
			{
				person[i][2] = rank;
				++k;
			}

		}
		++min;
		rank += k;
		k = 0;

	}

	for (int i = 0; i < n; ++i)
	{
		cout << person[i][2] << endl;
	}
	return 0;
}
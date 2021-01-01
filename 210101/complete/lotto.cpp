#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//1~49까지 k개 숫자 중에서 6개 고르기
//S와 k가 주어졌을 때 수 고르기
//S가 주어지므로 permutation 함수를 쓰는 것이 편리할 듯

bool cmp(vector<int> a,vector<int> b)
{
	return a < b;
}

//정수를 내림차순 정렬할 때:greater<int>() 를 sort의 마지막 인자로 써주면 된다

int main()
{
	//0이 아니면 계속 입력 받기
	vector<int> k;
	vector<vector<int>> s(10, vector<int>(20));
	
	int var;
	vector<int> trick;
	int test_case = 0;

	cin >> var;
	
	while (var != 0)
	{
		k.push_back(var);
		for (int i = 0; i < k[test_case]; ++i){
			cin >> var;
			s[test_case][i]=var;
		}

		++test_case;//이제 test_case 1
		cin >> var;
	}
	int T = test_case;
	test_case = 0;
	while (T>test_case) {
		//현재 출력은 0111111->1011111->... 
		//답안 출력은 1111110->1111101->... 되어야함
		for (int i = 0; i < 6; ++i)
			trick.push_back(1);
		for (int i = 0; i < k[test_case] - 6; ++i)
			trick.push_back(0);

		//sort(trick.begin(), trick.end(), greater<int>());

		//내림차순으로 sorting하면 1111110, greater<int>()
		//내림차순 후 do,while(prev_per)하면 똑바로, 전부 출력됨
		//내림차순 후 do,while(next_per)하면 똑바로, 하나만 출력됨

		//오름차순으로 sorting하면 0111111
		//오름차순 후 do,while(prev_per)하면 거꾸로, 하나만 출력됨
		//오름차순 후 do, while(next_per)하면 거꾸로, 전부 출력됨

		//for (int i = 0; i < trick.size(); ++i)
		//	cout << trick[i];
		//cout << endl;
		do{
			for (int i = 0; i < k[test_case]; ++i)
			{
				if (trick[i])
					cout << s[test_case][i] << " ";
			}
			cout << endl;
		} while (prev_permutation(trick.begin(), trick.end()));
		//next_permutation 대신에 prev_permutation 사용

		cout << endl;
		trick.clear();
		//s.clear();
		++test_case;
	}
	return 0;
}
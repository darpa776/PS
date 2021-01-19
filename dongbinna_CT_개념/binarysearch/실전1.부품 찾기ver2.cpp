#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<int> origin;
vector<int> custom;
int target;

//동일한 문제를 set자료형을 이용해 풀이
int main()
{
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		origin.insert(x);
	}
	//손님의 요구사항 입력
	int m;
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		int x;
		cin >> x;
		custom.push_back(x);
	}

	////회사 부품, 손님이 요구하는 부품들 정렬 후 이진탐색
	//sort(origin.begin(), origin.end());
	//sort(custom.begin(), custom.end());

	for (int i = 0; i < m; i++)
	{
		if (origin.find(custom[i])!=origin.end())
			//origin 안에 찾는 값의 위치가 end()가 아니라면 부품이 존재
			//find 함수는 매개변수의 위치를 리턴함
			cout << "yes ";
		else
			cout << "no ";
		
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<pair<int, int>> info;
////dist, house
vector<int> house;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{//집의 위치 입력받기
		int x;
		cin >> x;
		house.push_back(x);
	}
	////연산시작
	//for(int i=0;i<n;i++)
	//{
	//	int antenna = house[i];
	//	int dist = 0;
	//	for (int i = 0; i < n; i++)
	//	{
	//		dist += abs(house[i] - antenna);
	//		
	//	}
	//	info.push_back({dist,antenna});
	//}
	//sort(info.begin(), info.end());
	//cout << info[0].second;
	sort(house.begin(), house.end());

	//n-1: 마지막 인덱스 값
	// 중간값(median)을 출력
	cout << house[(n - 1) / 2] << '\n';
}

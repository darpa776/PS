#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> origin;
vector<int> custom;
int target;

//재귀함수로 작성하기
 void binarysearch(int start, int end)
{
	 if (start > end)
	 {
		 cout << "no ";
		 return;
	 }
	int middle = (start + end) / 2;
	if (origin[middle] > target) return binarysearch(start, middle-1);
	else if (origin[middle] < target) return binarysearch(middle+1,end );
	else if (origin[middle] == target)
	{
		cout << "yes ";
		return;
	}
}
//이진탐색을 이용한 코드를 작성했으나, 계수정렬방법처럼 배열을 이용해 origin벡터에 존재하는
//부품은 1로 처리하고 custom벡터를 받으면서 해당 부품이 존재하는지 확인하는 방법도 있다.
//또는 set 함수를 이용해 단순히 특정한 수가 한 번이라도 등장했는지를 검사하면 된다.

int main()
{
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		origin.push_back(x);
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

	//회사 부품, 손님이 요구하는 부품들 정렬 후 이진탐색
	sort(origin.begin(), origin.end());
	sort(custom.begin(), custom.end());

	for (int i = 0; i < m; i++)
	{
		target = custom[i];
		binarysearch(0, n - 1);
	}
	return 0;
}
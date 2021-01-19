#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool reverse(int a, int b)
{
	return a > b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> A;
	vector<int> B;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		B.push_back(x);
	}
	//1. 수열 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), reverse);

	//2. A의 최소값과 B의 최대값을 교환!
	int count_=0;
	while (count_ < k)
	{
		if (A[count_] < B[count_])
		{
			swap(A[count_], B[count_]);
			count_++;

		}
		else
		break;
	}

	//3. 합을 출력
	int ans=0;
  //입력되는 수를 보아하니 longlong 자료형을 쓰는 것이 좋을듯함
  //앞으로 신경쓸 것
	for (int i = 0; i < n; i++)
	{
		ans += A[i];
	}
	cout << ans;
	return 0;
}
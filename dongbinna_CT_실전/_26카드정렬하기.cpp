#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(-x);
	}
	
	//if(pq.size()==1)
	//{//예외처리 없음
	//	cout << -pq.top();
	//	pq.pop();
	//	return 0;
	//}
	int ans = 0;
	while (pq.size()>=2)
	{
		int one = -pq.top();
		pq.pop();
		int two = -pq.top();
		pq.pop();

		// 카드 묶음을 합쳐서 다시 삽입
		int sum = one + two;
		ans += sum;
		pq.push(-sum);
	}
	cout << ans;
	return 0;
}

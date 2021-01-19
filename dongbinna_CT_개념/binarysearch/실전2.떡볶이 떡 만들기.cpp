#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, m;
//떡의 개수 n, 요청한 떡의 길이 m
int ans;

int cut(int key)
{
	int sum=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - key > 0)
			sum += (arr[i] - key);
	}
	return sum;
}

int main()
{
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	//이진탐색,,자를 길이를 전부 다 탐색하는 것을 편히 하기 위해 이진탐색 사용
	//0이 start, 최대길이가 end
	int start = 0;
	sort(arr.begin(), arr.end());
	int end = arr[n - 1];
	

	//이진탐색시작
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (cut(mid) > m)
		{
			//더 많이 줬음
			start = mid + 1;
			ans = mid;
			//돌다가 while문에 안맞으면 그대로 나갈것임
			//현재 mid값도 정답이 될 수 있으므로 ans에 저장
		}
		else if (cut(mid) < m)
		{
			//저기요 제가 주문한 양보다 더 적은데요
			end = mid - 1;
		}
		else if (cut(mid) >= m)
		{//더 많이 줬거나 딱맞는 경우
			ans = mid;
			break;
		}
		
	}
	cout << ans << endl;
	return 0;
}
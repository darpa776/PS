#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int start = 0;
	int end = n - 1;
	
	while (start<=end) {
		int mid = (start+end) / 2;
		if (v[mid] > mid) {//뒤는 고정점 있을 확률이 없다
			end = mid - 1;
		}
		else if (v[mid] < mid) {//앞은 고정점 있을 확률이 없다
			start = mid + 1;
		}
		else if (v[mid] ==mid) {//고정점 찾았다
			cout << mid<<endl;
			return 0;
		}

	}
		cout << -1 << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	//입력받으면서 최소값 확인하기
	//int chart[100];//배열 필요없음!
	int x;//임의의 변수
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{//**행의 첫 비교마다 최소값을 새로 설정해주어야하므로
  //for문 안에 선언**
    int tmp=10001;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			tmp = min(tmp, x);
			//tmp= 한행 중 가장 작은 값
		}
		ans = max(tmp, ans);
	}
	cout << ans << endl;
	return 0;
}
//재귀 dfs,backtracking 10-18(2)
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//하루에 한명씩 꼭 상담을 잡아 놓았으므로 나름 쉽게 문제를 설계해놓은 것 같다
//dfs에서 정해줄 것은 두경우(상담o,상담x)
int ans, sum;
int n;
int t[15];
int p[15];
int visited[15];
void work(int day)//day부터 시작
{
	for (int i = 0; i < 2; ++i)
	{
		//8일째면 dfs가능,10일째도 가능, 입력받은 day가 11부터는 안됨
		if (day >= n) return;
		//11일은 아니고 더 진행하면 10일넘는 경우는 continue해서 day+1을 진행하게 한다
		//0부터 시작일 때 9일째 되는 날(10일==n) 1일치 일이면 할수 있따


		if (i == 0)//상담o
		{
			if (day + t[day] > n) continue;

			//일하자
			sum += p[day];//돈먼저 받자
			ans = max(ans, sum);
			work(day + t[day]);
			sum -= p[day];
			//day -= t[day];			
		}
		if (i == 1)//상담x
			work(day + 1);

	}
	return;
}
int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i] >> p[i];
	}
	for (int i = 0; i < n; ++i)
	{
		work(i);
		sum = 0;
	}

	cout << ans << endl;


	return 0;
}

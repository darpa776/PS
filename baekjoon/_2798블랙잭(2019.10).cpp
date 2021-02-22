#include <iostream>

using namespace std;

int n;//카드 장수
int m;//최대값
int visited[101];
int sum,ans;//case 끝날때마다 초기화
int flag;//한번에 종료위한 변수
int card[101];

void dfs(int num, int selected)
{
	if (selected >= 3)
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (visited[i] == 1)
				//cout << i << " ";
				sum += card[i];
		}
		//cout << endl;
		if (sum == m)
		{
			ans = m;
			flag = 1;
			return;
		}
		else if (sum < m && ans < sum)
		{
			ans = sum;
			
			return;
		}
		return;//***이거 꼭해주기...이거 안해줘서 시간초과 남

	}
	for (int i = num; i < n; ++i)
	{
		if (flag)
			return;
	
		if (visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i, selected + 1);
			visited[i] = 0;
		}
	}
	
}

int main()
{
	/*ios::sync_with_stdio(0);
	cin.tie(0);*/
	//freopen("sample_input.txt", "r", stdin);
	/*cin >> n;
	cin >> m;*/
	scanf("%d", &n);
	scanf("%d", &m);
	//카드 내용
	for (int i = 0; i < n; ++i)
	{
		//cin >> card[i];
		scanf("%d", &card[i]);
	}
	dfs(0, 0);
	printf("%d", ans);

	//초기화(삼성 칠때는 꼭 챙기기)
	/*ans = 0;
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}*/
	return 0;
}

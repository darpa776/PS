#include <iostream>

using namespace std;
int n,m;
int visited[10];
int ans[10];

int dfs( int cnt) {
	if (cnt == m) 
	{
		for (int i = 0; i < n; ++i)
		{
			/*if (visited[i])
				cout << i + 1 << " ";*/;//이렇게만하면 오름차순으로 출력됨
		if (ans[i])
			cout << ans[i] << " ";

		}
		cout << endl;//시간제한이 1초이므로
		//cout << "\n";//을 사용하는 것이 바람직
		return 0;
	}

	for (int i = 0; i < n; ++i)//시작이 0이므로 처음부터 다돎
	{
		if (!visited[i])
		{
			visited[i] = true;
			ans[cnt] = i+1;
			dfs(cnt+1);
			visited[i] = false;
		}
	}
	return 0;
}
int main() {
//일단 입력 받기
	cin >> n>>m;
//1부터 n까지의 숫자중에 m개 골라서 출력
	dfs(0);
	return 0;
}

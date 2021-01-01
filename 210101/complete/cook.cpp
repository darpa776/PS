#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int test_case = 1;
int n;
int map[17][17];//������� �� N�� 4�̻� 16������ ¦���̴�. 
int visited[17];
vector<int> A;
vector<int> B;
int sumA, sumB;
int result;
int ans = 100000;

int cal()
{
	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			A.push_back(i);

		else
			B.push_back(i);
	}
	for (int i = 0; i < n/2; ++i)
	{
		for(int j=i+1;j<n/2;++j)
		{
		sumA += map[A[i]][A[j]] + map[A[j]][A[i]];
		sumB += map[B[i]][B[j]] + map[B[j]][B[i]];
		}

	}
	//�� �丮�� ���� ��������� ������ �ó��� ���� ���
	result = sumA - sumB;
	if (result < 0)
		result = -result;
	if (ans > result)
		ans = result;
	
	//�ʱ�ȭ
	sumA = 0; sumB = 0;
	A.clear(); B.clear();
	return 0;
}
int dfs(int chk, int idx)
{
	if(chk==n/2)
	{	
		/*for (int i=0;i<n;++i)
		{
			cout << visited[i];			
		}
		cout << endl;*/
		cal();
		
		

	}
	for (int i = idx; i < n; ++i)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(chk+1,i);//idx�� i �ִ� ������: ���� ��ġ���� Ž���ؼ� �ߺ��� ���ϱ� ������**
		visited[i] = 0;
	}
	return 0;
}
int main() {

	freopen("sample_input.txt", "r", stdin);
	
	cin >> T;
	while (T >= test_case) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for(int j=0;j<n;++j){
			cin >> map[i][j];
			}
		}
		dfs(0,0);

		cout << "#" << test_case << " " << ans << endl;
		test_case++;
		//�ʱ�ȭ
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				map[i][j]=0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			visited[i] = 0;
		}
		ans = 100000;
	}
	return 0;
}
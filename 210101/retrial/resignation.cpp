//��� dfs,backtracking 10-18(2)
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//�Ϸ翡 �Ѹ� �� ����� ��� �������Ƿ� ���� ���� ������ �����س��� �� ����
//dfs���� ������ ���� �ΰ��(���o,���x)
int ans, sum;
int n;
int t[15];
int p[15];
int visited[15];
void work(int day)//day���� ����
{
	for (int i = 0; i < 2; ++i)
	{
		//8��°�� dfs����,10��°�� ����, �Է¹��� day�� 11���ʹ� �ȵ�
		if (day >= n) return;
		//11���� �ƴϰ� �� �����ϸ� 10�ϳѴ� ���� continue�ؼ� day+1�� �����ϰ� �Ѵ�
		//0���� ������ �� 9��° �Ǵ� ��(10��==n) 1��ġ ���̸� �Ҽ� �ֵ�


		if (i == 0)//���o
		{
			if (day + t[day] > n) continue;

			//������
			sum += p[day];//������ ����
			ans = max(ans, sum);
			work(day + t[day]);
			sum -= p[day];
			//day -= t[day];			
		}
		if (i == 1)//���x
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

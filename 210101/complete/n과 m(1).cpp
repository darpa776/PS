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
				cout << i + 1 << " ";*/;//�̷��Ը��ϸ� ������������ ��µ�
		if (ans[i])
			cout << ans[i] << " ";

		}
		cout << endl;//�ð������� 1���̹Ƿ�
		//cout << "\n";//�� ����ϴ� ���� �ٶ���
		return 0;
	}

	for (int i = 0; i < n; ++i)//������ 0�̹Ƿ� ó������ �ٵ�
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
//�ϴ� �Է� �ޱ�
	cin >> n>>m;
//1���� n������ �����߿� m�� ��� ���
	dfs(0);
	return 0;
}

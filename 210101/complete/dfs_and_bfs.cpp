#include <iostream>
#include <queue>
using namespace std;

bool map[1001][1001];
bool visited[1001];
int n, m, v;
queue<int> q;

//�湮�� ������ �������� ��� ������ȣ�� ���� �� ���� �湮
void dfs(int node)
{
	visited[node] = 1;
	cout << node << " ";

	for (int i = 1; i <= n; ++i)
	{
		if (map[node][i] && !visited[i])//���� �� ���� �湮��������
		{
			dfs(i);//���� ���� �湮
		}
	}
	return;
}

void bfs(int node)
{
	q.push(node);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (!visited[now])
		{
			visited[now] = 1;
			cout << now << " ";

			for (int i = 1; i <= n; ++i)
			{
				if (map[now][i]&&!visited[i])
				{
					q.push(i);
					//���⿡ visit=1���ָ� ť�� �� �ִ°� ��� ���α׷� ����ð��� �� ª������
				}
			}
		}
	}

	//https://twpower.github.io/73-how-to-implement-dfs-and-bfs-in-cpp ����
	//���� ��ũ������ push�ϰ� �ٷ� visit�Ѵ�. visit�� vertex�� ���̻� ť�� �־����� �ʱ�

	return;
}

int main()
{
	cin >> n >> m >> v;
	for (int a = 0; a < m; ++a)//m�� �Է�
	{//������� �����
		int i, j;
		cin >> i >> j;
		map[i][j]=1;
		map[j][i]=1; //����� ����
	}

	//dfs
	dfs(v);
	cout << endl;
	//�ʱ�ȭ
	for (int i = 1; i <= n; ++i)
		visited[i] = 0;
	//bfs
	bfs(v);
	cout << endl;
	return 0;
}
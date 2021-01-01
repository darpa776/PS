#include <iostream>
#include <queue>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
//�����¿�
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int visited[25][25];
queue<pair<int,int>> q;
int n;
int map[25][25]; // ����
int village;
int vilnum[700];//1���� 1������ ��� 25�� ���� ���� �ִ�.
void bfs(int, int);

int main()
{
	freopen("input.txt", "r", stdin);
	
	cin >> n;
	//cin�� �ϸ� ���� �ؾ� �ϳ��� ������ �Էµȴ�.
	//���� ���� ���ص� �ϳ��� ������ �Է¹������� ���ھ� �����Ѵ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			//cin >> map[i][j];
			scanf("%1d", &map[i][j]);//*******�ѱ��ھ� ���� ���� scanf
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// ���̸鼭 �湮���� �ʾҴٸ� -> �湮
			if (map[i][j] == 1 && visited[i][j] == 0) {
				++village;//village�� �׻� 1���� �����Ѵ�.
				
				bfs(i, j);
			}
		}
	}
	//������ �� ��ΰ�
	cout << village << endl;
	//����� �ִ���(vilnum) ������������ ���
	sort(vilnum+1,vilnum+village+1);//���������� + 1 = a(�迭�� ������) + �迭�� ũ��
	for(int i=1; i<= village ;++i)//village�� �׻� 1���� �����Ѵ�.
	cout << vilnum[i] <<endl;
	return 0;
}

void bfs(int x, int y)
{
	visited[x][y] = 1;
	q.push(make_pair(x, y));
	++vilnum[village];
	//���ΰ˻�

	//���� �ֺ��˻�
	while (!q.empty())
	{
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 25 && ny < 25)//���������� �˻�
			{
				if (visited[nx][ny]==0 && map[nx][ny] == 1 )//�湮���� ���� ���
				{
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					++vilnum[village];//village������ �׻� 1���� �����̱� ������ 
					//sort �Լ����� begin�� vilnum+1�̴�.
				}
			}

		}


	}
	return;
}

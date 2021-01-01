#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T, test_case;
int ans;
int map[50][50];
int n, m, r, c, l;
int visited[50][50];
//�����¿�
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int nx, ny;
queue<pair<int,int>> q;
//x,y���� nx,ny��
//��:(�ϰ� �ո� ��)1,2,5,6
//��:(���� �ո� ��)1,2,4,7
//��:(�찡 �ո� ��)1,3,4,5
//��:(�°� �ո� ��)1,3,6,7
vector<vector<int>> dest = { {0,1,2,3}, {0,1},{2,3},{0,3},{1,3},{1,2},{0,2} };




int go2(int nx,int ny, int i)//i�� �����¿츦 ��Ÿ���� �ε���
{
	if (i == 0)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6) return 1;
		else return 0;
	}

	else if (i == 1)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7)
			return 1;
		else return 0;
	}
	else if (i == 2)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
			return 1;
		else return 0;
	}
	else if (i == 3)
	{
		if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7)
			return 1;
		else return 0;
	}
	
}

void go(int x, int y)
{
	q.push(make_pair(x,y));
	visited[x][y] = 1;
	//��Ȧ������ 1�ð����� �ִ�

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;

		q.pop();
		if (map[now_x][now_y])//&&!visited[now_x][now_y]
		{
			for (int i = 0; i < dest[map[now_x][now_y]-1].size(); ++i)//map[now_x][now_y]==1�̸� dest[0]���� ����
			{
				nx = now_x + dx[dest[map[now_x][now_y] - 1][i]];
				ny = now_y + dy[dest[map[now_x][now_y] - 1][i]];
				// �� ���� ����ٸ�
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				//����Ǿ��ִ��� Ȯ��
				if (go2(nx, ny, dest[map[now_x][now_y]-1][i]) && !visited[nx][ny])//���ᰡ���ϰ� �湮���� ���� ���
				{//����Ǿ�������
					q.emplace(make_pair(nx, ny));
					visited[nx][ny] = 1 + visited[now_x][now_y];
				}
			}
		}

	}
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin>>n >>m >>r >> c>>l;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>map[i][j];

		go(r,c);

		//������� visited�� ���� �̵��ð� L������ ��찡 �� ������ ���
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visited[i][j]>0 && visited[i][j] <= l)
					//***0�� ���� ���Ƹ��ΐ���, �������ؾ���
				{
					ans++;
				}

			}
		}

		
		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		
		//�ʱ�ȭ
		ans = 0;
		
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}*/


		for (int i = 0; i < n; i++) {
			memset(map[i], 0, sizeof(int) * m); //��� �� 0���� �ʱ�ȭ
			memset(visited[i], 0, sizeof(int) * m);
		}
		//��ó: https://dahyeee.tistory.com/entry/c-2����-�迭-�ʱ�ȭmemset���

			
	}
	return 0;
}

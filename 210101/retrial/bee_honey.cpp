#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
// (3 �� N �� 10)
// (1 �� M �� 5)
//(10 �� C �� 30)

using namespace std;
int map[10][10];//�����
int T, test_case;
int ans;
int n, m, c;
bool visited[6];//����
int sum;
bool check[100];//n*n

typedef struct node{
	int x; int y; int profit;
}node;

vector<node> profit_list;

void honey(int x, int y, int idx, int cnt, int t)//m�� �� �����غ���
{//https://yabmoons.tistory.com/99 ����
	if (cnt == t)
	{
		//print();
		//visited==true�ΰ� ����ϱ�
		int tmp = 0;//sum�� ���� tmp
		int crit=0;//c�� ���� ���� ��
		for(int k = 0; k < 6; ++k)
		{
			if (visited[k])// k:������ ���� index
			{
				tmp += pow((map[x][y + k]),2);
				crit += map[x][y + k];
			}
		}
		if (crit > c)
		{
			return;
		}
		sum = max(sum, tmp);
		
		//cout<<sum << endl;
		return;
	}
	for (int i = idx; i < m; ++i)
	{
		if (visited[i] == true) continue;
		visited[i] = true;
		honey(x,y,i, cnt + 1, t);
		visited[i] = false;
	}

	return;
}
bool Compare(node& first, node& second)
{
	return first.profit > second.profit; // ���ϰ� ���� T Ÿ���� ������ ����� ���ؾ� �Ѵ�
}

//��ó: https://celdee.tistory.com/281 [������ ���]


void comb(int idx, int cnt)
{//https://yabmoons.tistory.com/99
	
	if (cnt == 2)//2������
	{
		int tmp = 0;
		//print();
		//check==true�ΰ� ���ؼ� max==ans
		int flag = 0;
		int a, b;
		for (int k = 0; k < profit_list.size(); ++k)
		{
			if (check[k])
			{
				++flag;
				if (flag == 1)//ù��° ��ġ
					a = k;
				if (flag == 2)
					b = k;

			}
		}


		if (profit_list[a].x == profit_list[b].x)//���� ���̰�
		{
			if (profit_list[a].y + m <= profit_list[b].y)//������ �Ȱ�ġ��
			{
				tmp = profit_list[a].profit + profit_list[b].profit;
				ans = max(ans, tmp);
			}
		}
		else//�ٸ����̸� ������ ������ ����ϸ� ��
		{
			tmp = profit_list[a].profit + profit_list[b].profit;
			ans = max(ans, tmp);
		}
	
		return;
	}
	for (int i = idx; i < profit_list.size(); ++i)//profit_list.size()�߿��� 2�� ����
	{
		if (check[i] == true) continue;
		check[i] = true;
		comb(i, cnt + 1);
		check[i] = false;
	}

	return;
}



int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin>>n>>m>>c;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> map[i][j];

		for (int i = 0; i < n; ++i) 
		{
			for (int j = 0; j < n-(m-1); ++j) 
			{
				for (int l = 1; l <= m; ++l)
				{
					honey(i, j, 0, 0, l);//��(i,j)��ġ���� m���� �� �߿� ������ index���� �����غ���
				}
				node a;
				a.x = i; a.y = j; a.profit = sum;
				profit_list.push_back(a);
				//cout << sum << endl;
				sum = 0;
			}
		}
		//��� ���͵��� ū ������� ������
		//sort(profit_list.begin(), profit_list.end(), Compare);//profit�������� ���� setting
		//������ �� �����غ��Ŵϱ� sorting�غ��ʿ� ���� ��
		
		//���սἭ ������ ��ġ���� Ȯ��
		int tmp=0;
		comb(0, 0);
		
		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		//�ʱ�ȭ
		ans = 0;
		profit_list.clear();

	}
	return 0;
}

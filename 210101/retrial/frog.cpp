#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <time.h> 
using namespace std;

int T, test_case;
int ans;
int n, a, k;
vector<pair<int,int>> stone;
queue<int> q;
int dist;
//int visited[100000000];
//�ִ���� �����غ���
//�ִ������ 10�� 9���̱� ������ �ٸ� ����� ã�ƾ���. k�� �־����־ �׸���ε� Ǯ��
//k�ִ���� �Ѿư���
//������ ������ stone�� pair�� ���ͷ� ������µ� �ð��ʰ��� ����.......�������� 1�� �Ѱ� �ɸ��� Ǯ���Ÿ
void frog()
{
	int b = stone.back().first;
	q.push(0);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
	
		for (auto i = stone.begin(); i < stone.end(); ++i)
		{
			if (now == (*i).first)
			{
				dist = (*i).second; 
			}
			if (( (*i).first <= now + k)&& !(*i).second&&(now < (*i).first))
			{
				(*i).second = dist+ 1;
				q.push((*i).first);
				if ((*i).first == b)
				{
					ans = (*i).second; return;
				}
			}
				
			//������ ���� ������ ������ ���� visited�� ans�� �ְ� ���,����
			//visited�� ��� �ѹ� �� �湮���� �ʱ�
			//!visited�� ��� �湮�ϱ�
			//q���� ������ visited�� ������Ŵ
		}
	}

}
int main() {
	//clock_t start, end;
	//double result;
	//start = clock();
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin >> n;

		stone.push_back(make_pair(0, 0));
		for (int i = 0; i < n; ++i) //n���� ��
		{
			cin >> a;
			stone.push_back(make_pair(a,0));
		}
		cin >> k;
		//�Է¿Ϸ�
		frog();
		//cout << stone.back() << endl;


		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		//�ʱ�ȭ
		ans = -1;
		stone.clear();
		


	}
	//end = clock();
	//result = (double)(end - start);
	//cout << result;
	return 0;
}

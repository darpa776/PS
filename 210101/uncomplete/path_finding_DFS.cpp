#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<vector<int>> adj;
//int adj[100][100];
int N;
stack<int> st;
vector<int> visited;
//�� ������� �ȵǳ�. �� ������ �߻��ϳ�
void PRINT() {

	for (int i = 0; i < st.size(); ++i)
	{
		
		cout<<visited[i];

	}
	cout << endl;
}
void AAA(int begin)
{
	//�湮�ߴ��� Ȯ���ϱ�
	if (visited[begin]) return;
	else {
		visited[begin] = 1;
		for (int i = 0; i < adj[begin].size(); ++i)
		{
			if (adj[begin][i])//�������� ����Ǵ� vertex�� �ִٸ�
			{
				cout << begin;
				st.push(adj[begin][i]);//���ÿ� �ְ�
				AAA(adj[begin][i]);//����Լ�
				st.pop();
				cout << ","<<endl;
			}
			

		}
		visited[begin] = 0;
	}
}

int main()
{
//else//�������� ����Ǵ� vertex�� ������
//			{
//			//���� ���� �Ǵ� print
//			//PRINT();
//			//return;
//			}
	
	cin >> N;
	//adj�� �Է³ֱ�
	/*for (int i = 0; i < N; ++i)	
		for (int j = 0; j < N; ++j)
			cin>>adj[i][j];*/

	adj = { {0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0},
	{1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0 ,0 ,1},
	{0, 0, 1, 0, 0, 0, 0} };
	AAA(0);//0�� vertex���� ����
}
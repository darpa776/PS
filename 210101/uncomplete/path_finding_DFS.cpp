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
//왜 디버깅이 안되나. 왜 에러가 발생하나
void PRINT() {

	for (int i = 0; i < st.size(); ++i)
	{
		
		cout<<visited[i];

	}
	cout << endl;
}
void AAA(int begin)
{
	//방문했는지 확인하기
	if (visited[begin]) return;
	else {
		visited[begin] = 1;
		for (int i = 0; i < adj[begin].size(); ++i)
		{
			if (adj[begin][i])//다음으로 연결되는 vertex가 있다면
			{
				cout << begin;
				st.push(adj[begin][i]);//스택에 넣고
				AAA(adj[begin][i]);//재귀함수
				st.pop();
				cout << ","<<endl;
			}
			

		}
		visited[begin] = 0;
	}
}

int main()
{
//else//다음으로 연결되는 vertex가 없으면
//			{
//			//스택 저장 또는 print
//			//PRINT();
//			//return;
//			}
	
	cin >> N;
	//adj에 입력넣기
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
	AAA(0);//0번 vertex부터 시작
}
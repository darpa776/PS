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
//최대범위 생각해보기
//최대범위가 10의 9승이기 때문에 다른 방법을 찾아야함. k가 주어져있어서 그리디로도 풀림
//k최대부터 쫓아가기
//저범위 때문에 stone을 pair형 벡터로 만들었는데 시간초과가 난다.......실전에서 1초 넘게 걸린다 풀기실타
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
				
			//마지막 돌이 나오면 마지막 돌의 visited를 ans에 넣고 출력,종료
			//visited인 경우 한번 더 방문하지 않기
			//!visited인 경우 방문하기
			//q에서 빼내서 visited를 증가시킴
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
		for (int i = 0; i < n; ++i) //n개의 돌
		{
			cin >> a;
			stone.push_back(make_pair(a,0));
		}
		cin >> k;
		//입력완료
		frog();
		//cout << stone.back() << endl;


		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		//초기화
		ans = -1;
		stone.clear();
		


	}
	//end = clock();
	//result = (double)(end - start);
	//cout << result;
	return 0;
}

#include <iostream>
#include <queue>

using namespace std;
#define MAX 200000
int n, k;
int check[MAX];

int main()
{
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	int now;
	while (!q.empty())
	{
		//세 경우 모두 다 방문한 경우에는 한바퀴 돌고나서 pop하게 됨
		now = q.front();
		q.pop();
		if (now == k)
			break;
		if (now - 1 >= 0)
		{
			if (check[now - 1]==0)
			{
				check[now - 1] = check[now] + 1;
				q.push(now - 1);
				
			}
		}
		if (now + 1 <= MAX)//check[MAX]에 접근할 수 없고 check[MAX-1]가 최대 인덱스이기 때문에
			//항상 등호가 없어야 성립한다.등호가 있을 때도 성립하는 것은 MAX정도의 인덱스까지 접근하지 않기 때문
		{
			if (check[now + 1]==0)//방문안했으면 방문하기
			{
				check[now + 1] = check[now] + 1;
				q.push(now + 1);

			}
		}
		if (now*2 <= MAX)
		{
			if (check[now*2] == 0)
			{
				check[now * 2] = check[now] + 1;
				q.push(now * 2);

			}
		}
	}

	cout << check[now] << endl;

	return 0;
}
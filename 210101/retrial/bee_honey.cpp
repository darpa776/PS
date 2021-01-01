#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
// (3 ≤ N ≤ 10)
// (1 ≤ M ≤ 5)
//(10 ≤ C ≤ 30)

using namespace std;
int map[10][10];//벌통들
int T, test_case;
int ans;
int n, m, c;
bool visited[6];//벌통
int sum;
bool check[100];//n*n

typedef struct node{
	int x; int y; int profit;
}node;

vector<node> profit_list;

void honey(int x, int y, int idx, int cnt, int t)//m개 다 조합해보기
{//https://yabmoons.tistory.com/99 응용
	if (cnt == t)
	{
		//print();
		//visited==true인것 출력하기
		int tmp = 0;//sum을 위한 tmp
		int crit=0;//c를 위한 꿀의 합
		for(int k = 0; k < 6; ++k)
		{
			if (visited[k])// k:선택할 통의 index
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
	return first.profit > second.profit; // 비교하고 싶은 T 타입의 데이터 멤버를 비교해야 한다
}

//출처: https://celdee.tistory.com/281 [날개의 기억]


void comb(int idx, int cnt)
{//https://yabmoons.tistory.com/99
	
	if (cnt == 2)//2개고르기
	{
		int tmp = 0;
		//print();
		//check==true인것 더해서 max==ans
		int flag = 0;
		int a, b;
		for (int k = 0; k < profit_list.size(); ++k)
		{
			if (check[k])
			{
				++flag;
				if (flag == 1)//첫번째 위치
					a = k;
				if (flag == 2)
					b = k;

			}
		}


		if (profit_list[a].x == profit_list[b].x)//같은 열이고
		{
			if (profit_list[a].y + m <= profit_list[b].y)//범위가 안겹치면
			{
				tmp = profit_list[a].profit + profit_list[b].profit;
				ans = max(ans, tmp);
			}
		}
		else//다른열이면 조합을 무조건 사용하면 됨
		{
			tmp = profit_list[a].profit + profit_list[b].profit;
			ans = max(ans, tmp);
		}
	
		return;
	}
	for (int i = idx; i < profit_list.size(); ++i)//profit_list.size()중에서 2개 고르기
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
					honey(i, j, 0, 0, l);//각(i,j)위치별로 m개의 통 중에 선택할 index에서 조합해보기
				}
				node a;
				a.x = i; a.y = j; a.profit = sum;
				profit_list.push_back(a);
				//cout << sum << endl;
				sum = 0;
			}
		}
		//모든 이익들을 큰 순서대로 정렬함
		//sort(profit_list.begin(), profit_list.end(), Compare);//profit기준으로 정렬 setting
		//어차피 다 조합해볼거니까 sorting해볼필요 없을 듯
		
		//조합써서 범위가 겹치는지 확인
		int tmp=0;
		comb(0, 0);
		
		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		//초기화
		ans = 0;
		profit_list.clear();

	}
	return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T,test_case;
int ans;
int charge[4];
int plan[12];
int d[12];
vector<int> one;//1일권,1달권으로 저장

void dp()
{

	//1달권,1일권 비교
	for (int i = 0; i < 12; ++i)
	{
		if (plan[i] == 0)
			one.push_back(0);
		else if (charge[0] * plan[i] < charge[1])//1달권보다 1일권이 더 쌀때
			one.push_back(plan[i] * charge[0]);//one vector에 1일권으로 넣는다
		else
			one.push_back(charge[1]);//one vector에 1달권으로 넣는다

		if (i == 0)
			d[i] = one[i];
		else if (i != 0)//i가 0이 아닐때만, i가 0이면 -1에 접근할 수 없으므로.
			d[i] = d[i - 1] + one[i];//이때까지의 최소요금
		//3달권이랑 같이 최소요금을 계산해야한다
	//------1일권,1달권 저장완료

	//3달모였는지 확인하기
		if (i >= 2)//3월부터
		{
			if (i == 2)
				d[i] = min(d[i], charge[2]);
				//3월에는 1달권/1일권을 더한 값과 3월권 중 최소값을 최소요금으로 넣는다
			else
				//기본 점화식
				d[i] = min(d[i - 1] + one[i], d[i - 3] + charge[2]);
				//5월까지 최소요금은 min(4월까지 최소요금+5월 1일권/1달권,2월까지 최소요금+3달권)

		}


	}
	//1년권과 비교하기
	ans = min(d[11], charge[3]);

}
int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;//test_case 몇개인지 입력받기
	while (test_case < T)
	{
		for(int i=0;i<4;++i)
			cin>> charge[i];//이용권 가격들
		for (int i = 0; i < 12; ++i)
			cin >> plan[i];//이용계획
		
		dp();
	
	
	++test_case;
	cout<<"#"<< test_case<<" "<< ans<<endl;
	//초기화
	ans = 0;
	one.clear();
	}
	return 0;
}

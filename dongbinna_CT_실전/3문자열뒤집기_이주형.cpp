#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{//문자열 뒤집기
	string s;
	getline(cin, s);

	vector<int> num;
	int flag=0;
	for (int i = 0; i < s.size(); i++)
	{
		num.push_back(s[i] - '0');
	}
	//연산시작
	for (int i = 1; i < s.size(); i++)
	{
		if (num[i - 1] != num[i])
			flag++;
		
	}
  //flag가 1일때부터 직접 계산해보며 규칙성을 파악한 것임
  //임의로 계산을 조작한 것이라 할 수 있음
	int ans;
	if(flag%2!=0)
	{
		flag += 2;
		
	}
	ans = flag / 2;
	cout << ans << endl;
	return 0;
}
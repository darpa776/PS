#include <iostream>
#include <string>
using namespace std;

int main()
{
	//곱하기 혹은 더하기
	
	string s;
	getline(cin, s);
	int num[21];
	for (int i = 0; i < s.size(); i++)
	{
		num[i]=s[i]-'0';
	}
	
	int ans=num[0];//첫번째 값으로 미리 초기화
	for (int i = 1; i < s.size(); i++)
	{// 현재 값 또는 ans이 '0' 혹은 '1'인 경우, 곱하기보다는 더하기 수행
		if (num[i] <= 1||ans<=1)
		{
			ans += num[i];
		}


		else
		{
			ans *= num[i];

		}

		

	}
	cout << ans << endl;
	
	return 0;
}
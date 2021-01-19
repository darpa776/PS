#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{//문자열 뒤집기
	string s;
	getline(cin, s);

	int count0=0;//모두 0으로 만들기
	int count1 = 0;//모두 1로 만들기

	if (s[0] == '0')
		count1++;
	else
		count0++;

	for (int i = 1; i < s.size(); i++)
	{
		if (s[i - 1] != s[i])
		{
			if (s[i] == '1')
				count0++;
			else
				count1++;
		}
	}
	int ans = min(count1, count0);
	
	cout << ans << endl;
	return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int num = 0;
	vector<char> newS;
	for(int i=0;i<s.size();i++)
	{//아래 if문 또는 isalpha 함수를 사용하면 알파벳인지 알 수 있다.
		if (s[i] < 65)//숫자
			num += s[i]-'0';
		else//알파벳대문자
			newS.push_back(s[i]);
	}
	sort(newS.begin(), newS.end());
	for (int i = 0; i < newS.size(); i++)
	{
		cout << newS[i];
	}
	cout << num << endl;
}

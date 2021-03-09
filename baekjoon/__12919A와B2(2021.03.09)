#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int ans = 0;
string T;

int recur(string S) {
	if (S != T) {
		string S_ = S;
		reverse(S_.begin(), S_.end());
		int tmp1=T.find(S);
		int tmp2 = T.find(S_);

		if (0 <= tmp1 || 0 <= tmp2) {
			//만약 T안에 S나 S_가 포함되어 있으면
			recur(S.append("A"));
			S.pop_back();
			string tmp=S.append("B");
			reverse(tmp.begin(), tmp.end());
			recur(tmp);
			S.pop_back();
		}
		else return 0;
		
	}
	
	else if (S == T)
		ans =1;
	return 0;
}


int main() {
	
	string s;
	//S를 T로 바꿀수 있는가
	getline(cin, s);
	getline(cin, T);

	recur(s);
	cout << ans;
}

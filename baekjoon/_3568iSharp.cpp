#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string tmp;
	getline(cin, tmp, ';');
	//원래 입력받은 문자열은 tmp
	stringstream ss(tmp);
	string str;
	ss >> str;
	//띄어쓰기 만날때까지 parsing하므로 str에는 첫번째 공통 변수형이 들어감
	vector<string> x;
	x.push_back(str);
	//x[0]는 공통 변수형
	while (getline(ss, str, ',')) {
		x.push_back(str);
	}
	//x에 콤마기준으로 분리해 문자열이 들어감

	for (int i = 1; i < x.size(); i++) {
		cout << x[0];

		int idx;
		for (int j = x[i].size() - 1; j >= 0; j--) {
			if (x[i][j] >= 'A' && x[i][j] <= 'Z') {
				idx = j;
				break;
			}

			else if (x[i][j] >= 'a' && x[i][j] <= 'z') {
				idx = j;
				break;
			}

			else if (x[i][j] == ']') {//배열 변수형인 경우
				j--;
				cout<<"[]";
			}

			else {//변수형인 경우
				cout << x[i][j];
			}
		}

		for (int j = 0; j <= idx; j++)
			cout << x[i][j];
		cout << ";" << endl;
	}

	return 0;
}

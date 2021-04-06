#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#define _crt_secure_no_warnings
//#pragma warning(disable:4996)
using namespace std;

int r, c, k;//map[r-1][c-1]의 값이 k가 되는 시간은?
vector<int> R[100];
vector<int> C[100];
vector<pair<int,int>> vec;
int t = 0;
int Rmax = 0;
int Cmax = 0;

bool key(pair<int,int>a, pair<int,int>b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

void count(vector<int> num, int in, int idx) {
	//똑같은 숫자가 몇개 있는지 세기 위해 이진탐색 시작
	//num 벡터에서 가장 큰수 = 가장 마지막에 있는 수
	int max = num[num.size() - 1];
	for (int i = 1; i <= max; i++) {
		//num벡터에서 i가 몇개 인지 찾아라
		auto start = lower_bound(num.begin(), num.end(), i);
		auto fine = upper_bound(num.begin(), num.end(), i);
		if (fine - start != 0) {
			vec.push_back({i,fine-start});//i가 몇개인지 저장
		}
	}
	sort(vec.begin(), vec.end(), key);
	//in이 0이면 R, 1이면 C
	if (in == 0) {
		R[idx].clear();
		for (int i = 0; i<vec.size(); i++) {
			R[idx].push_back(vec[i].first);
			R[idx].push_back(vec[i].second);
		}
		vec.clear();
	}
	else if (in == 1) {
		C[idx].clear();
		for (int i = 0; i<vec.size(); i++) {
			C[idx].push_back(vec[i].first);
			C[idx].push_back(vec[i].second);
		}
		vec.clear();
	}
	return;
}

void R_calc() {
	for (int i = 0; i < Cmax; i++) {
		vector<int> num;
		for (int j = 0; j < R[i].size(); j++) {
			num.push_back(R[i][j]);
		}
		sort(num.begin(), num.end());
		count(num, 0,i);
	}
	return;
}

void C_calc() {
	for (int i = 0; i < Rmax; i++) {
		vector<int> num;
		for (int j = 0; j < C[i].size(); j++) {
			num.push_back(C[i][j]);
		}
		sort(num.begin(), num.end());
		count(num, 1,i);
	}
	return;
}

bool check() {
	
	if (R[r-1].size()<= c-1)//R[r-1][c-1]에 접근할 수 없는 경우
		return true;//while문에 들어가서 키워야한다.
	else if (R[r - 1][c - 1] != k)//행렬에 접근가능하지만 k가 아닌 경우
		return true;//while문에 들어가서 연산을 수행한다.
	else if(R[r - 1][c - 1] == k)//같아지면
		return false;//이제 나와서 답을 출력한다.
}

int main() {
	
	cin >> r >> c >> k;
	//첫 배열크기는 3*3

	int x;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x;
			R[i].push_back(x);
			C[j].push_back(x);
		}
	}
	Rmax = 3;
	Cmax = 3;
	
	while (check()) {//주어진 조건이 될때까지


		//R연산할지 C연산할지 정하기
		if (Rmax <= Cmax)
		{
			R_calc();
			//크기가 가장 큰 행의 크기에 맞추어 남은 자리에 0을 넣어준다.
			Rmax = 0;
			for (int i = 0; i < 100; i++) {
				if (Rmax < R[i].size())
					Rmax = R[i].size();
			}
			for (int i = 0; i < Cmax; i++) {
				for (int j = R[i].size(); j < Rmax; j++) {
					R[i].push_back(0);
				}
			}
			//남은 C벡터들 초기화해주고 재설정해주기
			for (int i = 0; i < Rmax; i++) {
				C[i].clear();
			}

			for (int i = 0; i < Cmax; i++) {
				for (int j = 0; j < R[i].size(); j++) {
					C[j].push_back(R[i][j]);
				}

			}
		}
		else if (Rmax > Cmax)
		{
			C_calc();
			Cmax = 0;
			for (int i = 0; i < 100; i++) {
				if (Cmax < C[i].size())
					Cmax = C[i].size();
			}
			for (int i = 0; i < Rmax; i++) {
				for (int j = C[i].size(); j < Cmax; j++) {
					C[i].push_back(0);
				}
			}
			//남은 R벡터들 초기화해주고 재설정해주기
			for (int i = 0; i < Cmax; i++) {
				R[i].clear();
			}
			for (int i = 0; i < Rmax; i++) {
				for (int j = 0; j < C[i].size(); j++) {
					R[j].push_back(C[i][j]);
				}
			}
		}
		
		
		
		t++;
		if (t > 100) {
			cout << -1 << endl;
			exit(0);
		}

	}
	cout << t << endl;
	//vec을 second 기준으로 먼저 sort(key함수)
	return 0;
}

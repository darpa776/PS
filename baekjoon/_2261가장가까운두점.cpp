#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
//#define _crt_secure_no_warnings
//#pragma warning(disable:4996)
using namespace std;
//가장 가까운 두점의 거리의 제곱을 출력:(x1-x2)^2+ (y1-y2)^2를 그대로 출력
vector<pair<int, int>> point;
int n;//점의 개수
int min_dist;

void solve(int start, int end) {

	if (end - start <= 2)//서로 직접 비교가 가능한 수준, 이 값이 최대한 작을수록 속도가 오른다.
	{//2일때랑 3일때 속도가 다르다. 2일때는 좌표 3개를 도니까(3*2=6), 3일때는 좌표 4개라서(4*3=12), 속도가 2배차이.
	//1일때는 재귀를 많이 돌려야해서 속도차이가 크지 않음
		for (int i = start; i < end; i++) {
			for (int j = i + 1; j <= end; j++) {

				if (pow((point[i].first - point[j].first), 2) < min_dist)
				{
					if (pow((point[i].second - point[j].second), 2) < min_dist) {
						int x_dist = (point[i].first - point[j].first);
						int y_dist = (point[i].second - point[j].second);
						int dist = pow(x_dist, 2) + pow(y_dist, 2);
						min_dist = min(dist, min_dist);
						if (min_dist == 0)
						{
							cout << "0" << endl;
							exit(0);
						}
					}
					//else break;
				}
				else {

					break;
				}

			}
		}
		return;
	}
	if (end <= start) return;

	int mid_idx = (start + end) / 2;
	solve(start, mid_idx);//왼쪽
	solve(mid_idx + 1, end);//오른쪽
	//BF로 여러번 재귀돌았으니까 이미 min_dist는 많이 작은 상태임
	//중간**
	//중간인 point[mid_idx]의 x좌표를 기준으로 min_dist 이상 떨어진 친구들은 비교하지 않는다.
	vector<pair<int,int>> midband;
	for (int i = start; i <= end; i++) {
		if (pow((point[mid_idx].first - point[i].first), 2) < min_dist)

			midband.push_back({point[i].second, point[i].first});

	}
	sort(midband.begin(), midband.end());//y좌표를 오름차순으로 정렬함
	for (int i = 0; i < midband.size()-1; i++) {
		for (int j = i + 1; j < midband.size(); j++) {
			//midband에서는 first가 y좌표임
			if (pow((midband[i].first - midband[j].first), 2) < min_dist)
			{
					int y_dist = (midband[i].first - midband[j].first);
					int x_dist = (midband[i].second - midband[j].second);
					int dist = pow(x_dist, 2) + pow(y_dist, 2);
					min_dist = min(dist, min_dist);
					if (min_dist == 0)
					{
						cout << "0" << endl;
						exit(0);
					}
			}

			else {
				break;
			}

		}
	}
	return;
}

int main() {

	//L = 1e9;
	//R = -1e9;
	//freopen("3.in.txt", "r", stdin);
	//각각의 좌표는 절댓값이 10,000을 넘지 않는 정수(음,양 모두 가능)
	cin >> n;
	for (int i = 0; i < n; i++) {
		//x축 기준으로 정렬
		int x, y;
		cin >> x >> y;
		point.push_back({ x,y });
	}
	
	sort(point.begin(), point.end());//x좌표 기준 오름차순 정렬
	min_dist = (point[0].first - point[1].first) * (point[0].first - point[1].first)
		+ (point[0].second - point[1].second) * (point[0].second - point[1].second);
	if (min_dist == 0)
	{
		cout << "0" << endl;
		return 0;
	}

	solve(0, n - 1);

	cout << min_dist << endl;
	return 0;
}

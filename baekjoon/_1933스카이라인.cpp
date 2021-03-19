#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool point_key(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.first == b.first.first)
	{
		if (a.second.second == b.second.second)
			return a.second.first > b.second.first;
		//in,out 위치가 모두 같으면 높은 빌딩이 먼저 오도록 정렬
		return a.first.second > b.first.second;
		//동일한 위치라면 in인 좌표가 먼저 오도록 정렬
	}
	return a.first.first < b.first.first;//x축 기준 먼저 오도록 정렬
}

int main() {

	int n;
	cin >> n;//건물의 개수

	priority_queue<pair<int, int>>pq;//높이,out 좌표
	vector<pair<pair<int, int>, pair<int,int>>> point;//x축 좌표, in/out, 높이, 반대좌표
	vector<pair<int, int>> ans;//위치, 높이


	for (int i = 0; i < n; i++) {

		int x, h, y;
		cin >> x >> h >> y;
		point.push_back({ { x,1 },{ h,y } });
		point.push_back({ { y,0 },{ h,x } });
		
	}
	//정렬이 오름차순으로 되니까 같은 좌표면 out을 먼저 pop하도록 되어있음 -> point_key 함수
	sort(point.begin(), point.end(), point_key);//x축 기준 정렬
	int last = point.back().first.first+1;
	pq.push({ 0, last });//높이, out 좌표 
	//pq는 max 힙
	
	//벡터는 최대 10억개까지 push 가능
	for (int i = 0; i < point.size(); i++) {
		int IO = point[i].first.second;
		int x = point[i].first.first;
		int h = point[i].second.first;
		int cmp = point[i].second.second;
		//x가 in 이라면 out 좌표, x가 out이라면 in 좌표

		if (IO == 1) {//in이면
			
			if (h > pq.top().first )
				ans.push_back({x,h});
			//현재 높이가 최고높이면 ans.push
			
			pq.push({ h,cmp });
		}
		else if (IO == 0) {//out이라면
			//해당하는 빌딩을 pq에서 pop
			//정확히 이 빌딩만 pop할 수 없으므로(pq) 좌표기준으로 현재 좌표까지 모두 pop
			while (!pq.empty()) {
				if (x < pq.top().second) {
					//현재 out 위치에 걸쳐져있는 애들까지 모두 pop
					
					if (pq.top().first < h && (ans.end() == find(ans.begin(), ans.end(), make_pair(x, pq.top().first))))
						//지금 빌딩 높이가 더 높으면 지금 빌딩 없애는 위치에 보다 낮은 빌딩의 높이를 ans에 넣어줘야함
						//ans에 동일한 좌표가 존재하면 ans에 써주지 않음
						ans.push_back({ x, pq.top().first });
					break;
				}
				
				pq.pop();
			}
		}
	}
	
	for (int i = 0; i < ans.size(); i++) {
	
		cout << ans[i].first << " " << ans[i].second << " ";
	}
	cout << endl;
	return 0;
}

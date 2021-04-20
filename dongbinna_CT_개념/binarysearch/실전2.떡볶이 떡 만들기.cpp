//떡볶이 떡 확인
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;// 떡의 개수, 요청한 떡의 길이
vector<int> bread;
int ans;

void binary_search(int start, int end) {//매개변수로 받는 것은 높이임
	if (start > end) return;//start와 end가 같을 경우도 이진탐색 함수를 돌게 설계
	int mid = (start + end) / 2;
	//mid에서 자른다.
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if(bread[i] - mid>0)
			sum += (bread[i]-mid);
	}
		//만약 자른 길이가 부족할경우
	if (sum < m){
		
		return binary_search(start, mid-1);
		//항상 end는 mid-1
	}
	//만약 자른 길이가 손님이 주문할 양보다 많거나 같을 경우
	else if (sum >= m) {
		ans = mid;
		return binary_search(mid+1, end);
		//항상 start는 mid+1
	}
	

	return;
}

int main() {
	//절단기 높이: H, 잘린 떡의 길이만큼을 손님이 가져가신다.
	//손님이 요청한 길이는 m, m이상의 떡을 줘야한다.
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		bread.push_back(tmp);
	}
	//가장 낮은 가래떡의 길이부터, 가장 높은 길이의 가래떡 사이에서 잘라야한다.
	//->0cm부터 가장 높은 가래떡 길이
	sort(bread.begin(), bread.end());
	binary_search(0, bread[n - 1]);

	//손님이 최대한 떡을 많이 가져갈수 있는 절단 높이
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//못생긴수:2,3,5 만을 약수로 가지는 수
int main() {
	//n번째 못생긴 수를 출력해라
	int n;
	cin >> n;
	vector<int> ugly = { 1 };
	for (int i = 0; ugly.size() <= n; i++) {
		int a = ugly[i];
		int x = a*2;
		ugly.push_back(x);
		int y = a * 3;
		ugly.push_back(y);
		int z = a * 5;
		ugly.push_back(z);
		sort(ugly.begin(), ugly.end());
		ugly.erase(unique(ugly.begin(), ugly.end()), ugly.end());
	}

	cout << ugly[n - 1] << endl;
	return 0;
}

//sort 비용이 많이 들 경우
//int main(void) {
//    cin >> n;
//
//    // 2배, 3배, 5배를 위한 인덱스
//    int i2 = 0, i3 = 0, i5 = 0;
//    // 처음에 곱셈 값을 초기화
//    int next2 = 2, next3 = 3, next5 = 5;
//
//    ugly[0] = 1; // 첫 번째 못생긴 수는 1
//    // 1부터 n까지의 못생긴 수들을 찾기
//    for (int l = 1; l < n; l++) {
//        // 가능한 곱셈 결과 중에서 가장 작은 수를 선택
//        ugly[l] = min(next2, min(next3, next5));
//        // 인덱스에 따라서 곱셈 결과를 증가
//        if (ugly[l] == next2) {
//            i2 += 1;
//            next2 = ugly[i2] * 2;
//        }
//        if (ugly[l] == next3) {
//            i3 += 1;
//            next3 = ugly[i3] * 3;
//        }
//        if (ugly[l] == next5) {
//            i5 += 1;
//            next5 = ugly[i5] * 5;
//        }
//    }
//
//    // n번째 못생긴 수를 출력
//    cout << ugly[n - 1] << '\n';
//}

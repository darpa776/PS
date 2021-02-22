#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, ans=0, sum = 0;
	int card[100];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	vector<int> binary(n, 0);
	fill(binary.end() - 3, binary.end(), 1);
	do {

		for (int i = 0; i < n; i++) {
			if (binary[i]) {
				sum += card[i];
			}
		}
		if (sum <= m) 
			ans = max(sum, ans);
		sum = 0;
	} while (next_permutation(binary.begin(), binary.end()));
	
	cout << ans << endl;
	
	return 0;
}

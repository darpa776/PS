#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> v ;


int main()
{
	int n,x;
	cin >> n>> x;
	for (int i = 0; i < n; i++)
	{
		int z;
		cin >> z;
		v.push_back(z);
	}

	vector<int>::iterator right =upper_bound(v.begin(), v.end(), x);//iter형
	vector<int>::iterator left=lower_bound(v.begin(), v.end(), x);
	int ans=right - left;
	cout << ans << endl;
	
	return 0;
}

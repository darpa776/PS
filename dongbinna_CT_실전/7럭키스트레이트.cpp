#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int origin = n;

	vector<int> number;
	while(n>10)
	{
		number.push_back(n % 10);
		n /= 10;
	}
	number.push_back(n);
	int m = number.size() / 2;
	//앞뒤로 더해서 같은지 확인
	int sum1 = 0;
	int sum2 = 0;
	for(int i=0;i<m;i++)
	{
		sum1 += number[i];
		sum2 += number[2 * m - i-1];
	}
	if (sum1 == sum2)
		cout << "LUCKY";
	else
		cout << "READY";
}

//// 왼쪽 부분의 자릿수의 합 더하기
////정수로 들어오는 입력을 str으로 입력받아서 size()함수로 자릿수 바로 알아내기
//for (int i = 0; i < str.size() / 2; i++) {
//	summary += str[i] - '0';
//}
//
//// 오른쪽 부분의 자릿수의 합 빼기
//for (int i = str.size() / 2; i < str.size(); i++) {
//	summary -= str[i] - '0';
//}
//
//// 왼쪽 부분과 오른쪽 부분의 자릿수 합이 동일한지 검사
//if (summary == 0) cout << "LUCKY" << '\n';
//else cout << "READY" << '\n';

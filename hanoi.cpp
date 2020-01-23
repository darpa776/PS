#include <iostream>
#include <cmath>
using namespace std;

int n;//서로 다른 n개의 원판이 놓여있다.
void hanoi(int num, int from, int tmp, int to)
{
	
	if (num == 2)
	{
		cout << from << " " << tmp<< "\n";
		cout << from << " " << to << "\n";
		cout << tmp << " " << to << "\n";
		return;
	}

	hanoi(num - 1, from,to,tmp);//무더기를 1->2에 쌓아놓고
	cout << from << " " << to << "\n";//맨마지막 친구를 쌓는다
	hanoi(num - 1, tmp,from,to);//2에 있는 무더기를 3으로 옮긴다
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	//기둥에 원판 넣기, data 입력
	cout << (int)pow(2, n) - 1 << endl;
	hanoi(n, 1,2,3);
	return 0;
	//(1 << n) - 1
}
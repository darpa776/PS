#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;//식량창고 개수
	cin >> n;
	
	int cart[100];
	int mem[100];
	
	for (int i = 0; i < n; i++)
	{//한 창고당 존재하는 식량 수
		cin >> cart[i];
	}

	
	//개미전사가 얻을 수 있는 식량의 최댓값
	//전처리
	mem[0] = cart[0];
	mem[1] = max(cart[0],cart[1]);
	

	for (int i = 2;i<n;i++)
	{
		mem[i] = max(mem[i-1],mem[i-2]+cart[i]);
		//바로 인접한 최대값을 선택하느냐, 또는 전 창고에 현재 창고를 더한 값을 선택하느냐
		//= 안터느냐, 터느냐
	}

	cout << mem[n - 1];//마지막 값==최대값
	//for문에서 항상 최대값을 저장하기 때문임.

	return 0;
}
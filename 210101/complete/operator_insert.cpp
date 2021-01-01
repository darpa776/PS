#include <iostream>

using namespace std;
int n;//수의 개수
int num[12];//입력 받을 수들을 담을 변수(2~11)
int opr[4];//연산자의 개수를 담고 있는 변수(덧뺄곱나)

int maxx=-1000000000;//다시한번 더 확인하기
int minn=1000000000;

int dfs(int idx,int result)
{
	if (idx == n)
	{
		if (result >= maxx)
		{
			maxx = result;
		}
		if (result <= minn)
		{
			minn = result;

		}
		return 0;
	}


	if (opr[0] > 0)
	{
		opr[0]--;
		dfs(idx + 1, result + num[idx]);
		opr[0]++;

	}
	if (opr[1] > 0)
	{
		opr[1]--;
		dfs(idx + 1, result - num[idx]);
		opr[1]++;
	}
	if (opr[2] > 0)
	{

		opr[2]--;
		dfs(idx + 1, result * num[idx]);
		opr[2]++;
	}
	if (opr[3] > 0)
	{
		opr[3]--;
		dfs(idx + 1, result / num[idx]);
		opr[3]++;
	}
	
	return 0;
}

int main()
{
	
	//수의 개수 입력(n)
	cin >> n;
	//수들 입력(n)
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	//4종류의 연산자 개수 입력(4종류 다합쳐서 n-1)
	for (int i= 0; i < 4; ++i)
	{
		cin >> opr[i];
	}
	//이제 dfs를 시작하자
	dfs(1, num[0]);
	cout << maxx<<endl; 
	cout << minn<<endl;
	//ambigious일때는 builtin 있어서 그러니까 변수명을 바꿔주자
	return 0;

}
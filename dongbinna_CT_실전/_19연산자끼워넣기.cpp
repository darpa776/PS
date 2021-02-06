#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> numbers;
vector<int> operators;
//dfs
int sum;
int index = 0;
int tmp;
int ans_min = 1e9;
int ans_max = -1e9;

void dfs(int sum,int index) {
	
	if(index>=n)
	{ 
		ans_min = min(ans_min, sum);
		ans_max = max(ans_max, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i])//만약 남은 연산자 수가 0이 아니면
		{
			if (i == 0) { //plus
				
				sum += numbers[index];
				operators[i]--;
				dfs(sum,index+1);
				operators[i]++;
				sum -= numbers[index];
				
				
			}
			else if (i == 1) { //minus 
				
				sum -= numbers[index];
				operators[i]--;
				dfs(sum,index+1);
				operators[i]++;
				sum += numbers[index];
				
				
			}
			else if (i == 2) { //multiple
				
				sum *= numbers[index];
				operators[i]--;
				dfs(sum,index+1);
				operators[i]++;
				sum /= numbers[index];
				
				
			}
			else if (i == 3) { //division
				
				//have to consider under zero numbers
				tmp = sum / numbers[index];
				//sum /= numbers[index];
				operators[i]--;
				dfs(tmp,index+1);
				operators[i]++;
				//sum *= numbers[index];
				
				
			}
			
		}
		
	}
	
}

int main()
{
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}
	
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		operators.push_back(x);
	}//덧뺄곱나
	dfs(numbers[index],index+1);

	cout << ans_max << endl;
	cout << ans_min << endl;
	
	return 0;
}

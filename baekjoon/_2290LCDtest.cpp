#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s, n;
vector<int> numbers;
char display[230][120];

int main() {
	for (int i = 0; i < 230; i++) {
		fill_n(display[i], 120, ' ');
	}
	
	cin >> s >> n;
	//크기와 그릴 숫자
	//numbers 배열에 하나하나 집어 넣자.
	while (n >= 10) {
		numbers.push_back(n % 10);
		n /= 10;
	}
	numbers.push_back(n % 10);
	reverse(numbers.begin(), numbers.end());
	for (int idx = 0; idx < numbers.size(); idx++) {
		if (numbers[idx] == 0) {
			for (int i = 0; i < 2 * s + 4; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {
					if (i == 0 || i == 2 * s + 2) {//맨위칸이거나 맨 아래칸이고
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 처음칸이거나 맨 마지막 칸이 아니면
							display[i][j] = '-';
					}
					else if (i != 0 && i != s + 1 && 2 * s + 2)
					{
						if (j == (s + 3) * idx || j == (s + 3) * (idx + 1) - 2)
							display[i][j] = '|';
					}
				}
			}
		}
		else if (numbers[idx] == 1) {
			for (int i = 0; i < 2 * s + 4; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {
					if (i != 0 && i != 2 * s + 2 && i != s + 1) {
						//맨위칸도 아니고 맨아래칸도 아니고 중간칸도 아닌 경우
						if (j == (s + 3) * (idx + 1) - 2)
							display[i][j] = '|';
					}
				}
			}

		}
		else if (numbers[idx] == 2) {
			for (int i = 0; i < 2 * s + 4; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {
					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * idx)
								display[i][j] = '|';
						}
					}
					else {//맨위, 맨아래, 중간일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}
				}
			}

		}
		else if (numbers[idx] == 3) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
					}
					else {//맨위, 맨아래, 중간일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}


				}
			}
		}
		else if (numbers[idx] == 4) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * (idx + 1) - 2 || j == (s + 3) * idx)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
					}
					else if (i == s + 1) {//중간일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}


				}
			}
		}
		else if (numbers[idx] == 5) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * idx)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
					}
					else {//맨위, 맨아래, 중간일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}


				}
			}
		}
		else if (numbers[idx] == 6) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * idx)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * (idx + 1) - 2 || j == (s + 3) * idx)
								display[i][j] = '|';
						}
					}
					else {//맨위, 맨아래, 중간일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}


				}
			}
		}
		else if (numbers[idx] == 7) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
					}
					else if (i == 0) {//맨위일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}
				}
			}
		}

		else if (numbers[idx] == 8) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * idx || j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * idx || j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
					}
					else {//맨위일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}
				}
			}
		}
		else if (numbers[idx] == 9) {
			for (int i = 0; i < 2 * s + 3; i++) {
				for (int j = (s + 3) * idx; j < (s + 3) * (idx + 1); j++) {

					if (i != 0 && i != 2 * s + 2 && i != s + 1) {//맨위칸이거나 맨 아래칸이거나 중간 칸이 아니고

						if (i < s + 1) {//중간칸보다 위일 경우
							if (j == (s + 3) * idx || j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
						if (i > s + 1) {//중간칸보다 아래일 경우
							if (j == (s + 3) * (idx + 1) - 2)
								display[i][j] = '|';
						}
					}
					else {//맨위일 경우
						if (j != (s + 3) * idx && j != (s + 3) * (idx + 1) - 2 && j != (s + 3) * (idx + 1) - 1)
							//맨 앞, 공백을 제외한 맨뒤가 아닐경우
							display[i][j] = '-';
					}
				}
			}
		}
	}



	for (int i = 0; i < 2 * s + 3; i++) {
		for (int j = 0; j < (s + 3) * numbers.size(); j++) {
			cout << display[i][j];
		}
		cout << endl;
	}
	return 0;
}

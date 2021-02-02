#include <string>
#include <vector>

using namespace std;

vector<vector<int>> keyrotate(vector<vector<int>> key) {
	int m = key.size();
	vector<vector<int>> new_key(m, vector<int>(m));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			new_key[j][m-1-i] = key[i][j];
		}
	}
	return new_key;
}



bool check(vector<vector<int>> new_lock, vector<vector<int>> lock) {
	//new_lock의 중간부분과 key가 맞는지 검사
	//더해서 모든 위치가 1인지
	int n= lock.size();

	for (int a = 0; a < lock.size(); a++) {
		for (int b = 0; b < lock.size(); b++) {
			if (1 != new_lock[n + a][n + b])
			{
				return false;
			}

		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	//lock size: n*n
	//key size: m*m
	vector<vector<int>> new_lock(lock.size()*3,vector<int>(lock.size() * 3));
	//new_lock에 3배에 해당하는 넓은 자물쇠를 만든다
	//new_lock의 중간부분에 lock 값들을 넣는다.
	int n = lock.size();
	int m = key.size();


	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			new_lock[n+i][n+j] = lock[i][j];
		}
	}

	
	for (int rot = 0; rot < 4; rot++) {
		//4번 회전시킨다
		for (int i = 0; i < lock.size()*2; i++) {
			for (int j = 0; j < lock.size() * 2; j++) {

				for (int a = 0; a < key.size(); a++) {
					for (int b = 0; b < key.size(); b++) {
						new_lock[i + a][j + b] += key[a][b];

					}
				}
				if (check(new_lock, lock))//만약 꼭 맞으면
					return true;
				else//맞지 않으면 원래대로 돌리고 완전탐색을 계속한다.
				{
					for (int a = 0; a < key.size(); a++) {
						for (int b = 0; b < key.size(); b++) {
							new_lock[i + a][j + b] -= key[a][b];

						}
					}
				}
			}
		}
		//열쇠 회전
		key=keyrotate(key);
	}
	return false;
	//자물쇠를 열수 있으면 true 반환
}

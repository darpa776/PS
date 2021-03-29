#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//벡터를 쓰지 말고 배열로 쓸 것
int food[10][10];
int winter_map[10][10];//로봇이 주는 양분, A배열
vector<int> tree[10][10];//나무나이
int n, m, k, K;
vector<int> dead[10][10];//나무나이, 위치


void spring() {
	//나이가 어린 나무부터 자신의 나이만큼 양분을 먹는다
	//그리고 나이를 한살 먹는다.
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (tree[i][j].size())
			{
				sort(tree[i][j].begin(), tree[i][j].end());

				for (auto it = tree[i][j].begin(); it < tree[i][j].end(); ) {
					if (food[i][j] >= *it)
					{
						food[i][j] -= *it;
						*it+=1;
						it++;
					}

					else {//나이수만큼 양분을 먹지 못하고 나무가 죽으면
						dead[i][j].push_back(*it);
						it=tree[i][j].erase(it);

					}
					
				}
				
			}
		}
	}
	
	return;
}


void summer() {
	//죽은 나무가 양분이 되고,
	//죽은 나무의 나이를 2로 나눈것이 양분이 된다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for(int s=0; s < dead[i][j].size(); s++)
				food[i][j] += dead[i][j][s] / 2;
			dead[i][j].clear();
		}
		
	}
	return;
}

void autumn() {
	int dx[8] = { -1,-1,-1,0,0,+1,+1,+1 };
	int dy[8] = { -1,0,+1,-1,+1,-1,0,+1 };

	//나이가 5배수인 나무만 주변 8곳에 번식
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int s = 0; s < tree[x][y].size(); s++) {
				if (tree[x][y][s] % 5 == 0) {//나이가 5배수

					for (int i = 0; i < 8; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n)
							continue;
						else
							tree[nx][ny].push_back(1);
					}

				}
			}
		}
	}

	return;
}

void winter() {
	//로봇이 양분을 추가한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			food[i][j] += winter_map[i][j];
		}
	}
	return;
}

int main() {
	cin >> n >> m >> K;
	for (int i = 0; i < n; i++)
		fill_n(food[i], n, 5);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> winter_map[i][j];
		}
	}

	//m개의 나무를 구매해 땅에 심는다.
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		//나무의 위치, 나무의 나이
		tree[x-1][y-1].push_back(z);
	}

	//봄: 나이만큼 양분을 먹으면 한살올라간다.
	//나이가 어린 나무부터 양분을 먹는다.
	//자신의 나이만큼 양분을 못 먹으면 죽는다.
	int k = 0;
	while (K > k)
	{
		spring();
		summer();
		autumn();
		winter();
		k++;
	}


	//k년이 지난후 상도의 땅에 살아 있는 나무의 개수?
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans+=tree[i][j].size();
		}
	}
	cout << ans << endl;
	return 0;
}

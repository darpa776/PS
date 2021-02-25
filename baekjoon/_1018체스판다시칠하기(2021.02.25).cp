#include <iostream>
using namespace std;
int n, m,ans=1e9; 
char map[50][50];
char first;
int visited[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
int first_x, first_y;

int dfs(int x, int y) {

    visited[x][y] = 1;
    //i idx가 홀수이고 j idx가 짝수이면 first와 달라야한다.
    //i idx가 짝수이고 j idx가 홀수이면 first와 달라야한다.
    if ((x+y)%2==1) {
        if (map[x][y] == first) {//근데 만약 같다면
            //새로 색칠해야한다.
            cnt += 1;
        }
    }
    else if((x + y) % 2 == 0) { //홀홀,짝짝
        if (map[x][y] != first) {
            cnt += 1;
        }

    }
   

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx<0||ny<0||nx>=n||ny>=m||nx-first_x>=8||ny-first_y>=8||nx < first_x ||ny<first_y )//접근할 수 없는 범위라면
            continue;
        if (visited[nx][ny])//이미 방문했던 곳이라면
            continue;
        dfs(nx, ny);
    }
    return 0;
}

int main() {

	
	cin >> n >> m;
	
    //전체 map 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    

    //dfs 수행
    for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
            //8칸까지 계산가능한 경우만 세려본다.
            first_x = i; first_y = j;
            first = map[i][j];
			dfs(i, j);
            cnt = min(cnt, 64 - cnt);//흑백이 뒤집어진 체스판일 경우
            ans = min(cnt, ans);
            cnt = 0;

            //메모테이블 초기화
            for (int i = 0; i < 50; i++) {
                fill_n(visited[i], 50, 0);

            }
		}
    }
    
    
    cout << ans << endl;

	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int n, m, p;
long long d[101][101][101];

//position= 현재 idx
//x= 플레이리스트에 넣은 곡
//y= 플레이리스트에 넣을 곡 (꼭 들어가야하는 곡)

long long go(int position, int x, int y) {

    if (position == p) {
        if (y == 0)//넣어야할 모든 곡들을 넣었다면
            return 1;//가능한 플레이리스트, 재귀를 수행할 수 있도록 1을 리턴

        return 0;//넣어야할 모든 곡이 안들어간 경우
        //잘못된 플레이리스트, 경우의 수에 포함시키지 않는다.
        //그전 재귀함수 값이 무엇이든 0을 곱하면 경우의 수가 0으로 계산되므로 0을 리턴해주는 것임
    }

    //메모이제이션 안하면 시간초과 발생한다.
    //long long& ans = d[position][x][y];
    //주소에 바로 저장한다
    //ans= 배열의 주소를 바로 참조한다.
    //굳이 이렇게 해야하나...
    //-> ans를 다 d[position][x][y]로 교체해도 문제 풀림
    //삼차원 배열을 쓰는 이유는 position, x,y 가 매번 다른 경우가 너무 많기 때문에 각각의 경우를 다 구분하기 위함인듯
    if (d[position][x][y] != -1) {//방문한 곳이면
        return d[position][x][y];//이미 계산한 결과를 답으로 반환
    }
    d[position][x][y] = 0;//방문안한곳이면 이제 재귀연산 시작

    //플레이리스트에 넣을 곡을 선정하는 방법은 두가지가 있다.
    //아직 넣지 않은 곡 중에서 넣기(넣을 곡y 이 있는 경우)
    //이미 넣은 곡들 중 중복되는 곡 넣기 (중복되는 곡을 넣을 조건m 이 되지 않으면 넣지 x)
    //** 두 경우의 수를 모두 세기 위해 (+)를 사용한다.**//

    if (y > 0) {
        d[position][x][y] += go(position + 1, x + 1, y - 1) * y;
        //넣은 곡은+1, 넣어야할 곡은-1
        //넣어야할 곡이 y개 존재하므로 y를 곱함
    }
    if (x > m) {
        d[position][x][y] += go(position + 1, x, y) * (x - m);
        //넣은 곡 중에서 고르니까 넣은 곡은 여전히 x
        //넣어야할 곡 중에서 고르지 않으니까 넣어야할 곡도 여전히 y

        //중복된 곡은 x-m개
        //이미 플레이리스트에 들어가있는 곡의 수가 중복조건보다 많으면 넣은 곡들 중에서 중복되는 곡을 
        //x추가할 수 있다.
    }
    d[position][x][y] %= 1000000007;
    return d[position][x][y];
}

int main() {
    cin >> n >> m >> p;
    memset(d, -1, sizeof(d));

    cout << go(0, 0, n) << endl;

    return 0;
}

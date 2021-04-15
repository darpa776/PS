#include <iostream>
#include <vector>
using namespace std;

//https://sangdo913.tistory.com/185
//전체는 arr의 인덱스가 다이고, arr에 9의 배수마다 다른 plane을 부여한다.
//plane과, plane에 맞닿은 배열이 따로 움직인다.

/*
U: 0~8 'w'
D: 9~17 'y'
F: 18~26 'r'
B: 27~35 'o'
L: 36~44 'g'
R: 45~53 'b'
*/

/*            U
		  0  1  2
		  3  4  5
		  6  7  8
L        __________    R            B
36 37 38 |F18 19 20 | 45 46 47 | 27 28 29
39 40 41 | 21 22 23 | 48 49 50 | 30 31 32
42 43 44 | 24 25 26 | 51 52 53 | 33 34 35
		 ----------
		  9  10 11
		  12 13 14
		  15 16 17
		  D
*/

char arr[54];//9*6
int cube[6][3][3];
//12시방향으로부터 시계방향으로 4방
int around[6][12] = {
	{29,28,27,47,46,45,20,19,18,38,37,36},//U
	{24,25,26,51,52,53,33,34,35,42,43,44},//D
	{6,7,8,45,48,51,11,10,9,44,41,38},//F
	{2,1,0,36,39,42,15,16,17,53,50,47},//B
	{0,3,6,18,21,24,9,12,15,35,32,29},//L
	{8,5,2,27,30,33,17,14,11, 26,23,20}//R
};

void init() {
	//U, D, F, B, L, R
	char init[6] = { 'w','y','r','o','g','b' };
	for (int i = 0; i < 6; i++) {
		fill_n(arr+(i * 9), 9, init[i]);
	}
	//큐브의 각 면에 알파벳(색)을 채운다.
	return;
}

void move(int plane_num, int dir_num) {//plane 면을 dir 방향으로 돌려라
	char tmp[12];//주변 회전에 사용할 변수
	char temp[3][3];//면 회전에 사용할 변수

	while(dir_num--){
		//plane의 주변을 돌린다.
		//around를 돌리는 게 아니라 cube도 돌아야한다.
		for(int i=0;i<12;i++)
			tmp[i] = arr[around[plane_num][i]];//주변 index에 해당하는 색을 tmp에 차례대로 저장
		for(int i=0;i<12;i++)
			arr[around[plane_num][i]]=tmp[(i+3)%12];//옮겨진 색을 index에 해당하는 색으로 저장
		//그러면 인덱스의 위치는 동일하고 그 index에 해당하는 색깔만 바뀜
		//arr를 쓴 방향(시계방향)에서 +3한 것을 대입하는 것은 순서로 읽으면 반시계방향 회전임

		//해당 면(plane)을 돌린다.
		//A배열을 회전해서 B배열을 만드는 경우
		//시계방향 90도 회전 식:B[i][j]=A[2-j][i];
		//반시계방향 90도 회전 식: B[i][j]=A[j][2-i];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[i][j]=arr[ cube[plane_num][j][2-i] ];//cube에 해당하는 색을 변경한다.
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[cube[plane_num][i][j]]=temp[i][j];
	}
	return;
}

void convert(char plane, char dir) {//char형을 int형으로 바꾸는 함수
	int dir_num;
	if (dir == '-')	dir_num = 1;
	else if (dir == '+') dir_num = 3;//시계방향 회전은 반시계방향 회전을 3번한것
	switch (plane)
	{
	case 'U':
		move(0, dir_num);
		break;

	case 'D':
		move(1, dir_num);
		break;

	case 'F':
		move(2, dir_num);
		break;

	case 'B':
		move(3, dir_num);
		break;

	case 'L':

		move(4, dir_num);
		break;

	case 'R':
		move(5, dir_num);
		break;
	
	}
	
	return;
}

int main() {
	//큐브에 index 준다.
	//U, D, F, B, L, R
	for (int f = 0; f < 6; f++)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cube[f][i][j] = (f * 9) + (i * 3) + j;

	int T;
	cin >> T;

	while (T--) {
		init();//큐브 초기화
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			

			char plane, dir;
			cin>> plane >> dir ;
			convert(plane, dir);

			
		}
		//index는 가만히 있고, index에 해당하는 색(arr)을 출력한다.
		//색이 회전한다.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << arr[cube[0][i][j]];
			}
			cout << endl;
		}
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
//pair랑 struct중에 struct사용
struct person {
	int x, y;
	//현재좌표
}typedef person;
person a, b;

struct A {
	//위치
	int x, y;
	//세기
	int c;
	//충전량
	int p;
};
struct A BC[9];

int ap[101];//화살표저장
int bp[101];
//set<int> max_;
int flag_A[9], flag_B[9];//특정시간에 접속가능한 BC의 index를 저장
int power;//power 최대값 저장. +=이용

void path(int, person);

int main()
{
	freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	int M, A;
	
	//M:이동시간, A:무선충전기 개수
	
	int n;//임시변수
	int test_case = 1;
	while (T--) {
		
		cin >> M >> A;

		for (int i = 0; i < M; i++) {
			cin >> n;
			ap[i]=n;
			//path(n, a);
		}
		for (int i = 0; i < M; i++) {
			cin >> n;
			bp[i] = n;
		}//화살표만 저장하고 필요할 때 실시간으로 경로계산함
		//스페이스바 하면 배열에 하나씩 들어감***

		for (int i = 1; i <= A; i++) {
			cin >> BC[i].x >> BC[i].y >> BC[i].c >> BC[i].p;
		}//index가 1부터 시작한다.


		for (int i = 0; i <= M; i++) {
			//i==0일 때. 초기위치도 BC유효범위인지 계산해봐야함
			if (i == 0) {
				b.x = 10; b.y = 10;
			}

			//2. BC유효범위 계산
			int dist;
			for (int j = 1; j <= A; j++) {
				dist = abs(a.x - BC[j].x) + abs(a.y - BC[j].y);
				if (dist <= BC[j].c) {
					flag_A[j] = j;
				}
				dist = abs(b.x - BC[j].x) + abs(b.y - BC[j].y);
				if (dist <= BC[j].c) {
					flag_B[j] = j;//BC의 index자체를 넣는다
				}

			}
			
			//3. 충전량 계산
			//int temp_A,temp_B=0;
			int temp = 0;

			for (int j = 1; j <= A; j++) {
				//충전할 BC가 A에 있는 경우
				
					//탐색하는 두개의 원소가 서로 같을 경우
					if (flag_A[j] == flag_B[j]) {
						if (flag_A[j]) {
							if (temp < BC[j].p) {
								temp = BC[j].p;
							}
						}
					}
					//탐색하는 두개의 원소가 서로 같지 않을경우
					//(0,1)또는 (1,0)
					else if (flag_A[j] != flag_B[j]) {
						if (flag_A[j] | flag_B[j]) {//(1,0)
							if (temp < BC[j].p) {
								temp = BC[j].p;
							}
						}
					}
					
				/*	if (flag_A[j]) {
						for (int k = j; k <= A; k++) {
							
							if (flag_B[k] & flag_A[j]) {
								if (temp < BC[j].p + BC[k].p) {
									temp = BC[j].p + BC[k].p;

								}
							}

						}
					}*/
					
					power += temp;
					temp = 0;//혹시 몰라 초기화
					//for문을 하고 if문을 하는게 빠른가 if문을 하고 for문을 하는게 빠른가?
					//두개가 같은가?
					//충전할 BC가 B에만 있는 경우
					/*if (flag_B[j]) {

					}
					power += temp;
					temp = 0;//혹시 몰라 초기화*/
					
				



			}
			
			//1. 사용자 이동
			path(ap[i], a); path(bp[i], b);

		}

		//4. 충전량 최대값 출력
		cout << '#' << test_case<<" "<<power<<endl;
			test_case++;
	}
	return 0;

}

void path(int n, person p){
	//화살표->좌표
	switch (n)
	{
		case 1:
			p.y--;
			break;
		case 2:
			p.x++;
			break;
		case 3:
			p.y++;
			break;
		case 4:
			p.x--;
			break;
	default:

		//아무것도 하지않음,skip
		break;
	}

}
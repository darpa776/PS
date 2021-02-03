#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(vector<vector<int>> answer ) {
    for(int i=0;i<answer.size();i++){
        int x = answer[i][0];
        int y = answer[i][1];
        int stuff = answer[i][2];//보인지 기둥인지

        
        if (stuff == 0) {//기둥이라면
            bool check = false;
            //바닥이면 설치 가능하다
            if (y == 0) check = true;
            //보 위거나 기둥 위면 설치 가능하다
            for (int j = 0; j < answer.size(); j++) {
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {//좌측에 보가 설치 되어있는 경우
                    check = true;
                }
                if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {//해당위치에 보가 설치되어있는 경우
                    check = true;
                }
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {//기둥이 설치되어있는 경우
                    check = true;
                }
            }
            if (!check) return false;
        }
        else//보라면
        {
            bool check = false;
            bool left = false;
            bool right = false;
            //바닥에 보를 설치하도록 입력이 들어오지 않으므로 예외처리할 필요 없다.
            //좌측 또는 우측에 기둥이 있는 경우
            //좌우측 모두 보가 설치되어 있는 경우

			for (int j = 0; j < answer.size(); j++) {
				if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {//좌측에 보가 설치 되어있는 경우
					left = true;
				}
				if (x +1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {//우측에 보가 설치되어있는 경우
					right = true;
				}
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {//좌측아래에기둥이 설치되어있는 경우
					check = true;
				}
                if (x+1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {//좌측아래에기둥이 설치되어있는 경우
                    check = true;
                }
			}
            if (left && right) //둘다 true인 경우
                check = true;
            if (!check) return false;

        }


    }

    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

    vector<vector<int>> answer;
  
    for (int i = 0; i < build_frame.size(); i++) {

        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int stuff = build_frame[i][2];//보인지 기둥인지
        int install = build_frame[i][3];//설치할지 삭제할지

        if (install) {//만약 설치해야한다면
            vector<int> inserted;
            inserted.push_back(x);
            inserted.push_back(y);
            inserted.push_back(stuff);
            answer.push_back(inserted);
            if (!possible(answer)) {
                answer.pop_back();
            }
        }
        else {//만약 삭제하는 거면
            int index;
            for (int j = 0; j < answer.size(); j++) {
                if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]) {
                    //설치된 건축물이 이미 존재하면 해당 인덱스의 answer를 삭제
                    index = j;
                }
            }
            vector<int> erased = answer[index];//지우기 전 임시저장
            answer.erase(answer.begin() + index);//해당 index의 건축물을 삭제
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.push_back(erased); // 가능한 구조물이 아니라면 다시 설치
            }
        }

    }
    sort(answer.begin(), answer.end());
    return answer;

   
}

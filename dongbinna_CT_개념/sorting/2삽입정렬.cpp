#include <iostream>
using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    for (int i = 1; i < n; i++) {
        // 인덱스 i부터 1까지 감소하며 반복하는 문법
        for (int j = i; j > 0; j--) {
            // 한 칸씩 왼쪽으로 이동
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                //swap하면 앞으로 가며 자기보다 작은 값이 나와 안바꿔도 될 때까지 적절한 위치 찾기
            }
            // 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
            else break;
            //앞은 다 정렬되어 있기 때문에 여기가 내 적절한 위치니까 여기서부터는 전진하지 않음
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}
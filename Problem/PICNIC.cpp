#include <iostream>
#include <cstring>

using namespace std;


int n;
bool areFriends[10][10];

// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
    int firstFree = -1; // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다
    
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }
    
    // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다
    if (firstFree == -1) return 1;
    int ret = 0;
    
    // 이 학생과 짝지을 학생을 결정한다
    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true; // 짝이 정해져 있는 상태에서
            ret += countPairings(taken); // 재귀한다
            taken[firstFree] = taken[pairWith] = false; // 다른 경우의 수 찾기 위해 짝을 해제한다
        }
    }
    return ret;
}

int main() {
    int test;
    bool taken[10];
    
    cin >> test;
    if (test < 0 || test > 50)
        exit(-1);
    for (int i = 0; i < test; i++) {
        int pair;
        cin >> n >> pair;
        if (n < 2 || n > 10 || pair < 0 || pair > (((n) * (n - 1)) / 2))
            exit(-1);
        
        // 초기화
        memset(areFriends, false, sizeof(areFriends));
        memset(taken, false, sizeof(taken));
        
        for (int k = 0; k < pair; k++) {
            int student1, student2;
            cin >> student1 >> student2;
            areFriends[student1][student2] = areFriends[student2][student1] = true;
        }
        cout << countPairings(taken) << '\n';
    }
    return 0;
}

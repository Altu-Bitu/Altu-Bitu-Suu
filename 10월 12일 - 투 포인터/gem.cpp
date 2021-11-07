//샘플 코드 + 주석 제출
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
/**
 * [투 포인터]
 * 2020 카카오 인턴십 : 보석 쇼핑
 * 1. 보석이 저장된 배열이 존재할 때, set을 이용해 보석의 종류 수를 알아낸다.
 * 2. (효율성 O .ver) 두 포인터를 맨 왼쪽부터 시작해 오른쪽으로 점점 이동시킨다.
 * 3. map을 이용해 현재 구간의 보석 종류 개수를 센다. 만약 구간 안 보석 종류 수가 전체 보석 종류 수와 동일하다면 최단 구간을 갱신한다.
 *    또한, 최대한 짧은 구간을 잡기 위해 left를 오른쪽으로 이동한다. 제외된 보석의 개수는 빼준다.
 * 3-1. 구간 안 보석 종류 수가 전체 보석 종류 수보다 작다면 right를 오른쪽으로 이동한다. 포함된 보석의 개수는 늘려준다.
 * 3-2  (구간 안 보석 종류 수가 전체 보석 종류 수보다 커지는 경우는 없음)
 */

//시간복잡도 O(n^2) -> 정확성 O, 효율성 X
vector<int> gemList(vector<string> &gems, int gem_size) { // gems: 보석 배열, gem_size: 보석 종류 개수
    int size = gems.size();
    vector<int> ans = {1, size};

    for (int i = 0; i < size; i++) { //i로 시작하는 구간
        map<string, int> m; //구간에 있는 보석
        for (int j = i; j < size; j++) { //j에서 끝나는 구간
            m[gems[j]]++; //보석 추가
            if (m.size() == gem_size) { //모든 종류의 보석이 있음
                if (j - i < ans[1] - ans[0]) //최단 구간 갱신
                    ans = {i + 1, j + 1};
                break; //더이상 구간을 늘릴 필요 없음
            }
        }
    }
    return ans;
}

//시간복잡도 O(n) -> 정확성 O, 효율성 O
vector<int> gemListTwoPointer(vector<string> &gems, int gem_size) { // gems: 보석 배열, gem_size: 보석 종류 개수
    int left = 0, right = 0, size = gems.size(); //같은 위치에서 같은 방향으로 이동하는 투 포인터
    vector<int> ans = {1, size}; //정답 구간 초기화. (맨 처음부터 맨 끝이 가능한 가장 넓은 구간이므로)
    map<string, int> m;
    m[gems[left]]++; //초기 구간

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    //right는 항상 size보다 작은 값이어야 함
    while (left <= right && right < size) {
        //m.size(): 구간 안 보석 종류 개수 by map / gem_size: 모든 보석 종류 개수 by set
        if (m.size() == gem_size) { // 모든 종류의 보석이 있음
            if (right - left < ans[1] - ans[0]) //모든 종류의 보석을 포함한 구간일 때, right 와 left 사이 간격이 현재 최단 구간보다 작다면 갱신
                ans = {left + 1, right + 1};
            left++; //구간을 짧게하기 위해 left 이동 (최대한 짧은 구간을 잡아야하므로 구간 내에 모든 종류의 보석이 있어도 좁혀야함)
            m[gems[left - 1]]--; //left 이동 후 구간에서 제외된 보석 개수 하나 빼줌
            if (m[gems[left - 1]] == 0) //더이상 이 보석이 없다면 제거 (종류 하나 없어짐)
                m.erase(gems[left - 1]);
        } else if (m.size() < gem_size) { //모든 종류의 보석이 있는게 아니라면
            right++; //구간을 길게하기 위해 right 이동 (보석 종류 수를 늘려야하니까)
            if (right == size) //런타임 에러 방지. right가 맨 오른쪽에 도달하면 break
                break;
            m[gems[right]]++; //구간에 새로 포함된 보석 개수 하나 증가
        }
    }
    return ans;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    set<string> unique_gem; //set을 이용해 보석의 종류 저장
    for (int i = 0; i < gems.size(); i++)
        unique_gem.insert(gems[i]);
    int gem_size = unique_gem.size(); //보석의 종류 개수

    answer = gemListTwoPointer(gems, gem_size); // 최단 구간 반환
    return answer;
}

int main() {
    //입력
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"}; //보석들의 이름이 저장된 배열

    //연산
    vector<int> ans = solution(gems);

    //출력
    cout << ans[0] << ' ' << ans[1]; // 모든 보석을 하나 이상 포함하는 가장 짧은 구간
}
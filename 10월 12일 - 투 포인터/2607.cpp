//샘플 코드 + 주석 제출 (필수 문제)
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26; // 알파벳 개수 만큼

/**
 * [투 포인터]
 * 2607 비슷한 단어
 * 1. 입력으로 주어진 첫번째 단어를 구성하고 있는 알파벳 개수를 벡터에 저장.
 * 2. 입력 단어와 비교할 타겟 단어를 구성하고 있는 알파벳 개수를 마찬가지로 벡터에 저장.
 * 3. A ~ Z까지 알파벳 개수 차이를 diff에 누적.
 * 3-1. 만약 diff가 1과 같거나 작으면 두 단어는 '비슷한 단어'. diff가 2여도 두 단어의 길이가 같으면 한 문자만 바꿔도 비슷한 단어가 됨.
 */

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0);
    for (int i = 0; i < str.size(); i++)
        result[str[i] - 'A']++; //str을 구성하는 알파벳 개수 저장. result[알파벳 순서. A:0, Z: 25] = 개수
    return result;
}

/**
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */
int main() {
    int n, ans = 0;
    string source, target;

    //입력
    cin >> n >> source;

    //연산
    vector<int> source_alpha = alphaMap(source); //source 단어를 이루고 있는 알파벳 개수를 저장한 벡터. source_alph[26]
    while (--n) {
        cin >> target;

        int diff = 0;
        vector<int> target_alpha = alphaMap(target); //target 단어를 이루고 있는 알파벳 개수를 저장한 벡터.
        for (int i = 0; i < SIZE; i++) //알파벳 A~Z까지. 두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]); //동일 알파벳 개수 차이를 diff에 누적해줌
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) //문자를 더하거나, 빼거나, 바꾸거나 (알파벳 차이 없거나, 하나 차이거나, 둘 차이 나는데 단어 길이 똑같으면 한문자만 바꿔도 됨)
            ans++;
    }

    //출력
    cout << ans;
}
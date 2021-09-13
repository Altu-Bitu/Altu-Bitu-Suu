//18870 좌표 압축
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> arr, v;

int binary_search(int target) {
    // 이분 탐색 수행
    int left = 0, right = v.size() - 1; // left, right 초기화
    while (left <= right) {
        int mid = (left + right) / 2; // mid 갱신
        // 타겟 값 찾음
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

int main(){
    set<int> s;
    int N;
    cin >> N;
    arr.assign(N, 0);
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    v.reserve(s.size ());
    copy (s.begin (), s.end (), back_inserter (v));
    for (int i = 0 ; i < N ; i++)
        cout << binary_search(arr[i]) << ' ';
    return 0;
}
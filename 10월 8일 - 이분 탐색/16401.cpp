//16401 과자 나눠주기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int N, M;

//upper bound
int upperBound(int left, int right) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값

        int num = 0; // num: mid로 나누어줄 수 있는 과자 개수
        for(int i = N-1; i>=0 ; i--){
            if(arr[i] < mid) break;
            num += arr[i] / mid;
        }

        if (num >= M){//과자의 길이를 늘린다
            left = mid + 1; // mid보다 커져야됨
        }
        if (num < M) // 과자의 길이를 줄인다
            right = mid - 1; //mid보다 작아져야됨

    }
    return right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin >> M >> N;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); //이분 탐색을 하기 위해선 반드시 정렬을 해야함

    cout << upperBound(1, arr[N-1]);
}
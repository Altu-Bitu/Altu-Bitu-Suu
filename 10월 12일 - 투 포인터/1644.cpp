//샘플 코드 + 주석 제출 (라이브 코딩)
#include <iostream>
#include <vector>

using namespace std;

/**
 * [투 포인터]
 * 1644 소수의 연속합
 * 1. 자연수 N이 주어질 때, 1부터 N까지 값들이 소수인지 판단하는 bool 자료형 vector(is_prime)를 만든다. (에라토스테네스의 체 사용)
 * 2. 소수인지 판단하는 bool vector를 이용해서 1부터 N까지 소수들을 모아놓은 vector(prime_list)를 만든다. 자연히 오름차순이 된다.
 * 3. 두 포인터와 구간을 맨 왼쪽(같은 위치)부터 시작해 점점 오른쪽으로 이동한다.
 *     구간의 합이 N보다 작으면 right를 벌릴 것이며 구간의 합이 N보다 크다면 left를 좁힐 것이다. 두 포인터의 방향은 오른쪽으로 동일하다.
 */
//에라토스테네스의 체로 n 이하인 모든 소수 구하기
vector<bool> isPrime(int n) {
    vector<bool> is_prime(n + 1, true); //소수 여부 저장

    is_prime[0] = is_prime[1] = false; // 0이랑 1은 false로 초기화
    for (int i = 2; i * i <= n; i++) { //2부터 루트n 까지
        if (is_prime[i]) { //i가 소수라면
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false; //i의 배수 제거(=flase로 만듬)
        }
    }
    return is_prime;
}

//n 이하의 모든 소수
vector<int> primeList(vector<bool> &is_prime) {
    vector<int> prime_list;

    for (int i = 2; i <= is_prime.size(); i++) { //2부터 n까지
        if (is_prime[i]) //소수이면 prime_list에 추가함
            prime_list.push_back(i);
    }
    return prime_list;
}

//같은 위치에서 시작하여 같은 방향으로 이동하는 투 포인터
int findSum(vector<int> &prime_list, int target) { //2부터 n까지 중 소수가 담긴 오름차순 배열에서 합이 target(=n)이 되는 구간을 찾자
    int ans = 0; // 구간 개수 카운트
    int size = prime_list.size(), left = 0, right = 0;
    int sum = prime_list[left]; //초기 구간은 맨 왼쪽 개수 하나. 전체적으로 구간이 오른쪽으로 이동함.

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    //right는 항상 size보다 작은 값이어야 함
    while (left <= right && right < size) {
//        if (sum == target) { //구간의 합이 target과 같을 때
//            ans++; left++; right++; //모든 포인터 이동
//            if (right == size) //오른쪽 끝에 도달하면 break
//                break;
//            sum -= prime_list[left - 1]; //이번 구간에 제외되는 값
//            sum += prime_list[right]; //이번 구간에 추가되는 값
//        } else if (sum > target) { //구간의 합이 target보다 클 때
//            left++; //합을 작게하기 위해 left 이동
//            sum -= prime_list[left - 1];
//        } else if (sum < target) { //구간의 합이 target보다 작을 때
//            right++; //합을 크게하기 위해 right 이동
//            if (right == size)
//                break;
//            sum += prime_list[right];
//        }
        if (sum >= target) { //구간의 합이 target보다 크거나 같다면
            if (sum == target) //같다면
                ans++; //경우의 수 증가
            left++; //합을 작게하기 위해 left 이동 (맨 왼쪽 값 하나 빼는거임)
            sum -= prime_list[left - 1]; //left 이동 후 값 하나 제외
        } else if (sum < target) { //구간의 합이 target보다 작을 때
            right++; //합을 크게하기 위해 right 이동
            if (right == size) //끝에 도달했으면 break
                break;
            sum += prime_list[right]; //right 이동 후 값 하나 추가
        }
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산
    vector<bool> is_prime = isPrime(n); //1~n까지 자연수들(index) 소수인지(bool) 저장.
    vector<int> prime_list = primeList(is_prime);
    int ans = findSum(prime_list, n); // 자연수 n을 연속된 소수의 합으로 나타낼 수 있는 경우의 수

    //출력
    cout << ans;
}
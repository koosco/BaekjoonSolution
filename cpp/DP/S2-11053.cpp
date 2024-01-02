#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

/*
	[문제]
	수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

	예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

	[입력]
	첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

	둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	[출력]
	첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
	
	[풀이]
	* 알고리즘
		1. N을 입력받는다
		2. 배열 A를 입력받고, 배열 A와 크기가 같고 1로 초기화된 dp 배열을 생성한다
		3. 배열을 순회: 현재 인덱스보다 앞에 있던 수들 중 현재값보다 작은 수들과 비교한다
					: 해당하는 값들 중 dp배열의 인덱스 값이 가장 큰 값 + 1을 저장한다
		4. dp배열에서 가장 큰 값을 출력한다
*/


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int A[1000], dp[1000];
	
	for(int i=0;i<1000;i++)
		dp[i] = 1;
	
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	for(int i=0;i<N;i++) {
		for(int j=0;j<i;j++) {
			if(A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	
	cout << *max_element(dp, dp+N) << endl;
	
    return 0;
}

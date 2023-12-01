#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


/*
	[문제]
	옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.

	길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

	S = A[0] × B[0] + ... + A[N-1] × B[N-1]

	S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.

	S의 최솟값을 출력하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 N이 주어진다. 둘째 줄에는 A에 있는 N개의 수가 순서대로 주어지고, 셋째 줄에는 B에 있는 수가 순서대로 주어진다. N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수이다.

	[출력]
	첫째 줄에 S의 최솟값을 출력한다.

	[풀이]
	* 조건
		- B를 재배열하면 안된다
		
	* 알고리즘
		1. N, A, B를 입력받는다
		2. B를 복제해 배열 C를 만든다
		3. A와 C를 각각 오름차순, 내림차순 정렬한다
		4. index에 맞게 각 값들을 곱해준다
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, val;
	int res = 0;
	vector<int> A, B;
	
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> val;
		A.push_back(val);
	}
	
	for(int i=0;i<N;i++){
		cin >> val;
		B.push_back(val);
	}
	
	vector<int> C(B);
	
	sort(A.begin(), A.end());
	sort(C.begin(), C.end(), greater<>());
	
	for(int i=0;i<N;i++)
		res += A[i] * C[i];
	
	cout << res << endl;
		
    return 0;
}

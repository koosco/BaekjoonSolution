#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

/*
	[문제]
	N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다.
	
	다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
	
	모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.

	[출력]
	M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
	
	[풀이]
	* 알고리즘
		1. N과 N개의 정수를 입력받는다
		2. 이분 탐색을 위해 A를 정렬한다
		3. M을 입력받는다
		4. M번 반복하며 값을 입력받고 이분탐색을 통해 값이 A에 있는지 확인하고 출력한다
		시간 복잡도: 정렬: O(NlogN), 순환 x 이분탐색: O(NlogN) -> O(NlogN)
	
	* 변수설정
		- 입력값: N, M, A를 생성
			- A는 전역변수로 설정
		- 입력값을 받기 위한 변수 설정
	
	* 이분탐색을 이용한 확인 함수
		- 입력값: int
		- 출력값: bool
			- 이분탐색을 하며 해당하는 값이 있다면 true 반환
			- 없다면 false를 반환
			
	[이력]
	1. 시간 초과
		: vector를 사용
	2. 시간 초과
		: 배열을 사용
	3. 통과
		: stdio를 사용해서 입출력 방식 변경
*/

int A[100000];
int N, M, val;

bool isInA(int num) {
	int left = 0, right = N - 1;
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(A[mid] == num)
			return true;
		else if(A[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

int main() {

	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	
	sort(A, A + N);
	
	scanf("%d", &M);
	for(int i=0;i<M;i++){
		scanf("%d", &val);
		if(isInA(val))
			printf("1\n");
		else
			printf("0\n");
	}
	
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

/*
	[문제]
	숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

	셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

	[출력]
	첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.
	
	[풀이]
	* 알고리즘
		1. N과 N개의 수를 입력받는다
		2. 배열을 정렬한다
		3. M을 입력받는다
		4. M개의 수를 순환하며 lower bound와 upper bound의 차이를 반환하는 함수를 사용
		5. 함수 반환값을 출력한다
		
	* 변수설정
		- 입력값: N, M
		- N개 값 저장을 위한 배열: A
		
	[이력]
	1. 시간 초과
		: map 사용, O(NlogN) + O(N) = O(NlogN)
	2. 통과
		: lower bound, upper bound 사용
		: O(NlogN)
	
*/



int main() {
	int N, M, val;
	int A[500000];
	
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	
	sort(A, A + N);
	
	scanf("%d", &M);
	for(int i=0;i<M;i++) {
		scanf("%d", &val);
		cout << upper_bound(A, A+N, val) - lower_bound(A, A+N, val) << " ";
	}
    return 0;
}

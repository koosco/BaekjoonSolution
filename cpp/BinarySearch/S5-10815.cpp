#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*
	[문제]
	숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
	
	두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

	셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다.
	
	이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

	[출력]
	첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.
	
	[풀이]
	* 알고리즘
		1. N과 N개의 수를 입력받는다
		2. N개의 수를 정렬한다
		3. M과 M개의 수를 입력받는다
		4. 갖고 있는지 판별하는 함수를 이용해 반환값을 받아 출력한다
		
	* isInCard
		- 입력값: int target
		- 출력값: bool
			- 이분 탐색을 이용해 target이 있는지 확인한다
			- 있는 경우 true, 없는 경우 false를 반환한다
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, val;
	
	
	cin >> N;
	int* A = new int[N];
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	
	sort(A, A+N);
	
	cin >> M;
	for(int i=0;i<M;i++) {
		scanf("%d", &val);
		if(binary_search(A, A+N, val))
			printf("1 ");
		else
			printf("0 ");
	}
	
    return 0;
}
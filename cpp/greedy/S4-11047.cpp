#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*
	[문제]
	준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

	동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

	둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

	[출력]
	첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.
	
	[풀이]
	* 알고리즘
		1. N과 K를 입력받는다
		2. 동전의 가치를 입력받아 배열 A에 입력받는다
		3. 동전의 가치를 뒤에서부터 돌며 K와 비교한다
		4. K보다 동전의 가치가 크다면 다음 동전과 비교한다
		5. K보다 동전의 가치가 작다면 결과값에 동전의 가치로 나눈 값을 더해준다
		6. 남은 동전의 가치를 나머지값으로 바꿔준다
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K, val, cnt = 0;
	vector<int> A;
	
	cin >> N >> K;
	for(int i=0;i<N;i++) {
		cin >> val;
		A.push_back(val);
	}
	
	for(int i=N-1;i>=0;i--) {
		if(K == 0)
			break;
		else if(K >= A[i]) {
			cnt += K / A[i];
			K %= A[i];
		}
	}
	
	cout << cnt << endl;
	
    return 0;
}

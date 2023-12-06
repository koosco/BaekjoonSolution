/*
	[문제]
	n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

	예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

	[입력]
	첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

	[출력]
	첫째 줄에 답을 출력한다.
	
	[풀이]
	* 알고리즘
		1. N과 크기 N의 배열을 입력받는다
		2. 값의 최댓값이 음수라면 가장 큰 수를 출력하고 종료한다
		3. 결과를 저장하는 변수와 임시 변수를 각각 0으로 초기화한다
		4. 값의 최댓값이 음수가 아니라면
			: 임시 변수가 배열을 순회한다
		5. 첫 번째 임시 변수값을 결과값으로 저장한다
		6. 순회하는 값을 임시 변수에 더해준다
			- 임시 변수값이 음수가 되면 0으로 초기화해준다
			- 임시 변수값이 결과값보다 커지면 결과값을 임시 변수값으로 바꿔준다
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, res, tmp;
	
	cin >> N;
	int *arr = new int[N];
	
	for(int i=0;i<N;i++)
		cin >> arr[i];
	
	res = *max_element(arr, arr+N);
	
	if(res > 0) {
		tmp = arr[0]; res = arr[0];
		for(int i=1;i<N;i++) {
			tmp += arr[i];
			if(tmp > res)
				res = tmp;
			if(tmp < 0)
				tmp = 0;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
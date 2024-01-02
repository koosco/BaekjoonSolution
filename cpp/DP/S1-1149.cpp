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
	RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

	집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 
	
	아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

	1번 집의 색은 2번 집의 색과 같지 않아야 한다.
	N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
	i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

	[입력]
	첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
	
	집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

	[출력]
	첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
	
	[풀이]
	* 알고리즘
		1. N을 입력받는다
		2. N번 반복하며 각 집을 빨강, 초록, 파랑으로 칠하는 비용을 입력받아 배열에 저장한다 -> costs
		3. dp 배열을 생성한다
		4. dp[0] = arr[0], 첫 번째 집을 칠하는 비용 자체가 최솟값
		5. dp[i][0] = arr[i][0] + min(dp[i-1][1] + dp[i-1][2])
			: 이번에 빨강으로 칠한다면 이전에 초록, 파랑 중 적은 비용을 선택
			: 이번에 초록으로 칠한다면 이전에 빨강, 파랑 중 적은 비용을 선택
			: 이번에 파랑으로 칠한다면 이전에 빨강, 초록 중 적은 비용을 선택
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int arr[1000][3];
	int dp[1000][3];
	
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	
	for(int i=0;i<3;i++)
		dp[0][i] = arr[0][i];
	
	for(int i=1;i<N;i++) {
		dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}
	
	cout << *min_element(dp[N-1], dp[N-1] + 3) << endl;
	
    return 0;
}

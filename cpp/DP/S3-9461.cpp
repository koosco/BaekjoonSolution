/*
	[문제]
	첫 삼각형은 정삼각형으로 변의 길이는 1이다. 그 다음에는 다음과 같은 과정으로 정삼각형을 계속 추가한다. 
	
	나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가한다.

	파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이이다. P(1)부터 P(10)까지 첫 10개 숫자는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9이다.

	N이 주어졌을 때, P(N)을 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. (1 ≤ N ≤ 100)

	[출력]
	각 테스트 케이스마다 P(N)을 출력한다.
	
	[풀이]
	* 패턴
		- arr[i] = arr[i-3] + arr[i-4] + arr[i-5];
		
	* 알고리즘
		1. T를 입력받는다
		2. 배열 arr을 초기화한다
		3. 패턴에 따라 값을 채운다 -> tabulation 방식
		4. 각 테스트 케이스에 대한 답을 출력한다
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, val;
	long arr[100] = {1, 1, 1};
	
	for(int i=3;i<100;i++)
		arr[i] = arr[i-2] + arr[i-3];
	
	cin >> T;
	while(T--) {
		cin >> val;
		cout << arr[val-1] << endl;
	}
    return 0;
}

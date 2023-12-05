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
	2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

	[출력]
	첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
	
	[풀이]
	* 패턴
		case 1
			- 세로 1개
			: 1
		case 2
			- 세로 2개
			- 가로 2개
			: 2
		case 3
			- case 1 + 가로 2개
			- case 2 + 세로 1개
		...
	
	* 알고리즘
		1. n을 입력받는다
		2. 1,000 크기의 배열을 초기화한다
		3. arr[1] = 1, arr[2] = 2로 초기화한다
		4. arr[n] = arr[n-1] + arr[n-2]로 넣어준다
		5. arr[n+1]을 10,007로 나눈 값을 출력한다
	
	[이력]
	1: x
		- 값을 저장할 때 10007로 나누지 않고 마지막에만 나누어줌
		-> 값이 오버플로우됨
	2: 통과
		- 값을 저장할 때마다 10007로 나누어줌
		-> 값이 오버플로우되지 않음
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	vector<int> arr(1000, 0);
	
	cin >> n;
	arr[1] = 1; arr[2] = 2;
	for(int i=3;i<=n;i++)
		arr[i] = (arr[i-1] + arr[i-2]) % 10007;
	
	cout << arr[n] << endl;
	
    return 0;
}

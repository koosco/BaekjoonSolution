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
	다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

	int fibonacci(int n) {
		if (n == 0) {
			printf("0");
			return 0;
		} else if (n == 1) {
			printf("1");
			return 1;
		} else {
			return fibonacci(n‐1) + fibonacci(n‐2);
		}
	}
	fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

	fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
	fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
	두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
	fibonacci(0)은 0을 출력하고, 0을 리턴한다.
	fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
	첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
	fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
	1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 테스트 케이스의 개수 T가 주어진다.

	각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

	[출력]
	각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
	
	[풀이]
	* 패턴
		case 0
			: [1, 0]
		case 1
			: [0, 1]
		case 2
			: [1, 1]
		case 3
			: [1, 2]
		case 4
			: [2, 3]
		...
	
	* 알고리즘
		1. 테스트 케이스 T를 입력받는다
		2. 40까지의 피보나치 수 배열을 생성한다
			[0, 1, 1, 2, 3, 5, 8, 13, 21, ...]
		3. 테스트 케이스 수를 입력받는다
			1) 0이라면 1, 0을 출력한다
			2) x가 1 이상이라면 x-1번째 인덱스와 x번째 인덱스 피보나치 수를 출력한다
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, val;
	vector<int> arr(41, 0);
	
	arr[1] = 1; arr[2] = 1; arr[3] = 2;
	
	cin >> T;
	for(int i=4;i<=40;i++)
		arr[i] = arr[i-1] + arr[i-2];
	
	while(T--) {
		cin >> val;
		if(val == 0)
			cout << 1 << " " << 0 << endl;
		else
			cout << arr[val-1] << " " << arr[val] << endl;
	}
	
    return 0;
}

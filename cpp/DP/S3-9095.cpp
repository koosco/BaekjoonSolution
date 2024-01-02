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
	정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

	1+1+1+1
	1+1+2
	1+2+1
	2+1+1
	2+2
	1+3
	3+1
	정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

	[출력]
	각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
	
	[풀이]
	* 패턴
		case 1:
			- 1
		case 2:
			- 1 + 1
			- 2
		case 3:
			- 1 + 1 + 1
			- 1 + 2
			- 2 + 1
			- 3
		case 4:
			- case1 + 3
			- case2 + 2
			- case3 + 1
		case 5:
			- case2 + 3
			- case3 + 2
			- case4 + 1
			
	* 알고리즘
		1. 1, 2, 3을 초기화시킨다
		2. case는 다음과 같은 패턴을 가진다
			: X번째 수에 대해
				- X-3번째 수를 만드는 경우 + 3
				- X-2번째 수를 만드는 경우 + 2
				- X-1번째 수를 만드는 경우 + 1
		3. 반복문을 돌며 위 규칙에 따라 수를 채워준다
		...
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int X, val;
	
	cin >> X;
	vector<int> arr(11, 0);
	
	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	for(int i=4;i<11;i++) {
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	}
	
	while(X--) {
		cin >> val;
		cout << arr[val] << endl;
	}
	
    return 0;
}

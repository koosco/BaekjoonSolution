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
	정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

	X가 3으로 나누어 떨어지면, 3으로 나눈다.
	X가 2로 나누어 떨어지면, 2로 나눈다.
	1을 뺀다.
	정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

	[입력]
	첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

	[출력]
	첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
	
	[풀이]
	* 알고리즘
		1. X를 입력받는다
		2. 크기 X의 배열을 만든다
		3. 초기 인덱스값을 설정한다
			1) [1] = 0, [2] = 1, [3] = 1
		4. 인덱스값을 순회하며 현재 인덱스 x2, x3, +1 인덱스값을 현재 인덱스값 + 1로 만든다
		5. x2, x3, +1 인덱스값이 현재 인덱스값+1보다 작다면 인덱스값을 바꿔준다
*/

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int X;
	cin >> X;
	vector<int> arr(X + 1, 0);
	
	arr[2] = 1;
	arr[3] = 1;
	
	for(int i=4;i<X+1;i++) {
		arr[i] = arr[i-1] + 1;
		if(i % 2 == 0)
			arr[i] = min(arr[i], arr[i/2] + 1);
		if(i % 3 == 0)
			arr[i] = min(arr[i], arr[i/3] + 1);
	}
	
	cout << arr[X] << endl;
	
    return 0;
}

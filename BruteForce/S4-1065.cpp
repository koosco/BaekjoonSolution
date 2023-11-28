#include <iostream>
#include <string>
#include <vector>

/*
	[문제]
	어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

	[입력]
	첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

	[출력]
	첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
	
	[풀이]
	* 변수 설정
		- 입력값: N
	
	* 한수 판별 함수
		- 입력값: int, 한수인지 판별할 세자리 수
		- 반환값: bool, 한수인지 여부 반환
			- 1. 일의 자리 수와 십의 자리 수 차이 == 십의 자리 수와 백의 자리 수 차이
				1) 같다면 true 반환
				2) 다르다면 false 반환
	
	* 알고리즘
		1. N을 입력받는다
			1) N이 100이하의 숫자라면 N을 출력
		2. N이 100 이상이라면
			1) 한수의 개수를 99로 초기화한다
			2) 100 이상 N 이하의 수들에 대해 한수인지 판별한다
				1) 한수라면 한수의 개수를 증가시킨다
			3) 한수의 개수를 출력
*/

using namespace std;

bool isHan(int num) {
	int hun = num / 100;
	int ten = num/10 % 10;
	int one = num % 10;
	if(hun - ten == ten - one)
		return true;
	return false;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	cin >> num;
	
	if(num < 100)
		cout << num << endl;
	else{
		int cnt = 99;
		for(int i=100;i<=num;i++)
			if(isHan(i))
				cnt++;
		cout << cnt << endl;
	}
    return 0;
}

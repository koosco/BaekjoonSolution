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
	세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

	그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

	괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
	
	그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

	[출력]
	첫째 줄에 정답을 출력한다.
	
	[풀이]
	* 조건
		- 식은 '0' ~ '9', '+', '-'로만 구성된다
		- 처음과 마지막은 숫자이다
		- 연속해서 두 개 이상의 연산자가 나오지 않는다
		- 5자리보다 많이 연속되는 숫자는 없다
		- 수는 0으로 시작할 수 있다 -> 0을 처리하는 로직 필요
		- 식의 길이는 50보다 작다
		
	* 알고리즘
		1. 식을 입력받는다
		2. flag를 false로 설정한다
		3. 문자열의 값을 하나씩 읽어들인다
			1) 숫자라면
				:버퍼에 넣는다
			2) 숫자가 아니라면
				1) flag == true
					: 값을 뺀다
				2) flag == false
					: 값을 더한다
				
				1) '-'라면
					: flag를 true로 바꾼다
		3. 더 이상 읽을 값이 없으면 결과를 반환한다
	
	[이력]
	1. x
		: 재귀함수를 호출하는 방법 사용
		: 음수가 한 번 더 나오는 경우를 처리하지 않음
	2. o
		: 음수가 한 번이라도 나오면 뒤에 있는 수들은 모두 빼는 연산이 된다
		: flag를 만들어 음수가 나오면 flag=true로 바꿔주고 뒤에 오는 수들을 모두 빼줌
		: 마지막에 buffer가 남아있다면 flag에 따라 값을 처리해줌
	
*/

int solve(string input) {
	string buffer = "";
	int res = 0;
	bool flag = false;
	
	for(int i=0;i<input.size();i++) {
		if(isdigit(input[i]))
			buffer += input[i];
		else{
			if(flag)
				res -= stoi(buffer);
			else
				res += stoi(buffer);
			buffer = "";
			if(input[i] == '-')
				flag = true;
		}
	}
	if(buffer.size() > 0) {
		if(flag) res -= stoi(buffer);
		else res += stoi(buffer);
	}
	return res;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string equation, buffer;
	int res = 0;
	
	cin >> equation;
	cout << solve(equation) << endl;
	
    return 0;
}

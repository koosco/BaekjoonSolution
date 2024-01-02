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
	타로는 자주 JOI잡화점에서 물건을 산다. JOI잡화점에는 잔돈으로 500엔, 100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고,
	
	언제나 거스름돈 개수가 가장 적게 잔돈을 준다. 타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장 냈을 때,
	
	받을 잔돈에 포함된 잔돈의 개수를 구하는 프로그램을 작성하시오.

	[입력]
	입력은 한줄로 이루어져있고, 타로가 지불할 돈(1 이상 1000미만의 정수) 1개가 쓰여져있다.

	[출력]
	제출할 출력 파일은 1행으로만 되어 있다. 잔돈에 포함된 매수를 출력하시오.
	
	[풀이]
	* 알고리즘
		1. 1000미만의 액수를 입력받는다
		2. 1000에서 액수를 뺀다
		3. 잔돈과 액수를 비교하며 액수보다 크다면 다음 잔돈과 액수를 비교한다
		4. 잔돈이 액수보다 크다면 액수를 잔돈으로 나눈 값을 결과에 더해준다
		5. 액수에 잔돈으로 나눈 나머지를 대입한다
		
	* 변수 설정
		- 액수: N
		- 결과 저장: res
		- 잔돈 배열: arr
*/
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, res = 0;
	vector<int> arr = {500, 100, 50, 10, 5, 1};
	
	cin >> N;
	N = 1000 - N;
	
	for(int price: arr) {
		if(N >= price) {
			res += N / price;
			N %= price;
		}
	}
	
	cout << res << endl;
	
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*
	[문제]
	상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

	상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.

	상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)

	[출력]
	상근이가 배달하는 봉지의 최소 개수를 출력한다. 만약, 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.
	
	[풀이]
	* 알고리즘
		1. N을 입력받는다
		2. 5킬로 그램 봉지의 개수를 하나씩 줄이며 설탕을 넣는 과정을 반복한다
			1) 개수를 5킬로 그램 봉지 개수만큼 증가시킨다
			2) 나머지 무게를 3키로 그램 봉지에 넣을 수 있으면 개수를 3키로 그램 봉지만큼 추가하고 종료한다
			3) 개수를 다시 0으로 만든다
		3. -1을 출력한다
*/

int solve(int N) {
	for(int i=N/5;i>=0;i--) {
		if((N - 5*i) % 3 == 0)
			return i + (N - 5*i) / 3;
	}
    return -1;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	cout << solve(N) << endl;
	return 0;
}
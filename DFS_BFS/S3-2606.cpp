/*
	[문제]
	신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 
	
	한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

	예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자.
	
	1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어
	
	2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 
	
	영향을 받지 않는다.

	어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 
	
	1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

	[입력]
	첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
	
	둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

	[출력]
	1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
	
	[풀이]
	* 알고리즘
		1. 컴퓨터의 수 n을 입력받는다
		2. 컴퓨터 쌍의 수 m을 입력받는다
		3. m번 반복하며 컴퓨터 쌍을 입력받는다 -> graph에 값을 넣어준다
		4. queue에 1을 넣어준다. visited 행렬을 생성한다
		5. !queue.empty()일 동안 반복한다
			1) 값을 하나 꺼낸다 -> 결과값을 하나 증가시킨다
			2) graph를 참고해 !visited라면 queue에 넣어준다
		6. 결과값을 출력한다
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	int from, to, res = 0;
	vector<int> graph[101];
	bool visited[101] = {};
	queue<int> q;
	
	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	q.push(1);
	visited[1] = true;

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(int i=0;i<graph[x].size();i++) {
			if(!visited[graph[x][i]]){
				res += 1;
				visited[graph[x][i]] = true;
				q.push(graph[x][i]);
			}
		}
	}
	
	cout << res << endl;
}
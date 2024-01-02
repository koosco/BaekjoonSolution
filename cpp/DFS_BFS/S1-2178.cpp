/*
	[문제]
	N×M크기의 배열로 표현되는 미로가 있다.

	1	0	1	1	1	1
	1	0	1	0	1	0
	1	0	1	0	1	1
	1	1	1	0	1	1
	미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

	위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

	[입력]
	첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

	[출력]
	첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
	
	[풀이]
	* 알고리즘
		1. n, m을 입력받는다
		2. graph를 입력받는다
		3. visited 배열을 생성한다
		4. queue에 (1, 1) 좌표를 넣어준다
		5. queue가 비어있지 않을 동안 동작을 반복한다
			1) 하나의 수를 deque한다
			2) 수가 graph 범위를 벗어나지 않는지 확인한다
			3) 수를 기준으로 좌, 우, 상, 하 값을 확인하고, !visited라면 queue에 좌표를 넣어준다
			4) visited[nx][ny] = visited[x][y] + 1로 설정해준다
			5) n, m 값이 채워지면 반복을 멈추고 답을 출력한다
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	int graph[100][100] = {};
	int dist[100][100] = {};
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	queue<pair<int, int>> q;
	
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		string row;
		cin >> row;
		for(int j=0;j<m;j++)
			graph[i][j] = row[j] - '0';
	}
	
	q.push(make_pair(0, 0));
	dist[0][0] = 1;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(-1 < nx && nx < n &&
			  -1 < ny && ny < m &&
			  graph[nx][ny] && !dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	
	cout << dist[n-1][m-1] << endl;
	
	return 0;
}
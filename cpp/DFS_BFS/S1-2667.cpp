/*
	[문제]
	<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
	
	철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
	
	여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. 
	
	<그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 
	
	각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

	[입력]
	첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

	[출력]
	첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

	[풀이]
	* 알고리즘
		1. n을 입력받는다
		2. graph를 입력받는다
		3. 각 좌표에 대해 반복하면서 !visitetd이면서 graph == 1인 좌표에 대해 check함수를 사용한다
	
	* check 함수
		1. queue를 생성한다
		2. queue에 좌표를 넣는다
		3. 좌, 우, 상, 하에 대해 범위 안에 있으며 !visited인 값을 queue에 넣어준다	
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool visited[25][25] = {};
int graph[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;

int check(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true;
	int ret = 1;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(-1 < nx && nx < n &&
			  -1 < ny && ny < n &&
			  graph[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				ret++;
			}
		}
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> res;
	
	cin >> n;
	for(int i=0;i<n;i++) {
		string row;
		cin >> row;
		
		for(int j=0;j<row.size();j++)
			graph[i][j] = row[j] - '0';
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(graph[i][j] && !visited[i][j])
				res.push_back(check(i, j));
		}
	}
	
	sort(res.begin(), res.end());
	
	cout << res.size() << endl;
	for(int num: res)
		cout << num << endl;
}
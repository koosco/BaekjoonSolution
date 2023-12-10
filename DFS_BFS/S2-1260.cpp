/*
	[문제]
	그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
	
	단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
	
	정점 번호는 1번부터 N번까지이다.

	[입력]
	첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
	
	다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
	
	입력으로 주어지는 간선은 양방향이다.

	[출력]
	첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
	
	[풀이]
	* 알고리즘
		1. N, M, V를 입력받는다
		2. M번 반복하며 두 정점의 번호를 입력받는다
		3. 입력받은 정점들은 양방향으로 이어져있음 -> 2차원 인접행렬에 저장
		4. 작은 수부터 출력해야하기 때문에 map에 저장된 값을 오름차순으로 정렬한다
		4. bool로 된 visited 배열을 생성한다
	
		* BFS
		1. queue에 v를 넣는다
		2. queue에서 값을 deque한다
		3. deque한 값을 visited 배열에서 true로 바꿔준다
		4. deque한 값 출력
		5. 인접행렬을 참고하여 visited == false인 값들을 enque한다
		6. 2-5 반복
		
		* DFS
		1. visited 배열을 false로 초기화한다
		2. stack에 v를 넣는다
		3. stack에서 값을 pop한다
		4. pop한 값을 visited 배열에서 true로 바꿔준다
		5. pop한 값 출력
		6. 인접행렬을 참고하여 visited == false인 값들을 push한다
			1) 이 때 작은 값부터 출력해야하기 때문에 뒤에서부터 stack에 넣어준다
		7. 3-6 반복
*/

// 1. 새로 푼 코드

// #include <stack>
// #include <queue>
// #include <vector>
// #include <iostream>
// #include <map>
// #include <algorithm>

// using namespace std;

// int N, M, V, from, to;
// int graph[1001][1001];

// void getBFS(int v) {
// 	queue<int> q;
// 	bool visited[1001] = {false};
	
// 	q.push(v);
	
// 	while(!q.empty()) {
// 		int elem = q.front();
// 		q.pop();
// 		if(!visited[elem]) {
// 			cout << elem << " ";
// 			visited[elem] = true;
// 		}
// 		for(int i=1;i<N+1;i++) {
// 			if(graph[elem][i] && !visited[i])
// 				q.push(i);
// 		}
// 	}
// 	cout << endl;
// }

// void getDFS(int v) {
// 	stack<int> stk;
// 	bool visited[1001] = {false};
	
// 	stk.push(v);
	
// 	while(!stk.empty()) {
// 		int elem = stk.top();
// 		stk.pop();
// 		if(!visited[elem]) {
// 			cout << elem << " ";
// 			visited[elem] = true;
// 		}
// 		for(int i=N;i>0;i--) {
// 			if(graph[elem][i] && !visited[i])
// 				stk.push(i);
// 		}
// 	}
	
// 	cout << endl;
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
	
// 	cin >> N >> M >> V;
// 	for(int i=0;i<M;i++){
// 		cin >> from >> to;
// 		graph[from][to] = 1;
// 		graph[to][from] = 1;
// 	}
	
// 	getDFS(V);
// 	getBFS(V);
	
// 	return 0;
// }


// 2. 이전에 푼 코드
// vector를 배열로 선언하고 사용

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
vector<int> res_dfs;
vector<int> res_bfs;
bool dfs_visited[1001] = {};

void bfs(int v){
    queue<int> q;
    bool visited[1001] = {};
    
    q.push(v);
    visited[v] = true;
    res_bfs.push_back(v);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            if(!visited[graph[x][i]]){
                visited[graph[x][i]] = true;
                res_bfs.push_back(graph[x][i]);
                q.push(graph[x][i]);
            }
        }
    }
}

void dfs(int v){
    if(!dfs_visited[v]){
        dfs_visited[v] = true;
        res_dfs.push_back(v);
        for(int i=0;i<graph[v].size();i++)
            dfs(graph[v][i]);
    }
}

int main(){
    int n, m, v;
    int u, w;
    
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0;i<m;i++){
        scanf("%d %d", &u, &w);
        graph[u].push_back(w);
        graph[w].push_back(u);
    }
    for(int i=1;i<n+1;i++)
        sort(graph[i].begin(), graph[i].end());
    
    bfs(v);
    dfs(v);
    for(auto& i: res_dfs)
        cout << i << " ";
    cout << endl;
    for(auto& i: res_bfs)
        cout << i << " ";
}

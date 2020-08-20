/*
... iss Crew
... Made By Mukho
... 2020-08-20 THU
... Breadth First Search and Depth First Search
*/

/*
	너비우선탐색(BFS) : 자신과 연결된 주변 정점부터 탐색.
						깊이가 깊은 그래프에서 높은 성능을 보임.
						넓이가 넓은 그래프에서 낮은 성능을 보임.
						Queue를 사용함. Tree의 Level-Order와 같음
						인접행렬 사용시 O(v^2), 인접리스트 사용시 O(V+E)

						0. 시작점을 queue에 push.
						1. queue의 가장 앞에 있는 노드를 pop
						2. 현재 노드에 인접한 모든 노드들 중 아직 방문하지 않은 노드들을 queue에 push
						3. queue가 비어있지 않으면, 1번부터 다시 실행

	깊이우선탐색(DFS) : 정점을 하나 선택해 연결된 모든 정점을 끝까지 탐색.
						넓이가 넓은 그래프에서 높은 성능을 보임.
						깊이가 깊은 그래프에서 낮은 성능을 보임.
						Stack 또는 재귀를 사용함. Tree의 Inorder와 같음
						인접행렬 사용시 O(v^2), 인접리스트 사용시 O(V+E)
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAXV 8

vector<int> adj[MAXV]; // 그래프의 연결 관계를 인접리스트로 저장
int visitB[MAXV]; // 노드 i를 방문한 적이 있으면 1, 없으면 0
int visitD[MAXV]; // 노드 i를 방문한 적이 있으면 1, 없으면 0
int visitD2[MAXV]; // 노드 i를 방문한 적이 있으면 1, 없으면 0

void BFS(int start);
void DFS(int start); // recursion
void DFS2(int start); // stack
int main() {
	// A-B
	adj[1].push_back(2);
	adj[2].push_back(1);
	// A-C
	adj[1].push_back(3);
	adj[3].push_back(1);
	// A-D
	adj[1].push_back(4);
	adj[4].push_back(1);
	// B-E
	adj[2].push_back(5);
	adj[5].push_back(2);
	// B-F
	adj[2].push_back(6);
	adj[6].push_back(2);
	// C-G
	adj[3].push_back(7);
	adj[7].push_back(3);
	/*
	            1
		2		3		4
	   5 6       7

	   BFS -> 1 2 3 4 5 6 7
	   DFS -> 1 2 5 6 3 7 4
	*/

	BFS(1); // 1번 노드부터 BFS 실행
	DFS(1); // 1번 노드부터 DFS(재귀) 실행
	cout << endl;
	DFS2(1); // 1번 노드부터 DFS(stack) 실행
	

	return 0;
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visitB[start] = 1;

	while (!q.empty()) {
		int x = q.front(); // 노드
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < adj[x].size(); i++) { // 그 노드에 자식 노드들이 있으면 push
			int y = adj[x][i];
			if (!visitB[y]) {
				q.push(y);
				visitB[y] = 1;
			}
		}
	}
	cout << endl;
}

void DFS(int start) {
	if (visitD[start])
		return;

	visitD[start] = 1;
	cout << start << ' ';

	for (int i = 0; i < adj[start].size(); i++) {
		int x = adj[start][i];
		DFS(x);
	}
}

void DFS2(int start) {
	stack<int> s;
	s.push(start);
	visitD2[start] = 1;
	cout << start << ' ';
	
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (!visitD2[y]) {
				cout << y << ' ';
				visitD2[y] = 1;
				s.push(x);
				s.push(y);
				break;
			}
		}
	}
	cout << endl;
}
/*
... iss Crew
... Made By Mukho
... 2020-08-21 FRI
... Dijkstra
*/

/*
	Dijkstra Algorithm using Priority Queue( O(N * log N) )
		- 모든 정점을 heap에 넣어 가장 작은 경로를 가진 정점이 나오도록 하자.
		- Linear Search나 Recursion을 이용하는 방법도 있다.( O(N^2) )
*/

// 시작점(1)에서 각 정점으로 가는 '최단 경로' 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 1000000;

vector<pair<int, int>> a[7]; // 간선 정보
int d[7]; // 최소 비용

void dijkstra(int start) {
	d[start] = 0; // 시작점
	priority_queue<pair<int, int> > pq; // Heap

	pq.push(make_pair(start, 0)); // 시작점
	// 가까운 순서대로 처리하기 때문에 Queue를 사용
	while (!pq.empty()) {
		int current = pq.top().first; // 현재 위치
		int distance = -pq.top().second; // 짧은 것이 먼저 오도록 음수화
		pq.pop();

		if (d[current] < distance) continue; // 최단 거리가 아닌 경우 스킵
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first; // 선택된 노드의 인접 노드
			int nextDistance = distance + a[current][i].second; // 선택된 노드를 인접 느드로 거쳐서 가는 비용

			// 기존의 최소 비용보다 더 저렴하다면 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		} 
	}
}

int main() {
	for (int i = 1; i <= number; i++)
		d[i] = INF; // 연결되지 않은 경우 비용은 무한으로 처리
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	// 시작점은 1
	dijkstra(1);

	for (int i = 1; i <= number; i++)
		cout << d[i] << ' ';
	cout << endl;
}
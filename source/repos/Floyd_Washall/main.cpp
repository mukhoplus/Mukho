/*
... iss Crew
... Made By Mukho
... 2020-08-21 FRI
... Floyd Warshall
*/

/*
	Floyd Warshall
		- '모든 정점'에서 '모든 정점'으로의 최단 경로를 구하고 싶다면 사용
		- 경로의 길이가 '음수'인 경우에도 사용 가능
		- 거쳐가는 정점을 기준으로 알고리즘을 수행
		- 3중 for문을 통해 구현 가능. O(V^3) -> 속도 느림
		- Dynamic Programming
		https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F
*/

#include <iostream>
using namespace std;

int number = 4;
int INF = 10000000;

// 자료 배열 초기화
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{-1, INF, 0, 4},
	{INF, INF, 3, 0}
};

void Floyd_Warshall() {
	int d[4][4]; // 결과 그래프 초기화
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			d[i][j] = a[i][j];

	// m = 거쳐가는 노드(경유지), s = 출발 노드, e = 도착 노드
	for (int m = 0; m < number; m++)
		for (int s = 0; s < number; s++) {
			for (int e = 0; e < number; e++)
				if (d[s][e] > d[s][m] + d[m][e])
					d[s][e] = d[s][m] + d[m][e];
		}

	// 결과 출력
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) 
			cout << d[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	Floyd_Warshall();

	return 0;
}
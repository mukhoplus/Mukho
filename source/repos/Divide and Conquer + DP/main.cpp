/*
... iss Crew
... Made By Mukho
... 2020-08-19 WEN
... Divide and Conquer
... Dynamic Programming
*/

/*
	Divide and Conquer(분할 정복법)
		- 주어진 문제를 작은 사례로 나누어, 각각의 작은 문제들을 해결하여 정복하는 방법.
		- Top-Down 방식(하향식 접근 방식)
		1. 문제 사례를 하나 이상의 작은 사례로 분할한다.
		2. 작은 사례들을 각각 정복한다.(사례가 충분히 적지 않은 이상 재귀를 사용한다.)
		3. 필요시 작은 사례들을 통합해 원래 사례의 답을 구한다.

		- 장점 : 문제를 나눔으로써 어려운 문제를 해결 가능.
			   : 병렬적으로 문제 해결하는데 강점을 가짐.
		- 단점 : 재귀 함수 호출로 인한 overhead 발생.
		       : 스택에 다양한 정보를 보관하고 있어야 하므로 Stack Overflow가 발생하거나 과도한 메모리 사용을 유발.
		
		- 예시 : Binary Search, 최대값 찾기, Merge Sort, Quick Sort, ...

		* Sudo Code
		Function F(x):
			If F(x) is Simple Then return 'F(x)의 결과'
			Else:
				x -> x1, x2
				Call F(x1), F(x2)
				return F(x1), F(x2)의 결과

		* Binary Search 1
		void Binary_Search(vector<int> v, int start, int end, int key) {
			if (start > end) return;
	
			int mid = (start + end) / 2;
			if (key == v[mid]) {
				cout << key << "는 " << mid << " 에 있다." << endl;
				return;
			}
			else {
				if (key < v[mid])
					Binary_Search(v, start, mid - 1, key);
				else
					Binary_Search(v, mid + 1, end, key);
			}
		}

		* Binary Search 2
		int Binary_Search(int target) {
			int low = 0;
			int high = v.size() - 1;

			while (low <= high) {
				int mid = (low + high) / 2;
				if (target == v[mid]) return mid; // found
				else if (target < v[mid]) low = mid + 1;
				else high = mid - 1;
			}
			return -1; // not found
		}

		* 최대값 찾기
		int findMax(vector<int> v, int start, int end) {
			if (start == end) return v[start]; // found
	
			int mid = (start + end) / 2;
			// divide
			int left = findMax(v, start, mid);
			int right = findMax(v, mid + 1, end);

			return (left > right) ? left : right;
		}
*/

/*
	Dynamic Programming(동적 계획법)
		- 복잡한 문제를 간단한 여러 개의 문제로 나누어 푸는 방법
		- 전체 문제를 작은 문제로 단순화한 다음, 점화식으로 만들어 재귀적인 구조를 활용, 전체 문제를 해결하는 방식
		- 불필요한 계산을 줄이고, 효율적으로 최적해를 찾을 수 있음
		- 하위 문제의 수가 기하급수적으로 증가할 때 유용하다.
		
		1. 단순화(divide)
		2. 점화식 생성(recursion 이용)
		3. 해결(conquer)

		- 최단 경로 문제, 행렬의 제곱 문제 등의 최적화에 사용된다.
		- Memoization : 함수의 값을 계산한 뒤, 그 값을 배열에 저장하는 방식.

		- Dynamic Programming : 약간의 시간은 걸림. 단, 우리가 갈 수 있는 모든 상황과 교통 정체를 전부 감안하여 최적의 경로를 찾아냄.
		- Greedy Algorithm : 즉효성은 있음. 단, 전체적인 상황을 고려하지 않고, 순간순간 교차로가 보일 때마다 가장 빠른 경로를 검색하여 찾음.

		예제) 피보나치 수열

			보통의 함수는 다음과 같다.
				function fib(n)
					if n = 0
						return 0
					else if n=1
						return 1 
					else
						return fib(n-1) + fib(n-2)
			- 중복되는 계산이 존재하기 때문에( 예시. level 3. (fib(3) + fib(2)) + (fib(2) + fib(1)) ), 전체적인 계산 속도가 떨어진다. 이 알고리즘의 시간 복잡도는 지수 함수( O(2^N) )가 된다.
			- 각 함수의 계산값을 저장하는 객체를 사용하면 중복 계산이 줄어들고, 시간 복잡도가 O(n)이 된다.
				var m := map(0 → 1, 1 → 1) // Memoization

				function fib(n)
					if n not in keys(m)
						m[n] := fib(n-1) + fib(n-2)
					return m[n]
*/

// 피보나치 수열 DP(재귀, 반복문)으로 구하기
#include <iostream>
using namespace std;

// DP_재귀
int Fib(int n) {
	int* data;
	data = new int[n + 1];

	data[0] = 0;
	data[1] = 1;

	if (data[n] > 0 || (n == 0)) return data[n];
	return Fib(n - 1) + Fib(n - 2);
}
// DP_반복문
int fib(int n) {
	int* data;
	data = new int[n + 1];

	data[0] = 0;
	data[1] = 1;

	if (n > 1)
		for (int i = 2; i <= n; i++)
			data[i] = data[i - 2] + data[i - 1];

	return data[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	while (1) {
		cout << "숫자 입력 : ";
		cin >> num;
		if (num < 0) break;
		else
			cout << fib(num) << "\n"; // 반복문
			cout << Fib(num) << "\n"; // DP
			// 반복문 O(n), DP O(n). 반복문이 더 빠르다
			// 재귀적 방식이 더 직관적이다.
	}

	return 0;
}
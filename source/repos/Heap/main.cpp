/*
... iss Crew
... Made By Mukho
... 2020-08-20 THU
... Heap
*/

/*
	Heap : 완전 이진 트리의 일종으로, 부모 노드와 자식 노드간에 항상 대소관계가 성립하는 자료구조(형제 노드들간에는 대소관계 상관 없음)
		   부모 노드가 자식 노드보다 항상 크면 최대힙(Max Heap), 항상 작으면 최소힙(Min Heap)
		   루트 노드에는 항상 가장 크거나 작은 값이 오기 때문에, 이를 이용해 우선 순위 큐(Priority Queue)의 구현이 가능하다.
		   
		   Max-Heap Example
								100
					19						36
			17				3		  25		   1
		2		7

			- 완전 이진 트리는 Array로 구현한다.
			- 구현을 쉽게 하기 위해 index는 1부터 시작한다.
			- 특정 노드의 index가 n이라 하면, 부모 노드는 n/2, 자식 노드는 n*2, n*2+1로 접근할 수 있다.
*/
#include <iostream>
#include <time.h>
using namespace std;

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

int heap[HEAP_SIZE]; // min heap
int heap_count = 0; // heap 원소의 갯수, 배열의 가장 끝 원소를 나타냄

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void init() {
	heap_count = 0;
}
int size() {
	return heap_count;
}
void push(int data) {
	heap[++heap_count] = data; // data 추가

	// 원소를 하나씩 올리는 부분
	int child = heap_count; // 방금 추가한 data
	int parent = child / 2; // 추가한 node의 parent
	while (child > 1 && heap[parent] > heap[child]) { // parent가 더 크면(min heap이기 때문)
		swap(&heap[parent], &heap[child]); // 교체
		child = parent; // node를 한단계 올려서 반복
		parent = child / 2;
	}
}
int pop() {
	int result = heap[1]; // 첫 원소 반환

	swap(&heap[1], &heap[heap_count]); // 첫 원소를 마지막 원소와 바꿈
	heap_count--;

	// 원소를 하나씩 내리는 부분(바꿨으니 정렬을 해야지)
	int parent = 1; // 방금 삭제한 후 바꿔준 원소
	int child = parent * 2; // 비교할 원소의 left child
	if (child + 1 <= heap_count) // 노드가 child를 가지고 있는가
		child = (heap[child] < heap[child + 1]) ? child : child + 1; // left와 right 중 더 작은 node로 비교
	while (child<=heap_count && heap[parent]>heap[child]) { // child가 parent보다 더 작은게 맞는가?
		swap(&heap[parent], &heap[child]); // 교체

		parent = child; // node를 한단계 낮춰서 반복
		child = child * 2;
		if (child + 1 <= heap_count) // 노드가 child를 가지고 있는가
			child = (heap[child] < heap[child + 1]) ? child : child + 1; // left와 right 중 더 작은 node로 비교
	}
	return result;
}
int main() {
	int arr[ARRAY_SIZE];

	// 랜덤함수를 위한 srand와 seed
	srand(unsigned(time(NULL)));

	for (int i = 0; i < ARRAY_SIZE; i++)
		arr[i] = rand() % 50 + 1; // 배열을 1~50의 난수로 초기화 -> 분명 99.9% 확률로 정렬되지 않은 순서일 것이다.

	// heap에 삽입
	for (int i = 0; i < ARRAY_SIZE; i++)
		push(arr[i]);

	// pop하면서 값들을 확인
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << pop() << ' ';
	cout << endl;

	return 0;
}


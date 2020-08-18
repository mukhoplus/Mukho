/*
... iss Crew
... Made By Mukho
... 2020-08-18 TUE
... Sorting and Search Algorithm
*/

#include <iostream>
#include <vector>
using namespace std;

/*
	선택 정렬(Selection Sort)
	- 현재 위치에 들어갈 값을 찾아 정렬하는 알고리즘.
	- 최소/최대 선택 정렬로 구분 가능.
	- 1. 정렬 되지 않은 index의 맨 앞에서부터, 이를 포함한 그 이후의 배열값 중 가장 작은 값을 찾는다.
	  2. 가장 작은 값을 찾으면, 그 값을 현재 index의 값과 바꾼다.
	  3. 다음 index에서 위 과정을 반복한다.

	- 시간복잡도 : O(n^2) -> 무조건 전체 비교
	- 공간복잡도 : O(1) -> 하나의 배열에서만 진행
*/
void Selection_Sort(vector<int>& v); // 전체 비교 후 맨 앞으로 정렬

/*
	삽입 정렬(Insertion Sort)
	- 현재 위치에서, 그 이하의 배열들을 비교해 자신이 들어갈 위치를 찾아 그 위치에 삽입하는 알고리즘.
	- 1. 2번째 index부터 시작함. 현재 index는 별도의 변수에 저장하고, 비교 index는 (현재 index-1)로 잡는다.
	  2. 삽입을 위한 변수와 비교 index의 배열 값을 비교한다.
	  3. 삽입 변수의 값이 더 작으면 현재 index로 비교 index의 값을 저장해주고, 비교 index를 -1하여 비교를 반복한다.
	  4. 만약 삽입 변수가 더 크면, 비교 index + 1에 삽입 변수를 저장한다.

	- 시간복잡도 : O(n^2) / (최선의 경우, 이미 정렬된 배열에서 실행-O(n)
	- 공간복잡도 : O(1)
*/
void Insertion_Sort(vector<int>& v); // 맨 앞(정렬된 값)의 값들과 비교

/*
	버블 정렬(Bubble Sort)
	- 매번 연속된 두개 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨 정렬하는 방법
	- 1. 2번째 index부터 시작함. 현재 index는 별도의 변수에 저장하고, 비교 index는 (현재 index-1)로 잡는다.
	  2. 삽입을 위한 변수와 비교 index의 배열 값을 비교한다.
	  3. 삽입 변수의 값이 더 작으면 현재 index로 비교 index의 값을 저장해주고, 비교 index를 -1하여 비교를 반복한다.
	  4. 만약 삽입 변수가 더 크면, 비교 index + 1에 삽입 변수를 저장한다.

	- 시간복잡도 : O(n^2) -> 무조건 전체 비교
	- 공간복잡도 : O(1)
*/
void Bubble_Sort(vector<int>& v); // 따다아아아아악 따다아아아악 따다아아악 따다아악 따닥 딱!

/*
	합병 정렬(Merge Sort)
	- 분할 정복(Divide and Conquer) 방식으로 설계된 알고리즘.
	- 입력으로 하나의 배열을 받고, 연산 중에 두개의 배열로 계속 쪼개 나간 뒤, 합치면서 정렬해 최후에는 하나의 정렬을 출력
	- 1. 하나의 배열을 반으로 쪼갠다. 배열의 시작 위치와 종료 위치를 입력받아, 둘을 더한 후 2를 나눠 기준을 잡는다.
	  2. 이를 쪼갠 배열의 크기가 0이거나 1일때 까지 비교한다.
	- 1. 두 배열 A, B의 크기를 배교해 각각 배열의 첫 index를 i, j로 하자.
	  2. A[i]와 B[j]를 비교해 작은 값(오름차순 기준)을 새 배열 C에 저장하자. 저장한 배열의 index는 1 증가시킨다.
	  3. 2번의 과정을 한 배열이 끝까지 도달할 때 까지 반복한다.
	  4. 남은 배열의 값을 모두 C에 저장한다.
	  5. C를 원래 배열에 저장한다.

	- 시간복잡도 : O(N log N)
	- 공간복잡도 : O(N)
*/
void Merge_Sort(vector<int>& v, int start, int end);
void merge(vector<int>& v, int start, int end, int mid); // 합병 함수

/*
	합병 정렬(Merge Sort)
	- 분할 정복(Divide and Conquer) 방식으로 설계된 알고리즘. 분할과 정복을 동시에 한다.
	- pivot이라 하는 기준이 되는 값을 기준으로 비교해 작은 값은 왼쪽, 큰 값은 오른쪽으로 옮기는 방식으로 진행.
	- 1. pivot 값을 정한다.
	  2. 가장 왼쪽 index를 저장할 left 변수, 가장 오른쪽 index를 저장할 right 변수를 생성한다.
	  3. right부터, right가 left보다 클때만 반복하여 비교한다. 비교한 배열값이 pivot보다 크면 right를 하나 감소시키고 비교를 반복한다. pivot보다 작은 배열 값을 찾으면 반복을 중지한다.
	  4. 그 다음 left부터, right가 left보다 클때만 비교를 진행한다. 비교한 배열값이 pivot보다 작으면 left를 하나 증가시키고 비교를 반복한다. pivot보다 큰 배열 값을 찾으면 반복을 중지한다.
	  5. left index 값과 right index 값을 바꿔준다.
	  6. 3~5 과정을 left<right가 만족할 때 까지 반복한다.
	  7. 위 과정이 끝나면 left의 값과 pivot을 바꿔준다.
	  8. 맨 왼쪽부터 left - 1까지, left+1부터 맨 오른쪽까지로 나눠 Quick Sort를 반복한다.

	- 시간복잡도 : O(N log N) / (최악의 경우 - 이미 정렬되어 있는 경우 O(N^2)
	- 공간복잡도 : O(log N)
*/
void Quick_Sort(vector<int>& v, int start, int end);

// 선형 검색
void Linear_Search(vector<int> v, int key);
// 이진 검색(재귀 사용)
void Binary_Search(vector<int> v, int start, int end, int key);

int main() {
	vector<int> select;
	vector<int> insert;
	vector<int> bubble;
	vector<int> merge;
	vector<int> quick;

	select.push_back(2);
	select.push_back(5);
	select.push_back(3);
	select.push_back(1);
	select.push_back(4);
	insert.push_back(2);
	insert.push_back(5);
	insert.push_back(3);
	insert.push_back(1);
	insert.push_back(4);
	bubble.push_back(2);
	bubble.push_back(5);
	bubble.push_back(3);
	bubble.push_back(1);
	bubble.push_back(4);
	merge.push_back(2);
	merge.push_back(5);
	merge.push_back(3);
	merge.push_back(1);
	merge.push_back(4);
	quick.push_back(2);
	quick.push_back(5);
	quick.push_back(3);
	quick.push_back(1);
	quick.push_back(4);

	// 기존 배열 출력
	cout << "select before : ";
	for (int i = 0; i < select.size(); i++)
		cout << select[i] << ' ';
	cout << endl;

	cout << "insert before : ";
	for (int i = 0; i < insert.size(); i++)
		cout << insert[i] << ' ';
	cout << endl;

	cout << "bubble before : ";
	for (int i = 0; i < bubble.size(); i++)
		cout << bubble[i] << ' ';
	cout << endl;

	cout << "merge before : ";
	for (int i = 0; i < merge.size(); i++)
		cout << merge[i] << ' ';
	cout << endl;

	cout << "quick before : ";
	for (int i = 0; i < quick.size(); i++)
		cout << quick[i] << ' ';
	cout << endl;

	cout << "* linear search 1 : ";
	Linear_Search(select, 1);
	cout << "* linear search 0 : ";
	Linear_Search(select, 0);
	cout << endl;

	// 정렬
	Selection_Sort(select);
	Insertion_Sort(insert);
	Bubble_Sort(bubble);
	Merge_Sort(merge, 0, merge.size() - 1);
	Quick_Sort(quick, 0, quick.size() - 1);

	// 정렬 후 배열 출력
	cout << "select after : ";
	for (int i = 0; i < select.size(); i++)
		cout << select[i] << ' ';
	cout << endl;

	cout << "insert after : ";
	for (int i = 0; i < insert.size(); i++)
		cout << insert[i] << ' ';
	cout << endl;

	cout << "bubble after : ";
	for (int i = 0; i < bubble.size(); i++)
		cout << bubble[i] << ' ';
	cout << endl;

	cout << "merge after : ";
	for (int i = 0; i < merge.size(); i++)
		cout << merge[i] << ' ';
	cout << endl;

	cout << "quick after : ";
	for (int i = 0; i < quick.size(); i++)
		cout << quick[i] << ' ';
	cout << endl;

	cout << "* binary search 4 : ";
	Binary_Search(quick, 0, quick.size() - 1, 4);
	cout << "* binary search -1 : ";
	Binary_Search(quick, 0, quick.size() - 1, -1);
	cout << endl;

	return 0;
}

void Selection_Sort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[minIdx] > v[j])
				minIdx = j;
		swap(v[i], v[minIdx]);
	}
}

void Insertion_Sort(vector<int>& v) {
	for (int i = 1; i < v.size(); i++) {
		int key = v[i];
		int j = i - 1;
		for (j; j >= 0 && key < v[j]; j--)
			v[j + 1] = v[j]; // 값 이동 ->
		v[j + 1] = key; // 해당 위치에 값 저장
	}
}

void Bubble_Sort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++)
		for (int j = 1; j < v.size(); j++)
			if (v[j - 1] > v[j])
				swap(v[j - 1], v[j]);
}

void Merge_Sort(vector<int>& v, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;

		// 분할 Divide
		Merge_Sort(v, start, mid);
		Merge_Sort(v, mid + 1, end);

		// 합병 Conquer
		merge(v, start, end, mid);
	}
}
void merge(vector<int>& v, int start, int end, int mid) {
	vector<int> temp;
	int i = start, j = mid + 1, tempIdx = 0;

	while (i <= mid && j <= end) {
		if (v[i] < v[j])
			temp.push_back(v[i++]);
		else
			temp.push_back(v[j++]);
	}

	while (i <= mid)
		temp.push_back(v[i++]);
	while (j <= end)
		temp.push_back(v[j++]);

	for (int k = start; k <= end; k++)
		v[k] = temp[tempIdx++];
}

void Quick_Sort(vector<int>& v, int start, int end) {
	int pivot = v[start]; // start를 하든, random으로 하든, mid( (start+end)/2 )로 하든 자유
	int left = start, right = end;

	// Partition start
	while (start < end) {
		while (pivot <= v[end] && start < end)
			end--; // <-
		while (pivot >= v[start] && start < end)
			start++; // ->

		swap(v[start], v[end]);
	}
	swap(v[left], v[start]);
	/*
		1. pivot을 선택한다.
		2. 오른쪽(end)에서 왼쪽으로 가면서 pivot보다 작은 수를 찾는다. (<- pivot보다 작은 첫 값)
		3. 왼쪽(start)에서부터 오른쪽으로 가면서 pivot보다 큰 수를 찾는다. (pivot보다 큰 첫 값 ->)
		4. 각 인덱스 start, end 에 대한 요소를 교환한다.

		5. 2, 3, 4번 과정을 반복한다.
		6. 2, 3번을 더이상 진행할 수 없다면, 현재 pivot과 교환한다.

		7. 그 결과 교환된 pivot를 기준으로 왼쪽은 pivot보다 작은 수들이 존재하고, 오른쪽은 큰 수들이 존재한다.
		https://mygumi.tistory.com/308
	*/
	// Partition end

	if (left < start)
		Quick_Sort(v, left, start - 1);
	if (right > end)
		Quick_Sort(v, start + 1, right);

	/*
	  function quicksort(a, left, right)
	  if right > left then
		  select a pivot value a[pivotIndex]
		  pivotNewIndex := partition(a, left, right, pivotIndex)
		  quicksort(a, left, pivotNewIndex-1)
		  quicksort(a, pivotNewIndex+1, right)
	*/
}

void Linear_Search(vector<int> v, int key){
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			cout << key << " 값은 " << i << " index에 존재한다." << endl;
			break;
		}
		if (i == v.size() - 1)
			cout << key << " 값을 찾을 수 없다." << endl;
	}
}
void Binary_Search(vector<int> v, int start, int end, int key) {
	if (start > end) {
		cout << key << " 값을 찾을 수 없다." << endl;
		return;
	}
	
	int mid = (start + end) / 2;
	if (v[mid] == key) {
		cout << key << " 값은 " << mid << " index에 존재한다." << endl;
		return;
	}
	else if (v[mid] < key)
		Binary_Search(v, mid + 1, end, key);
	else
		Binary_Search(v, start, mid - 1, key);
}
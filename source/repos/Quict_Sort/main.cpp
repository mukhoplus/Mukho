/*
... iss Cruw
... Made By Mukho
... 2020-06-28 SUN
... Quick Sort
*/
#include <iostream>
using namespace std;
#define SIZE 10
#define Swap(x, y, temp) ( temp=x, x=y, y=temp )

void QuickSort(int list[], int left, int right);
int partition(int list[], int left, int right);

int main()
{
	int arr[SIZE] = { 2, 7, 1, 25, 37, 5, 16, 12, 9, 36 };

	cout << "정렬 전 배열 출력" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << ' ';
	cout << endl << endl;

	// 정렬
	QuickSort(arr, 0, SIZE - 1);

	cout << "정렬 후 배열 출력" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

void QuickSort(int list[], int left, int right)
{
	if (left < right)
	{
		int p = partition(list, left, right);

		QuickSort(list, left, p - 1);
		QuickSort(list, p + 1, right);
	}
}
int partition(int list[], int left, int right)
{
	int low = left;
	int high = right + 1;
	int pivot = list[left]; // 맨 왼쪽 데이터를 pivot으로 선택
	int temp;

	do
	{
		// low, high를 이용해 pivot과 비교해 작은 값과 큰 값을 pivot 좌우로 분리
		do
		{
			low++; // low는 left + 1부터 증가
		} while(low <= right && list[low] < pivot);
		// list[low]가 pivot보다 작으면 low 증가

		do
		{
			high--; // high는 right부터 시작
		} while (high >= left && list[high] > pivot);
		// list[high]가 pivot보다 크면 high 감소
		
		// low와 high가 교차하지 않았으면 list[low]와 list[high]를 교환(실 교환 코드)
		if (low < high)
			Swap(list[low], list[high], temp);
	} while (low < high);

	// low와 high가 교차했으면 반복문 밖에서 list[left]와 list[high]를 교환 // pivot(list[left])을 제 위치(high)로 보내는 과정임
	Swap(list[left], list[high], temp);

	return high; // pivot 위치 반환
}
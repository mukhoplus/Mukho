/*
... iss Crew
... Made By Mukho
... 2020-06-27 SAT
... Sorting 2/2
*/
#include <iostream>
using namespace std;

#define SIZE 10
int sorted[SIZE];

void Double_Selection_Sort(int list[], int size); // 한 사이클씩 비교 후 최소값을 찾아 맨 앞 값과 교체.
void merge(int list[], int left, int mid, int right);
void Merge_Sort(int list[], int left, int right);

int main()
{
	// 배열 선언
	int arr1[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Double Selection Sort
	int arr2[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Merge Sort
	
														   // 정렬 전 배열 출력
	cout << "정렬 전 배열 출력" << endl;
	cout << "arr1 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr1[i] << ' ';
	cout << endl;
	cout << "arr2 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr2[i] << ' ';
	cout << endl;

	// 정렬
	Double_Selection_Sort(arr1, SIZE);
	Merge_Sort(arr2, 0, SIZE - 1);

	// 정렬 후 배열 출력
	cout << "정렬 후 배열 출력" << endl;
	cout << "arr1 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr1[i] << ' ';
	cout << endl;
	cout << "arr2 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr2[i] << ' ';
	cout << endl;
	
	return 0;
}

void Double_Selection_Sort(int list[], int size)
{
	int start = 0;
	int end = size - 1;

	while(start < end)
	{
		int minIndex = start;
		int maxIndex = end;
		for(int i=start+1; i<end+1;i++)
		{
			if (list[i] < list[minIndex])
				minIndex = i;
			if (list[i] > list[maxIndex])
				maxIndex = i;
		}
		if (start != minIndex)
		{
			int temp = list[start];
			list[start] = list[minIndex];
			list[minIndex] = temp;
		}
		if (end != maxIndex)
		{
			int temp = list[end];
			list[end] = list[maxIndex];
			list[maxIndex] = temp;
		}
		start++;
		end--;
	}
}

void merge(int list[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (int l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (int l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
}
void Merge_Sort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		Merge_Sort(list, left, mid);
		Merge_Sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
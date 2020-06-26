/*
... iss Crew
... Made By Mukho
... 2020-06-26 FRI
... Sorting 1/2
*/
#include <iostream>
using namespace std;

#define SIZE 10

void Bubble_Sort(int list[], int size);
void Selection_Sort(int list[], int size); // 한 사이클씩 비교 후 최소값을 찾아 맨 앞 값과 교체.
void Insertion_Sort(int list[], int size); // 한 값을 정한 후, 앞의 값들과 비교해 그 값의 위치를 찾아 서로 교체함.

void BinarySearch(int list[], int size, int key);
void BinarySearchRecursion(int list[], int first, int last, int key);
void LinearSearch(int list[], int size, int key);

int main()
{
	// 배열 선언
	int arr1[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Binary Search after Bubble Sort
	int arr2[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Binary Search with Recursion after Selection Sort
	int arr3[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Linear Search after Insertion Sort

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
	cout << "arr3 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr3[i] << ' ';
	cout << endl << endl;

	// 정렬
	Bubble_Sort(arr1, SIZE);
	Selection_Sort(arr2, SIZE);
	Insertion_Sort(arr3, SIZE);

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
	cout << "arr3 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr3[i] << ' ';
	cout << endl << endl;

	// 검색
	cout << "검색" << endl;
	cout << "Binary Search를 이용해 16과 17을 찾기" << endl;
	BinarySearch(arr1, SIZE, 16);
	BinarySearch(arr1, SIZE, 17);
	cout << endl;
	cout << "Recursion을 이용한 Binary Search를 이용해 9와 28을 찾기" << endl;
	BinarySearchRecursion(arr2, 0, SIZE, 9);
	BinarySearchRecursion(arr2, 0, SIZE, 28);
	cout << endl;
	cout << "Linear Search를 이용해 27과 5을 찾기" << endl;
	LinearSearch(arr3, SIZE, 27);
	LinearSearch(arr3, SIZE, 5);
	cout << endl;

	return 0;
}

void Bubble_Sort(int list[], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 1; j < size; j++)
			if (list[j - 1] > list[j])
			{
				int temp = list[j-1];
				list[j-1] = list[j];
				list[j] = temp;
			}
}
void Selection_Sort(int list[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < size; j++)
			if (list[j] < list[minIndex])
				minIndex = j;
		if (i != minIndex)
		{
			int temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}
void Insertion_Sort(int list[], int size)
{
	int i = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		int CurData = list[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (list[j] > CurData)
				list[j + 1] = list[j];
			else
				break;
		}
		list[j + 1] = CurData; // for문에서 -1이 되어서 나옴.
	}
}


void BinarySearch(int list[], int size, int key)
{
	int first = 0, last = size - 1, mid;
	bool found = false;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (list[mid] == key)
		{
			cout << key << "의 index는 " << mid << endl;
			found = true;
			break;
		}
		else if (list[mid] > key)
			last = mid - 1;
		else
			first = mid + 1;
	}

	if (found == false)
		cout << key << "의 값을 찾을 수 없다." << endl;
}
void BinarySearchRecursion(int list[], int first, int last, int key)
{
	if (first > last)
	{
		cout << key << "의 값을 찾을 수 없다." << endl;
		return;
	}
	int mid = (first + last) / 2;

	if (list[mid] == key)
	{
		cout << key << "의 index는 " << mid << endl;
		return;
	}
	else if (list[mid] > key)
		BinarySearchRecursion(list, first, mid - 1, key);
	else
		BinarySearchRecursion(list, mid + 1, last, key);

}
void LinearSearch(int list[], int size, int key)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (list[i] == key)
		{
			cout << key << "의 index는 " << i << endl;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << key << "의 값을 찾을 수 없다." << endl;
}
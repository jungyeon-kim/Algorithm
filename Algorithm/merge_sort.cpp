#include <iostream>

using namespace std;

/*
	합병 정렬) nlogn

	1. 배열을 나눌 수 없는 상태까지 분할
	2. 쪼개 놓은 배열들을 한 쌍으로 짝지어 병합
	3. 합쳐진 쌍들끼리 첫번째 원소들을 비교, 배제해가며 정렬
	4. 2,3 반복

	※ 정렬하려는 배열의 크기와 똑같은 임시 컨테이너 필요 (공간복잡도 ↑)
*/

void merge(int* arr, int* arr2, int start, int end)
{
	int mid{ (start + end) / 2 };
	int i{ start };
	int j{ mid + 1 };
	int k{ start };

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j]) arr2[k++] = arr[i++];
		else arr2[k++] = arr[j++];
	}

	int tmp{ i > mid ? j : i };

	while (k <= end) arr2[k++] = arr[tmp++];

	for (int i = start; i <= end; i++) arr[i] = arr2[i];
}

void partition(int* arr, int* arr2, int start, int end)
{
	int mid{};

	if (start < end)
	{
		mid = (start + end) / 2;
		partition(arr, arr2, start, mid);
		partition(arr, arr2, mid + 1, end);
		merge(arr, arr2, start, end);
	}
}

int main()
{
	constexpr int NUM{ 100 };
	int arr[NUM]{}, arr2[NUM]{};

	for (int i = 0; i < NUM; ++i) arr[i] = rand() % 1000;

	partition(arr, arr2, 0, NUM - 1);

	for (int i = 0; i < NUM; i++) cout << arr[i] << " ";
}
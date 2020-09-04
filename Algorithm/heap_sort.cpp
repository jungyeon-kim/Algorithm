#include <iostream>

using namespace std;

/*
	힙 정렬) nlogn

	1. 힙을 구성
	2. root 노드와 맨끝 노드를 swap
	3. 1, 2 반복

	※ Heap:			부모, 자식간에 상하관계가 존재하는 완전이진트리
	※ 완전이진트리:	빈 공간없이 순차적으로 채워져있는 트리
*/

void heapify(int* arr, int size) 
{
	for (int i = 1; i < size; ++i) 
	{
		int child{ i };

		while (child)
		{
			int root{ (child - 1) / 2 };

			// 자식 노드가 부모 노드보다 크면 swap
			if (arr[root] < arr[child]) swap(arr[root], arr[child]);
			child = root;
		}
	}
}

void heapSort(int* arr, int* size)
{
	// 최하단 노드의 기준을 좁혀가며 최상단 노드와 최하단 노드 교체
	swap(arr[0], arr[(*size) - 1]);
	--(*size);
}

int main() 
{
	constexpr int NUM{ 10 };
	int arr[NUM]{};
	int size{ NUM };

	for (int i = 0; i < NUM; ++i) arr[i] = rand() % 1000;

	for (int i = 0; i < NUM; ++i)
	{
		heapify(arr, size);
		heapSort(arr, &size);
	}

	for (int i = 0; i < NUM; ++i) cout << arr[i] << " ";
}
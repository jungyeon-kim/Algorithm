#include <iostream>

using namespace std;

/*
	힙 정렬) nlogn

	1. 초기 힙 구성
	2. root 노드와 맨끝 노드를 swap
	3. 맨끝 노드를 제외하고 루트 노드부터 시작해 힙 재구성
	4. 3, 4 반복

	※ insert 방식보다 전체 배열을 최초 한번 힙으로 구성하는 것이 효율적

	※ Heap:			부모, 자식간에 상하관계가 존재하는 완전이진트리
					insert:	맨끝에 노드를 삽입 -> 부모와 비교해가며 swap (logn)
					delete:	맨끝노드를 루트노드로 대체 -> 자식과 비교해가며 swap (logn)
	※ 완전이진트리:	빈 공간없이 순차적으로 채워져있는 트리
*/

// 최대 힙
void heapify(int* arr, int size, int parentIdx)
{
	int left{ 2 * parentIdx + 1 }, right{ 2 * parentIdx + 2 }, Idx{ parentIdx };

	// 자식이있다면, 부모보다 값이 큰 자식 인덱스를 max에 대입 (둘중 값이 더 큰 자식)
	if (left < size && arr[left] > arr[Idx]) Idx = left;
	if (right < size && arr[right] > arr[Idx]) Idx = right;

	// 더 큰 자식이 있었다면, 값을 swap
	// 자식의 값이 바뀌었다면, 자식 또한 재귀호출로 검사 & 처리
	if (Idx != parentIdx)
	{
		swap(arr[parentIdx], arr[Idx]);
		heapify(arr, size, Idx);
	}
}

void heapSort(int* arr, int size)
{
	// 초기 상태를 힙으로
	for (int i = size / 2 - 1; i >= 0; --i) heapify(arr, size, i);

	// 루트와 맨끝 노드를 swap하게 되면 힙의 성질이 깨짐
	// 때문에, 루트 노드부터 차례로 재귀호출 (이 때, size - 1로 맨끝 노드는 제외 -> 정렬이 끝났기에)
	for (int i = size - 1; i >= 0; --i)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N{};
	cin >> N;

	int* arr{ new int[N] };
	for (int i = 0; i < N; ++i) cin >> arr[i];

	heapSort(arr, N);

	for (int i = 0; i < N; ++i) cout << arr[i] << "\n";
}
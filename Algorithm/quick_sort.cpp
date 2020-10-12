#include <iostream>

using namespace std;

/*
	퀵 정렬) O(nlogn)

	1. pivot을 선정한다.
	2. 맨 왼쪽과 맨 오른쪽을 left와 right로 선정
	3. start, right가 pivot으로 이동 중 left가 pivot보다 큰 수를, right가 pivot보다 작은 수를 만나면 서로 swap
	4. left가 right보다 커질 때 까지 3을 반복
	5. left, right를 기준으로 배열을 나눠 1, 2, 3, 4 반복

	※ nlogn 정렬 알고리즘 중 평균적으로 가장 높은 성능
*/

void quickSort(int* arr, int start, int end)
{
	if (start >= end) return;					// 더이상 연산할 수 없는 경우

	int pivot{ arr[(start + end + 1) / 2] };	// 중간값을 피벗으로
	int left{ start };
	int right{ end };

	while (left <= right)
	{
		while (arr[left] < pivot) ++left;		// pivot보다 크거나 같은 left 탐색
		while (arr[right] > pivot) --right;		// pivot보다 작거나 같은 right 탐색

		if (left <= right)
		{
			swap(arr[left], arr[right]);		// 스왑
			++left; --right;
		}
	}
	
	// left, right를 기준으로 나눠 재정렬
	quickSort(arr, start, right);
	quickSort(arr, left, end);
}

int main()
{
	constexpr int NUM{ 100 };
	int arr[NUM]{};

	for (int i = 0; i < NUM; ++i) arr[i] = rand() % 1000;

	quickSort(arr, 0, NUM - 1);

	for (int i = 0; i < NUM; i++) cout << arr[i] << " ";
}
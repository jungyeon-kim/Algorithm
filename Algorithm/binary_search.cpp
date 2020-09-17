#include <iostream>

using namespace std;

/*
	이진탐색) O(logn)

	1. 배열의 중간값(부모노드)이 찾는값인지 검사
	2. 찾는값이 중간값보다 작다면 좌측의 중간값과 비교하고, 크다면 우측의 중간값과 비교
	3. 2 반복

	※ 전제조건으로 정렬이 되어있어야함 (정렬 오버헤드 고려할 것)
*/

bool binarySearch(int* arr, int len, int key)
{
	int start{};
	int end{ len - 1 };
	int mid{};

	while (end - start >= 0)
	{
		mid = (start + end) / 2;					// 중간값(부모노드) Set

		if (arr[mid] == key) return true;			// 찾는값이 중간값이라면
		else if (arr[mid] < key) start = mid + 1;	// 찾는값이 중간값보다 크다면
		else end = mid - 1;							// 찾는값이 중간값보다 작다면
	}

	return false;
}

int main()
{
	constexpr int NUM{ 10000 };
	int arr[NUM];
	int key{};

	for (int i = 0; i < NUM; ++i) arr[i] = i;

	while (1)
	{
		cout << "찾을 정수: ";
		cin >> key;

		cout << "결과: " << binarySearch(arr, NUM, key) << "\num";
	}
}
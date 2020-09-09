#include <iostream>

using namespace std;

/*
	�պ� ����) nlogn

	1. �迭�� ���� �� ���� ���±��� ����
	2. �ɰ� ���� �迭���� �� ������ ¦���� ����
	3. ������ �ֵ鳢�� ù��° ���ҵ��� ��, �����ذ��� ����
	4. 2,3 �ݺ�

	�� �����Ϸ��� �迭�� ũ��� �Ȱ��� �ӽ� �����̳� �ʿ� (�������⵵ ��)
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
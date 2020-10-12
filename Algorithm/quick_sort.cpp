#include <iostream>

using namespace std;

/*
	�� ����) O(nlogn)

	1. pivot�� �����Ѵ�.
	2. �� ���ʰ� �� �������� left�� right�� ����
	3. start, right�� pivot���� �̵� �� left�� pivot���� ū ����, right�� pivot���� ���� ���� ������ ���� swap
	4. left�� right���� Ŀ�� �� ���� 3�� �ݺ�
	5. left, right�� �������� �迭�� ���� 1, 2, 3, 4 �ݺ�

	�� nlogn ���� �˰��� �� ��������� ���� ���� ����
*/

void quickSort(int* arr, int start, int end)
{
	if (start >= end) return;					// ���̻� ������ �� ���� ���

	int pivot{ arr[(start + end + 1) / 2] };	// �߰����� �ǹ�����
	int left{ start };
	int right{ end };

	while (left <= right)
	{
		while (arr[left] < pivot) ++left;		// pivot���� ũ�ų� ���� left Ž��
		while (arr[right] > pivot) --right;		// pivot���� �۰ų� ���� right Ž��

		if (left <= right)
		{
			swap(arr[left], arr[right]);		// ����
			++left; --right;
		}
	}
	
	// left, right�� �������� ���� ������
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
#include <iostream>

using namespace std;

/*
	�� ����) nlogn

	1. �ʱ� �� ����
	2. root ���� �ǳ� ��带 swap
	3. �ǳ� ��带 �����ϰ� ��Ʈ ������ ������ �� �籸��
	4. 3, 4 �ݺ�

	�� insert ��ĺ��� ��ü �迭�� ���� �ѹ� ������ �����ϴ� ���� ȿ����

	�� Heap:			�θ�, �ڽİ��� ���ϰ��谡 �����ϴ� ��������Ʈ��
					insert:	�ǳ��� ��带 ���� -> �θ�� ���ذ��� swap (logn)
					delete:	�ǳ���带 ��Ʈ���� ��ü -> �ڽİ� ���ذ��� swap (logn)
	�� ��������Ʈ��:	�� �������� ���������� ä�����ִ� Ʈ��
*/

// �ִ� ��
void heapify(int* arr, int size, int parentIdx)
{
	int left{ 2 * parentIdx + 1 }, right{ 2 * parentIdx + 2 }, Idx{ parentIdx };

	// �ڽ����ִٸ�, �θ𺸴� ���� ū �ڽ� �ε����� max�� ���� (���� ���� �� ū �ڽ�)
	if (left < size && arr[left] > arr[Idx]) Idx = left;
	if (right < size && arr[right] > arr[Idx]) Idx = right;

	// �� ū �ڽ��� �־��ٸ�, ���� swap
	// �ڽ��� ���� �ٲ���ٸ�, �ڽ� ���� ���ȣ��� �˻� & ó��
	if (Idx != parentIdx)
	{
		swap(arr[parentIdx], arr[Idx]);
		heapify(arr, size, Idx);
	}
}

void heapSort(int* arr, int size)
{
	// �ʱ� ���¸� ������
	for (int i = size / 2 - 1; i >= 0; --i) heapify(arr, size, i);

	// ��Ʈ�� �ǳ� ��带 swap�ϰ� �Ǹ� ���� ������ ����
	// ������, ��Ʈ ������ ���ʷ� ���ȣ�� (�� ��, size - 1�� �ǳ� ���� ���� -> ������ �����⿡)
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
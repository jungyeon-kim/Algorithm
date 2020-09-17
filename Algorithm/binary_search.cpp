#include <iostream>

using namespace std;

/*
	����Ž��) O(logn)

	1. �迭�� �߰���(�θ���)�� ã�°����� �˻�
	2. ã�°��� �߰������� �۴ٸ� ������ �߰����� ���ϰ�, ũ�ٸ� ������ �߰����� ��
	3. 2 �ݺ�

	�� ������������ ������ �Ǿ��־���� (���� ������� ����� ��)
*/

bool binarySearch(int* arr, int len, int key)
{
	int start{};
	int end{ len - 1 };
	int mid{};

	while (end - start >= 0)
	{
		mid = (start + end) / 2;					// �߰���(�θ���) Set

		if (arr[mid] == key) return true;			// ã�°��� �߰����̶��
		else if (arr[mid] < key) start = mid + 1;	// ã�°��� �߰������� ũ�ٸ�
		else end = mid - 1;							// ã�°��� �߰������� �۴ٸ�
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
		cout << "ã�� ����: ";
		cin >> key;

		cout << "���: " << binarySearch(arr, NUM, key) << "\num";
	}
}
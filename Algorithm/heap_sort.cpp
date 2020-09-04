#include <iostream>

using namespace std;

/*
	�� ����) nlogn

	1. ���� ����
	2. root ���� �ǳ� ��带 swap
	3. 1, 2 �ݺ�

	�� Heap:			�θ�, �ڽİ��� ���ϰ��谡 �����ϴ� ��������Ʈ��
	�� ��������Ʈ��:	�� �������� ���������� ä�����ִ� Ʈ��
*/

void heapify(int* arr, int size) 
{
	for (int i = 1; i < size; ++i) 
	{
		int child{ i };

		while (child)
		{
			int root{ (child - 1) / 2 };

			// �ڽ� ��尡 �θ� ��庸�� ũ�� swap
			if (arr[root] < arr[child]) swap(arr[root], arr[child]);
			child = root;
		}
	}
}

void heapSort(int* arr, int* size)
{
	// ���ϴ� ����� ������ �������� �ֻ�� ���� ���ϴ� ��� ��ü
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
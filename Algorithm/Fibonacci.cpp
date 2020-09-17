#include <iostream>

using namespace std;

/*
	fibonacci) O(n)

	1. ������������ ������ ��, �ߺ��� �Լ�ȣ���� ���� �������� -> O(n^2)
	2. DP�� ���� ��ȭ���� ����
	3. � ������ �ذ��ϰ� �� ������ �����س���(Memoization)
*/

int fibonacci(int n)
{
	// Memoization�� ���� �޸�
	int* arr{ new int[n] };

	if (n == 0 || n == 1) return n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; ++i) arr[i] = arr[i - 1] + arr[i - 2];

	return arr[n];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num{};
	cin >> num;

	cout << fibonacci(num);
}
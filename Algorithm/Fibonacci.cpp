#include <iostream>

using namespace std;

/*
	fibonacci) O(n)

	1. ������������ ������ ��, �ߺ��� �Լ�ȣ���� ���� �������� -> O(n^2)
	2. DP�� ���� ��ȭ���� ����
	3. � ���� ������ �ذ��ϰ� �� ������ �����س���(Memoization)
*/

unsigned long long fibonacci(int n)
{
	// Memoization�� ���� �޸�
	unsigned long long* DP{ new unsigned long long[n] };

	if (n == 0 || n == 1) return n;

	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= n; ++i) DP[i] = DP[i - 1] + DP[i - 2];

	return DP[n];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num{};
	cin >> num;

	cout << fibonacci(num);
}
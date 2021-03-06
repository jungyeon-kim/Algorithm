#include <iostream>

using namespace std;

/*
	fibonacci) O(n)

	1. 분할정복으로 구현할 시, 중복된 함수호출이 많아 성능저하 -> O(n^2)
	2. DP를 통해 점화식을 도출
	3. 어떤 작은 문제를 해결하고 그 문제를 저장해놓음(Memoization)
*/

unsigned long long fibonacci(int n)
{
	// Memoization을 위한 메모리
	unsigned long long* DP{ new unsigned long long[n]{} };

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
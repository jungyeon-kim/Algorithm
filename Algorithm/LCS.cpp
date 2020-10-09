#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
	Longest Common Subsequence) O(n^2)

	1. 해당 문자들이 같다면 DP에 이전 DP + 1을 저장한다.
	2. 같지않다면 str1 - 1자리의 DP와 str2 - 1자리의 DP중 더 큰값을 저장한다.
	3. 1, 2 반복
*/

int DP[1001][1001];

int main()
{
	// 문자열 입력
	string left{}, right{};
	cin >> left >> right;

	for(int i = 1; i <= left.size(); ++i)
		for (int j = 1; j <= right.size(); ++j)
		{
			if (left[i - 1] == right[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}

	cout << DP[left.size()][right.size()];
}
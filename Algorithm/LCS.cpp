#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
	Longest Common Subsequence) O(n^2)

	1. �ش� ���ڵ��� ���ٸ� DP�� ���� DP + 1�� �����Ѵ�.
	2. �����ʴٸ� str1 - 1�ڸ��� DP�� str2 - 1�ڸ��� DP�� �� ū���� �����Ѵ�.
	3. 1, 2 �ݺ�
*/

int DP[1001][1001];

int main()
{
	// ���ڿ� �Է�
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
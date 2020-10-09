#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Longest Increasing Subsequence) O(nlogn)

	1. ������ ������ �����̳ʸ� �غ�
	2. ù��° ���� ����
	3. ���� �������� �����̳��� ���� ���� ũ�ٸ� �� �ڿ� ���� (������ �����)
	4. �۴ٸ� ����Ž���� ���� �ش� ���������� �������� ū �ڸ��� �����
	5. 3, 4 �ݺ�

	�� 2�������� ���ؼ��� ������ �� ������, ����Ž���� �̿��� �� ȿ�������� ��갡��
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ������ ����
	int N{};
	cin >> N;

	// �� ������ ��
	int* val{ new int[N] };
	for (int i = 0; i < N; ++i) cin >> val[i];

	// ������� ������ �����ϴ� �����̳�
	vector<int> DP{ val[0] };
	for (int i = 1; i < N; ++i)
	{
		// �ش� �������� �����̳��� �������� ũ�ٸ� �����ϴ� �����̴� �����Ѵ�.
		if (DP.back() < val[i]) DP.emplace_back(val[i]);
		// �ش� �������� �������� �۴ٸ� �ش�������� �������� ū ��ġ�� ������.
		else if (DP.back() > val[i]) *lower_bound(DP.begin(), DP.end(), val[i]) = val[i];
	}

	// ���������� �����̳ʿ��� ���� ���̰� �� �����ϴ� �������� ����ȴ�.
	cout << DP.size();
}
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

/*
	next_permutation:	������ �ش��ϴ� ���� ������ ������ �����̳ʸ� �ٲٰ� true ��ȯ
						���� ������ ������ ���� ������ �������� ������ �ڶ��(���̻� ������ ã�� �� ���ٸ�) false ��ȯ

	�� ����� ������������ ���ĵǾ��ִٰ� �����ϰ� ������ �����ϱ� ������ ���ĵǾ� �־���Ѵ�.
*/

constexpr int MAX_SIZE{ 3 };

int main()
{
	set<vector<int>> set{};
	int arr[MAX_SIZE]{ 9, 8, 3 };

	sort(arr, arr + MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; ++i)
		do
		{
			vector<int> v{};
			for (int j = 0; j <= i; ++j) v.emplace_back(arr[j]);
			set.emplace(v);
		} while (next_permutation(arr, arr + MAX_SIZE));

	for (const auto& i : set)
	{
		for (int j : i) cout << j << " ";
		cout << "\n";
	}
}
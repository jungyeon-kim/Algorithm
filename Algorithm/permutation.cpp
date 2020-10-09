#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

/*
	next_permutation:	범위에 해당하는 다음 조합의 순열로 컨테이너를 바꾸고 true 반환
						다음 조합의 순열이 이전 조합의 순열보다 순서가 뒤라면(더이상 조합을 찾을 수 없다면) false 반환

	※ 대상이 오름차순으로 정렬되어있다고 가정하고 순열을 조합하기 때문에 정렬되어 있어야한다.
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
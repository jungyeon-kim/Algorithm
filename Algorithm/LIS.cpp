#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Longest Increasing Subsequence) O(nlogn)

	1. 수열을 적재할 컨테이너를 준비
	2. 첫번째 수열 적재
	3. 다음 수열값이 컨테이너의 끝값 보다 크다면 그 뒤에 적재 (정렬이 보장됨)
	4. 작다면 이진탐색을 통해 해당 수열값보다 다음으로 큰 자리에 덮어씌움
	5. 3, 4 반복

	※ 2중포문을 통해서도 구현할 수 있지만, 이진탐색을 이용해 더 효율적으로 계산가능
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 수열의 개수
	int N{};
	cin >> N;

	// 각 원소의 값
	int* val{ new int[N] };
	for (int i = 0; i < N; ++i) cin >> val[i];

	// 최장길이 수열을 저장하는 컨테이너
	vector<int> DP{ val[0] };
	for (int i = 1; i < N; ++i)
	{
		// 해당 수열값이 컨테이너의 끝값보다 크다면 증가하는 수열이니 적재한다.
		if (DP.back() < val[i]) DP.emplace_back(val[i]);
		// 해당 수열값이 끝값보다 작다면 해당수열값을 다음으로 큰 위치에 덮어씌운다.
		else if (DP.back() > val[i]) *lower_bound(DP.begin(), DP.end(), val[i]) = val[i];
	}

	// 최종적으로 컨테이너에는 가장 길이가 긴 증가하는 수열들이 적재된다.
	cout << DP.size();
}
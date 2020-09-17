#include <iostream>

using namespace std;

/*
	카운팅 정렬) O(n)

	1. 정렬할 원소의 수만큼 배열을 구성
	2. 원소와 대응되는 배열 인덱스의 값을 증가(카운팅)
	3. 값이 존재하는 인덱스를 차례대로 출력
*/

// 값이 0 ~ 10000 사이라고 가정
constexpr int NUM{ 10000 + 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[NUM]{};

	int N{};
	cin >> N;

	int val{};
	for (int i = 0; i < N; ++i)
	{
		cin >> val;
		++arr[val];		// 카운트 증가
	}

	for (int i = 0; i < NUM; ++i)				// 값은 0 ~ 10000 사이이므로
		if (arr[i])								// arr[i]에 값이 있다는 것은 input에 해당원소가 있었다는 것
			for (int j = 0; j < arr[i]; ++j)	// 중복되는 원소가 있을 수 있으므로
				cout << i << "\n";
}
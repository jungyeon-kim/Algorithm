#include <iostream>

using namespace std;

/*
	n-queen) DFS

	1. 첫 행을 기준으로 퀸을 놓는다고 가정 -> 각 행에는 하나의 퀸만이 존재
	2. 행을 제외한 열, 두 대각선에 대해서 검사
*/

int DFS(int N, int count)
{
	// 퀸 존재여부 -> 열, 증가하는 대각선, 감소하는 대각선
	static bool* col{ new bool[N]{} }, * upDiag{ new bool[N * 2 - 1]{} }, * downDiag{ new bool[N * 2 - 1]{} };
	static int result{};

	if (count == N) ++result;

	// 행을 기준으로 퀸을 놓아본다.
	for (int i = 0; i < N; ++i)
		// 증가하는 대각선: 좌측상단 기준, 감소하는 대각선: 좌측하단 기준
		if (!col[i] && !upDiag[i + count] && !downDiag[(i - count) + N - 1])
		{
			col[i] = upDiag[i + count] = downDiag[(i - count) + N - 1] = true;
			DFS(N, count + 1);
			col[i] = upDiag[i + count] = downDiag[(i - count) + N - 1] = false;
		}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N개의 퀸, N X N 체스판
	int N{};
	cin >> N;

	cout << DFS(N, 0);
}
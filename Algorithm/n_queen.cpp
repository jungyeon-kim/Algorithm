#include <iostream>

using namespace std;

/*
	n-queen) DFS

	1. ù ���� �������� ���� ���´ٰ� ���� -> �� �࿡�� �ϳ��� ������ ����
	2. ���� ������ ��, �� �밢���� ���ؼ� �˻�
*/

int DFS(int N, int count)
{
	// �� ���翩�� -> ��, �����ϴ� �밢��, �����ϴ� �밢��
	static bool* col{ new bool[N]{} }, * upDiag{ new bool[N * 2 - 1]{} }, * downDiag{ new bool[N * 2 - 1]{} };
	static int result{};

	if (count == N) ++result;

	// ���� �������� ���� ���ƺ���.
	for (int i = 0; i < N; ++i)
		// �����ϴ� �밢��: ������� ����, �����ϴ� �밢��: �����ϴ� ����
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

	// N���� ��, N X N ü����
	int N{};
	cin >> N;

	cout << DFS(N, 0);
}
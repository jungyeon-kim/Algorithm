#include <iostream>

using namespace std;

/*
	ī���� ����) O(n)

	1. ������ ������ ����ŭ �迭�� ����
	2. ���ҿ� �����Ǵ� �迭 �ε����� ���� ����(ī����)
	3. ���� �����ϴ� �ε����� ���ʴ�� ���
*/

// ���� 0 ~ 10000 ���̶�� ����
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
		++arr[val];		// ī��Ʈ ����
	}

	for (int i = 0; i < NUM; ++i)				// ���� 0 ~ 10000 �����̹Ƿ�
		if (arr[i])								// arr[i]�� ���� �ִٴ� ���� input�� �ش���Ұ� �־��ٴ� ��
			for (int j = 0; j < arr[i]; ++j)	// �ߺ��Ǵ� ���Ұ� ���� �� �����Ƿ�
				cout << i << "\n";
}
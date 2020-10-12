#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
	���ͽ�Ʈ��) �ִܰ��

	1. ����Ǿ� �����鼭 ����ġ�� ���� ������ Ž���ذ��� �Ÿ��� ����
	2. PriorityQueue�� �̿�
	3. ����ġ�� ����ϱ� ������ ��ռӵ��� BFS���� ���� But, ����ġ�� �����ϴ� �׷����� BFS�� �ִܰ�θ� ã�� �� ����

	�� ����� ��ȣ�� ���ӵ� ��� -> �迭�� �̿� (�� �ڵ�� ����ȣ�� 1���� ����)
*/

// �̵��� �� ���ٴ� ���� 16������ INT_MAX�� ǥ��
constexpr int INF{ 0x7FFFFFFF };

int* Dijkstra(int start, vector<pair<int, int>>* arr, int size)
{
	// �湮�� ����� �Ÿ��� ��ȣ�� �����ϴ� �켱����ť
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
	// �� ����� �ִܰŸ��� �����ϴ� �迭
	int* dist{ new int[size]{} };

	// ��� ��带 �̵��� �� ���� ������ �ʱ�ȭ
	for (int i = 0; i < size; ++i) dist[i] = INF;

	pq.push({ 0, start - 1 });	// ����ġ������ �����ϱ����� ����ġ�� first�� ��
	dist[start - 1] = 0;

	while (!pq.empty())
	{
		int curWeight{ pq.top().first };				// �湮�� ����� ����ġ
		int curNode{ pq.top().second };					// �湮�� ���

		pq.pop();

		for (int i = 0; i < arr[curNode].size(); ++i)
		{
			int nextNode{ arr[curNode][i].first - 1 };	// �湮�� ���
			int nextWeight{ arr[curNode][i].second };	// �湮�� ����� ����ġ

			// ���� �������� �Ÿ� + �湮�� ����� ����ġ�� �湮�� �������� �Ÿ����� �۴ٸ�,
			// �湮�� �������� �Ÿ��� �����ϰ� pq�� �湮�� �������� �Ÿ��� �湮�� ��带 push
			if (dist[curNode] + nextWeight < dist[nextNode])
			{
				dist[nextNode] = dist[curNode] + nextWeight;
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ����� ����, ������ ����
	int N{}, E{};
	cin >> N >> E;

	// ���� ���
	int start;
	cin >> start;

	// from���� to�� weight�� �����
	vector<pair<int, int>>* arr{ new vector<pair<int, int>>[N]{} };
	int from{}, to{}, weight{};
	for (int i = 0; i < E; ++i)
	{
		cin >> from >> to >> weight;
		arr[from - 1].emplace_back(to, weight);
	}

	int* dist{ Dijkstra(start, arr, N) };

	for (int i = 0; i < N; ++i) cout << "from: " << start << " to: " << i + 1 << " dist: " << dist[i] << "\n";
}
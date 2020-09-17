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

	�� ����� ��ȣ�� ���ӵ��� ���� ��� -> map�� �̿� (�� �ڵ�� ����������� ��带 ������� ����)
*/

// �̵��� �� ���ٴ� ���� 16������ INT_MAX�� ǥ��
constexpr int INF{ 0x7FFFFFFF };

const map<int, int>& Dijkstra(int start, map<int, vector<pair<int, int>>>& arr)
{
	// �湮�� ����� �Ÿ��� ��ȣ�� �����ϴ� �켱����ť
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
	// �� ����� �ִܰŸ��� �����ϴ� �迭
	static map<int, int> dist{};

	// ��� ��带 �̵��� �� ���� ������ �ʱ�ȭ
	for (const auto& i : arr)
	{
		dist[i.first] = INF;
		for (int j = 0; j < i.second.size(); ++j)
			if (dist[i.second[j].first] != INF)
				dist[i.second[j].first] = INF;
	}

	pq.push({ 0, start });	// ����ġ������ �����ϱ����� ����ġ�� first�� ��
	dist[start] = 0;

	while (!pq.empty())
	{
		int curWeight{ pq.top().first };				// �湮�� ����� ����ġ
		int curNode{ pq.top().second };					// �湮�� ���

		pq.pop();

		for (int i = 0; i < arr[curNode].size(); ++i)
		{
			int nextNode{ arr[curNode][i].first };		// �湮�� ���
			int nextWeight{ arr[curNode][i].second };	// �湮�� ����� ����ġ

			// ���� �������� �Ÿ� + �湮�� ����� ����ġ�� �湮�� �������� �Ÿ����� �۴ٸ�,
			// �湮�� �������� �Ÿ��� �����ϰ� pq�� �湮�� �������� �Ÿ��� �湮�� ����� ��ȣ�� push
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
	map<int, vector<pair<int, int>>> arr{};
	int from{}, to{}, weight{};
	for (int i = 0; i < E; ++i)
	{
		cin >> from >> to >> weight;
		arr[from].emplace_back(to, weight);
	}

	const auto& dist{ Dijkstra(start, arr) };

	for (const auto& i : dist) cout << "from: " << start << " to: " << i.first << " dist: " << i.second << "\n";
}
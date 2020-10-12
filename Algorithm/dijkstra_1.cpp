#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
	다익스트라) 최단경로

	1. 연결되어 있으면서 가중치가 적은 노드부터 탐색해가며 거리를 갱신
	2. PriorityQueue를 이용
	3. 가중치를 고려하기 때문에 평균속도는 BFS보다 느림 But, 가중치가 존재하는 그래프는 BFS로 최단경로를 찾을 수 없음

	※ 노드의 번호가 연속된 경우 -> 배열을 이용 (이 코드는 노드번호가 1부터 시작)
*/

// 이동할 수 없다는 것을 16진수의 INT_MAX로 표현
constexpr int INF{ 0x7FFFFFFF };

int* Dijkstra(int start, vector<pair<int, int>>* arr, int size)
{
	// 방문할 노드의 거리와 번호를 저장하는 우선순위큐
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
	// 각 노드의 최단거리를 저장하는 배열
	int* dist{ new int[size]{} };

	// 모든 노드를 이동할 수 없는 곳으로 초기화
	for (int i = 0; i < size; ++i) dist[i] = INF;

	pq.push({ 0, start - 1 });	// 가중치순으로 정렬하기위해 가중치가 first로 옴
	dist[start - 1] = 0;

	while (!pq.empty())
	{
		int curWeight{ pq.top().first };				// 방문한 노드의 가중치
		int curNode{ pq.top().second };					// 방문한 노드

		pq.pop();

		for (int i = 0; i < arr[curNode].size(); ++i)
		{
			int nextNode{ arr[curNode][i].first - 1 };	// 방문할 노드
			int nextWeight{ arr[curNode][i].second };	// 방문할 노드의 가중치

			// 현재 노드까지의 거리 + 방문할 노드의 가중치가 방문할 노드까지의 거리보다 작다면,
			// 방문할 노드까지의 거리를 갱신하고 pq에 방문할 노드까지의 거리와 방문할 노드를 push
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

	// 노드의 개수, 간선의 개수
	int N{}, E{};
	cin >> N >> E;

	// 시작 노드
	int start;
	cin >> start;

	// from에서 to가 weight로 연결됨
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
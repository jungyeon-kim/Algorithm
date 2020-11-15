#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
	순열조합) DFS

	※ DFS에 변수하나를 추가하여 중복된 원소들로 이루어진 순열을 배제할 수 있음
*/

vector<vector<int>>* DFS(int* arr, int size, int limit, int cnt) // int last
{
	static vector<vector<int>> v1{};
	static vector<int> v2{};
	static unordered_map<int, bool> visited{};

	if (cnt == limit)
	{
		v1.emplace_back(v2);
		return nullptr;
	}

	// int i = last;
	for (int i = 0; i < size; ++i)
		if (visited.find(arr[i]) == visited.end() || !visited[arr[i]])
		{
			v2.emplace_back(arr[i]);
			visited[arr[i]] = true;
			DFS(arr, size, limit, cnt + 1); // i + 1
			visited[arr[i]] = false;
			v2.pop_back();
		}

	return &v1;
}

constexpr int MAX_SIZE{ 3 };

int main()
{
	int arr[MAX_SIZE]{ 7, 5, 9 };

	sort(arr, arr + MAX_SIZE);

	vector<vector<int>>* result{};
	// 순열을 담는 컨테이너가 static 변수이므로 조합이 누적된다.
	for (int i = 0; i < MAX_SIZE; ++i) result = DFS(arr, MAX_SIZE, i + 1, 0); // 0

	for (const auto& i : *result)
	{
		for (int j : i) cout << j << " ";
		cout << "\n";
	}
}
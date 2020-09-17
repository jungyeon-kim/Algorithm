#include <iostream>

using namespace std;

/*
	깊이우선탐색) 모든경로

	1. 한 방향부터 방문 (막히면 다시 돌아와 다른곳을 탐색 -> 백트래킹)
	2. Stack or 재귀함수를 이용
	4. BFS와 다르게 최단경로를 보장안함
*/

template <typename T>
class Stack
{
private:
	T* arr{};
	int topIdx{ -1 };
	int maxSize{ 1 };
private:
	void deepCopy(const Stack& rhs)
	{
		arr = new T[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; ++i) arr[i] = rhs.arr[i];
		topIdx = rhs.topIdx;
		maxSize = rhs.maxSize;
	}
	void resize()
	{
		T* newArr{ new T[maxSize *= 2] };
		copy(arr, arr + maxSize / 2, newArr);
		delete[] arr;
		arr = newArr;
	}
public:
	Stack() { arr = new T[maxSize]; };
	Stack(const Stack& rhs) { deepCopy(rhs); }
	~Stack() { if (arr) { delete[] arr; arr = nullptr; } }

	Stack& operator=(const Stack& rhs) { if (arr) delete[] arr; deepCopy(rhs); return *this; }

	void push(const T& value) { if (topIdx == maxSize - 1) resize(); arr[++topIdx] = value; }
	void pop() { if (!empty()) --topIdx; }
	int size() const { return topIdx + 1; }
	int capacity() const { return maxSize; }
	bool empty() const { return topIdx == -1 ? true : false; }
	void reverse() { for (int i = 0; i < size() / 2; ++i) swap(arr[i], arr[size() - i - 1]); }
	T& top() const { static T tmp{}; return empty() ? tmp : arr[topIdx]; }
};

struct Pos
{
	int x{}, y{};
	bool operator==(const Pos& rhs) { return x == rhs.x && y == rhs.y; }
	friend ostream& operator<<(ostream& os, const Pos& rhs) { cout << "(" << rhs.x << ", " << rhs.y << ")"; return os; }
};

Stack<Stack<Pos>> DFS(Pos start, Pos end, int** G, Pos size)
{
	// 이동방향을 저장하는 배열 (상, 하, 좌, 우)
	Pos dir[4]{ {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	// 이동경로를 저장하는 스택
	static Stack<Stack<Pos>> path{};
	// 현재 위치한 노드
	Pos curPos{};

	static Stack<Pos> stk{};
	stk.push(start);
	G[start.y][start.x] = 0;

	curPos = stk.top();

	// 현재위치가 도착지점이라면 경로를 path에 push후 리턴
	if (curPos == end) { path.push(stk); return Stack<Stack<Pos>>{}; };

	// 이동가능한 노드인지 검사 & 처리
	for (int i = 0; i < 4; ++i)
	{
		if (curPos.x + dir[i].x >= 0 && curPos.x + dir[i].x < size.x &&			// x가 배열범위를 벗어나는가?
			curPos.y + dir[i].y >= 0 && curPos.y + dir[i].y < size.y &&			// y가 배열범위를 벗어나는가?
			G[curPos.y + dir[i].y][curPos.x + dir[i].x] == 1)					// 이동가능한 노드인가?
		{
			DFS(Pos{ curPos.x + dir[i].x, curPos.y + dir[i].y }, end, G, size);	// 다음노드부터 재귀
			G[curPos.y + dir[i].y][curPos.x + dir[i].x] = 1;					// 빠져나온길 갈 수 있는 길로 Set
			stk.pop();															// 빠져나온길 pop
		}
	}

	return path;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int row{}, column{};
	cin >> row >> column;

	int** Graph{ new int*[row] };
	for (int i = 0; i < row; ++i) Graph[i] = new int[column];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			scanf_s("%1d", &Graph[i][j]);	// cin >> Graph[i][j];

	Stack<Stack<Pos>> path{ DFS(Pos{0, 0}, Pos{column - 1, row - 1}, Graph, Pos{column, row}) };

	cout << "경우의 수: " << path.size() << "\n이동경로: \n";
	while (!path.empty())
	{
		path.top().reverse();
		while (!path.top().empty())
		{
			cout << path.top().top() << " ";
			path.top().pop();
		}
		path.pop();
		cout << "\n";
	}
}
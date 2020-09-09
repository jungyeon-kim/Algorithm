#include <iostream>

using namespace std;

/*
	BFS)

	1. 인접한 노드부터 방문
	2. Queue를 이용
	3. DFS보다 많은 메모리 사용
	4. DFS와 다르게 최단경로를 보장
*/

// 길찾기용
template <typename T>
class Queue
{
private:
	T* arr{};
	int frontIdx{}, rearIdx{ -1 };
	int curSize{}, maxSize{ 1 };
private:
	void resize()
	{
		T* newArr{ new T[maxSize * 2] };
		
		if (frontIdx - rearIdx > 0)
		{
			copy(arr + frontIdx, arr + maxSize, newArr);
			copy(arr, arr + frontIdx, newArr + (maxSize - frontIdx));
			frontIdx = 0;
			rearIdx = maxSize - 1;
		}
		else copy(arr, arr + maxSize, newArr);

		delete[] arr;
		arr = newArr;
		maxSize *= 2;
	}
public:
	Queue() { arr = new T[maxSize]; }
	Queue(const Queue& rhs)
	{
		arr = new T[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; ++i) arr[i] = rhs.arr[i];
		frontIdx = rhs.frontIdx;
		rearIdx = rhs.rearIdx;
		curSize = rhs.curSize;
		maxSize = rhs.maxSize;
	}
	~Queue() { if (arr) { delete[] arr; arr = nullptr; } }

	void push(T value) { if (curSize == maxSize) resize(); arr[++rearIdx %= maxSize] = value; ++curSize; }
	void pop() { if (!empty()) { ++frontIdx %= maxSize; --curSize; } }
	int size() const { return curSize; }
	int capacity() const { return maxSize; }
	bool empty() const { return !curSize ? true : false; }
	T front() const { return empty() ? T{} : arr[frontIdx]; }
};

// 경로 저장용
template <typename T>
class Stack
{
private:
	T* arr{};
	int topIdx{ -1 };
	int maxSize{ 1 };
private:
	void resize()
	{
		T* newArr{ new T[maxSize *= 2] };
		copy(arr, arr + maxSize / 2, newArr);
		delete[] arr;
		arr = newArr;
	}
public:
	Stack() { arr = new T[maxSize]; };
	Stack(const Stack& rhs)
	{
		arr = new T[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; ++i) arr[i] = rhs.arr[i];
		topIdx = rhs.topIdx;
		maxSize = rhs.maxSize;
	}
	~Stack() { if (arr) { delete[] arr; arr = nullptr; } }

	void push(T value) { if (topIdx == maxSize - 1) resize(); arr[++topIdx] = value; }
	void pop() { if (!empty()) --topIdx; }
	int size() const { return topIdx + 1; }
	int capacity() const { return maxSize; }
	bool empty() const { return topIdx == -1 ? true : false; }
	T top() const { return empty() ? T{} : arr[topIdx]; }
};

struct Pos
{
	int x{}, y{};
	bool operator==(const Pos& rhs) { return x == rhs.x && y == rhs.y; }
	bool operator!=(const Pos& rhs) { return x != rhs.x || y != rhs.y; }
	friend ostream& operator<<(ostream& os, const Pos& rhs) { cout << "(" << rhs.x << ", " << rhs.y << ")"; return os; }
};

Stack<Pos> BFS(Pos start, Pos end, int** G, Pos size)
{
	// 이동방향을 저장하는 배열 (상, 하, 좌, 우)
	Pos dir[4]{ {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	// 부모노드(지나온 노드)를 저장하는 배열
	Pos** parent{ new Pos * [size.y] };
	for (int i = 0; i < size.y; ++i) parent[i] = new Pos[size.x];
	// 최단이동 경로를 저장하는 스택
	Stack<Pos> path{};
	// 현재 위치한 노드
	Pos curPos{};

	Queue<Pos> que{};
	que.push(start);
	G[start.y][start.x] = 0;

	while (!que.empty())
	{
		curPos = que.front();
		que.pop();

		// 현재위치가 도착지점이라면 break
		if (curPos == end) break;

		// 이동가능한 노드인지 검사 & 처리
		for (int i = 0; i < 4; ++i)
			if (curPos.x + dir[i].x >= 0 && curPos.x + dir[i].x < size.x &&			// x가 배열범위를 벗어나는가?
				curPos.y + dir[i].y >= 0 && curPos.y + dir[i].y < size.y &&			// y가 배열범위를 벗어나는가?
				G[curPos.y + dir[i].y][curPos.x + dir[i].x] == 1)					// 이동가능한 노드인가?
			{
				que.push({ curPos.x + dir[i].x, curPos.y + dir[i].y });
				G[curPos.y + dir[i].y][curPos.x + dir[i].x] = 0;								// 재방문 못하게
				parent[curPos.y + dir[i].y][curPos.x + dir[i].x] = Pos{ curPos.x, curPos.y };	// 부모노드 Set
			}
	}

	for (Pos i = end; i != start; i = parent[i.y][i.x]) path.push(i);			// 역추적

	return path;
}

int main()
{
	int row{}, column{};
	cin >> row >> column;

	int** Graph{ new int* [row] };
	for (int i = 0; i < row; ++i) Graph[i] = new int[column];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			scanf_s("%1d", &Graph[i][j]);	// cin >> Graph[i][j];

	Stack<Pos> path{ BFS(Pos{0, 0}, Pos{column - 1, row - 1}, Graph, Pos{column, row}) };

	cout << "최단거리: " << path.size() << "\n최단경로: ";
	for (int i = path.size(); i != 0; --i) { cout << path.top() << " "; path.pop(); }
}
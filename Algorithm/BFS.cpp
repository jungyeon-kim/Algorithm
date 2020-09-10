#include <iostream>

using namespace std;

/*
	BFS) �ִܰŸ�, �ִܰ��

	1. ������ ������ �湮
	2. Queue�� �̿�
	4. DFS�� �ٸ��� �ִܰ�θ� ����
*/

template <typename T>
class Queue
{
private:
	T* arr{};
	int frontIdx{}, rearIdx{ -1 };
	int curSize{}, maxSize{ 1 };
private:
	void deepCopy(const Queue& rhs)
	{
		arr = new T[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; ++i) arr[i] = rhs.arr[i];
		frontIdx = rhs.frontIdx;
		rearIdx = rhs.rearIdx;
		curSize = rhs.curSize;
		maxSize = rhs.maxSize;
	}
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
	Queue(const Queue& rhs) { deepCopy(rhs); }
	~Queue() { if (arr) { delete[] arr; arr = nullptr; } }

	Queue& operator= (const Queue& rhs) { if (arr) delete[] arr; deepCopy(rhs); return *this; }

	void push(T value) { if (curSize == maxSize) resize(); arr[++rearIdx %= maxSize] = value; ++curSize; }
	void pop() { if (!empty()) { ++frontIdx %= maxSize; --curSize; } }
	int size() const { return curSize; }
	int capacity() const { return maxSize; }
	bool empty() const { return !curSize ? true : false; }
	void reverse() { for (int i = 0; i < size() / 2; ++i) swap(arr[i], arr[size() - i - 1]); }
	T& front() const { static T tmp{}; return empty() ? tmp : arr[frontIdx]; }
};

struct Pos
{
	int x{}, y{};
	bool operator==(const Pos& rhs) { return x == rhs.x && y == rhs.y; }
	bool operator!=(const Pos& rhs) { return x != rhs.x || y != rhs.y; }
	friend ostream& operator<<(ostream& os, const Pos& rhs) { cout << "(" << rhs.x << ", " << rhs.y << ")"; return os; }
};

Queue<Pos> BFS(Pos start, Pos end, int** G, Pos size)
{
	// �̵������� �����ϴ� �迭 (��, ��, ��, ��)
	Pos dir[4]{ {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	// �θ���(������ ���)�� �����ϴ� �迭
	Pos** parent{ new Pos*[size.y] };
	for (int i = 0; i < size.y; ++i) parent[i] = new Pos[size.x];
	// �ִ��̵� ��θ� �����ϴ� ť
	Queue<Pos> path{};
	// ���� ��ġ�� ���
	Pos curPos{};

	Queue<Pos> que{};
	que.push(start);
	G[start.y][start.x] = 0;

	while (!que.empty())
	{
		curPos = que.front();
		que.pop();

		// ������ġ�� ���������̶�� break
		if (curPos == end) break;

		// �̵������� ������� �˻� & ó��
		for (int i = 0; i < 4; ++i)
			if (curPos.x + dir[i].x >= 0 && curPos.x + dir[i].x < size.x &&		// x�� �迭������ ����°�?
				curPos.y + dir[i].y >= 0 && curPos.y + dir[i].y < size.y &&		// y�� �迭������ ����°�?
				G[curPos.y + dir[i].y][curPos.x + dir[i].x] == 1)				// �̵������� ����ΰ�?
			{
				que.push({ curPos.x + dir[i].x, curPos.y + dir[i].y });
				G[curPos.y + dir[i].y][curPos.x + dir[i].x] = 0;								// ��湮 ���ϰ�
				parent[curPos.y + dir[i].y][curPos.x + dir[i].x] = Pos{ curPos.x, curPos.y };	// �θ��� Set
			}
	}

	for (Pos i = end; i != start; i = parent[i.y][i.x]) path.push(i);			// ������
	path.reverse();

	return path;
}

int main()
{
	int row{}, column{};
	cin >> row >> column;

	int** Graph{ new int*[row] };
	for (int i = 0; i < row; ++i) Graph[i] = new int[column];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			scanf_s("%1d", &Graph[i][j]);	// cin >> Graph[i][j];

	Queue<Pos> path{ BFS(Pos{0, 0}, Pos{column - 1, row - 1}, Graph, Pos{column, row}) };

	cout << "�ִܰŸ�: " << path.size() << "\n�ִܰ��: ";
	for (int i = path.size(); i != 0; --i) { cout << path.front() << " "; path.pop(); }
}
#include <iostream>

using namespace std;

// 최대공약수
int gcd(int lhs, int rhs)
{
	int tmp{};

	while (rhs)
	{
		tmp = lhs % rhs;
		lhs = rhs;
		rhs = tmp;
	}
	return lhs;
}

// 최소공배수
int lcm(int lhs, int rhs)
{
	return lhs * rhs / gcd(lhs, rhs);
}

int main()
{
	int lhs{}, rhs{};

	while (true)
	{
		cout << "두 수를 입력하세요: ";
		cin >> lhs >> rhs;

		cout << lhs << "와 " << rhs << "의 최대공약수: " << gcd(lhs, rhs) << "\n";
		cout << lhs << "와 " << rhs << "의 최소공배수: " << lcm(lhs, rhs) << "\n";
	}
}
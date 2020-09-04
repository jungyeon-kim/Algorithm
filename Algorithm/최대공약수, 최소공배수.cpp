#include <iostream>

using namespace std;

/*
	유클리드)

	2개의 자연수의 최대공약수는 (큰 수 - 작은 수)와 (작은 수)와의 최대공약수와 같다는 성질을 이용
*/

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

		cout << lhs << "와 " << rhs << "의 최대공약수: " << gcd(lhs, rhs) << "\num";
		cout << lhs << "와 " << rhs << "의 최소공배수: " << lcm(lhs, rhs) << "\num";
	}
}
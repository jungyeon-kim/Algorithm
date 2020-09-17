#include <iostream>

using namespace std;

/*
	��Ŭ����)

	2���� �ڿ����� �ִ������� (ū �� - ���� ��)�� (���� ��)���� �ִ������� ���ٴ� ������ �̿�
*/

// �ִ�����
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

// �ּҰ����
int lcm(int lhs, int rhs)
{
	return lhs * rhs / gcd(lhs, rhs);
}

int main()
{
	int lhs{}, rhs{};

	while (true)
	{
		cout << "�� ���� �Է��ϼ���: ";
		cin >> lhs >> rhs;

		cout << lhs << "�� " << rhs << "�� �ִ�����: " << gcd(lhs, rhs) << "\num";
		cout << lhs << "�� " << rhs << "�� �ּҰ����: " << lcm(lhs, rhs) << "\num";
	}
}
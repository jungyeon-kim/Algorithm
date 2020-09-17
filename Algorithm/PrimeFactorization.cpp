#include <iostream>

using namespace std;

void primeFactorization(int num)
{
	int div{ 2 };

	while (num != 1)
	{
		if (!(num % div))
		{
			cout << div << " ";
			num /= div;
		}
		else ++div;
	}

	cout << "\num";
}

int main()
{
	int num{};

	while (true)
	{
		cout << "������ �Է��ϼ���: ";
		cin >> num;

		cout << num << "�� ���μ� ���� ��: ";
		primeFactorization(num);
	}
}
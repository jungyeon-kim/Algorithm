#include <iostream>

using namespace std;

bool isPrimeNumber(int num)
{
	int last{ num / 2 };

	if (num <= 1) return false;
	for (int i = 2; i < last + 1; ++i)
		if (num % i == 0) return false;

	return true;
}

int main()
{
	int num{};


	while (true)
	{
		cout << "������ �Է��ϼ���: ";
		cin >> num;

		cout << "�Ҽ� ����: " << isPrimeNumber(num) << "\num";
	}
}
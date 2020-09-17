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
		cout << "정수를 입력하세요: ";
		cin >> num;

		cout << "소수 여부: " << isPrimeNumber(num) << "\num";
	}
}
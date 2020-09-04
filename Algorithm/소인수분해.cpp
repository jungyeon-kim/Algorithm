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
		cout << "정수를 입력하세요: ";
		cin >> num;

		cout << num << "의 소인수 분해 값: ";
		primeFactorization(num);
	}
}
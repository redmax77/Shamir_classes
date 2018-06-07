#include "stdafx.h"
#include "field.h"

void extended_euclid(int a, int b, int *x, int *y, int *d)
{
	// calculates a * *x + b * *y = gcd(a, b) = *d

	int q, r, x1, x2, y1, y2;

	if (b == 0)
	{
		*d = a, *x = 1, *y = 0;
		return;
	}

	x2 = 1, x1 = 0, y2 = 0, y1 = 1;

	while (b > 0)
	{
		q = a / b, r = a - q * b;
		*x = x2 - q * x1, *y = y2 - q * y1;
		a = b, b = r;
		x2 = x1, x1 = *x, y2 = y1, y1 = *y;
	}

	*d = a, *x = x2, *y = y2;
}

bool prime(int n) {
	long long i;
	n = (long long)n;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

field::field(int characteristic)
{
	_characteristic = characteristic;
	p = prime(_characteristic);
	if (p != true)
	{
		cout << endl << "Invalid field characteristic!" << endl << endl;
		//throw "Invalid field characteristic!";
	}
	//ctor
}

field::~field()
{
	//dtor
}

// Любой элемент в поле
int field::mod(int element)
{
	int m = element % _characteristic;

	return (element >= 0) ? m : m + _characteristic;
}

// Обратный по сложению
int field::get_symmetric(int element)
{
	return mod(0 - element);
}

// Обратный по умножению
int field::get_inverse(int element)
{
	int gcd, x, y;

	extended_euclid(mod(element), _characteristic, &x, &y, &gcd);

	if (gcd == 1)
		return mod(x);

	return 0;
}
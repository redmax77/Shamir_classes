#include "stdafx.h"
#include "polynom.h"

int pow_god(int j, int n)
{
	int i;
	int res = j;
	int counter = abs(n);

	if (n == 0)
		res = 1;

	else if (n == 1)
		res = j;

	else if (n > 1)
	{
		for (i = 1; i < n; i++)
			res = res * j;
	}

	return res;
}

int recover_polynom_use_points_multiplicative_part_2(int *arr_points, int j, int characteristic, int degree)
{
	int x = 1;
	int y = 1;
	int i;

	field f(characteristic);

	//cout << "                       j = " << j << "   arr_points[" << j << "] = " << arr_points[j] << endl;
	for (i = 1; i < (degree + 1); i++)
	{
		if (i != j)
		{
			//xi = xi [*, i!=j] (rj / (rj - ri)  % mod N)
			y = arr_points[i] - arr_points[j];
			//cout << "               members[ i ] - members[j] = " << arr_points[ i ] << " - " << arr_points[j]<< " = " <<y << endl;
			if (y < 0)
			{
				y = f.mod(y);
				//y = field (field_char, y, 1);
				//cout << "                       members[i] - members[j] + " << characteristic << " = " << y << endl;
			}
			//cout << endl << "                                 " << y << endl;
			y = f.get_inverse(y);
			//y = field( field_char, y, 2 );
			//cout << " * " << arr_points[i] << " * " << y << " =  ";
			x = (x * arr_points[i] * y) % characteristic;
			//cout << x;
		}
	}
	//cout << endl << "S(" << arr_points[j] << ") = " << x << endl;
	return x;
}

polynom::polynom(int characteristic, int degree)
{
	//ctor
	_degree = degree;
	_characteristic = characteristic;
	_polynom = new int[_degree];
}

polynom::~polynom()
{
	delete[] _polynom;
	delete[] _polynom_res;
}

// Генерация
int polynom::generate_and_return_secret()
{
	srand(time(NULL));

	for (int i = 0; i < _degree; i++)
	{
		_polynom[i] = abs( rand() ) % _characteristic;

		cout << "polynom[" << i << "] = " << _polynom[i] << endl;
	}
	secret = _polynom[0];
	return _polynom[0];
}

// Вычисление значения полинома сгенерированого от n
int polynom::calculate(int j)
{
	int x = 0;
	int i;

	//_polynom_res = new int [ number_users + 1 ];

	for (i = 0; i < _degree; i++)
	{
		x = (x + _polynom[i] * pow_god(j, i)) % _characteristic;
		//x = (x + _polynom[i] * (int)pow(j, i)) % _characteristic;  // (int)pow(j, i) - не работает корректно в  Code Blocks
		//if (j == 5) cout << "5^" << i << " = " << (int)pow(j, i) << " * " << _polynom[i] << " = " << (_polynom[i] * (int)pow(j, i)) % _characteristic << endl;
	}

	//cout << "f(" << j << ") = " << x << "                       ";

	return x;
}

int polynom::calculate_n_values(int n)
{
	_polynom_res = new int[n];
	int i;

	cout << endl;

	for (i = 1; i < (n + 1); i++)
	{
		_polynom_res[i] = calculate(i);
		cout << "f(" << i << ") = " << _polynom_res[i] << endl;
	}

	return 0;
}

int polynom::recover_polynom_secret_use_points(int *arr_points)
{
	int i;
	int z = 0;
	int x = 0;

	for (i = 1; i < (_degree + 1); i++)
	{
		z = recover_polynom_use_points_multiplicative_part_2(arr_points, i, _characteristic, _degree);

		//cout << _polynom_res[arr_points[i]] << " * " << z << " = " << ((_polynom_res[arr_points[i]] * z)) % _characteristic << endl;

		x = (x + (_polynom_res[arr_points[i]] * z)) % _characteristic;

	}
	recover_secrer = x;
	//cout << endl << endl << "recover_secrer = " << recover_secrer;
	return recover_secrer;
}
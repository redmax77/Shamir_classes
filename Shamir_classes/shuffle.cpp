#include "stdafx.h"
#include "shuffle.h"

int shuffle_array(int *arr, int number_users)
{
	int i;
	int j;
	int tmp;

	srand(time(NULL));

	for (i = number_users - 1; i > 1; i--)
	{
		do
		{
			j = rand() % (i + 1);
		} while (j == 0);

		tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}

	return 0;
}

shuffle::shuffle(int array_size)
{
	_array_size = array_size + 1;
	//ctor
}

shuffle::~shuffle()
{
	delete[] tmp_array;
	//dtor
}

int shuffle::get_n_random_members_from_array(int n, int *members)
{
	int i;
	n = n + 1;
	tmp_array = new int[_array_size];

	for (i = 1; i < _array_size; i++)
	{
		tmp_array[i] = i;
	}

	cout <<  "List of users" << endl;

	shuffle_array(tmp_array, _array_size);

	for (i = 1; i < n; i++)
	{
		members[i] = tmp_array[i];

		cout << "member number: " << members[i] << endl;
	}

	return 0;
}
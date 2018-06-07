#pragma once

#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

class shuffle
{
public:
	shuffle(int array_size);
	virtual ~shuffle();

	int get_n_random_members_from_array(int n, int *members);

protected:

private:
	int _array_size;
	int *tmp_array = NULL;
};
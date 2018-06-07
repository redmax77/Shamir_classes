#pragma once
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

class field
{
public:
	field(int characteristic);
	virtual ~field();

	int mod(int element);
	int get_symmetric(int element);
	int get_inverse(int element);

private:
	int _characteristic;
	bool p;

};
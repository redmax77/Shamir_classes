#pragma once
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "field.h"

using namespace std;

class polynom
{
public:
	polynom(int characteristic, int degree);
	virtual ~polynom();

	int get_secret() { return secret; };
	int get_recover_secret() { return recover_secrer; };
	int generate_and_return_secret();
	int calculate(int j);
	int calculate_n_values(int n);
	int recover_polynom_secret_use_points(int *arr_points);

protected:

private:
	int _degree;
	int _characteristic;
	int secret;
	int recover_secrer;
	int *_polynom = NULL;
	int *_polynom_res = NULL;
};
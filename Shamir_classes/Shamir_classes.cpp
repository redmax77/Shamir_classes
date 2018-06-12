#include "stdafx.h"
#include "polynom.h"
#include "shuffle.h"
#include "field.h"


int main()
{
	int field_caracter; 
	int number_users; 
	int polynom_deegry;
	int secret;
	int *arr;

	cout << "Enter Field : ";
	cin >> field_caracter;
	cout << endl << "Enter Number of secterts part : ";
	cin >> number_users;
	cout << endl << "Enter min Number of secterts part for recovering : ";
	cin >> polynom_deegry;
	cout << endl;

	if (polynom_deegry >= number_users)
		return 0;

	arr = new int[number_users + 1];

	polynom p(field_caracter, polynom_deegry);
	p.generate_and_return_secret();				// Генерируем коэфф. полинома
	p.calculate_n_values(number_users);			// Подсчитываем значение полинома от  всех участников

	cout << endl <<"Secret = " << p.get_secret() << endl << endl;

	shuffle s(number_users);				
	s.get_n_random_members_from_array(polynom_deegry, arr);	// Генерируем минимальное кол-во участников для восстановления

	secret = p.recover_polynom_secret_use_points(arr); //Восстанавливаем секрет
	cout << endl <<  "Recover secrer = " << secret << endl;
	delete[] arr;

	system("pause");
    return 0;
}
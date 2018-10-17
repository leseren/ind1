#include <iostream>
#include <string>
#include "product.h"
using namespace std;




int main()
{
	setlocale(LC_ALL, "Russian");
	stock a = all_sozd();
	cout <<a;

	system("pause");
	return 0;
}
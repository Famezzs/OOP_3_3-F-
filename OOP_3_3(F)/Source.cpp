//////////////////////////////////////////////////////////
// Source.cpp
#include "TriangleO.h"
#include "TriangleC.h"

int main()
{
	TriangleO a;
	TriangleC b;

	cout << "\nTriangle Open:\n";
	cin >> a;
	cout << a;

	cout << "\nTriangle Closed:\n";
	cin >> b;
	cout << b;

	cout << "\n++(Triangle Open):\n";
	cout << ++a;

	cout << "\n++(Triangle Cloesd):\n";
	cout << ++b;

	return 0;
}
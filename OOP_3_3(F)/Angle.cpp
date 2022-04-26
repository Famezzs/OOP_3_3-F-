//////////////////////////////////////////////////////////
// Angle.cpp
#include "Angle.h"

Angle::Angle() 
	:grades(90), minutes(0) {}

Angle::Angle(double x)
{
	int* p = ToDefault(x);
	grades = p[0];
	minutes = p[1];

	delete[] p;
}

Angle::Angle(const int* p, const size_t size)
{
	if (size > 2)
	{
		grades = p[0];
		minutes = p[1];
	}
	else
	{
		grades = 90;
		minutes = 0;
	}
}

Angle::Angle(const Angle& cpy) 
	:grades(cpy.grades), minutes(cpy.minutes) { }

void Angle::SetDegrees(int x)
{
	while (x >= 360)
	{
		x -= 360;
	}
	while (x < 0)
	{
		x += 360;
	}
	grades = x;
}

void Angle::SetMinutes(int x)
{
	if (x >= 0)
	{
		int z = 0;
		while (x >= 60)
		{
			x -= 60;
			z++;
		}
		grades += z;
		minutes = x;
	}
}

double Angle::ToDegrees() const
{
	return GetDegrees() + GetMinutes() / 60.;
}
double Angle::ToRadians() const { return ToDegrees() * Pi / 180.; }
int* Angle::ToDefault(double x)
{
	while (x >= 360)
	{
		x -= 360;
	}
	while (x < 0)
	{
		x += 360;
	}

	int todegrees = int(x);
	int tominutes = int((x - todegrees) * 100);
	while (tominutes >= 60)
	{
		tominutes -= 60;
		todegrees++;
	}

	int* todefault = new int[2];
	todefault[0] = todegrees;
	todefault[1] = tominutes;

	return todefault;
}

void Angle::Increase(const double x)
{
	int* p = ToDefault(ToDegrees() + abs(x));
	grades = p[0];
	minutes = p[1];

	delete[] p;
}

void Angle::Decrease(const double x)
{
	int* p = ToDefault(ToDegrees() - abs(x));
	grades = p[0];
	minutes = p[1];

	delete[] p;
}

double Angle::Sin() const { return sin(ToRadians()); }
double Angle::Cos() const { return cos(ToRadians()); }
bool operator == (const Angle& a, const Angle& b)
{
	return (a.GetDegrees() == b.GetDegrees() && a.GetMinutes() == b.GetMinutes());
}

bool operator != (const Angle& a, const Angle& b)
{
	return !(a == b);
}

bool operator > (const Angle& a, const Angle& b)
{
	return (a.GetDegrees() > b.GetDegrees() || a.GetDegrees() == b.GetDegrees() && a.GetMinutes() > b.GetMinutes());
}

bool operator < (const Angle& a, const Angle& b)
{
	return (a.GetDegrees() < b.GetDegrees() || a.GetDegrees() == b.GetDegrees() && a.GetMinutes() < b.GetMinutes());
}

bool operator >= (const Angle& a, const Angle& b)
{
	return !(a < b);
}

bool operator <= (const Angle& a, const Angle& b)
{
	return !(a > b);
}

ostream& operator << (ostream& out, const Angle& to_out)
{
	out << string(to_out) << endl;
	return out;
}

istream& operator >> (istream& in, Angle& to_in)
{
	int todegrees;
	int tominutes;
	do
	{
		cout << "Degrees: "; in >> todegrees;
		cout << "Minutes: "; in >> tominutes;
	} while (tominutes < 0);

	to_in.SetDegrees(todegrees);
	to_in.SetMinutes(tominutes);

	return in;
}

Angle::operator string() const
{
	stringstream sout;
	sout << "Angle: " << grades << " degrees " << minutes << " minutes";
	return sout.str();
}

Angle& Angle::operator=(const Angle& cpy)
{
	minutes = cpy.minutes;
	grades = cpy.grades;
	return *this;
}

Angle& Angle::operator++()
{
	SetDegrees(grades + 1);
	SetMinutes(minutes + 1);
	return *this;
}

Angle Angle::operator++(int)
{
	Angle tmp(*this);
	SetDegrees(grades + 1);
	SetMinutes(minutes + 1);
	return tmp;
}

Angle& Angle::operator--()
{
	SetDegrees(grades - 1);
	if (minutes > 0)
		SetMinutes(minutes - 1);
	return *this;
}

Angle Angle::operator--(int)
{
	Angle tmp(*this);
	SetDegrees(grades - 1);
	if (minutes > 0)
		SetMinutes(minutes - 1);
	return tmp;
}
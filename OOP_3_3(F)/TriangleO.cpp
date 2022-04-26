//////////////////////////////////////////////////////////
// TriangleO.cpp
#include "TriangleO.h"

TriangleO::TriangleO() 
	:Angle(60), a(1), b(1), c(1), B(60), C(60) {}

TriangleO::TriangleO(double x, double y, double z)
{
	if (IsAdequate(x, y, z) && IsAdequate(y, x, z) && IsAdequate(z, x, y))
	{
		a = x;
		b = y;
		c = z;
		Seta(x);
		Setb(y);
		Setc(z);
	}
	else
	{
		a = 1;
		b = 1;
		c = 1;
		Seta(1);
		Setb(1);
		Setc(1);
	}
}

TriangleO::TriangleO(const TriangleO& cpy) 
	:Angle(cpy), a(cpy.a), b(cpy.b), c(cpy.c), B(cpy.B), C(cpy.C) {}

void TriangleO::Seta(const double x)
{
	if (IsAdequate(x, b, c))
	{
		a = x;
		int* p = ToDefault(acos((b * b + c * c - a * a) / (2. * b * c)) * 180 / Pi);
		SetDegrees(p[0]);
		SetMinutes(p[1]);
		delete[] p;
	}
}

void TriangleO::Setb(const double x)
{
	if (IsAdequate(x, a, c))
	{
		b = x;
		int* p = B.ToDefault(acos((a * a + c * c - b * b) / (2. * a * c)) * 180 / Pi);
		B.SetDegrees(p[0]);
		B.SetMinutes(p[1]);
		delete[] p;
	}
}

void TriangleO::Setc(const double x)
{
	if (IsAdequate(x, a, b))
	{
		c = x;
		int* p = C.ToDefault(acos((a * a + b * b - c * c) / (2. * a * b)) * 180 / Pi);
		C.SetDegrees(p[0]);
		C.SetMinutes(p[1]);
		delete[] p;
	}
}

bool TriangleO::IsAdequate(const double x, const double y, const double z) const
{
	return (x > 0 && x > abs(y - z) && x < (y + z));
}

double TriangleO::Heighta() const { return c * B.Sin(); }
double TriangleO::Heightb() const { return a * C.Sin(); }
double TriangleO::Heightc() const { return b * Sin(); }
double TriangleO::Area() const { return 0.5 * Heighta() * a; }
double TriangleO::Perimeter() const { return a + b + c; }

string TriangleO::Type() const
{
	if (a == b && b == c)
		return "equilateral";
	if (a == b || b == c || a == c)
		return "isosceles triangle";
	Angle t(90);
	if (((GetDegrees() == t) && GetMinutes() == 0) || (B == t) || (C == t))
		return "right triangle";
	if ((GetDegrees() > t || ((GetDegrees() == t) && GetMinutes() > 0) ) || (B > t) || (C > t))
		return "obtuse triangle";
	else
		return "acute triangle";
}

ostream& operator << (ostream& out, const TriangleO& to_out)
{
	out << string(to_out) << endl;
	return out;
}

istream& operator >> (istream& in, TriangleO& to_in)
{
	double aa, bb, cc;
	do
	{
		cout << "Enter a\na = "; in >> aa;
		cout << "Enter b\nb = "; in >> bb;
		cout << "Enter c\nc = "; in >> cc;
	} while (!to_in.IsAdequate(aa, bb, cc) ||
		!to_in.IsAdequate(bb, aa, cc) || !to_in.IsAdequate(cc, bb, aa));

	to_in.a = aa;
	to_in.b = bb;
	to_in.c = cc;
	to_in.Seta(aa);
	to_in.Setb(bb);
	to_in.Setc(cc);

	return in;
}

TriangleO::operator string() const
{
	stringstream sout;
	sout << "a = " << a << " , b = " << b << " , c = " << c << " ;\nA = " << ToDegrees()
		<< " , B = " << B.ToDegrees() << " , C = " << C.ToDegrees() << " ;\nArea = " << Area()
		<< " , perimeter = " << Perimeter() << " , heighta = " << Heighta() << " , heightb = "
		<< Heightb() << " , heightc = " << Heightc() << " , type = " << Type();

	return sout.str();
}

TriangleO& TriangleO::operator=(const TriangleO& cpy)
{
	if (&cpy == this) return *this;

	a = cpy.a;
	b = cpy.b;
	c = cpy.c;

	SetDegrees(cpy.GetDegrees());
	SetMinutes(cpy.GetMinutes());
	B = cpy.B;
	C = cpy.C;

	return *this;
}

TriangleO& TriangleO::operator++()
{
	++a;
	++b;
	++c;
	Seta(a);
	Setb(b);
	Setc(c);

	return *this;
}

TriangleO TriangleO::operator++(int)
{
	TriangleO tmp(*this);
	++a;
	++b;
	++c;
	Seta(a);
	Setb(b);
	Setc(c);

	return tmp;
}

TriangleO& TriangleO::operator--()
{
	if (a > 1 && b > 1 && c > 1)
	{
		--a;
		--b;
		--c;
		Seta(a);
		Setb(b);
		Setc(c);
	}

	return *this;
}

TriangleO TriangleO::operator--(int)
{
	TriangleO tmp(*this);
	if (a > 1 && b > 1 && c > 1)
	{
		--a;
		--b;
		--c;
		Seta(a);
		Setb(b);
		Setc(c);
	}

	return tmp;
}
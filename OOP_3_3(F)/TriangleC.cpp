//////////////////////////////////////////////////////////
// TriangleC.cpp
#include "TriangleC.h"

TriangleC::TriangleC()
	:Angle(60), a(1), b(1), c(1), B(60), C(60) {}

TriangleC::TriangleC(double x, double y, double z)
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

TriangleC::TriangleC(const TriangleC& cpy)
	:Angle(cpy), a(cpy.a), b(cpy.b), c(cpy.c), B(cpy.B), C(cpy.C) {}

void TriangleC::Seta(const double x)
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

void TriangleC::Setb(const double x)
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

void TriangleC::Setc(const double x)
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

bool TriangleC::IsAdequate(const double x, const double y, const double z) const
{
	return (x > 0 && x > abs(y - z) && x < (y + z));
}

double TriangleC::Heighta() const { return c * B.Sin(); }
double TriangleC::Heightb() const { return a * C.Sin(); }
double TriangleC::Heightc() const { return b * Sin(); }
double TriangleC::Area() const { return 0.5 * Heighta() * a; }
double TriangleC::Perimeter() const { return a + b + c; }

string TriangleC::Type() const
{
	if (a == b && b == c)
		return "equilateral";
	if (a == b || b == c || a == c)
		return "isosceles triangle";
	Angle t(90);
	if (((GetDegrees() == t) && GetMinutes() == 0) || (B == t) || (C == t))
		return "right triangle";
	if ((GetDegrees() > t || ((GetDegrees() == t) && GetMinutes() > 0)) || (B > t) || (C > t))
		return "obtuse triangle";
	else
		return "acute triangle";
}

ostream& operator << (ostream& out, const TriangleC& to_out)
{
	out << string(to_out) << endl;
	return out;
}

istream& operator >> (istream& in, TriangleC& to_in)
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

TriangleC::operator string() const
{
	stringstream sout;
	sout << "a = " << a << " , b = " << b << " , c = " << c << " ;\nA = " << ToDegrees()
		<< " , B = " << B.ToDegrees() << " , C = " << C.ToDegrees() << " ;\nArea = " << Area()
		<< " , perimeter = " << Perimeter() << " , heighta = " << Heighta() << " , heightb = "
		<< Heightb() << " , heightc = " << Heightc() << " , type = " << Type();

	return sout.str();
}

TriangleC& TriangleC::operator=(const TriangleC& cpy)
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

TriangleC& TriangleC::operator++()
{
	++a;
	++b;
	++c;
	Seta(a);
	Setb(b);
	Setc(c);

	return *this;
}

TriangleC TriangleC::operator++(int)
{
	TriangleC tmp(*this);
	++a;
	++b;
	++c;
	Seta(a);
	Setb(b);
	Setc(c);

	return tmp;
}

TriangleC& TriangleC::operator--()
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

TriangleC TriangleC::operator--(int)
{
	TriangleC tmp(*this);
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
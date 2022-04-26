//////////////////////////////////////////////////////////
// TriangleC.h
#pragma once
#include "Angle.h"
class TriangleC :
    private Angle
{
private:
	double a;
	double b;
	double c;
	Angle B;
	Angle C;
public:
	TriangleC();
	TriangleC(double, double, double);
	TriangleC(const TriangleC&);
	double Geta() const { return a; }
	double Getb() const { return b; }
	double Getc() const { return c; }
	Angle GetB() const { return B; }
	Angle GetC() const { return C; }
	void Seta(const double);
	void Setb(const double);
	void Setc(const double);
	double Area() const;
	double Perimeter() const;
	double Heighta() const;
	double Heightb() const;
	double Heightc() const;
	string Type() const;
	bool IsAdequate(const double, const double, const double) const;
	friend ostream& operator << (ostream&, const TriangleC&);
	friend istream& operator >> (istream&, TriangleC&);
	operator string() const;
	TriangleC& operator=(const TriangleC&);
	TriangleC& operator++();
	TriangleC operator++(int);
	TriangleC& operator--();
	TriangleC operator--(int);
};


//////////////////////////////////////////////////////////
// TriangleO.h
#pragma once
#include "Angle.h"
class TriangleO
	:public Angle
{
private:
	double a;
	double b;
	double c;
	//Angle A;
	Angle B;
	Angle C;
public:
	TriangleO();
	TriangleO(double, double, double);
	TriangleO(const TriangleO&);
	double Geta() const { return a; }
	double Getb() const { return b; }
	double Getc() const { return c; }
	//Angle GetA() const { return A; }
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
	friend ostream& operator << (ostream&, const TriangleO&);
	friend istream& operator >> (istream&, TriangleO&);
	operator string() const;
	TriangleO& operator=(const TriangleO&);
	TriangleO& operator++();
	TriangleO operator++(int);
	TriangleO& operator--();
	TriangleO operator--(int);
};


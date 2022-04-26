//////////////////////////////////////////////////////////
// Angle.h
#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#define Pi (atan(1) * 4)

using namespace std;

class Angle
{
private:
	int grades;
	int minutes;
public:
	Angle();
	Angle(double);
	Angle(const int*, const size_t);
	Angle(const Angle&);
	int GetDegrees() const { return grades; }
	int GetMinutes() const { return minutes; }
	void SetDegrees(int);
	void SetMinutes(int);
	double ToRadians() const;
	double ToDegrees() const;
	int* ToDefault(double);
	void Increase(const double);
	void Decrease(const double);
	double Sin() const;
	double Cos() const;
	friend ostream& operator << (ostream&, const Angle&);
	friend istream& operator >> (istream&, Angle&);
	friend bool operator == (const Angle&, const Angle&);
	friend bool operator >= (const Angle&, const Angle&);
	friend bool operator <= (const Angle&, const Angle&);
	friend bool operator > (const Angle&, const Angle&);
	friend bool operator < (const Angle&, const Angle&);
	operator string() const;
	Angle& operator=(const Angle&);
	Angle& operator++();
	Angle operator++(int);
	Angle& operator--();
	Angle operator--(int);
};

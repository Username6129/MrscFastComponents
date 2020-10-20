#pragma once
#include <string>
#include <cmath>

using namespace std;

struct Vector2d {
	Vector2d();
	Vector2d(double x, double y);
	double x;
	double y;

	Vector2d operator + (const Vector2d& v) const;
	Vector2d operator - (const Vector2d& v) const;
	Vector2d& operator += (const Vector2d& v);
	Vector2d& operator -= (const Vector2d& v);
	bool operator == (const Vector2d& v) const;
	Vector2d operator >> (const Vector2d& v) const;
	Vector2d operator << (const Vector2d& v) const;
	bool operator < (const Vector2d& v) const;
	string to_string() const;
	Vector2d getUnitVector() const;
	double getAngleDf(const Vector2d& v) const;
};

// For Optimization Purpose
double GetAngleDf(const Vector2d&& v1, const Vector2d&& v2);
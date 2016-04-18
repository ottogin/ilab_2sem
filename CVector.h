#pragma once

class CVector
{
	public:
		double x, y, z;	

		CVector();
		CVector(double tx, double ty);
		CVector(double tx, double ty, double tz);
		CVector(const CVector& a);
		~CVector();

		float len();		

		const CVector& operator=(const CVector& a);
		const CVector& operator+(const CVector& a, const CVector& b);
		const CVector& operator-(const CVector& a, const CVector& b);
		double operator^(const CVector& a, const CVector& b);
		const CVector& operator*(const CVector& a, const CVector& b);
		const CVector& operator*(const CVector& a, double b);
		const CVector& operator*(double b, const CVector& a);
		const CVector& operator+=(CVector& a, const CVector& b);
		const CVector& operator-=(CVector& a, const CVector& b);
		const CVector& operator*=(Cvector& a, const CVector& b);
		const CVector& operator*=(Cvector& a, double b);
		
		bool is_ok();
		bool dump();
		bool print();
}

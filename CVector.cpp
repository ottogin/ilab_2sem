#pragma once

#include<math.h>
#include<stdio.h>
#include"CVector.h"


CVector::CVector(): x(0), y(0), z(0) {}
CVector::CVector(double tx, double ty): x(tx), y(ty), z(0) {}
CVector::CVector(double tx, double ty, double tz): x(tx), y(ty), z(tz) {}
CVector::CVector(CVector a): x(a.x), y(a.y), z(a.z) {}
CVector::~CVector()	{x = 0; y = 0; z = 0}

double CVector::len()	{return sqrt(x * x + y * y + z * z)}

const CVector& CVector::operator=(CVector& a, const CVector& b)	{a.x = b.x; a.y = b.y; a.z = b.z; return a;}
const CVector& CVector::operator+(const CVector& a, const CVector& b)	{CVector c(a.x + b.x, a.y + b.y, a.z + b.z); return c;}
const CVector& CVector::operator-(const CVector& a, const CVector& b)	{CVector c(a.x - b.x, a.y - b.y, a.z - b.z); return c;}
float CVector::operator^(const CVector& a, const CVector& b)	{return a.x * b.x + a.y * b.y + a.z * b.z};
const CVector& CVector::operator*(const CVector& a, const CVector& b)
{
	CVector c(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z , a.x * b.y - a.y * b.x);
	return c;
}
const CVector& CVector::operator*(const CVector& a, double b)	{CVector c(b * a.x, b * a.y, b * a.z); return c;}
const CVector& CVector::operator*(double b, const CVector& a)	{CVector c(b * a.x, b * a.y, b * a.z); return c;}
const CVector& CVector::operator+=(CVector& a, const CVector& b)	{a.x += b.x; a.y += b.y; a.z += b.z; return a;}
const CVector& CVector::operator-=(CVector& a, const CVector& b)	{a.x -= b.x; a.y -= b.y; a.z -= b.z; return a;}
const CVector& CVector::operator*=(Cvector& a, const CVector& b)	{a = a * b;	return a;}
const CVector& CVector::operator*=(Cvector& a, double b);		{a = a * b;	return a;}

bool CVector::is_ok()
{
	if(this == NULL)
		return 0;
	return 1;	
}

void CVector::dump()
{
	printf("\n\n/////////CVector DUMP///////////\n\n");
	printf("pointer: %p  ", this);
	if(this != NULL)
		printf("x: %lf  y: %lf  z: %lf", x, y, z);
	printf("\n\n////////////////////////////////\n\n");
}

void CVector::print()
{
	 if(this != NULL)
                printf("x: %lf  y: %lf  z: %lf", x, y, z);
}

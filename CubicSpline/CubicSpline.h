/**
 * @author Jose Davis Nidhin
 */

#pragma once

#include <math.h>
#include <iostream>

using namespace std;

class CubicSpline
{
public:
	CubicSpline();
	~CubicSpline();

	void Initialize(float * srcX, float * srcY, int size);
	float GetY(float x);

private:
	float *m_arrayB, *m_arrayC, *m_arrayD, *m_arrayX, *m_arrayY;
	int m_size;

	int Bisection(float x);
	float Interpolate(float x, int index);
};
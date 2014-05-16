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
	float Interpolate(float x);

private:
	float *m_B, *m_C, *m_D, *m_X, *m_Y;
	int m_size;

	int GetIndex(float x);
	float Interpolate(float x, int index);
	void Reset();
};
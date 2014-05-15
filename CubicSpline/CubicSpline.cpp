/**
 * @author Jose Davis Nidhin
 * @desc A simple cubic spline interpolation class
 */

#include "stdafx.h"
#include "CubicSpline.h"

/**
 *
 */
CubicSpline::CubicSpline()
{}

/**
 *
 */
CubicSpline::~CubicSpline()
{
	delete[] m_arrayB;
	delete[] m_arrayC;
	delete[] m_arrayD;
}

/**
 *
 */
void CubicSpline::Initialize(float * srcX, float * srcY, int size)
{
	m_arrayX = srcX;
	m_arrayY = srcY;
	m_size = size;

	m_arrayB = new float[size];
	m_arrayC = new float[size];
	m_arrayD = new float[size];

	float * arrayH = new float[size];
	float * arraySig = new float[size];
	float * arrayL = new float[size];
	float * arrayU = new float[size];
	float * arrayZ = new float[size];

	for (int i = 0; i < size - 1; i++) {
		arrayH[i] = srcX[i + 1] - srcX[i];
	}

	for (int i = 1; i < size - 1; i++) {
		arraySig[i] = (3.0f / arrayH[i] * (srcY[i + 1] - srcY[i])) - (3.0f / arrayH[i - 1] * (srcY[i] - srcY[i - 1]));
	}

	arrayL[0] = arrayU[0] = arrayZ[0] = 0.0f;

	for (int i = 1; i < size - 1; i++) {
		arrayL[i] = (2.0f * (srcX[i + 1] - srcX[i - 1])) - (arrayH[i - 1] * arrayU[i - 1]);
		arrayU[i] = arrayH[i] / arrayL[i];
		arrayZ[i] = (arraySig[i] - (arrayH[i - 1] * arrayZ[i - 1])) / arrayL[i];
	}

	arrayZ[size - 1] = 0.0f;
	m_arrayC[size - 1] = 0.0f;

	for (int i = size - 2; i >= 0; i--) {
		m_arrayC[i] = arrayZ[i] - (arrayU[i] * m_arrayC[i + 1]);
		m_arrayB[i] = ((srcY[i + 1] - srcY[i]) / arrayH[i]) - (arrayH[i] * (m_arrayC[i + 1] + 2 * m_arrayC[i]) / 3);
		m_arrayD[i] = (m_arrayC[i + 1] - m_arrayC[i]) / (3 * arrayH[i]);
	}

	delete[] arrayH;
	delete[] arraySig;
	delete[] arrayL;
	delete[] arrayU;
	delete[] arrayZ;
}

/**
 *
 */
float CubicSpline::GetY(float x)
{
	int index = Bisection(x);

	return Interpolate(x, index);
}

/**
 *
 */
int CubicSpline::Bisection(float x)
{
	int last = m_size - 1;
	int first = 0;
	int mid;

	while (last - first > 1) {
		mid = (last + first) / 2;

		if (x > m_arrayX[mid])
			first = mid;
		else
			last = mid;
	}

	return first;
}

/**
 *
 */
float CubicSpline::Interpolate(float x, int index)
{
	float y;

	y = m_arrayY[index] +
		m_arrayB[index] * (x - m_arrayX[index]) +
		m_arrayC[index] * pow((x - m_arrayX[index]), 2) +
		m_arrayD[index] * pow((x - m_arrayX[index]), 3);

	return y;
}
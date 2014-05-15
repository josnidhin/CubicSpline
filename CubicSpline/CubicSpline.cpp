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
	delete[] m_B;
	delete[] m_C;
	delete[] m_D;
}

/**
 *
 */
void CubicSpline::Initialize(float * srcX, float * srcY, int size)
{
	m_X = srcX;
	m_Y = srcY;
	m_size = size;

	m_B = new float[size];
	m_C = new float[size];
	m_D = new float[size];

	float * H = new float[size];
	float * alpha = new float[size];
	float * L = new float[size];
	float * U = new float[size];
	float * Z = new float[size];

	for (int i = 0; i < size - 1; i++) {
		H[i] = srcX[i + 1] - srcX[i];
	}

	for (int i = 1; i < size - 1; i++) {
		alpha[i-1] = (3.0f / H[i] * (srcY[i + 1] - srcY[i])) - (3.0f / H[i - 1] * (srcY[i] - srcY[i - 1]));
	}

	L[0] = U[0] = Z[0] = 0.0f;

	for (int i = 1; i < size - 1; i++) {
		L[i] = (2.0f * (srcX[i + 1] - srcX[i - 1])) - (H[i - 1] * U[i - 1]);
		U[i] = H[i] / L[i];
		Z[i] = (alpha[i-1] - (H[i - 1] * Z[i - 1])) / L[i];
	}

	Z[size - 1] = 0.0f;
	m_C[size - 1] = 0.0f;

	for (int i = size - 2; i >= 0; i--) {
		m_C[i] = Z[i] - (U[i] * m_C[i + 1]);
		m_B[i] = ((srcY[i + 1] - srcY[i]) / H[i]) - (H[i] * (m_C[i + 1] + 2 * m_C[i]) / 3);
		m_D[i] = (m_C[i + 1] - m_C[i]) / (3 * H[i]);
	}

	delete[] H;
	delete[] alpha;
	delete[] L;
	delete[] U;
	delete[] Z;
}

/**
 *
 */
float CubicSpline::Interpolate(float x)
{
	int index = GetIndex(x);

	return Interpolate(x, index);
}

/**
 *
 */
int CubicSpline::GetIndex(float x)
{
	int last = m_size - 1;
	int first = 0;
	int mid;

	while (last - first > 1) {
		mid = (last + first) / 2;

		if (x > m_X[mid])
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

	y = m_Y[index] +
		m_B[index] * (x - m_X[index]) +
		m_C[index] * pow((x - m_X[index]), 2) +
		m_D[index] * pow((x - m_X[index]), 3);

	return y;
}
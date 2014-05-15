/** 
 * @author Jose Davis Nidhin
 * @desc Defines the entry point for the console application.
 */
#include "stdafx.h"

#include <iostream>
#include "CubicSpline.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CubicSpline cs;

	float x1[] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	float y1[] = { 0.0f, 100.0f, 50.0f, 100.0f, 50.0f, 200.0f };
	int size = 6;

	cs.Initialize(x1, y1, size);

	for (float i = 0.0f; i < 5.0f; i += 0.1f) {
		cout << i << ", " << cs.Interpolate(i) << std::endl;
	}

	cout << "Press any key to exit...";
	getchar();
	return 0;
}


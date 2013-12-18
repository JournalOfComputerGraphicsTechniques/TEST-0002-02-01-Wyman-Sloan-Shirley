
#include <math.h>
#include "xyz1931CIE_10nm.h"
#include "../data/ciexyzCurves1931_5nm.h"

float XYZ1931CIE10nm::X( float wavelen )
{
	if (wavelen < 360 || wavelen >= 780) 
		return 0;
	int wMin     = int(floor(wavelen)) / 10;
	int wMax     = wMin+1;
	float weight = (wavelen-float(wMin)*10.0f)/10.0f;

	return (1.0f-weight)*xyz1931_5nm[2*wMin-72][0] + weight*xyz1931_5nm[2*wMax-72][0];
}

float XYZ1931CIE10nm::Y( float wavelen )
{
	if (wavelen < 360 || wavelen >= 780) 
		return 0;
	int wMin     = int(floor(wavelen)) / 10;
	int wMax     = wMin+1;
	float weight = (wavelen-float(wMin)*10.0f)/10.0f;

	return (1.0f-weight)*xyz1931_5nm[2*wMin-72][1] + weight*xyz1931_5nm[2*wMax-72][1];
}

float XYZ1931CIE10nm::Z( float wavelen )
{
	if (wavelen < 360 || wavelen >= 780) 
		return 0;
	int wMin     = int(floor(wavelen)) / 10;
	int wMax     = wMin+1;
	float weight = (wavelen-float(wMin)*10.0f)/10.0f;

	return (1.0f-weight)*xyz1931_5nm[2*wMin-72][2] + weight*xyz1931_5nm[2*wMax-72][2];
}

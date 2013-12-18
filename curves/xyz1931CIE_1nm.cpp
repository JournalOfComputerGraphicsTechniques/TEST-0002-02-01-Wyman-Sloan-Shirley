
#include <math.h>
#include "xyz1931CIE_1nm.h"
#include "../data/ciexyzCurves1931_1nm.h"

float XYZ1931CIE1nm::X( float wavelen )
{
	if (wavelen < 360 || wavelen >= 830) 
		return 0;
	int wMin     = int( floor(wavelen) );
	int wMax     = wMin+1;
	float weight = wavelen-float(wMin);

	return (1.0f-weight)*xyz1931_1nm[wMin-360][0] + weight*xyz1931_1nm[wMax-360][0];
}

float XYZ1931CIE1nm::Y( float wavelen )
{
	if (wavelen < 360 || wavelen >= 830) 
		return 0;
	int wMin     = int( floor(wavelen) );
	int wMax     = wMin+1;
	float weight = wavelen-float(wMin);

	return (1.0f-weight)*xyz1931_1nm[wMin-360][1] + weight*xyz1931_1nm[wMax-360][1];
}

float XYZ1931CIE1nm::Z( float wavelen )
{
	if (wavelen < 360 || wavelen >= 830) 
		return 0;
	int wMin     = int( floor(wavelen) );
	int wMax     = wMin+1;
	float weight = wavelen-float(wMin);

	return (1.0f-weight)*xyz1931_1nm[wMin-360][2] + weight*xyz1931_1nm[wMax-360][2];
}

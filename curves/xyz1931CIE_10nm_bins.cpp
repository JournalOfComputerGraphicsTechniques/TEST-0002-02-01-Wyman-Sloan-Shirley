
#include <math.h>
#include "xyz1931CIE_10nm_bins.h"
#include "../data/ciexyzCurves1931_5nm.h"

float XYZ1931CIE10nmBins::X( float wavelen )
{
	if (wavelen < 355 || wavelen >= 785) 
		return 0;
	int wMin     = int(floor(wavelen+5.0f)/10.0);
	return xyz1931_5nm[2*wMin-72][0];
}

float XYZ1931CIE10nmBins::Y( float wavelen )
{
	if (wavelen < 355 || wavelen >= 785) 
		return 0;
	int wMin     = int(floor(wavelen+5.0f)/10.0f);
	return xyz1931_5nm[2*wMin-72][1];
}

float XYZ1931CIE10nmBins::Z( float wavelen )
{
	if (wavelen < 355 || wavelen >= 785) 
		return 0;
	int wMin     = int(floor(wavelen+5.0)/10.0f);
	return xyz1931_5nm[2*wMin-72][2];
}

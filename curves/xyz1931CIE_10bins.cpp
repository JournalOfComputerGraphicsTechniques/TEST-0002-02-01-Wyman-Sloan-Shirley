
#include <math.h>
#include "xyz1931CIE_10bins.h"
#include "../data/ciexyzCurves1931_1nm.h"

namespace {

bool binnedData=false;
float bins[10][3];

void ComputeBins( void )
{
	int wav=400;
	for (int i=0;i<10;i++)
	{
		bins[i][0] = bins[i][1] = bins[i][2] = 0;
		for (int j=0;j<30;j++)
		{
			bins[i][0] += xyz1931_1nm[wav-360][0];
			bins[i][1] += xyz1931_1nm[wav-360][1];
			bins[i][2] += xyz1931_1nm[wav-360][2];
			wav++;
		}
		bins[i][0] /= 30.0;
		bins[i][1] /= 30.0;
		bins[i][2] /= 30.0;
	}
	binnedData=true;
}

} // end anonymous namespace


float XYZ1931Binned30nm::X( float wavelen )
{
	if (wavelen < 400 || wavelen >= 700) 
		return 0;
	if (!binnedData) ComputeBins();
	int wMin = int(wavelen-399.99)/30;
	return bins[wMin][0];
}

float XYZ1931Binned30nm::Y( float wavelen )
{
	if (wavelen < 400 || wavelen >= 700) 
		return 0;
	if (!binnedData) ComputeBins();
	int wMin = int(wavelen-399.99)/30;
	return bins[wMin][1];
}

float XYZ1931Binned30nm::Z( float wavelen )
{
	if (wavelen < 400 || wavelen >= 700) 
		return 0;
	if (!binnedData) ComputeBins();
	int wMin = int(wavelen-399.99)/30;
	return bins[wMin][2];
}

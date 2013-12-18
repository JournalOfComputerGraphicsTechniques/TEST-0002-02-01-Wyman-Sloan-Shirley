
#include <math.h>
#include "oneGaussianPerLobe1931.h"


float XYZSimpleGaussian1931::X( float wavelen )
{
	float a1 = 1.065f;
	float b1 = 595.8f;
	float c1 = 33.33f;
	float tmp = ( wavelen - b1 ) / c1;
	float bigLobe = a1*expf(-0.5f*tmp*tmp);

	float a2 = 0.3660f;
	float b2 = 446.8f;
	float c2 = 19.44f;
	tmp = ( wavelen - b2 ) / c2;
	float smallLobe = a2*expf(-0.5f*tmp*tmp);

	return smallLobe+bigLobe;
}

float XYZSimpleGaussian1931::Y( float wavelen )
{
	float a = 1.014f;
	float b = 556.3f;
	float c = 0.075f;
	float tmp = ( logf( wavelen ) - logf( b ) ) / c;
	return a*expf(-0.5f*tmp*tmp);
}

float XYZSimpleGaussian1931::Z( float wavelen )
{
	float a = 1.839f;
	float b = 449.8f;
	float c = 0.051f;
	float tmp = ( logf( wavelen ) - logf( b ) ) / c;
	return a*expf(-0.5f*tmp*tmp);
}


#include <math.h>
#include "oneGaussianPerLobe1964.h"

float sqr( float x )
{
	return x * x;
}

float XYZSimpleGaussian1964::X( float wavelen )
{
	float val[4] = { 0.4f, 1014.0f, -0.02f, -570.f };
	float smallLobe = val[0]*expf( -1250* sqr( logf( (wavelen - val[3])/val[1] ) ) );

	float val2[4] = { 1.13f, 234.f, -0.001345f, -1.799f };
	float bigLobe = val2[0]*expf( -val2[1] * sqr( logf( (1338.0f - wavelen)/743.5f ) ) );

	return smallLobe + bigLobe;
}

float XYZSimpleGaussian1964::Y( float wavelen )
{
	float val[4] = { 1.011f, 556.1f, 46.14f, 0.0f }; 
	return val[0]*expf( -0.5f* sqr( (wavelen-val[1])/val[2] ) ) + val[3];
}

float XYZSimpleGaussian1964::Z( float wavelen )
{
	float val[4] = { 2.06f, 180.4f, 0.125f, 266.0f };
	return val[0]*expf( -32.0f* sqr( logf( (wavelen-val[3])/val[1] ) ) );
}

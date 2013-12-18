
#include <math.h>
#include "TannenbaumFit1974.h"

extern float sqr( float );

float Heaviside( float x )
{
	return x>=0.0f?1.0f:0.0f;
}

float XYZTannenbaum1974::X( float wavelen )
{
	return 2.37e-5f * powf(     0.101f*(wavelen-380.0f), 6.0f ) * 
		              sqr( 6 - (0.101f*(wavelen-380.0f)*0.5f) ) *
		              expf(    -0.101f*(wavelen-380.0f)*0.5f );
}

float XYZTannenbaum1974::Y( float wavelen )
{
	return 7.585e-4f * powf(      0.085f*(660.0f-wavelen), 6.0f ) *
		              expf( -2.0f*0.085f*(660.0f-wavelen)/3.0f ) *
					  Heaviside( 660.0f-wavelen );
}

float XYZTannenbaum1974::Z( float wavelen )
{
	return 4.167e-1f * powf( 0.093f * (wavelen-400.0f), 4.0f ) *
		              expf( -0.093f * (wavelen-400.0f) ) *
					  Heaviside( wavelen-400.0f );
}

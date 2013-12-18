
#include <math.h>
#include "MoonSpencerFit1945.h"


float XYZMoonSpencer1945::X( float wavelen )
{
	double wav = wavelen/1000.0;
	double xA = ( 1.237894975e+32 / pow( wav, 365.3388 ) )*exp( -164.9506 / wav );
	double xB = ( 3.247132422e+54 / pow( wav, 500.0    ) )*exp( -237.5    / wav );
	double xC = ( 3.933688807e+69 / pow( wav, 336.0385 ) )*exp( -199.1054 / wav );
    return float(xA - xB + xC);
}

float XYZMoonSpencer1945::Y( float wavelen )
{
	double wav = wavelen/1000.0;
	double yA = ( 2.592984973e+32 / pow( wav, 182.1905 ) )*exp( -100.9370 / wav );
	double yB = ( 0.000010681     / pow( wav, 3.205    ) )*exp( 0.1282    / wav );
	double yC = ( 1.44280378e+69  / pow( wav, 336.0385 ) )*exp( -199.1054 / wav );
	double yD = ( 1.07176606e+262 / pow( wav, 1013.5   ) )*exp( -679.045  / wav );

	if ( wav < 0.62 )
		return float(yA);
	if ( wav < 0.67 )
		return float(yA-yB);
	
	// if ( wav >= 0.67 )
	return float(yC);
}

float XYZMoonSpencer1945::Z( float wavelen )
{
	double wav = wavelen/1000.0;
	return float(( 5.657180035e+32 / pow( wav , 365.3388 ) )*exp( -164.9506 / wav ));
}

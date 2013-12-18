
#ifndef TANNENBAUM_FIT_1964_H
#define TANNENBAUM_FIT_1964_H

#include "xyzAbstract.h"

class XYZTannenbaum1974 : public XYZAbstract
{
public:
	XYZTannenbaum1974()          { strcpy( name, "Tannenbaum Fit (to 1964 CIE)" ); }
	virtual ~XYZTannenbaum1974() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
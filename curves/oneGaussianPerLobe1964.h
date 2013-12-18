
#ifndef ONEGAUSSIANPERLOBE_1964_H
#define ONEGAUSSIANPERLOBE_1964_H

#include "xyzAbstract.h"

class XYZSimpleGaussian1964 : public XYZAbstract
{
public:
	XYZSimpleGaussian1964()          { strcpy( name, "Single Lobe Fit (Sec 2.1) to 1964 CIE" ); }
	virtual ~XYZSimpleGaussian1964() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
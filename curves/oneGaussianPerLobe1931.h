
#ifndef ONEGAUSSIANPERLOBE_1931_H
#define ONEGAUSSIANPERLOBE_1931_H

#include "xyzAbstract.h"

class XYZSimpleGaussian1931 : public XYZAbstract
{
public:
	XYZSimpleGaussian1931()          { strcpy( name, "Single Lobe Fit (Sec 2.1) to 1931 CIE" ); }
	virtual ~XYZSimpleGaussian1931() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif

#ifndef XYZ_1931CIE_10BINS_H
#define XYZ_1931CIE_10BINS_H

#include "xyzAbstract.h"

class XYZ1931Binned30nm : public XYZAbstract
{
public:
	XYZ1931Binned30nm()          { strcpy( name, "CIE 1931, 10 bins (each 30nm)" ); }
	virtual ~XYZ1931Binned30nm() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
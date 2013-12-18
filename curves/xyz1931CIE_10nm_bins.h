
#ifndef XYZ_1931CIE_10NM_BINS_H
#define XYZ_1931CIE_10NM_BINS_H

#include "xyzAbstract.h"

class XYZ1931CIE10nmBins : public XYZAbstract
{
public:
	XYZ1931CIE10nmBins()          { strcpy( name, "CIE 1931, 10nm bins" ); }
	virtual ~XYZ1931CIE10nmBins() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
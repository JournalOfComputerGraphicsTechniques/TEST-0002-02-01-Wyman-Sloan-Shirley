
#ifndef XYZ_1931CIE_10NM_H
#define XYZ_1931CIE_10NM_H

#include "xyzAbstract.h"

class XYZ1931CIE10nm : public XYZAbstract
{
public:
	XYZ1931CIE10nm()          { strcpy( name, "CIE 1931, 10nm samples interpolated" ); }
	virtual ~XYZ1931CIE10nm() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
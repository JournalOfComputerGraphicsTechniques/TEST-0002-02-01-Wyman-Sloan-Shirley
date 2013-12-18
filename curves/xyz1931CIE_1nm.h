
#ifndef XYZ_1931CIE_1NM_H
#define XYZ_1931CIE_1NM_H

#include "xyzAbstract.h"

class XYZ1931CIE1nm : public XYZAbstract
{
public:
	XYZ1931CIE1nm()          { strcpy( name, "CIE 1931, 1nm samples" ); }
	virtual ~XYZ1931CIE1nm() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
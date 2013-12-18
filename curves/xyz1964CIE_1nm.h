
#ifndef XYZ_1964CIE_1NM_H
#define XYZ_1964CIE_1NM_H

#include "xyzAbstract.h"

class XYZ1964CIE1nm : public XYZAbstract
{
public:
	XYZ1964CIE1nm()          { strcpy( name, "CIE 1964, 1nm samples" ); }
	virtual ~XYZ1964CIE1nm() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
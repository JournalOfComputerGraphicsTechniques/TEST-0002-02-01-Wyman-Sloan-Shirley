
#ifndef MOONSPENCER_1931_H
#define MOONSPENCER_1931_H

#include "xyzAbstract.h"

class XYZMoonSpencer1945 : public XYZAbstract
{
public:
	XYZMoonSpencer1945()          { strcpy( name, "Moon and Spencer Fit (to CIE 1931)" ); }
	virtual ~XYZMoonSpencer1945() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
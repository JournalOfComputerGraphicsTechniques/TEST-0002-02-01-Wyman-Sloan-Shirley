
#ifndef MULTILOBEFIT_1931_H
#define MULTILOBEFIT_1931_H

#include "xyzAbstract.h"

class XYZMultiLobeFit1931 : public XYZAbstract
{
public:
	XYZMultiLobeFit1931()          { strcpy( name, "Multi-Lobe Fit (Sec 2.2) to CIE 1931" ); }
	virtual ~XYZMultiLobeFit1931() {}

	virtual float X( float wavelen );
	virtual float Y( float wavelen );
	virtual float Z( float wavelen );
};


#endif
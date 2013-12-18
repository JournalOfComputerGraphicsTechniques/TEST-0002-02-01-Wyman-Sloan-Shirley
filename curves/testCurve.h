
#ifndef TEST_H
#define TEST_H

#include "xyzAbstract.h"

class TestCurve : public XYZAbstract
{
public:
	TestCurve()          { strcpy( name, "Test curve" ); }
	virtual ~TestCurve() {}

	virtual float X( float wavelen ) { return 0; }
	virtual float Y( float wavelen ) { return 1; }
	virtual float Z( float wavelen ) { return 2; }
};


#endif
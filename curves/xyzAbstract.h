


#ifndef XYZ_ABSTRACT_H
#define XYZ_ABSTRACT_H

#include <string.h>
#include "iglu.h"


class XYZAbstract
{
protected:
	char name[256];
public:
	XYZAbstract()           { strcpy( name, "<Unknown curve!>" ); }
	virtual ~XYZAbstract()  {}

	// Returns the name of the curve; should be changed in derived classes
	virtual char* CurveName( void ) { return name; }

	// Derived classes need to define ways to find the X, Y, Z curves
	virtual float X( float wavelen ) = 0;
	virtual float Y( float wavelen ) = 0;
	virtual float Z( float wavelen ) = 0;

	// Derived classes may redefine this function to get all three values
	//    at once in a vec3 structure, if it would be faster than individually
	//    calling X(), Y(), and Z().
	virtual iglu::vec3 XYZ( float wavelen ) 
	{ 
		return iglu::vec3( X(wavelen), Y(wavelen), Z(wavelen) ); 
	}
};


#endif
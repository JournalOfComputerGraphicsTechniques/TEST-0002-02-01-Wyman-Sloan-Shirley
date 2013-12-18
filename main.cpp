/* A crude spectral curve viewer for the paper "Simple Analytic Approximations
**    to the CIE XYZ Color Matching Functions"
**
** The viewer code is not particularly interesting (or well constructed), however
**    the data in the directory "data/" may be useful for incorporation elsewhere
**    and the curves in the directory "curves/" can be used indepedent of the 
**    viewer and allow easy evaluation of all the curves discussed in the paper
**    based on derivations of the "XYZAbstract" abstract class.
**
** The viewer code relies on author Chris Wyman's "IGLU" library, which can
**    be downloaded from his University of Iowa webpage (and is fairly platform
**    independent), the windowing library FLTK, and the GL extension library GLEW.
*/

#include <GL/glew.h>
#include <stdio.h>
#include "iglu.h"
#include "curves/xyz1931CIE_1nm.h"
#include "curves/xyz1931CIE_10nm.h"
#include "curves/xyz1964CIE_1nm.h"
#include "curves/xyz1931CIE_10bins.h"
#include "curves/oneGaussianPerLobe1931.h"
#include "curves/multiLobeFit1931.h"
#include "curves/oneGaussianPerLobe1964.h"
#include "curves/MoonSpencerFit1945.h"
#include "curves/TannenbaumFit1974.h"
#include "curves/testCurve.h"

using namespace iglu;

IGLUShaderProgram::Ptr   draw      = 0;   // Shader to draw our XYZ curves
IGLUShaderProgram::Ptr   drawAxes  = 0;   // Shader to draw our graph axes

// The window containing UI widgets
IGLUWidgetWindow::Ptr    uiWin = 0;

// An array of the curves we might want to use plus drawable versions
IGLUArray1D< XYZAbstract * >        curves;
IGLUArray1D< IGLUVertexArray::Ptr > drawableCurves;
IGLUArray1D< IGLUVertexArray::Ptr > errorCurves;

IGLUInt  lineWidth   (2, IGLURange<int>(1,5), 1, "Curve width" );
IGLUBool displayX    (true,       "Show X curves");
IGLUBool displayY    (true,      "Show Y curves");
IGLUBool displayZ    (true,      "Show Z curves");
IGLUBool useErrors   (false,      "Error curve (select non-CIE curve)");

vec2     textOffsetFactor( 1.0, 1.0 );

// An array of UI variables for selecting which curves to draw
IGLUArray1D< IGLUBool::Ptr >  curveSelection;

// A list of vertices we can use to draw our x/y axes
IGLUVertexArray::Ptr  axes;

// Create a list of the labels and where they should be on screen
typedef struct { float x; float y; char name[128]; } Label;
Label labels[10] = {
	{ 2.0f,    22.0f,  "0.0" },
	{ 2.0f,    158.0f, "0.5" },
	{ 5.0f,    295.0f, "1.0" },
	{ 7.0f,    433.0f, "1.5" },
	{ 3.0f,    571.0f, "2.0" },
	{ 89.0f,   0.0f,   "400" },
	{ 246.0f,  0.0f,   "500" },
	{ 402.0f,  0.0f,   "600" },
	{ 558.0f,  0.0f,   "700" },
	{ 712.0f,  0.0f,   "800" },
};

// Colors used to draw curves.  Potentially a bug, in that there's a limited number we can show before
//   running off the end of the array...  but this a dirt simple viewer, and if you can understand 9 curves at once...
vec4 colorArr[27] = { 0.8f*color::Red+vec4(0.0f,0.6f,0.6f,0.0f), 0.8f*color::Green+vec4(0.6f,0.0f,0.6f,0.0f), 0.8f*color::Blue+vec4(0.6f,0.6f,0.0f,0.0f),
					 color::Red, color::Green, color::Blue,
                     color::Maroon, color::Aquamarine, color::MidnightBlue,
					 color::Plum, color::SeaGreen, color::SkyBlue,
					 color::HotPink, color::PaleGreen, color::Turquoise,
					 color::Sienna, color::LimeGreen, color::SlateBlue,
					 color::Black, color::Black, color::Black,
					 color::Black, color::Black, color::Black,
					 color::Black, color::Black, color::Black,
					 };

// Draw
void display ( void )
{
	int j=0;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLineWidth( GLfloat(lineWidth) );

	if (!useErrors)
	{
		// Bind and setup the shader
		draw->Enable();
		draw["xRange"] = vec2( 330.0f, 843.0f );
		draw["yRange"] = vec2( -0.13f, 2.05f );
		draw["useXYZ"]    = vec3( displayX ? 1.0f : 0.0f, 
								  displayY ? 1.0f : 0.0f, 
								  displayZ ? 1.0f : 0.0f );
			// For each curve, check if it's selected to be display, if so, draw it
			for (uint i=0; i<drawableCurves.Size(); i++)
			{
				// Check if this curve was selected to be drawn
				if ( curveSelection[i]->GetValue() )
				{
					draw["xColor"] = colorArr[j++];
					draw["yColor"] = colorArr[j++];
					draw["zColor"] = colorArr[j++];
					drawableCurves[i]->DrawArrays( GL_LINE_STRIP, 0, 471 );
				}
			}
		draw->Disable();

		// After drawing the curve, draw the axes
		drawAxes->Enable();
			axes->DrawArrays( GL_LINES, 0, 38 );
		drawAxes->Disable();
	}
	else
	{
		// Bind and setup the shader
		draw->Enable();
		draw["xRange"] = vec2( 330.0f, 843.0f );
		draw["yRange"] = vec2( -0.25f, 0.25f );
		draw["useXYZ"]    = vec3( displayX ? 1.0f : 0.0f, 
								  displayY ? 1.0f : 0.0f, 
								  displayZ ? 1.0f : 0.0f );
			// For each curve, check if it's selected to be display, if so, draw it
			for (uint i=0; i<errorCurves.Size(); i++)
			{
				// Check if this curve was selected to be drawn
				if ( curveSelection[i]->GetValue() )
				{
					draw["xColor"] = colorArr[j++];
					draw["yColor"] = colorArr[j++];
					draw["zColor"] = colorArr[j++];
					errorCurves[i]->DrawArrays( GL_LINE_STRIP, 0, 471 );
				}
			}
		draw->Disable();
	}

	// Draw the labels
	for (int i=0; i<10; i++)
		IGLUDraw::DrawColorText( IGLU_FONT_VARIABLE, 
		                         int(textOffsetFactor.X()*labels[i].x), 
								 int(textOffsetFactor.Y()*labels[i].y), 
								 color::Gray80, labels[i].name, textOffsetFactor.X() );
}



void keys(unsigned char key, int x, int y)
{
	if (key==27 || key=='Q' || key=='q')
		exit(0);
}

void idle ( void )
{
}

// Take an XYZ curve to a renderable vertex array
IGLUVertexArray::Ptr CurveToVertexArray( XYZAbstract *curve )
{
	IGLUVertexArray::Ptr vArr = new IGLUVertexArray();
	float *arrData = (float *)malloc( sizeof(float) * 4 * 471 );
	float *fptr = arrData;
	for (int i=360; i<=830; i++)
	{
		*(fptr++) = float(i);
		*(fptr++) = curve->X(float(i));
		*(fptr++) = curve->Y(float(i));
		*(fptr++) = curve->Z(float(i));
	}
	vArr->SetVertexArray( sizeof(float) * 4 * 471, arrData );
	vArr->EnableAttribute( IGLU_ATTRIB_VERTEX, 4, GL_FLOAT );
	free( arrData );
	return vArr;
}

// Do a pointwise difference between two XYZ curves and store into a renderable vertex array
IGLUVertexArray::Ptr DifferenceToVertexArray( XYZAbstract *approx, XYZAbstract *curve )
{
	IGLUVertexArray::Ptr vArr = new IGLUVertexArray();
	float *arrData = (float *)malloc( sizeof(float) * 4 * 471 );
	float *fptr = arrData;
	for (int i=360; i<=830; i++)
	{
		*(fptr++) = float(i);
		*(fptr++) = approx->X(float(i))-curve->X(float(i));
		*(fptr++) = approx->Y(float(i))-curve->Y(float(i));
		*(fptr++) = approx->Z(float(i))-curve->Z(float(i));
	}
	vArr->SetVertexArray( sizeof(float) * 4 * 471, arrData );
	vArr->EnableAttribute( IGLU_ATTRIB_VERTEX, 4, GL_FLOAT );
	free( arrData );
	return vArr;
}

void OpenGLInitialization( void )
{
	// We're drawing on a white background
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Convert our xyz curves into vertex arrays
	for (uint i=0; i<curves.Size(); i++)
		drawableCurves.Add( CurveToVertexArray( curves[i] ) );

	// Covert our xyz curves into difference arrays.  TODO: This is hard coded (our difference is
	//    computed from either curve #0 or curve #6)
	for (uint i=0; i<curves.Size(); i++)
		errorCurves.Add( DifferenceToVertexArray( curves[i], curves[ i<6?0:6 ] ) );

	// Load the shaders to draw our curves; set some parameters
	draw = new IGLUShaderProgram( "shaders/drawXYZCurve.vert.glsl", 
								  "shaders/drawXYZCurve.geom.glsl",
								  "shaders/drawXYZCurve.frag.glsl" );
	draw["xRange"] = vec2( 330.0f, 843.0f );
	draw["yRange"] = vec2( -0.13f, 2.05f );

	// Load the shader to draw our axes
	drawAxes = new IGLUShaderProgram( "shaders/drawAxes.vert.glsl", 
								      "shaders/drawAxes.frag.glsl" );

	// Create the geometry for our axes
	axes = new IGLUVertexArray();
	float axesData[] = { -0.90f, -0.88f, 0.95f, -0.88f,       // x-axis line
		                 -0.88f, -0.88f, -0.88f, 0.95f,       // y-axis line
						 -0.90f, -0.6513f, -0.88f, -0.6513f,  // 0.25 tick
						 -0.90f, -0.4225f, -0.88f, -0.4225f,  // 0.5 tick
						 -0.90f, -0.1938f, -0.88f, -0.1938f,  // 0.75 tick
						 -0.90f, 0.035f, -0.88f, 0.035f,      // 1.0 tick
						 -0.90f, 0.2638f, -0.88f, 0.2638f,    // 1.25 tick
						 -0.90f, 0.4925f, -0.88f, 0.4925f,    // 1.5 tick
						 -0.90f, 0.7213f, -0.88f, 0.7213f,    // 1.75 tick
						 -0.90f, 0.95f, -0.88f, 0.95f,        // 2.0 tick
						 -0.7243f, -0.88f, -0.7243f, -0.91f,  // 400 nm tick
						 -0.5296f, -0.88f, -0.5296f, -0.91f,  // 450 nm tick
						 -0.3349f, -0.88f, -0.3349f, -0.91f,  // 500 nm tick
						 -0.1402f, -0.88f, -0.1402f, -0.91f,  // 550 nm tick
						 0.0545f, -0.88f, 0.0545f, -0.91f,    // 600 nm tick
						 0.24915f, -0.88f, 0.24915f, -0.91f,  // 650 nm tick
						 0.4438f, -0.88f, 0.4438f, -0.91f,    // 700 nm tick
						 0.6385f, -0.88f, 0.6385f, -0.91f,    // 750 nm tick
						 0.8332f, -0.88f, 0.8332f, -0.91f,    // 800 nm tick
	};
	axes->SetVertexArray( sizeof( axesData ), axesData );
	axes->EnableAttribute( IGLU_ATTRIB_VERTEX, 2, GL_FLOAT );
}

void reshape( int w, int h )
{
	textOffsetFactor = vec2( w/800.0f, h/600.0f );
}

int main(int argc, char** argv)
{
	// Load all the XYZ curves we might look at...
	curves.Add( new XYZ1931CIE1nm() );
	curves.Add( new XYZ1931CIE10nm() );
	curves.Add( new XYZ1931Binned30nm() );
	curves.Add( new XYZSimpleGaussian1931() );
	curves.Add( new XYZMultiLobeFit1931() );
	curves.Add( new XYZMoonSpencer1945() );
	curves.Add( new XYZ1964CIE1nm() );
	curves.Add( new XYZSimpleGaussian1964() );
	curves.Add( new XYZTannenbaum1974() );

	// Setup our window 
	IGLUWindow::Ptr myWin = new IGLUWindow( 800, 600, "XYZ Curve and Approximation Viewer \t [Press (+) for options.]" );
	myWin->SetWindowProperties( IGLU_WINDOW_DOUBLE |
								IGLU_WINDOW_REDRAW_ON_IDLE ); 
	myWin->SetDisplayCallback( display );  
	myWin->SetIdleCallback( idle );
	myWin->SetKeyboardCallback( keys );
	myWin->SetReshapeCallback( reshape );
	myWin->SetPreprocessOnGLInit( OpenGLInitialization );
	myWin->CreateWindow( argc, argv );     

	// We set the window up with a particular scaling for the label locations.
	//    If we've changed the window resolution, we'll need to rescale
	textOffsetFactor = vec2( myWin->w()/800.0f, myWin->h()/600.0f );

	// Create a widget window to allow us to interact/change our IGLUVariables
	uiWin = new IGLUWidgetWindow( 300, 600, "UI Widget Window" );
	uiWin->AddWidget( &lineWidth );
	uiWin->AddWidgetSpacer();
	uiWin->AddWidget( &displayX );
	uiWin->AddWidget( &displayY );
	uiWin->AddWidget( &displayZ );
	uiWin->AddWidgetSpacer();

	// Convert these curves into vertex arrays
	for (uint i=0; i<curves.Size(); i++)
	{
		curveSelection.Add( new IGLUBool( i==0, curves[i]->CurveName() ) );
		uiWin->AddWidget( curveSelection[i] );
	}

	uiWin->AddWidgetSpacer();
	uiWin->AddWidget( &useErrors );

	myWin->SetWidgetWindow( uiWin );
	
	// Start the FLTK interaction loop
	IGLUWindow::Run();
	return 0;
}

Supplementary code for the paper:
   "Simple Analytic Approximations to the CIE XYZ Color Matching Functions"
   by Chris Wyman, Peter-Pike Sloan, and Peter Shirley

Included:
  * A window executable of the curve viewer
  * The CIE data we used in this paper (in directory "data/")
  * Our implementations of the curves tested in the paper (in "curves/")
  * Source for our crude curve viewer
  * A precompiled .lib and headers for the IGLU library dependency (in "iglu/")
     (+) Code for this library can also be downloaded online and compiled on
         a variety of platforms with various compilers.

The data and curves (in their respective directories) have been designed to
be easy to incorporate into other C++ programs.  You should be able to pull the
code directly from the directories and use in your code, without consulting
the viewer code (except perhaps as an example).  In fact, the viewer code was
written after the fact, once we had curves in the appropriate format.

The code should be cross platform, and we've done a reasonable job of ensure it
compiles warning-free.  

The included Visual Studio project is for VS2010, as is the precompiled IGLU
library we included in the "iglu/" directory.
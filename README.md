
[Journal of Computer Graphics Techniques](http://jcgt.org/published/0002/02/01/ "Permalink to Journal of Computer Graphics Techniques")


## Simple Analytic Approximations to the CIE XYZ Color Matching Functions

![icon](http://jcgt.org/published/0002/02/01/icon.png)

**Authors:**  
Chris Wyman  
Peter-Pike Sloan  
Peter Shirley  
_NVIDIA_

**Editor:**  
Larry Gritz  
_Sony Pictures Imageworks_

**Editor-in-Chief:**  
Morgan&nbsp;McGuire  
_Williams&nbsp;College&nbsp;&amp; NVIDIA_

## Abstract

We provide three analytical fits to the CIE _x̅_, _y̅_, and _z̅_ color matching curves commonly used in predictive and spectral renderers as an intermediate between light spectra and RGB colors. Any of these fits can replace the standard tabulated CIE curves. Using tabulated curves can introduce typos, encourage crude simplifying approximations, or add opportunities to download curves from sources featuring inconsistent or incorrect data. Our analytic fits are simple to implement and verify. While fitting introduces error, our fits introduce less than the variance between the human-subject data aggregated into the CIE standard. Additionally, common rendering approximations, such as coarse spectral binning, introduce significantly more error. We provide simple, analytic fits in Equations 2 and 3, but even our more accurate fit in Equation 4 only requires ten lines of code.


**Download: **

![pdf][1][ Full-Text PDF](http://jcgt.org/published/0002/02/01/paper.pdf) (1.3 MB)

![bibtex][2][ BibTex](http://jcgt.org/published/0002/02/01/bibtex.bib) (428 B)

![file][3][Source Code](releases)


**Citation:** Chris Wyman, Peter-Pike Sloan, and Peter Shirley, Simple Analytic Approximations to the CIE XYZ Color Matching Functions, _Journal of Computer Graphics Techniques (JCGT)_, vol. 2, no. 2, 1-11, 2013. Available online [http://jcgt.org/published/0002/02/01/](http://jcgt.org/published/0002/02/01/)

**Copyright:** © 2013 Wyman, Sloan, and Shirley

**Received:** 2012-11-01; **Recommended:** 2013-01-14; **Published:** 2013-07-12

   [1]: http://jcgt.org/pdficon_large.png
   [2]: http://jcgt.org/bibtex-icon.png
   [3]: http://jcgt.org/file-icon.png

---

# About this repository

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



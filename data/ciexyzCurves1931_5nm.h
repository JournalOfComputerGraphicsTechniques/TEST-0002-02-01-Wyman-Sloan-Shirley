/* This file contains the CIE XYZ 1931 Standard Observer curves    */
/*    sampled at 5 nm intervals, from 360 nm to 780 nm.  This data */
/*    obtained from:  http://www.cis.rit.edu/mcsl/online/cie.php   */


#ifndef CIE_XYZ_1931_STANDARD_OBSERVER_5NM_H
#define CIE_XYZ_1931_STANDARD_OBSERVER_5NM_H

static float const xyz1931_5nm[85][3] = {
    { 0.000130f, 0.000004f, 0.000606f },  // 360 nm
    { 0.000232f, 0.000007f, 0.001086f },  // 365 nm
    { 0.000415f, 0.000012f, 0.001946f },  // 370 nm
    { 0.000742f, 0.000022f, 0.003486f },  // 375 nm
    { 0.001368f, 0.000039f, 0.006450f },  // 380 nm
    { 0.002236f, 0.000064f, 0.010550f },  // 385 nm
    { 0.004243f, 0.000120f, 0.020050f },  // 390 nm
    { 0.007650f, 0.000217f, 0.036210f },  // 395 nm
    { 0.014310f, 0.000396f, 0.067850f },  // 400 nm
    { 0.023190f, 0.000640f, 0.110200f },  // 405 nm
    { 0.043510f, 0.001210f, 0.207400f },  // 410 nm
    { 0.077630f, 0.002180f, 0.371300f },  // 415 nm
    { 0.134380f, 0.004000f, 0.645600f },  // 420 nm
    { 0.214770f, 0.007300f, 1.039050f },  // 425 nm
    { 0.283900f, 0.011600f, 1.385600f },  // 430 nm
    { 0.328500f, 0.016840f, 1.622960f },  // 435 nm
    { 0.348280f, 0.023000f, 1.747060f },  // 440 nm
    { 0.348060f, 0.029800f, 1.782600f },  // 445 nm
    { 0.336200f, 0.038000f, 1.772110f },  // 450 nm
    { 0.318700f, 0.048000f, 1.744100f },  // 455 nm
    { 0.290800f, 0.060000f, 1.669200f },  // 460 nm
    { 0.251100f, 0.073900f, 1.528100f },  // 465 nm
    { 0.195360f, 0.090980f, 1.287640f },  // 470 nm
    { 0.142100f, 0.112600f, 1.041900f },  // 475 nm
    { 0.095640f, 0.139020f, 0.812950f },  // 480 nm
    { 0.057950f, 0.169300f, 0.616200f },  // 485 nm
    { 0.032010f, 0.208020f, 0.465180f },  // 490 nm
    { 0.014700f, 0.258600f, 0.353300f },  // 495 nm
    { 0.004900f, 0.323000f, 0.272000f },  // 500 nm
    { 0.002400f, 0.407300f, 0.212300f },  // 505 nm
    { 0.009300f, 0.503000f, 0.158200f },  // 510 nm
    { 0.029100f, 0.608200f, 0.111700f },  // 515 nm
    { 0.063270f, 0.710000f, 0.078250f },  // 520 nm
    { 0.109600f, 0.793200f, 0.057250f },  // 525 nm
    { 0.165500f, 0.862000f, 0.042160f },  // 530 nm
    { 0.225750f, 0.914850f, 0.029840f },  // 535 nm
    { 0.290400f, 0.954000f, 0.020300f },  // 540 nm
    { 0.359700f, 0.980300f, 0.013400f },  // 545 nm
    { 0.433450f, 0.994950f, 0.008750f },  // 550 nm
    { 0.512050f, 1.000000f, 0.005750f },  // 555 nm
    { 0.594500f, 0.995000f, 0.003900f },  // 560 nm
    { 0.678400f, 0.978600f, 0.002750f },  // 565 nm
    { 0.762100f, 0.952000f, 0.002100f },  // 570 nm
    { 0.842500f, 0.915400f, 0.001800f },  // 575 nm
    { 0.916300f, 0.870000f, 0.001650f },  // 580 nm
    { 0.978600f, 0.816300f, 0.001400f },  // 585 nm
    { 1.026300f, 0.757000f, 0.001100f },  // 590 nm
    { 1.056700f, 0.694900f, 0.001000f },  // 595 nm
    { 1.062200f, 0.631000f, 0.000800f },  // 600 nm
    { 1.045600f, 0.566800f, 0.000600f },  // 605 nm
    { 1.002600f, 0.503000f, 0.000340f },  // 610 nm
    { 0.938400f, 0.441200f, 0.000240f },  // 615 nm
    { 0.854450f, 0.381000f, 0.000190f },  // 620 nm
    { 0.751400f, 0.321000f, 0.000100f },  // 625 nm
    { 0.642400f, 0.265000f, 0.000050f },  // 630 nm
    { 0.541900f, 0.217000f, 0.000030f },  // 635 nm
    { 0.447900f, 0.175000f, 0.000020f },  // 640 nm
    { 0.360800f, 0.138200f, 0.000010f },  // 645 nm
    { 0.283500f, 0.107000f, 0.000000f },  // 650 nm
    { 0.218700f, 0.081600f, 0.000000f },  // 655 nm
    { 0.164900f, 0.061000f, 0.000000f },  // 660 nm
    { 0.121200f, 0.044580f, 0.000000f },  // 665 nm
    { 0.087400f, 0.032000f, 0.000000f },  // 670 nm
    { 0.063600f, 0.023200f, 0.000000f },  // 675 nm
    { 0.046770f, 0.017000f, 0.000000f },  // 680 nm
    { 0.032900f, 0.011920f, 0.000000f },  // 685 nm
    { 0.022700f, 0.008210f, 0.000000f },  // 690 nm
    { 0.015840f, 0.005723f, 0.000000f },  // 695 nm
    { 0.011359f, 0.004102f, 0.000000f },  // 700 nm
    { 0.008111f, 0.002929f, 0.000000f },  // 705 nm
    { 0.005790f, 0.002091f, 0.000000f },  // 710 nm
    { 0.004109f, 0.001484f, 0.000000f },  // 715 nm
    { 0.002899f, 0.001047f, 0.000000f },  // 720 nm
    { 0.002049f, 0.000740f, 0.000000f },  // 725 nm
    { 0.001440f, 0.000520f, 0.000000f },  // 730 nm
    { 0.001000f, 0.000361f, 0.000000f },  // 735 nm
    { 0.000690f, 0.000249f, 0.000000f },  // 740 nm
    { 0.000476f, 0.000172f, 0.000000f },  // 745 nm
    { 0.000332f, 0.000120f, 0.000000f },  // 750 nm
    { 0.000235f, 0.000085f, 0.000000f },  // 755 nm
    { 0.000166f, 0.000060f, 0.000000f },  // 760 nm
    { 0.000117f, 0.000042f, 0.000000f },  // 765 nm
    { 0.000083f, 0.000030f, 0.000000f },  // 770 nm
    { 0.000059f, 0.000021f, 0.000000f },  // 775 nm
    { 0.000042f, 0.000015f, 0.000000f }   // 780 nm
};

#endif


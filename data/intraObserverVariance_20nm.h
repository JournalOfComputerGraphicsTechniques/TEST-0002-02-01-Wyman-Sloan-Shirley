/* This file contains the between-observer variance in XYZ curves, */
/*    as reported by Nimeroff, Rosenblatt, and Dannemiller in      */
/*    "Variability of Spectral Tristimulus Values", JOSA 52(6)     */


#ifndef INTRA_OBSERVER_VARIANCES_20NM_NIMEROFF_H
#define INTRA_OBSERVER_VARIANCES_20NM_NIMEROFF_H

static float const withinObsVariance[17][3] = {
    { 0.00000390f,  0.000000036f, 0.0000788f },    // 400 nm
    { 0.0000288f,   0.000000806f, 0.000595f },     // 420 nm
    { 0.0000119f,   0.00000138f,  0.000301f },     // 440 nm
    { 0.0000337f,   0.00000306f,  0.000635f },     // 460 nm
    { 0.0000220f,   0.0000185f,   0.000187f },     // 480 nm
    { 0.0000128f,   0.0000396f,   0.0000183f },    // 500 nm
    { 0.00000562f,  0.0000141f,   0.00000200f },   // 520 nm
    { 0.0000192f,   0.0000182f,   0.00000133f },   // 540 nm
    { 0.0000871f,   0.0000261f,   0.00000309f },   // 560 nm
    { 0.000172f,    0.0000347f,   0.00000240f },   // 580 nm
    { 0.000152f,    0.0000225f,   0.00000117f },   // 600 nm
    { 0.0000489f,   0.00000740f,  0.000000380f },  // 620 nm
    { 0.00000231f,  0.000000391f, 0.000000009f },  // 640 nm
    { 0.00000141f,  0.000000220f, 0.000000001f },  // 660 nm
    { 0.000000131f, 0.000000019f, 0.0f },          // 680 nm
    { 0.000000011f, 0.000000002f, 0.0f },          // 700 nm
    { 0.000000001f, 0.0f,         0.0f },          // 720 nm
};

#endif


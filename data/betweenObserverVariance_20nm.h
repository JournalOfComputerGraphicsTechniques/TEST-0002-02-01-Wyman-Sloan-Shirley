/* This file contains the between-observer variance in XYZ curves, */
/*    as reported by Nimeroff, Rosenblatt, and Dannemiller in      */
/*    "Variability of Spectral Tristimulus Values", JOSA 52(6)     */


#ifndef BETWEEN_OBSERVER_VARIANCES_20NM_NIMEROFF_H
#define BETWEEN_OBSERVER_VARIANCES_20NM_NIMEROFF_H

static float const betweenObsVariance[17][3] = {
    { 0.000126f,    0.00000118f,  0.00256f },        // 400 nm
    { 0.000937f,    0.0000262f,   0.0193f },         // 420 nm
    { 0.000385f,    0.0000448f,   0.00978f },        // 440 nm
    { 0.00109f,     0.0000995f,   0.0206f },         // 460 nm
    { 0.000716f,    0.000602f,    0.00606f },        // 480 nm
    { 0.000414f,    0.00129f,     0.000593f },       // 500 nm
    { 0.000183f,    0.000457f,    0.0000649f },      // 520 nm
    { 0.000622f,    0.000590f,    0.0000431f },      // 540 nm
    { 0.00283f,     0.000847f,    0.000100f },       // 560 nm
    { 0.00569f,     0.00113f,     0.0000778f },      // 580 nm
    { 0.00493f,     0.000731f,    0.0000379f },      // 600 nm
    { 0.00159f,     0.000240f,    0.0000123f },      // 620 nm
    { 0.0000750f,   0.0000127f,   0.00000028f },     // 640 nm
    { 0.0000458f,   0.00000713f,  0.000000043f },    // 660 nm
    { 0.00000427f,  0.000000619f, 0.000000002f },    // 680 nm
    { 0.000000366f, 0.000000052f, 0.0f },            // 700 nm
    { 0.000000019f, 0.000000003f, 0.0f },            // 720 nm
};

#endif


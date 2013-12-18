
#include <math.h>
#include "multiLobeFit1931.h"


float XYZMultiLobeFit1931::X( float wavelen )
{
	float dParam1 = (wavelen-442.0f)*((wavelen < 442.0f)?0.0624f:0.0374f);
	float dParam2 = (wavelen-599.8f)*((wavelen < 599.8f)?0.0264f:0.0323f);
	float dParam3 = (wavelen-501.1f)*((wavelen < 501.1f)?0.0490f:0.0382f);
	return 0.362f*expf(-0.5f*dParam1*dParam1) + 1.056f*expf(-0.5f*dParam2*dParam2) - 0.065f*expf(-0.5f*dParam3*dParam3);
}

float XYZMultiLobeFit1931::Y( float wavelen )
{
	float dParam1 = (wavelen-568.8f)*((wavelen < 568.8f)?0.0213f:0.0247f);
	float dParam2 = (wavelen-530.9f)*((wavelen < 530.9f)?0.0613f:0.0322f);
	return 0.821f*expf(-0.5f*dParam1*dParam1) + 0.286f*expf(-0.5f*dParam2*dParam2);
}

float XYZMultiLobeFit1931::Z( float wavelen )
{
	float dParam1 = (wavelen-437.0f)*((wavelen < 437.0f)?0.0845f:0.0278f);
	float dParam2 = (wavelen-459.0f)*((wavelen < 459.0f)?0.0385f:0.0725f);
	return 1.217f*expf(-0.5f*dParam1*dParam1) + 0.681f*expf(-0.5f*dParam2*dParam2);
}

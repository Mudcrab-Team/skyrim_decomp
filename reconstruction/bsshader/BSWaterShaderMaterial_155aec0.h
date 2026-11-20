// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing only
// BSWaterShaderMaterial: STANDIN EXE_RTTI
// WaterVector4, Function155aec0: GUESS(low); a four-float value compared component by component
#pragma once

struct WaterVector4
{
	float x;  // 00
	float y;  // 04
	float z;  // 08
	float w;  // 0C
};

class BSWaterShaderMaterial
{
public:
	static bool Function155aec0(const WaterVector4* a_lhs, const WaterVector4* a_rhs);
};

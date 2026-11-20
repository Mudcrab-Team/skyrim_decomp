// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing only
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x155aec0 BSWaterShaderMaterial::Function155aec0
#include "BSWaterShaderMaterial_155aec0.h"

bool BSWaterShaderMaterial::Function155aec0(const WaterVector4* a_lhs, const WaterVector4* a_rhs)
{
	return a_lhs->x == a_rhs->x && a_lhs->y == a_rhs->y && a_lhs->z == a_rhs->z && a_lhs->w == a_rhs->w;
}

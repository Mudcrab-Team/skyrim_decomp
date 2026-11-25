// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfbc230 VortexCtorLeaffbc230::VortexCtorLeaffbc230
#include "VortexCtorLeaffbc230_fbc230.h"

VortexCtorLeaffbc230::VortexCtorLeaffbc230(void* first, void* second, void* third, float a, bool b, float c, const VortexVectorfbc230* vector)
    : VortexBasefbc230(first, second, third, a, b, c)
{
    direction.x = vector->x;
    direction.y = vector->y;
    direction.z = vector->z;
}

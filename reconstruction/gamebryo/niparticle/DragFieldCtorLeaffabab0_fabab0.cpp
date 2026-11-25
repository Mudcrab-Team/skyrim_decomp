// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfabab0 DragFieldCtorLeaffabab0::DragFieldCtorLeaffabab0
#include "DragFieldCtorLeaffabab0_fabab0.h"

DragFieldCtorLeaffabab0::DragFieldCtorLeaffabab0(void* first, void* second, void* third, float a, bool b, float c, bool use, const DragFieldVectorfabab0* vector)
    : DragFieldBasefabab0(first, second, third, a, b, c), useDirection(use)
{
    direction.x = vector->x;
    direction.y = vector->y;
    direction.z = vector->z;
}

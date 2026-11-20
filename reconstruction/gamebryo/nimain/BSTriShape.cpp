// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// Source exposure: binary-analysis. Drafted by Taylor Turner, assisted by claude-sonnet-5-5.
// 0x26d4d0 BSTriShape::AsTriShape
// 0xef2120 BSTriShape::IsEqual
#include "BSTriShape.h"

BSTriShape* BSTriShape::AsTriShape()
{
    return this;
}

bool BSTriShape::IsEqual(NiObject*)
{
    return false;
}

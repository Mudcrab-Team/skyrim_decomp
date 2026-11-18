// Origin: original reconstruction; NiObject declarations from reconstruction/netimmerse/NiObject.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x4b31d0 BSTempEffectSimpleDecal::sub
#include "BSTempEffectSimpleDecal.h"
void BSTempEffectSimpleDecal::Function4b31d0(NiObject* a_object)
{
 if (auto shape = a_object->AsTriShape()) {
  ApplyShape(shape);
 }
}

// Origin: original reconstruction; NiObject declarations from reconstruction/netimmerse/NiObject.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x1576830 BSLight::Function1576830
#include "BSLight.h"
void BSLight::Function1576830(NiObject* a_object)
{
 if (a_object) {
  if (auto node = a_object->AsNode()) {
   ApplyNode(node);
  }
 }
}

// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x4b5800 BSTempEffectSPG::GetType
// 0x4b5250 BSTempEffectSPG::FinishLoadGame
#include "BSTempEffectSPG.h"

// The value 6 is not a named enumerator in the shared TEMP_EFFECT_TYPE; the target returns it as a literal.
TEMP_EFFECT_TYPE BSTempEffectSPG::GetType() const
{
    return static_cast<TEMP_EFFECT_TYPE>(6);
}

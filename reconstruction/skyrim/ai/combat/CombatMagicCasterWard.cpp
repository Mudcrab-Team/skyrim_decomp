// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:118
// CombatMagicCasterWard, GetObjectType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x850ef0 CombatMagicCasterWard::GetObjectType
#include "CombatMagicCasterWard.h"
unsigned int CombatMagicCasterWard::GetObjectType() const
{
    // Use C++ dynamic local-static initialization: the Skyrim target uses thread-safe CRT initialization.
    // This replaces upstream's manually reconstructed guard; it is a game/compiler API adaptation.
    static unsigned int classType = CombatObjectBase::GenerateClassType("CombatMagicCasterWard");
    return classType;
}

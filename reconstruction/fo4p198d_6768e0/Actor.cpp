// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Actor::GetEditorLocation: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:507
// names: GUESS(low); signatures and helper identities need independent review.
// 0x6768e0 Actor::GetEditorLocation
#include "Actor.h"
bool Actor::GetEditorLocation(NiPoint3& location, NiPoint3& angle, TESForm*& form, TESForm*) { if (!editorLocForm) return false; location.x = editorLocCoord.x; location.y = editorLocCoord.y; location.z = editorLocCoord.z; angle.x = 0.0f; angle.y = 0.0f; angle.z = editorLocRot; form = editorLocForm; return true; }

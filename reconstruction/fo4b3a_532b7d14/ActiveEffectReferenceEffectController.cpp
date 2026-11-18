// ActiveEffectReferenceEffectController::HandleEvent: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Game/Magic/ReferenceEffectControllers.cpp:213.
// ActiveEffectReferenceEffectController::SwitchAttachedRoot: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Game/Magic/ReferenceEffectControllers.cpp:232.
// ActiveEffectReferenceEffectController::SetWindPoint: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Game/Magic/ReferenceEffectControllers.cpp:298.
// Semantic names and types: GUESS(low)
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// 0x5dc6b0 ActiveEffectReferenceEffectController::HandleEvent
// 0x5dc740 ActiveEffectReferenceEffectController::SwitchAttachedRoot
// 0x5dcac0 ActiveEffectReferenceEffectController::SetWindPoint
#include "ActiveEffectReferenceEffectController.h"
void ActiveEffectReferenceEffectController::HandleEvent(const BSFixedString& event) { effect->HandleEvent(event); }
void ActiveEffectReferenceEffectController::SwitchAttachedRoot(NiNode* from, NiNode* to) { effect->SwitchAttachedRoot(from, to); }
void ActiveEffectReferenceEffectController::SetWindPoint(const NiPoint3& point) { windPoint.x = point.x; windPoint.y = point.y; windPoint.z = point.z; }

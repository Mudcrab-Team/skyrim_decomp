// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// EffectRotatesWithCamera: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:155
// OwnedCameraEffectController, OwnedCameraEffectController::EffectRotatesWithCamera: SIBLING(fo4-private@1b765c70, author-permission)
// 0x5dc480 OwnedCameraEffectController::EffectRotatesWithCamera
#include "OwnedCameraEffectController.h"

bool OwnedCameraEffectController::EffectRotatesWithCamera() const { return inheritRotation; }

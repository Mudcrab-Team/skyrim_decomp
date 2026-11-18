// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ActiveEffectReferenceEffectController::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target save call.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:302
// names: GUESS(low); save helper signature is inferred.
// 0x5dcb40 ActiveEffectReferenceEffectController::SaveGame
#include "ActiveEffectReferenceEffectController.h"
void ActiveEffectReferenceEffectController::SaveGame(BGSSaveGameBuffer* buffer) const { unsigned int handle = target; buffer->SaveFormID(&handle, false); }

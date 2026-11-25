// Source exposure: mixed (community-generated layout and local binary analysis).
// Code origin: original reconstruction from the assigned local pack; no adapted body.
// ActorKnowledge, DetectionState: CRASHLOGGER_PDB(59818@2026.10.24)
// ClearDetectionState: SIBLING(fo4-private@1b765c70, author-permission); name only, via project label index.
// Destroy: GUESS(low); inferred ownership release operation.
// 0x7c4090 ActorKnowledge::ClearDetectionState
#include "ActorKnowledge_7c4090.h"
#include <intrin.h>
void ActorKnowledge::ClearDetectionState()
{
    auto* oldState = detectionState;
    if (oldState) {
        detectionState = nullptr;
        // Atomic ownership release protects shared detection state lifetime.
        if (_InterlockedExchangeAdd(&oldState->refCount, -1) == 1)
            oldState->Destroy();
    }
}

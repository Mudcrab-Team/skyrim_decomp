// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1658a0: GUESS(low); provisional member name
// 0x1658a0 ExtraDataList::Function1658a0
// CI hash: 0x1658a0 ?Function1658a0@ExtraDataList@@QEAAX_N@Z
#include "ExtraDataList_1658a0.h"

// Guess: Set or clear the selected extra-data flag.
void ExtraDataList::Function1658a0(bool enabled)
{
    auto* data = static_cast<Payload1658a0*>(GetByType(0x36));
    if (data) {
        unsigned char flags = data->flags;
        if (enabled) { data->flags = flags | 4; }
        else { data->flags = flags & ~4; }
    }
}

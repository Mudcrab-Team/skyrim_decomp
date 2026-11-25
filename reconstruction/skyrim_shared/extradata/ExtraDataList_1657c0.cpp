// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1657c0: GUESS(low); provisional member name
// 0x1657c0 ExtraDataList::Function1657c0
// CI hash: 0x1657c0 ?Function1657c0@ExtraDataList@@QEAAX_N@Z
#include "ExtraDataList_1657c0.h"

// Guess: Set or clear the selected extra-data flag.
void ExtraDataList::Function1657c0(bool enabled)
{
    auto* data = static_cast<Payload1657c0*>(GetByType(0x36));
    if (data) {
        unsigned char flags = data->flags;
        if (enabled) { data->flags = flags | 1; }
        else { data->flags = flags & ~1; }
    }
}

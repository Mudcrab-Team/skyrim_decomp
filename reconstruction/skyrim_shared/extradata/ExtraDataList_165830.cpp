// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165830: GUESS(low); provisional member name
// 0x165830 ExtraDataList::Function165830
// CI hash: 0x165830 ?Function165830@ExtraDataList@@QEAAX_N@Z
#include "ExtraDataList_165830.h"

// Guess: Set or clear the selected extra-data flag.
void ExtraDataList::Function165830(bool enabled)
{
    auto* data = static_cast<Payload165830*>(GetByType(0x36));
    if (data) {
        unsigned char flags = data->flags;
        if (enabled) { data->flags = flags | 2; }
        else { data->flags = flags & ~2; }
    }
}

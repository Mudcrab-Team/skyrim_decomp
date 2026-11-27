// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164ae0: GUESS(low); provisional member name
// 0x164ae0 ExtraDataList::Function164ae0
// CI hash: 0x164ae0 ?Function164ae0@ExtraDataList@@QEAAXPEAUValue164ae0@@@Z
#include "ExtraDataList_164ae0.h"

// Guess: Copy an optional extra-data record or its default sentinel.
void ExtraDataList::Function164ae0(Value164ae0* output)
{
    auto* data = static_cast<Payload164ae0*>(GetByType(134));
    if (data) {
        output->first = data->value.first;
        output->flag = data->value.flag;
        output->second = data->value.second;
    } else {
        output->first = ~0u;
        output->flag = 0;
        output->second = 0;
    }
}

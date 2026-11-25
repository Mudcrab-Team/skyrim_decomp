// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164a40: GUESS(low); provisional member name
// 0x164a40 ExtraDataList::Function164a40
// CI hash: 0x164a40 ?Function164a40@ExtraDataList@@QEAAXPEAUValue164a40@@@Z
#include "ExtraDataList_164a40.h"

// Guess: Copy an optional extra-data record or its default sentinel.
void ExtraDataList::Function164a40(Value164a40* output)
{
    auto* data = static_cast<Payload164a40*>(GetByType(78));
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

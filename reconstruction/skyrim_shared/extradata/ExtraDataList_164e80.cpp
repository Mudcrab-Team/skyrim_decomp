// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164e80: GUESS(low); provisional member name
// 0x164e80 ExtraDataList::Function164e80
// CI hash: 0x164e80 ?Function164e80@ExtraDataList@@QEAAPEAXXZ
#include "ExtraDataList_164e80.h"

// Guess: Retrieve the pointer carried by the selected extra-data kind.
void* ExtraDataList::Function164e80()
{
    auto* data = static_cast<Payload164e80*>(GetByType(20));
    if (data) { return data->value; }
    return nullptr;
}

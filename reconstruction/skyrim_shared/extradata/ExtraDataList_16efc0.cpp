// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function16efc0: GUESS(low); provisional member name
// 0x16efc0 ExtraDataList::Function16efc0
// CI hash: 0x16efc0 ?Function16efc0@ExtraDataList@@QEAAPEAXXZ
#include "ExtraDataList_16efc0.h"

// Guess: Retrieve the pointer carried by the selected extra-data kind.
void* ExtraDataList::Function16efc0()
{
    auto* data = static_cast<Payload16efc0*>(GetByType(2));
    if (!data) { return nullptr; }
    return data->value;
}

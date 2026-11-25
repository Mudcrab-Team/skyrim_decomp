// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function16d980: GUESS(low); provisional member name
// 0x16d980 ExtraDataList::Function16d980
// CI hash: 0x16d980 ?Function16d980@ExtraDataList@@QEAAPEAXXZ
#include "ExtraDataList_16d980.h"

// Guess: Retrieve the pointer carried by the selected extra-data kind.
void* ExtraDataList::Function16d980()
{
    auto* data = static_cast<Payload16d980*>(GetByType(107));
    if (data) { return data->value; }
    return nullptr;
}

// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function16db10: GUESS(low); provisional member name
// 0x16db10 ExtraDataList::Function16db10
// CI hash: 0x16db10 ?Function16db10@ExtraDataList@@QEAAPEAXXZ
#include "ExtraDataList_16db10.h"

// Guess: Retrieve the pointer carried by the selected extra-data kind.
void* ExtraDataList::Function16db10()
{
    auto* data = static_cast<Payload16db10*>(GetByType(108));
    if (data) { return data->value; }
    return nullptr;
}

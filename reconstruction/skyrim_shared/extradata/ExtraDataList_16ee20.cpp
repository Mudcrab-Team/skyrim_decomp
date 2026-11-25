// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function16ee20: GUESS(low); provisional member name
// 0x16ee20 ExtraDataList::Function16ee20
// CI hash: 0x16ee20 ?Function16ee20@ExtraDataList@@QEAAXPEAX@Z
#include "ExtraDataList_16ee20.h"

// Guess: Clear the extra-data pointer only when it names the supplied value.
void ExtraDataList::Function16ee20(void* value)
{
    auto* data = static_cast<Payload16ee20*>(GetByType(0x1a));
    if (data && data->value == value) { data->value = nullptr; }
}

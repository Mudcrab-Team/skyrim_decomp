// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1705e0: GUESS(low); provisional member name
// 0x1705e0 ExtraDataList::Function1705e0
// CI hash: 0x1705e0 ?Function1705e0@ExtraDataList@@QEAAPEAIPEAX@Z
#include "ExtraDataList_1705e0.h"

// Guess: Retrieve or create the extra-data record and expose its value.
unsigned* ExtraDataList::Function1705e0(void* owner)
{
    auto* data = static_cast<Payload1705e0*>(GetByType(0xe));
    if (!data) { data = Create(owner); }
    return &data->value;
}

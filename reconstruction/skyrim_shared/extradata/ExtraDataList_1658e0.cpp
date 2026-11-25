// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1658e0: GUESS(low); provisional member name
// 0x1658e0 ExtraDataList::Function1658e0
// CI hash: 0x1658e0 ?Function1658e0@ExtraDataList@@QEAAXE@Z
#include "ExtraDataList_1658e0.h"

// Guess: Update a scalar in the selected extra-data payload.
void ExtraDataList::Function1658e0(std::uint8_t value)
{
    auto* data = static_cast<Payload1658e0*>(GetByType(54));
    if (data) { data->value = value; }
}
